// $Id: ISR_genreco_muons2016.cc 1 2013-11-26 10:23:10Z jalmond $
/***************************************************************************
 * @Project: LQISR_genreco_muons2016 Frame - ROOT-based analysis framework for Korea SNU
 * @Package: LQCycles
 *
 * @author John Almond       <jalmond@cern.ch>           - SNU
 *
 ***************************************************************************/

/// Local includes
#include "ISR_genreco_muons2016.h"

//Core includes
#include "EventBase.h"                                                                                                                           
#include "BaseSelection.h"


//// Needed to allow inheritance for use in LQCore/core classes
ClassImp (ISR_genreco_muons2016);


 /**
  *   This is an Example Cycle. It inherits from AnalyzerCore. The code contains all the base class functions to run the analysis.
  *
  */
ISR_genreco_muons2016::ISR_genreco_muons2016() :  AnalyzerCore(), out_muons(0)  {
  
  
  // To have the correct name in the log:                                                                                                                            
  SetLogName("ISR_genreco_muons2016");
  
  Message("In ISR_genreco_muons2016 constructor", INFO);
  //
  // This function sets up Root files and histograms Needed in ExecuteEvents
  InitialiseAnalysis();
  MakeCleverHistograms(sighist_mm,"DiMuon");


}


void ISR_genreco_muons2016::InitialiseAnalysis() throw( LQError ) {
  
  /// Initialise histograms
  MakeHistograms();  
  //
  // You can out put messages simply with Message function. Message( "comment", output_level)   output_level can be VERBOSE/INFO/DEBUG/WARNING 
  // You can also use m_logger << level << "comment" << int/double  << LQLogger::endmsg;
  //
  
  Message("Making clever hists for Z ->ll test code", INFO);
  
  /// only available in v7-6-X branch and newer
  //// default lumimask is silver ////
  //// In v7-6-2-(current) the default is changed to gold (since METNoHF bug)
  ///When METNoHF isfixed the default will be back to silver
  /// set to gold if you want to use gold json in analysis
  /// To set uncomment the line below:


  return;
}


