#include "Riostream.h"
#include "TGraph.h"
#include <vector>


void EEValidation(){

  gROOT->LoadMacro("tdrstyle.C");
  
  setTDRStyle();
  gROOT->LoadMacro("CMS_lumi.C");


  vector <int> masses;
  masses.push_back(50);
  masses.push_back(100);
  masses.push_back(200);
  masses.push_back(500);
  masses.push_back(1100);


  vector <TString> smasses;
  smasses.push_back("50");
  smasses.push_back("100");
  smasses.push_back("200");
  smasses.push_back("500");
  smasses.push_back("1100");

  vector<TString> channel;
  channel.push_back("EmEm");
  channel.push_back("EpEp");

  vector<TString> cutnames;
  cutnames.push_back("SIGNALVALIDATION_EE_PRESEL");


  for(unsigned int ic= 0 ; ic < channel.size(); ++ic){
    
    for(unsigned int i = 0 ; i < masses.size(); ++i){
      
      TString im = smasses.at(i);
      
      if (channel[ic] == "EmEm" && im == "500") continue;
      if (channel[ic] == "EmEm" && im == "1100") continue;
	  
      TFile * file1 = new TFile(("/data2/CAT_SKTreeOutput/JobOutPut/jalmond/LQanalyzer//data/output/CAT/HNDiElectron/periodBtoH/HNDiElectron_SKHN"+channel[ic]+"_"+im+"_cat_v8-0-4.root").Data());
      
      TFile * file2 = new TFile(("/data2/CAT_SKTreeOutput/JobOutPut/jalmond/LQanalyzer//data/output/CAT/HNDiElectron/periodBtoH/HNDiElectron_SKHNMoriondLL"+channel[ic]+"_"+im+"_cat_v8-0-4.root").Data());
      
      TString hist = ("SIGNALVALIDATION_EE_PRESEL/h_Nelectrons_SIGNALVALIDATION_EE_PRESEL");
      TString canvasname = channel[ic]+im+histnames[h] + "_"+cutnames[c];
      
	  TH1*  h_private = (TH1F*)file1->Get(hist);
	  TH1*  h_moriond = (TH1F*)file2->Get(hist);

	  cout << hist << endl;
	  int W = 800;
	  int H = 600;
	  TCanvas* c1 = new TCanvas((canvasname).Data(),(canvasname).Data(),10,10,W,H);

	  h_private->Scale(1./h_private->Integral());
	  h_moriond->Scale(1./h_moriond->Integral());
	  h_private->SetLineColor(kRed);
	  h_moriond->SetLineColor(kBlue);
	  
	  h_private->Draw("hist");
	  h_moriond->Draw("histsame");
	  
	  CMS_lumi( c1, 4, 11 );
	  
	  c1->Update();
	  c1->RedrawAxis();
	  
	  c1->SaveAs((canvasname+"test.pdf").Data());
	}
      }
    }
  }
}

