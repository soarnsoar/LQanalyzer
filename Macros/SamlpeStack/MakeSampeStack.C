#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TKey.h"
#include <iostream>
#include <fstream>
#include <TStyle.h>
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include <sstream>      // std::stringstream


//#include "Macro.h"
void setTDRStyle();
TH1D* MakeHist(TString sample, TString an, TString catv, TString cut, TString hist);


void SampeStack(){
 
  setTDRStyle();
  
  vector<TString> samples;
  samples.push_back("SKHNEmEm_100_cat");
  samples.push_back("SKHNEmEm_100_cat");

  vector<TString> vcat;
  vcat.push_back("v8-0-7");
  vcat.push_back("v8-0-6");
  
  vector<Color_t >  cols;
  cols.push_back(kRed-2);
  cols.push_back(kBlue-2);
  
  TString anclass="HNDiElectron";
  TString cut="All";
  
  TString hist="h_llmass";
  
  TCanvas* c1 = new TCanvas("TL", "TL", 800, 600);
  TLegend *legend = new TLegend(.65, 0.5, .9, 0.7);
  legend->SetFillColor(10);
  legend->SetBorderSize(0);
  legend->SetTextSize(0.03);
  
  TString sampletag="";
  for(int i=0; i < samples.size(); i++){
    sampletag+=samples[i]+"_";
    //TH1D* h = MakeHist(samples[i],anclass,vcat[i],cut,hist);

    TString datapath="/data2/CAT_SKTreeOutput/JobOutPut/jalmond/LQanalyzer/data/output/CAT/"+anclass+"/periodBtoH/"+anclass+"_"+samples[i]+"_"+vcat[i]+".root";
    TFile * fdata  = new TFile(datapath);
    TH1D* h = (TH1D*)(fdata->Get((cut+"/"+hist+"_"+cut).Data()))->Clone(anclass+"_"+samples[i]+"_"+vcat[i]+cut);
    
    if(i==1) h->Scale(1.3753);
    h->Rebin(10.);
    cout << h << endl;
    if(!h) exit;
    cout << cols[i] << endl;
    h->SetLineColor(cols[i]);
    //h->Draw("hist");
    h->SetLineWidth(3.);
    if(i==0)h->Draw("hist");
    else h->Draw("histsame");
    
    legend->AddEntry(h, vcat[i]+samples[i],"l");
  }
  
  legend->Draw();
  
  c1->SaveAs("MCStact_"+hist+"_"+sampletag+".pdf");
}

TH1D* MakeHist(TString sample, TString an, TString catv, TString cut, TString hist)
{
  TH1::SetDefaultSumw2(); 
  TString datapath="/data2/CAT_SKTreeOutput/JobOutPut/jalmond/LQanalyzer/data/output/CAT/"+an+"/periodBtoH/"+an+"_"+sample+"_"+catv+".root";
  TFile * fdata  = new TFile(datapath);
  cout << fdata << " " << datapath << endl;
  cout << cut+"/"+hist+"_"+cut << endl; 
  TH1D* hloose = (TH1D*)(fdata->Get((cut+"/"+hist+"_"+cut).Data()))->Clone(an+"_"+sample+"_"+catv+cut);
  cout << hloose << endl;
  if(!hloose) exit(1);

  fdata->Close();
  delete fdata;

  return hloose;
}




void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);


  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);


  // For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);
  tdrStyle->SetEndErrorSize(2);
  //  tdrStyle->SetErrorMarker(20);
  //  tdrStyle->SetErrorX(0.);

  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);

  // tdrStyle->SetDateY(Float_t y = 0.01);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

  // Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.16);
  tdrStyle->SetPadRightMargin(0.02);

  // For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);

  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

  // For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.4);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset



  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.4);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();

}