void ISR_genreco_muons2016::ExecuteEvents()throw( LQError ){





  /// Apply the gen weight 
  if(!isData) weight*=MCweight;
    
  m_logger << DEBUG << "RunNumber/Event Number = "  << eventbase->GetEvent().RunNumber() << " : " << eventbase->GetEvent().EventNumber() << LQLogger::endmsg;
  m_logger << DEBUG << "isData = " << isData << LQLogger::endmsg;
   
  FillCutFlow("NoCut", weight);
  FillHist("Nocut_event", 1., weight, 0.,2.,2);
  //void AnalyzerCore::FillHist(TString histname, float value, float w, float xmin, float xmax, int nbins){
  FillHist("isLumiMaskGold_nocut",eventbase->GetEvent().LumiMask(), weight,0.,2.,2);


  float pileup_reweight=(1.0);
  float pileup_reweight_up=(1.0);
  float pileup_reweight_down=(1.0);
  if (!k_isdata) {
    //ileup_reweight = mcdata_correction->CatPileupWeight(eventbase->GetEvent(),0);   
 // pileup_reweight = mcdata_correction->PileupWeightByPeriod(eventbase->GetEvent());
    pileup_reweight=mcdata_correction->CatPileupWeight(eventbase->GetEvent(),0);
    pileup_reweight_up=mcdata_correction->CatPileupWeight(eventbase->GetEvent(),1);
    pileup_reweight_down=mcdata_correction->CatPileupWeight(eventbase->GetEvent(),-1);
  }

  
  if(isData) FillHist("Nvtx_nocut_data",  eventbase->GetEvent().nVertices() ,weight, 0. , 50., 50);
  else{
    
    FillHist("Nvtx_nocut_mc",  eventbase->GetEvent().nVertices() ,weight, 0. , 50., 50);
    FillHist("Nvtx_nocut_mc_pureweight",  eventbase->GetEvent().nVertices() ,weight*pileup_reweight, 0. , 50., 50);
    
   }  
  if(!PassMETFilter()) return;     /// Initial event cuts : 
  FillCutFlow("EventCut", weight); 
  FillHist("Basic_METFilter_Cut", 1, weight, 0.,2.,2);
  /// #### CAT::: triggers stored are all HLT_Ele/HLT_DoubleEle/HLT_Mu/HLT_TkMu/HLT_Photon/HLT_DoublePhoton
  
  if (!eventbase->GetEvent().HasGoodPrimaryVertex()) return; //// Make cut on event wrt vertex                                                                               
  FillHist("NonZero_Nvtx", 1, weight, 0.,2.,2);
  
  
  TString dimuon_trigmuon_trig1="HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v";
  TString dimuon_trigmuon_trig2="HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v";
  TString dimuon_trigmuon_trig3="HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v";
   TString dimuon_trigmuon_trig4="HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v";

   TString single_trig1 = "HLT_IsoMu24_v"; // 
   TString single_trig2 = "HLT_IsoTkMu24_v";  
   
  // Now you should do an OR of 4 triggers 
  //https://twiki.cern.ch/twiki/bin/view/CMS/MuonHLT2016  
  vector<TString> trignames;
  trignames.push_back(dimuon_trigmuon_trig1);
  trignames.push_back(dimuon_trigmuon_trig2);
  trignames.push_back(dimuon_trigmuon_trig3);
  trignames.push_back(dimuon_trigmuon_trig4);

  vector<TString> trignames2;
  trignames2.push_back(single_trig1);
  trignames2.push_back(single_trig2);


  FillHist("TargetLumi", TargetLumi, weight, 0.,5000.,50000);
 

  std::vector<snu::KElectron> electrons =  GetElectrons(false,false, "ELECTRON_NOCUT");
   //   std::vector<snu::KElectron> CFelectrons = GetElectrons(false,false, "ELECTRON_HN_TIGHTv4");
   /*
     
   std::vector<snu::KElectron> electrons =  GetElectrons(BaseSelection::ELECTRON_NOCUT);  ... WONT WORK
   std::vector<snu::KElectron> electrons =  GetElectrons("ELECTRON_NOCUT");               ... WILL WORK  
   
   std::vector<snu::KElectron> electrons =  GetElectrons(BaseSelection::ELECTRON_POG_TIGHT);  ... WILL WORK  
   std::vector<snu::KElectron> electrons =  GetElectrons("ELECTRON_POG_TIGHT");                ... WILL WORK  
   
   */

   //   std::vector<snu::KElectron> electrons2 =  GetElectrons(BaseSelection::ELECTRON_HN_FAKELOOSE_NOD0);

   std::vector<snu::KJet> jets =   GetJets("PFJET_TIGHT");
   std::vector<snu::KMuon> muons =GetMuons("MUON_POG_TIGHT",true); 
   
   //if(muons.size() > 0) cout << "muon reliso = " << muons[0].RelIso04() << endl;
   



   bool trig_pass= PassTriggerOR(trignames);
   bool trig_pass2= PassTriggerOR(trignames2);
   /*
   if(trig_pass){
   FillCutFlow("Trigger cut", weight);
   FillHist("Trigger_cut", 1, weight, 0.,2.,2);   
   
   }
   if(trig_pass2){
     FillCutFlow("Trigger cut2", weight);
     FillHist("Trigger_cut2", 1, weight, 0.,2.,2);
   }
   */

   /// CorrectMuonMomentum(muons);  will also work as Funcion in AnalyzerCore just calls mcdata_correction function
   
   double idsf = mcdata_correction->MuonScaleFactor("MUON_POG_TIGHT", muons, 0);
   double idsf_up = mcdata_correction->MuonScaleFactor("MUON_POG_TIGHT", muons, 1);
   double idsf_down = mcdata_correction->MuonScaleFactor("MUON_POG_TIGHT", muons, -1);
   //double MCDataCorrections::MuonScaleFactor(TString muid, vector<snu::KMuon> mu,int sys){

   //   double triggersf = TriggerSF_dimu_jhchoi(muons,trignames[0],0);//mcdata_correction->TriggerScaleFactor(electrons, muons, trignames,0);
   //double triggersf_up =  TriggerSF_dimu_jhchoi(muons,trignames[0],1);//mcdata_correction->TriggerScaleFactor(electrons, muons, trignames,1);
   //  double triggersf_down = TriggerSF_dimu_jhchoi(muons,trignames[0],-1);// mcdata_correction->TriggerScaleFactor(electrons, muons, trignames,-1);
   
   //   double triggersf = TriggerSF_dimu_jhchoi(muons,trignames2[0],0);//
   double triggersf = mcdata_correction->TriggerScaleFactor(electrons, muons, trignames2[0],0);                                                              
   // double triggersf_up =  TriggerSF_dimu_jhchoi(muons,trignames2[0],1);//
   double triggersf_up = mcdata_correction->TriggerScaleFactor(electrons, muons, trignames2[0],1);                                                             
   //double triggersf_down = TriggerSF_dimu_jhchoi(muons,trignames2[0],-1);// 
   double triggersf_down = mcdata_correction->TriggerScaleFactor(electrons, muons, trignames2[0],-1);                                                       
  


   //double triggersf = 1;
   //double triggersf_up = 1;
   // double triggersf_down = 1;

  //double MCDataCorrections::TriggerScaleFactor( vector<snu::KElectron> el, vector<snu::KMuon> mu,  TString trigname, int direction){

   double isosf = mcdata_correction->MuonISOScaleFactor("MUON_POG_TIGHT", muons, 0);
   double isosf_up = mcdata_correction->MuonISOScaleFactor("MUON_POG_TIGHT", muons, 1);
   double isosf_down = mcdata_correction->MuonISOScaleFactor("MUON_POG_TIGHT", muons, -1);

   //double MCDataCorrections::MuonISOScaleFactor(TString muid, vector<snu::KMuon> mu,int sys){

   double ev_weight = weight;

   if(!isData){
     //ev_weight
     //idsf
     //triggersf
     //pileup_reweight
     //isosf      
  }
   

   //MCFromTau()
   //   mcdata_correction->CorrectMuonMomentum(muons,eventbase->GetTruth());   




   bool is_doublemuon = (muons.size() == 2);
   if(!is_doublemuon) return;
   // FillHist("doublemuon_cut", 1, weight, 0.,2.,2);
   
   bool is_os = (muons.at(0).Charge() == (-muons.at(1).Charge()));
   //if(!is_os) return;
   FillHist("os_cut", 1, weight, 0.,2.,2);
 

   double iso04_0 = muons.at(0).RelIso04();
   double iso04_1 = muons.at(1).RelIso04();
  
   if(iso04_0 > 0.15) return;
   //FillHist("iso04_cut0", 1, weight, 0.,2.,2);
   if(iso04_1 > 0.15) return;
   //   FillHist("iso04_cut1", 1, weight, 0.,2.,2);

   //   bool mcfromtau_0 = muons[0];


   double ptlep1 = muons[0].Pt();
   double ptlep2 = muons[1].Pt();
   double etalep1 = muons[0].Eta();
   double etalep2 = muons[1].Eta();
   double dipt = (muons[0]+muons[1]).Pt();
   double dimass = (muons[0]+muons[1]).M();
   bool mcfromtau1 = muons[0].MCFromTau();
   bool mcfromtau2 = muons[1].MCFromTau();
   bool TriggerMatch1 =TriggerMatch( dimuon_trigmuon_trig1,muons);
   bool TriggerMatch2 =TriggerMatch( dimuon_trigmuon_trig2,muons);
   bool TriggerMatch3 =TriggerMatch( dimuon_trigmuon_trig3,muons);
   bool TriggerMatch4 =TriggerMatch( dimuon_trigmuon_trig4,muons);
   //if(!TriggerMatch1 &&!TriggerMatch2 &&!TriggerMatch3 && TriggerMatch4) return;
   bool SingleTriggerMatch1 = (muons[0].TriggerMatched(single_trig1) || muons[1].TriggerMatched(single_trig1));
    bool SingleTriggerMatch2 = (muons[0].TriggerMatched(single_trig2) || muons[1].TriggerMatched(single_trig2));
   //   bool SingleTriggerMatch1 = muons[0].TriggerMatched(single_trig1) || muons[0].TriggerMatched(single_trig2);


   if(mcfromtau1||mcfromtau2) return;
   //if(!mcfromtau1 && !mcfromtau2) return;
  
   if(!trig_pass2) return;
      if(!SingleTriggerMatch1 && !SingleTriggerMatch2) return;
   if(!SingleTriggerMatch1) return;
   if((ptlep1>10) && (ptlep2>5) && (fabs(etalep1) < 3) &&( fabs(etalep2) <3)){





     double lep1[16], lep2[16], weights[18], othervs[22];
     double jetinfo[3];
     lep1[8]=muons[0].Pt();
     lep1[9] = muons[0].Eta();
     lep1[10] = muons[0].Phi();
     lep1[11] = muons[0].E();
     lep1[12] = muons[0].Charge();
     lep1[13] = muons[0].ActiveLayer();
     lep1[14] = muons[0].PtShiftedUp();
     lep1[15] = muons[0].PtShiftedDown();

     lep2[8]=muons[1].Pt();
     lep2[9] = muons[1].Eta();
     lep2[10] = muons[1].Phi();
     lep2[11] = muons[1].E();
     lep2[12] = muons[1].Charge();
     lep2[13] = muons[1].ActiveLayer();
     lep2[14] = muons[1].PtShiftedUp();
     lep2[15] = muons[1].PtShiftedDown();
     float metx_old= eventbase->GetEvent().PFMETx();
     float mety_old= eventbase->GetEvent().PFMETy();
     float met_old= eventbase->GetEvent().PFMET();
     float pxold = (muons[0]+muons[1]).Px();
     float pyold = (muons[0]+muons[1]).Py();
     mcdata_correction->CorrectMuonMomentum(muons,eventbase->GetTruth());
     float pxnew = (muons[0]+muons[1]).Px();
     float pynew = (muons[0]+muons[1]).Py();
     float metx_new =  metx_old + pxold-pxnew;
     float mety_new = mety_old + pyold-pynew;
 
     float  met_new =sqrt(metx_new*metx_new + mety_new*mety_new);
     eventbase->GetEvent().SetPFMETx(metx_new);
     eventbase->GetEvent().SetPFMETy(mety_new);
     lep1[0] = muons[0].Pt();
     lep1[1] = muons[0].Eta();
     lep1[2] = muons[0].Phi();
     lep1[2] = muons[0].Phi();
     lep1[3] = muons[0].E();
     lep1[4] = muons[0].Charge();
     lep1[5] = mcfromtau1;
     lep1[6] = 1;
     lep1[7] = 1;


     lep2[0] = muons[1].Pt();
     lep2[1] = muons[1].Eta();
     lep2[2] = muons[1].Phi();
     lep2[2] = muons[1].Phi();
     lep2[3] = muons[1].E();
     lep2[4] = muons[1].Charge();
     lep2[5] = mcfromtau1;
     lep2[6] = 1;
     lep2[7] = 1;
   
     jetinfo[0] = 0;
     jetinfo[1] = 0;
     jetinfo[2] = 0;



     if(isData){
       weights[0] = 1;
       weights[1] = 1;
       weights[2] = 1;
       weights[3] = 1;
       weights[4] = 1;
       weights[5] = 1;
       weights[6] = 1;
       weights[7] = 1;
       weights[8] = 1;
       weights[9] = 1;
       weights[10] = 1;
       weights[11] = 1;
       weights[12] = 1;
       weights[13] = 1;
       weights[14] = 1;
       weights[15] = 1;
       weights[16] = 1;
       weights[17] = 1;


     }//end of if is data    

     if(!isData){

       weights[0] = weight;
       weights[1] = MCweight;
       weights[2] = idsf;
       weights[3] = pileup_reweight;
       weights[4] = triggersf;
       weights[5] =     WeightByTrigger(trignames,TargetLumi);
       weights[6] = isosf;
       weights[7] = idsf_up;
       weights[8] = idsf_down;
       weights[9] = isosf_up;
       weights[10] = isosf_down;
       weights[11] =  pileup_reweight_up;
       weights[12] =  pileup_reweight_down;
       weights[13] =  1;//pu69
       weights[14] =  1;//pu69up
       weights[15] =  1;//pu69down
       weights[16] = triggersf_up;
       weights[17] = triggersf_down;

     }//end of isnotdata !@#     
     FillHist("Mass",dimass,weight*idsf*pileup_reweight*triggersf*isosf,80,100,20);

     othervs[0] = jets.size();
     othervs[1] = met_old;
     othervs[20] = metx_old;
     othervs[21] = mety_old;
     othervs[11]=met_new ;//after correction
     othervs[13] =metx_new;
     othervs[14] =mety_new;


     othervs[2] =  eventbase->GetEvent().nVertices();
     othervs[3]=eventbase->GetEvent().PFMET() ;
     othervs[4]=eventbase->GetEvent().PFMET() ;
     othervs[5]=eventbase->GetEvent().PFMET() ;
     othervs[6]=eventbase->GetEvent().PFMET() ;
   
     //     BaseSelection::ID jetid=PFJET_TIGHT;
     //void  AnalyzerCore::CorrectedMETJES(int sys, vector<snu::KJet> jetall, vector<snu::KFatJet> fjetall,  double& OrignialMET, double& OriginalMETPhi){
     vector<snu::KFatJet> fjetall;
     double metsys=0, metphisys=0;
     AnalyzerCore::CorrectedMETJES(1,jets,fjetall,metsys,metphisys) ;
     othervs[7]=metsys;
     AnalyzerCore::CorrectedMETJES(-1,jets,fjetall,metsys,metphisys) ;
     othervs[8]=metsys;
     AnalyzerCore::CorrectedMETJER(+1,jets,fjetall,metsys,metphisys) ;
     othervs[9]=metsys;
     AnalyzerCore::CorrectedMETJER(-1,jets,fjetall,metsys,metphisys) ;
     othervs[10]=metsys;
     


     if(isData){

       othervs[9] = eventbase->GetEvent().PFMET() ;
       othervs[10] = eventbase->GetEvent().PFMET() ;

     }

     othervs[12]=eventbase->GetEvent().RunNumber();
     othervs[15] = eventbase->GetEvent().x1();
     othervs[16] = eventbase->GetEvent().x2();
     othervs[17] = eventbase->GetEvent().Q();
     

     int errorsize =eventbase->GetEvent().PdfWeights().size();
     othervs[18] = errorsize;
     //              FillHist("pdfweight_1" , eventbase->GetEvent().PdfWeights().at(1), 1., -6. , 6., 12);                                        
     //FillHist("pdfweight_0" , eventbase->GetEvent().PdfWeights().at(0), 1., -6. , 6., 12);                                                      
     //cout<<eventbase->GetEvent().PdfWeights().at(1)<<endl;                                                                                      
     ///if errorsize > 100                                                                                                                        
     
     //              for(int i = 0 ; i<errorsize; i++){                                                                                           
     
     //              }                                                                                                                            
     if(errorsize>100){
       double pdfweight[100];
       for(int i = 0 ; i<100; i++){
	 pdfweight[i] = eventbase->GetEvent().PdfWeights().at(i);
       }
       FillNtp("pdfweight", pdfweight);
       
       double pdfweight2[100];
       
       for(int i = 100 ; i<errorsize; i++){
	 pdfweight2[i-100] = eventbase->GetEvent().PdfWeights().at(i);
	 //   cout<<"pdfweight="<<pdfweight2[i]<<endl;                                                                                            
       }
       FillNtp("pdfweight2", pdfweight2);
     }
     //if errorisze>100                                                                                                                           
     else if(errorsize<=100){
       const int sizesize = errorsize;
       double pdfweight[sizesize];
       
       for(int i = 0 ; i<errorsize; i++){
	 pdfweight[i] = eventbase->GetEvent().PdfWeights().at(i);
       }
       FillNtp("pdfweight", pdfweight);
       
     }
     
     
     int errorsize_scl =eventbase->GetEvent().ScaleWeights().size();
     othervs[19] = errorsize_scl;
     

     

       const int sizesize_scl = errorsize_scl;
       double pdfsclweight[sizesize_scl];
     
       for(int i = 0 ; i<errorsize_scl; i++){
	 pdfsclweight[i] = eventbase->GetEvent().ScaleWeights().at(i);
       }
       FillNtp("pdfsclweight", pdfsclweight);
       

     
     FillNtp("prilep", lep1);
     FillNtp("seclep", lep2);
     FillNtp("weights", weights);
     FillNtp("othervs", othervs);
   


  
   }



   



   
   return;
}// End of execute event loop
  


void ISR_genreco_muons2016::EndCycle()throw( LQError ){
  
  Message("In EndCycle" , INFO);

}


void ISR_genreco_muons2016::BeginCycle() throw( LQError ){
  
  Message("In begin Cycle", INFO);
  
  //
  //If you wish to output variables to output file use DeclareVariable
  // clear these variables in ::ClearOutputVectors function
  //DeclareVariable(obj, label, treename );
  //DeclareVariable(obj, label ); //-> will use default treename: LQTree
  //  DeclareVariable(out_electrons, "Signal_Electrons", "LQTree");
  //  DeclareVariable(out_muons, "Signal_Muons");

  
  return;
  
}

ISR_genreco_muons2016::~ISR_genreco_muons2016() {
  
  Message("In ISR_genreco_muons2016 Destructor" , INFO);
  
}


void ISR_genreco_muons2016::BeginEvent( )throw( LQError ){

  Message("In BeginEvent() " , DEBUG);

  return;
}



void ISR_genreco_muons2016::MakeHistograms(){
  //// Additional plots to make
    
  maphist.clear();
  AnalyzerCore::MakeHistograms();
  Message("Made histograms", INFO);
  /**
   *  Remove//Overide this ISR_genreco_muons2016Core::MakeHistograms() to make new hists for your analysis
   **/

  MakeNtp("pdfweight","w0:w1:w2:w3:w4:w5:w6:w7:w8:w9:w10:w11:w12:w13:w14:w15:w16:w17:w18:w19:w20:w21:w22:w23:w24:w25:w26:w27:w28:w29:w30:w31:w32:w33:w34:w35:w36:w37:w38:w39:w40:w41:w42:w43:w44:w45:w46:w47:w48:w49:w50:w51:w52:w53:w54:w55:w56:w57:w58:w59:w60:w61:w62:w63:w64:w65:w66:w67:w68:w69:w70:w71:w72:w73:w74:w75:w76:w77:w78:w79:w80:w81:w82:w83:w84:w85:w86:w87:w88:w89:w90:w91:w92:w93:w94:w95:w96:w97:w98:w99");  

  MakeNtp("pdfweight2","w100:w101:w102:w103:w104:w105:w106:w107:w108:w109:w110:w111:w112:w113:w114:w115:w116:w117:w118:w119:w120:w121:w122:w123:w124:w125:w126:w127:w128:w129:w130:w131:w132:w133:w134:w135:w136:w137:w138:w139:w140:w141:w142:w143:w144:w145:w146:w147:w148:w149:w150:w151:w152:w153:w154:w155:w156:w157:w158:w159:w160:w161:w162:w163:w164:w165:w166:w167:w168:w169:w170:w171:w172:w173:w174:w175:w176:w177:w178:w179:w180:w181:w182:w183:w184:w185:w186:w187:w188:w189:w190:w191:w192:w193:w194:w195:w196:w197:w198:w199");

  MakeNtp("pdfsclweight","w0:w1:w2:w3:w4:w5:w6:w7:w8:w9");

  //  MakeNtp("pdsclfweight2","w100:w101:w102:w103:w104:w105:w106:w107:w108:w109:w110:w111:w112:w113:w114:w115:w116:w117:w118:w119:w120:w121:w122:w123:w124:w125:w126:w127:w128:w129:w130:w131:w132:w133:w134:w135:w136:w137:w138:w139:w140:w141:w142:w143:w144:w145:w146:w147:w148:w149:w150:w151:w152:w153:w154:w155:w156:w157:w158:w159:w160:w161:w162:w163:w164:w165:w166:w167:w168:w169:w170:w171:w172:w173:w174:w175:w176:w177:w178:w179:w180:w181:w182:w183:w184:w185:w186:w187:w188:w189:w190:w191:w192:w193:w194:w195:w196:w197:w198:w199");

  //  MakeNtp("corpriptstat","p0:p1:p2:p3:p4:p5:p6:p7:p8:p9:p10:p11:p12:p13:p14:p15:p16:p17:p18:p19:p20:p21:p22:p23:p24:p25:p26:p27:p28:p29:p30:p31:p32:p33:p34:p35:p36:p37:p38:p39:p40:p41:p42:p43:p44:p45:p46:p47:p48:p49:p50:p51:p52:p53:p54:p55:p56:p57:p58:p59:p60:p61:p62:p63:p64:p65:p66:p67:p68:p69:p70:p71:p72:p73:p74:p75:p76:p77:p78:p79:p80:p81:p82:p83:p84:p85:p86:p87:p88:p89:p90:p91:p92:p93:p94:p95:p96:p97:p98:p99");
  //MakeNtp("corsecptstat","p0:p1:p2:p3:p4:p5:p6:p7:p8:p9:p10:p11:p12:p13:p14:p15:p16:p17:p18:p19:p20:p21:p22:p23:p24:p25:p26:p27:p28:p29:p30:p31:p32:p33:p34:p35:p36:p37:p38:p39:p40:p41:p42:p43:p44:p45:p46:p47:p48:p49:p50:p51:p52:p53:p54:p55:p56:p57:p58:p59:p60:p61:p62:p63:p64:p65:p66:p67:p68:p69:p70:p71:p72:p73:p74:p75:p76:p77:p78:p79:p80:p81:p82:p83:p84:p85:p86:p87:p88:p89:p90:p91:p92:p93:p94:p95:p96:p97:p98:p99");

  // MakeNtp("corpriptzpt","p0");
  // MakeNtp("corsecptzpt","p0");

  //  MakeNtp("corpriptpmw","p0:p1:p2:p3:p4");
  //MakeNtp("corsecptpmw","p0:p1:p2:p3:p4");

  //  MakeNtp("corpriptfmw","p0:p1:p2:p3:p4");
  // MakeNtp("corsecptfmw","p0:p1:p2:p3:p4");



  MakeNtp("prilep", "pt:eta:phi:ee:charge:tau:trigmatch:trigmatch2:ptnocor:etanocor:phinocor:eenocor:chargenocor:ntrkl:pt_up:pt_down");
  MakeNtp("seclep", "pt:eta:phi:ee:charge:tau:trigmatch:trigmatch2:ptnocor:etanocor:phinocor:eenocor:chargenocor:ntrkl:pt_up:pt_down");
  //  MakeNtp("jets", "ljetpt:jetptsum:jethtsum");
  //$%^//                                                                                                                                                     
  MakeNtp("weights", "weight:MCweight:idsf:pu:triggersf:ps:isosf:idsf_up:idsf_down:isosf_up:isosf_down:pu_up:pu_down:pu69:pu69_up:pu69_down:triggersf_up:triggersf_down");
  MakeNtp("othervs", "njet:met_norc:nvtx:met_muen_up:met_muen_down:met_elen_up:met_elen_down:met_jeten_up:met_jeten_down:met_jetres_up:met_jetres_down:MET:runnum:metx:mety:x1:x2:Q:pdferrorsize:pdfsclerrorsize:metx_norc:mety_norc");

}


void ISR_genreco_muons2016::ClearOutputVectors() throw(LQError) {

  // This function is called before every execute event (NO need to call this yourself.
  
  // Add any new output vector you create to this list. 
  // if you do not the vector will keep keep getting larger when it is filled in ExecuteEvents and will use excessive amoun of memory
  //
  // Reset all variables declared in Declare Variable
  //
  out_muons.clear();
  out_electrons.clear();
}



