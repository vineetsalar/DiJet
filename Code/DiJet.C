#include "DiJet.h"

// Function to calculate Asymmetry as a function of Centrality
Double_t calDelta(Double_t pT, Double_t alpha, Double_t MM) ;
TH1D *XJ_GammaJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin, Int_t isPP);
TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin);
TH1D *Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, Int_t PtBin);


void DiJet()
{


  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetStatColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameLineColor(kBlack);
  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(0);
  gStyle->SetPadColor(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadBorderSize(0);
  gStyle->SetTextSize(0.04);
  gStyle->SetTextFont(42);
  gStyle->SetLabelFont(42,"xyz");
  gStyle->SetTitleFont(42,"xyz");
  gStyle->SetTitleSize(0.048,"xyz");
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.2);
  gStyle->SetPadRightMargin(0.065);
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetTitleXOffset(1.15);
  gStyle->SetTitleYOffset(1.2);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  gStyle->SetHistMinimumZero(kTRUE);
  gStyle->SetErrorX(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.3);
  gROOT->ForceStyle();

  cout<< " Npart for centrality  0 - 10 % "<<NPartFunc(0,10) <<endl;

  TFile *OutFile = new TFile("OutDiJet.root","RECREATE");
  
  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.04);

  // CMS Data Graphs XJ (Jet +Z0)


  TGraphAsymmErrors *grf_Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV = Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV = Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV();
  
  TGraphAsymmErrors *grf_Data_CMS_XJ_Z0Jet_PP_502TeV = Data_CMS_XJ_Z0Jet_PP_502TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Z0Jet_PP_502TeV = Data_Syst_CMS_XJ_Z0Jet_PP_502TeV();
  
  TGraphAsymmErrors *grf_Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV = Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV = Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV();
  
  TCanvas *Canv_Data_CMS_XJ_Z0Jet_502TeV = new TCanvas("Canv_Data_CMS_XJ_Z0Jet_502TeV","Canv_Data_CMS_XJ_Z0Jet_502TeV",1200,400);//coulamXRows
  Canv_Data_CMS_XJ_Z0Jet_502TeV->Divide(3,1);
  Canv_Data_CMS_XJ_Z0Jet_502TeV->cd(1);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "0-30%") ;

  
  Canv_Data_CMS_XJ_Z0Jet_502TeV->cd(2);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_Z0Jet_PP_502TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_Z0Jet_PP_502TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "pp") ;

  Canv_Data_CMS_XJ_Z0Jet_502TeV->cd(3);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "pp (uns.)") ;
  return;


  
  
  // CMS Data Graphs XJ (Jet+Gamma)
  TGraphAsymmErrors *grf_Data_CMS_XJ_GammaJet_Cent_00_10_276TeV = Data_CMS_XJ_GammaJet_Cent_00_10_276TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_GammaJet_Cent_00_10_276TeV = Data_Syst_CMS_XJ_GammaJet_Cent_00_10_276TeV();
  TGraphAsymmErrors *grf_Data_CMS_XJ_GammaJet_Cent_10_30_276TeV = Data_CMS_XJ_GammaJet_Cent_10_30_276TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_GammaJet_Cent_10_30_276TeV = Data_Syst_CMS_XJ_GammaJet_Cent_10_30_276TeV();
  TGraphAsymmErrors *grf_Data_CMS_XJ_GammaJet_Cent_30_50_276TeV = Data_CMS_XJ_GammaJet_Cent_30_50_276TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_GammaJet_Cent_30_50_276TeV = Data_Syst_CMS_XJ_GammaJet_Cent_30_50_276TeV();
  TGraphAsymmErrors *grf_Data_CMS_XJ_GammaJet_Cent_50_100_276TeV = Data_CMS_XJ_GammaJet_Cent_50_100_276TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_GammaJet_Cent_50_100_276TeV = Data_Syst_CMS_XJ_GammaJet_Cent_50_100_276TeV();
  TGraphAsymmErrors *grf_Data_CMS_XJ_GammaJet_PP_276TeV = Data_CMS_XJ_GammaJet_PP_276TeV();
  
  TCanvas *Canv_Data_CMS_XJ_GammaJet_Cent_276TeV = new TCanvas("Canv_Data_CMS_XJ_GammaJet_Cent_276TeV","Canv_Data_CMS_XJ_GammaJet_Cent_276TeV",1200,800);//coulamXRows
  Canv_Data_CMS_XJ_GammaJet_Cent_276TeV->Divide(3,2);

  Canv_Data_CMS_XJ_GammaJet_Cent_276TeV->cd(1);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_GammaJet_Cent_00_10_276TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_GammaJet_Cent_00_10_276TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "0-10%") ;

  Canv_Data_CMS_XJ_GammaJet_Cent_276TeV->cd(2);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_GammaJet_Cent_10_30_276TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_GammaJet_Cent_10_30_276TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "10-30%") ;

  
  Canv_Data_CMS_XJ_GammaJet_Cent_276TeV->cd(3);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_GammaJet_Cent_30_50_276TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_GammaJet_Cent_30_50_276TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "30-50%") ;

  Canv_Data_CMS_XJ_GammaJet_Cent_276TeV->cd(4);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_GammaJet_Cent_50_100_276TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_GammaJet_Cent_50_100_276TeV->Draw("2");
  tb->DrawLatex(0.75, 0.70, "50-100%") ;

  Canv_Data_CMS_XJ_GammaJet_Cent_276TeV->cd(5);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_GammaJet_PP_276TeV->Draw("AP");
  tb->DrawLatex(0.75, 0.70, "pp") ;
  

  // CMS Data Graphs AJ
  TGraphErrors *grf_Data_CMS_Aj_Cent_00_10_276TeV = Data_CMS_Aj_Cent_00_10_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Cent_10_20_276TeV = Data_CMS_Aj_Cent_10_20_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Cent_20_30_276TeV = Data_CMS_Aj_Cent_20_30_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Cent_30_50_276TeV = Data_CMS_Aj_Cent_30_50_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Cent_50_70_276TeV = Data_CMS_Aj_Cent_50_70_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Cent_70_100_276TeV = Data_CMS_Aj_Cent_70_100_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_pp_276TeV = Data_CMS_Aj_pp_276TeV();   

   
  TCanvas *Canv_Data_CMS_Aj_Cent_276TeV = new TCanvas("Canv_Data_CMS_Aj_Cent_276TeV","Canv_Data_CMS_Aj_Cent_276TeV",1600,800);//coulamXRows
  Canv_Data_CMS_Aj_Cent_276TeV->Divide(4,2);

  Canv_Data_CMS_Aj_Cent_276TeV->cd(1);
  grf_Data_CMS_Aj_Cent_00_10_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "0-10%") ;
  Canv_Data_CMS_Aj_Cent_276TeV->cd(2);
  grf_Data_CMS_Aj_Cent_10_20_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "10-20%") ;
  Canv_Data_CMS_Aj_Cent_276TeV->cd(3);
  grf_Data_CMS_Aj_Cent_20_30_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "20-30%") ;
  Canv_Data_CMS_Aj_Cent_276TeV->cd(4);
  grf_Data_CMS_Aj_Cent_30_50_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "30-50%") ;
  Canv_Data_CMS_Aj_Cent_276TeV->cd(5);
  grf_Data_CMS_Aj_Cent_50_70_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "50-70%") ;
  Canv_Data_CMS_Aj_Cent_276TeV->cd(6);
  grf_Data_CMS_Aj_Cent_70_100_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "70-100%") ;
  Canv_Data_CMS_Aj_Cent_276TeV->cd(7);
  grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "pp") ;

  
  TGraphErrors *grf_Data_CMS_Aj_Pt_120_150_276TeV = Data_CMS_Aj_Pt_120_150_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_150_180_276TeV = Data_CMS_Aj_Pt_150_180_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_180_220_276TeV = Data_CMS_Aj_Pt_180_220_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_220_260_276TeV = Data_CMS_Aj_Pt_220_260_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_260_300_276TeV = Data_CMS_Aj_Pt_260_300_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_300_500_276TeV = Data_CMS_Aj_Pt_300_500_276TeV();


  TCanvas *Canv_Data_CMS_Aj_Pt_276TeV = new TCanvas("Canv_Data_CMS_Aj_Pt_276TeV","Canv_Data_CMS_Aj_Pt_276TeV",1200,800);//coulamXRows
  Canv_Data_CMS_Aj_Pt_276TeV->Divide(3,2);
  
  Canv_Data_CMS_Aj_Pt_276TeV->cd(1);
  grf_Data_CMS_Aj_Pt_120_150_276TeV->Draw("AP");
  tb->DrawLatex(0.55, 0.70, "120 < p_{T,1} < 150 GeV/c") ;

  Canv_Data_CMS_Aj_Pt_276TeV->cd(2);
  grf_Data_CMS_Aj_Pt_150_180_276TeV->Draw("AP");
  tb->DrawLatex(0.55, 0.70, "150 < p_{T,1} < 180 GeV/c") ;

  Canv_Data_CMS_Aj_Pt_276TeV->cd(3);
  grf_Data_CMS_Aj_Pt_180_220_276TeV->Draw("AP");
  tb->DrawLatex(0.55, 0.70, "180 < p_{T,1} < 220 GeV/c") ;

  Canv_Data_CMS_Aj_Pt_276TeV->cd(4);
  grf_Data_CMS_Aj_Pt_220_260_276TeV->Draw("AP");
  tb->DrawLatex(0.55, 0.70, "220 < p_{T,1} < 260 GeV/c") ;

  Canv_Data_CMS_Aj_Pt_276TeV->cd(5);
  grf_Data_CMS_Aj_Pt_260_300_276TeV->Draw("AP");
  tb->DrawLatex(0.55, 0.70, "260 < p_{T,1} < 300 GeV/c") ;

  Canv_Data_CMS_Aj_Pt_276TeV->cd(6);
  grf_Data_CMS_Aj_Pt_300_500_276TeV->Draw("AP");
  tb->DrawLatex(0.55, 0.70, "300 < p_{T,1} < 500 GeV/c") ;

    
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_00_10_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_zero_ten();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_10_20_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_ten_twenty();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_20_30_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_twenty_thirty();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_30_40_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_thirty_forty();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_40_50_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_forty_fifty();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_50_60_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_fifty_sixty();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_60_70_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_sixty_seventy();
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_70_80_276TeV = jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_seventy_eighty();




  //coulamXRows
  TCanvas *Canv_Data_ATLAS_RAA_Cent_276TeV = new TCanvas("Canv_Data_ATLAS_RAA_Cent_276TeV","Canv_Data_ATLAS_RAA_Cent_276TeV",1200,1200);
  Canv_Data_ATLAS_RAA_Cent_276TeV->Divide(3,3);
  
  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(1);
  grf_Data_ATLAS_RAA_Cent_00_10_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "0-10%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(2);
  grf_Data_ATLAS_RAA_Cent_10_20_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "10-20%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(3);
  grf_Data_ATLAS_RAA_Cent_20_30_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "20-30%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(4);
  grf_Data_ATLAS_RAA_Cent_30_40_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "30-40%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(5);
  grf_Data_ATLAS_RAA_Cent_40_50_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "40-50%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(6);
  grf_Data_ATLAS_RAA_Cent_50_60_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "50-60%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(7);
  grf_Data_ATLAS_RAA_Cent_60_70_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "60-70%") ;

  Canv_Data_ATLAS_RAA_Cent_276TeV->cd(8);
  grf_Data_ATLAS_RAA_Cent_70_80_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "70-80%") ;




  TGraphErrors *grf_Data_ATLAS_RAA_Cent_00_10_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_zero0_ten10()        ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_10_20_502TeV =jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_ten10_twenty20()     ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_20_30_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_twenty20_thirty30()  ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_30_40_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_thirty30_forty40()   ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_40_50_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_forty40_fifty50()    ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_50_60_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_fifty50_sixty60()    ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_60_70_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_sixty60_seventy70()  ;
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_70_80_502TeV = jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_seventy70_eighty80() ;

  
  //coulamXRows
  TCanvas *Canv_Data_ATLAS_RAA_Cent_502TeV = new TCanvas("Canv_Data_ATLAS_RAA_Cent_502TeV","Canv_Data_ATLAS_RAA_Cent_502TeV",1200,1200);
  Canv_Data_ATLAS_RAA_Cent_502TeV->Divide(3,3);
  
  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(1);
  grf_Data_ATLAS_RAA_Cent_00_10_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "0-10%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(2);
  grf_Data_ATLAS_RAA_Cent_10_20_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "10-20%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(3);
  grf_Data_ATLAS_RAA_Cent_20_30_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "20-30%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(4);
  grf_Data_ATLAS_RAA_Cent_30_40_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "30-40%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(5);
  grf_Data_ATLAS_RAA_Cent_40_50_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "40-50%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(6);
  grf_Data_ATLAS_RAA_Cent_50_60_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "50-60%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(7);
  grf_Data_ATLAS_RAA_Cent_60_70_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "60-70%") ;

  Canv_Data_ATLAS_RAA_Cent_502TeV->cd(8);
  grf_Data_ATLAS_RAA_Cent_70_80_502TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "70-80%") ;


  // return;

  
  // Histograms
  TH1D *hAsymmetryDiff = new TH1D("hAsymmetryDiff", "hAsymmetryDiff", 17, 0.0, 1.0);
  hAsymmetryDiff->Sumw2();
  hAsymmetryDiff->SetLineWidth(2);

  TH1D *hist_Pt_Initial = new TH1D("hist_Pt_Initial", "hist_Pt_Initial", 25, 0.0, 500.0);
  hist_Pt_Initial->Sumw2();
  hist_Pt_Initial->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hist_Pt_Initial->GetYaxis()->SetTitle("Events");
  
  TH1D *hist_Pt_Final = new TH1D("hist_Pt_Final", "hist_Pt_Final", 25, 0.0, 500.0);
  hist_Pt_Final->Sumw2();
  hist_Pt_Final->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hist_Pt_Final->GetYaxis()->SetTitle("Events");
 
  TH1D *hist_Pt_Ratio = new TH1D("hist_Pt_Ratio", "hist_Pt_Ratio", 25, 0.0, 500.0);


 
  // pp distribution fit 
  //FitParaTsallisPP276TeV();
  //cout<<" Fitting parameters for Tsallis function dN/dy "<<jet_00_rapidity_21_pp_276tev_dNdy<<" nn "<< jet_00_rapidity_21_pp_276tev_nn<<
  //" p0 "<< jet_00_rapidity_21_pp_276tev_pzero <<endl;

  Double_t lc_jet_00_rapidity_21_pp_276tev_dNdy = 0.000690482;
  Double_t lc_jet_00_rapidity_21_pp_276tev_nn = 8.30672;
  Double_t lc_jet_00_rapidity_21_pp_276tev_pzero = 36.6118;
  
  //function for pp Jet pT distribution  
  TF1 *fJetpp276tev = new TF1("fJetpp276tev", tsallis_fitting_function, 30.0, 500.0, 3);
  fJetpp276tev->SetParNames("dN/dy", "nn", "pzero");
  //fJetpp276tev->SetParameters(jet_00_rapidity_21_pp_276tev_dNdy, jet_00_rapidity_21_pp_276tev_nn, jet_00_rapidity_21_pp_276tev_pzero);
  fJetpp276tev->FixParameter(0, lc_jet_00_rapidity_21_pp_276tev_dNdy);
  fJetpp276tev->FixParameter(1, lc_jet_00_rapidity_21_pp_276tev_nn);
  fJetpp276tev->FixParameter(2, lc_jet_00_rapidity_21_pp_276tev_pzero);
			     


  new TCanvas ;
  gPad->SetTicks(1);
  gPad->SetLogy(1);
  
  TGraphErrors *gr_atlas_jet_yield_00_rapidity_21 = jet_atlas_yield_00_rapidity_21_pp_276tev() ;
  gr_atlas_jet_yield_00_rapidity_21->GetXaxis()->SetTitleSize(0.05)             ;
  gr_atlas_jet_yield_00_rapidity_21->GetXaxis()->SetTitleOffset(1.10)           ;
  gr_atlas_jet_yield_00_rapidity_21->GetXaxis()->SetLabelSize(0.03)             ;
  gr_atlas_jet_yield_00_rapidity_21->GetXaxis()->SetTitle("p_{T} (GeV/c)")      ; 
  gr_atlas_jet_yield_00_rapidity_21->GetXaxis()->CenterTitle()                  ;
  gr_atlas_jet_yield_00_rapidity_21->GetYaxis()->SetTitleSize(0.05)             ;
  gr_atlas_jet_yield_00_rapidity_21->GetYaxis()->SetTitleOffset(1.10)           ;
  gr_atlas_jet_yield_00_rapidity_21->GetYaxis()->SetLabelSize(0.03)             ;
  gr_atlas_jet_yield_00_rapidity_21->GetYaxis()->SetTitle("1/(2#pi p_{T}) d^{2}N/dp_{T}dy (GeV/c)^{-2}"); 
  gr_atlas_jet_yield_00_rapidity_21->GetYaxis()->CenterTitle()                  ;
  gr_atlas_jet_yield_00_rapidity_21->GetXaxis()->SetLimits(0.0, 500.0)          ;
  gr_atlas_jet_yield_00_rapidity_21->GetYaxis()->SetRangeUser(1.0e-14, 1.0e+01) ;
  gr_atlas_jet_yield_00_rapidity_21->Draw("AP")                                 ;
  fJetpp276tev->SetLineColor(4);
  fJetpp276tev->Draw("same");
  
  
  // Random distribution;
  TRandom3 rand(0); 
  
  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative
  //Double_t RespT = 0.0;  // Relative
  
  //for Energy Loss
  //Double_t alpha = 0.5;
  //Double_t MM = 0.55;

  //Double_t alpha = 0.0;
  //Double_t MM = 6.0;


  //Double_t alpha = 0.5;
  //Double_t MM = 0.2;

  //On 19.May.2020
  //Double_t alpha = 0.55;
  //Double_t MM = 0.4;


  Double_t alpha = 0.4;
  Double_t MM = 0.50;


  
  // Size of the system
  Double_t Npart = NPartFunc(0,10);
  Double_t RR = RA*sqrt(Npart/(2*Am));

  int nn = 5000000;
  
  for(int i=0; i< nn; i++) {

    
    // Generate pT 
    Double_t pT = fJetpp276tev->GetRandom();


    if(pT<30.0) continue;
    
    // Generate position 
    Double_t rr = rand.Uniform(0.0,1.0)*RR;
    Double_t Phi = rand.Uniform(0.0,1.0)*2.0*pi;

    
    Double_t Phi1 = rand.Gaus(Phi, Phi*ResPhi);
    Double_t Phi2 = rand.Gaus(Phi+pi, (Phi+pi)*ResPhi);

    Double_t DeltaPhi = Phi2 - Phi1; 
    
    // Calculate pathlength
    Double_t d1 = sqrt(RR*RR - rr*rr*sin(Phi1)) - rr*cos(Phi1);
    Double_t d2 = sqrt(RR*RR - rr*rr*sin(Phi2)) - rr*cos(Phi2); 

    Double_t pTppMeas = rand.Gaus(pT, pT*RespT);
    //Double_t pTppMeas = pT;

    if(pTppMeas>50.0) hist_Pt_Initial->Fill(pTppMeas);
    
    // Calculate DeltapT
    Double_t dEdx = calDelta(pT, alpha, MM);

    Double_t E1 = pT-dEdx*d1;
    Double_t E2 = pT-dEdx*d2;

    //for pp no energy loss
    //E1 = pT;
    //E2 = pT;

    
    // Smear pT
    Double_t pT1 = rand.Gaus(E1, E1*RespT);
    Double_t pT2 = rand.Gaus(E2, E2*RespT);

    if(pT1 > 50.0) hist_Pt_Final->Fill(pT1);
    

    
    //Exp cut on pT
    Double_t L_Pt = TMath::Max(pT1,pT2);
    Double_t SubL_Pt = TMath::Min(pT1,pT2);;

        
    if(L_Pt< 120.0 || SubL_Pt < 30.0 || DeltaPhi < (2.0*pi)/3.0) continue; 



    
    //Double_t pTDiff = abs((pT1-pT2)/(pT1+pT2));

    Double_t pTDiff = (L_Pt-SubL_Pt)/(L_Pt+SubL_Pt); 

    //cout << pT << "  " << pTDiff << endl;

    //cout << pT1 << "  " << pT2<<"   "<<pTDiff << endl;
    
    hAsymmetryDiff->Fill(pTDiff);
  } 




  hAsymmetryDiff->Scale(1.0/ hAsymmetryDiff->Integral());

  new TCanvas;
  hAsymmetryDiff->SetLineColor(1);
  hAsymmetryDiff->GetXaxis()->SetTitle("Asymmetry");
  hAsymmetryDiff->GetXaxis()->CenterTitle();
  hAsymmetryDiff->GetYaxis()->SetTitle("No. of Events");
  hAsymmetryDiff->GetYaxis()->CenterTitle();
  hAsymmetryDiff->GetYaxis()->SetRangeUser(0,0.32);
  hAsymmetryDiff->SetLineColor(2);
  hAsymmetryDiff->SetMarkerColor(2);
  
  
  grf_Data_CMS_Aj_Cent_00_10_276TeV->Draw("AP");
  tb->DrawLatex(0.60, 0.70, "0-10%") ;
  
  //grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  //tb->DrawLatex(0.60, 0.70, "pp") ;

  hAsymmetryDiff->Draw("Psame");
  
  TLegend* leg= new TLegend(0.58,0.74,0.88,0.84);
  leg->SetBorderSize(0);
  leg->SetFillStyle(1001);
  leg->SetFillColor(10);
  leg->SetTextSize(0.035);
  leg->AddEntry(grf_Data_CMS_Aj_Cent_00_10_276TeV,"CMS Data","P");
  leg->AddEntry(hAsymmetryDiff,"Calculated","P");

  leg->Draw();

  gPad->SaveAs("Figure/OutFigures/Aj.png");
  gPad->SaveAs("Figure/OutFigures/Aj.pdf");

  TLine *line1 = new TLine(0,1,500,1);
  line1->SetLineColor(2);
 
  new TCanvas;
  gPad->SetLogy(1);
  hist_Pt_Final->SetMarkerColor(2);
  hist_Pt_Initial->Draw("P");
  TH1D *temp_hist = (TH1D*)hist_Pt_Final->Clone("temp_hist");
  temp_hist->SetMarkerColor(2);
  temp_hist->Draw("Psame");
    
  hist_Pt_Final->Divide(hist_Pt_Final,hist_Pt_Initial,1.0,1.0,"B");

  new TCanvas;
  hist_Pt_Final->Draw("P");
  line1->Draw("same");
 
  new TCanvas;
  grf_Data_ATLAS_RAA_Cent_00_10_276TeV->Draw("AP");
  hist_Pt_Final->Draw("Psame");
  line1->Draw("same");

  //return;

  // XJ Calculations as a function of Centrality
 //CentBins (0,10,30,50,100)
  const Int_t NCentBins_XJ = 4;
  const Int_t CentBins_XJ[NCentBins_XJ+1]={0,10,30,50,100};
  Double_t ANPartCent_XJ[NCentBins_XJ]={NPartFunc(0,10),NPartFunc(10,30),NPartFunc(30,50),NPartFunc(50,100)};
  TH1D *HistOutJetGamma_XJ[NCentBins_XJ];

  TGraphAsymmErrors *grf_Data_CMS_XJ_Cent_276TeV[NCentBins_XJ]={grf_Data_CMS_XJ_GammaJet_Cent_00_10_276TeV,grf_Data_CMS_XJ_GammaJet_Cent_10_30_276TeV,
								grf_Data_CMS_XJ_GammaJet_Cent_30_50_276TeV,grf_Data_CMS_XJ_GammaJet_Cent_50_100_276TeV};

  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Cent_276TeV[NCentBins_XJ]={grf_Data_Syst_CMS_XJ_GammaJet_Cent_00_10_276TeV,grf_Data_Syst_CMS_XJ_GammaJet_Cent_10_30_276TeV,
								grf_Data_Syst_CMS_XJ_GammaJet_Cent_30_50_276TeV,grf_Data_Syst_CMS_XJ_GammaJet_Cent_50_100_276TeV};
  // Canvas defined outside the centrality loop
  
  TCanvas *Canv_CMS_XJ_Cent_276TeV = new TCanvas("Canv_CMS_XJ_Cent_276TeV","Canv_CMS_XJ_Cent_276TeV",1200,800);//coulamXRows
  Canv_CMS_XJ_Cent_276TeV->Divide(3,2);
  char LatexChar_XJ[400];

  for(int i=0; i< NCentBins_XJ; i++) {
    cout<<" XJ calculation for centrality "<<CentBins_XJ[i]<<"  "<<CentBins_XJ[i+1]<<"% "<<endl;
    HistOutJetGamma_XJ[i] = XJ_GammaJet_Centrality(fJetpp276tev,  RespT, ResPhi, alpha, MM, ANPartCent_XJ[i], i,0);

    Canv_CMS_XJ_Cent_276TeV->cd(i+1);
    
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    gPad->SetLeftMargin(0.2);
    
    grf_Data_CMS_XJ_Cent_276TeV[i]->Draw("AP");
    grf_Data_Syst_CMS_XJ_Cent_276TeV[i]->Draw("2");
    HistOutJetGamma_XJ[i]->GetYaxis()->SetRangeUser(0.0,3.0);
    HistOutJetGamma_XJ[i]->Draw("Psame");
    leg->Draw("same");
    tb->DrawLatex(0.60,0.70,Form("Cent. %0d - %0d %%",CentBins_XJ[i],CentBins_XJ[i+1]));

  }

  Canv_CMS_XJ_Cent_276TeV->cd(5);
  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  gPad->SetLeftMargin(0.2);
  //This need to be coded better
  TH1D *HistOutJetGamma_XJ_PP = XJ_GammaJet_Centrality(fJetpp276tev,  RespT, ResPhi, alpha, MM, ANPartCent_XJ[3], 4,1);
  grf_Data_CMS_XJ_GammaJet_PP_276TeV->Draw("AP");
  HistOutJetGamma_XJ_PP->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.6, 0.7, "pp") ;


  Canv_CMS_XJ_Cent_276TeV->SaveAs("Figure/OutFigures/Fig_XJ_GammaJet_Centrality.pdf");
  Canv_CMS_XJ_Cent_276TeV->SaveAs("Figure/OutFigures/Fig_XJ_GammaJet_Centrality.png");

  // return;

  // make here pt functions

  //PtBins (120,150,180,220,260,300,500)
  const Int_t NPtBins = 6;
  const Int_t APtBins[NPtBins+1]={120,150,180,220,260,300,500};
  
  TH1D *HistOutJetAsymPt[NPtBins];

  TGraphErrors *grf_Data_CMS_Aj_Pt_276TeV[NPtBins]={grf_Data_CMS_Aj_Pt_120_150_276TeV,grf_Data_CMS_Aj_Pt_150_180_276TeV,
						    grf_Data_CMS_Aj_Pt_180_220_276TeV, grf_Data_CMS_Aj_Pt_220_260_276TeV,
						    grf_Data_CMS_Aj_Pt_260_300_276TeV, grf_Data_CMS_Aj_Pt_300_500_276TeV};


  TCanvas *Canv_Asym_DiJet_Pt = new TCanvas("Canv_Asym_DiJet_Pt","Canv_Asym_DiJet_Pt",1200,800);//coulamXRows
  Canv_Asym_DiJet_Pt->Divide(3,2);
  
  for(int i=0; i< NPtBins; i++) {
    cout<<" calculation for Pt "<<APtBins[i]<<"  "<<APtBins[i+1]<<" GeV/c "<<endl;

    //Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, Int_t PtBin)
    HistOutJetAsymPt[i] = Asym_DiJet_Pt(fJetpp276tev,  RespT, ResPhi, alpha, MM, NPartFunc(0,20), APtBins[i], APtBins[i+1], i);

    
    Canv_Asym_DiJet_Pt->cd(i+1);
    
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    grf_Data_CMS_Aj_Pt_276TeV[i]->Draw("AP");
    HistOutJetAsymPt[i]->GetYaxis()->SetRangeUser(0.0,0.32);
    HistOutJetAsymPt[i]->Draw("Psame");
    leg->Draw("same");
    tb->DrawLatex(0.60,0.70,Form("%0d < p_{T} < %0d",APtBins[i],APtBins[i+1]));

  }

  Canv_Asym_DiJet_Pt->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Pt.pdf");
  Canv_Asym_DiJet_Pt->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Pt.png");

  
  //return;

  //CentBins (0,10,20,30,50,70,100)
  const Int_t NCentBins = 6;
  const Int_t CentBins[NCentBins+1]={0,10,20,30,50,70,100};
  Double_t ANPartCent[NCentBins]={NPartFunc(0,10),NPartFunc(10,20),NPartFunc(20,30),NPartFunc(30,50),NPartFunc(50,70),NPartFunc(70,100)};
  TH1D *HistOutJetAsymCent[NCentBins];

  TGraphErrors *grf_Data_CMS_Aj_Cent_276TeV[NCentBins]={grf_Data_CMS_Aj_Cent_00_10_276TeV,grf_Data_CMS_Aj_Cent_10_20_276TeV,
							grf_Data_CMS_Aj_Cent_20_30_276TeV,grf_Data_CMS_Aj_Cent_30_50_276TeV,
							grf_Data_CMS_Aj_Cent_50_70_276TeV,grf_Data_CMS_Aj_Cent_70_100_276TeV};

    
  // Canvas defined outside the centrality loop
  
  TCanvas *Canv_Asym_DiJet_Centrality = new TCanvas("Canv_Asym_DiJet_Centrality","Canv_Asym_DiJet_Centrality",1200,800);//coulamXRows
  Canv_Asym_DiJet_Centrality->Divide(3,2);
  char LatexChar[400];

  for(int i=0; i< NCentBins; i++) {
    cout<<" calculation for centrality "<<CentBins[i]<<"  "<<CentBins[i+1]<<"% "<<endl;
    HistOutJetAsymCent[i] = Asym_DiJet_Centrality(fJetpp276tev,  RespT, ResPhi, alpha, MM, ANPartCent[i], i);

    //Int_t j = NCentBins -i;
    //Canv_Asym_DiJet_Centrality->cd(j);
    Canv_Asym_DiJet_Centrality->cd(i+1);
    
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    grf_Data_CMS_Aj_Cent_276TeV[i]->Draw("AP");
    HistOutJetAsymCent[i]->GetYaxis()->SetRangeUser(0.0,0.32);
    HistOutJetAsymCent[i]->Draw("Psame");
    leg->Draw("same");
    tb->DrawLatex(0.60,0.70,Form("Cent. %0d - %0d %%",CentBins[i],CentBins[i+1]));

  }

  //Canv_Asym_DiJet_Centrality->cd(7);
  //gPad->SetTopMargin(0.1);
  //gPad->SetBottomMargin(0.2);
  //grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  //hAsymmetryDiff->Draw("Psame");
  //leg->Draw("same");
  //tb->DrawLatex(0.6, 0.7, "pp") ;
  Canv_Asym_DiJet_Centrality->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Centrality.pdf");
  Canv_Asym_DiJet_Centrality->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Centrality.png");



  //OutFile->Write();
  //OutFile->Close();  
  //return;

  
  
}//void DiJet



TH1D *XJ_GammaJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin, Int_t isPP)
{

  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop


  TH1D *hAsymmetryOut = new TH1D(Form("hXJOutCent_%d ",CentBin),Form("hXJOutCent_%d ",CentBin), 20, 0.0, 2.0);

  Double_t RR = RA*sqrt(NPart/(2*Am));
  const Int_t NEvents = 5000000;
  
  for(int i=0; i< NEvents; i++) {

    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom();
    
    // Generate position 
    Double_t rr = rand.Uniform(0.0,1.0)*RR;
    Double_t Phi = rand.Uniform(0.0,1.0)*2.0*pi;
    
    // Smear Phi
    Double_t Phi1 = rand.Gaus(Phi, Phi*ResPhi);
    Double_t Phi2 = rand.Gaus(Phi+pi, (Phi+pi)*ResPhi);
    
    Double_t DeltaPhi = (Phi2 - Phi1); 
    
    // Calculate pathlength
    Double_t d1 = sqrt(RR*RR - rr*rr*sin(Phi1)) - rr*cos(Phi1);
    Double_t d2 = sqrt(RR*RR - rr*rr*sin(Phi2)) - rr*cos(Phi2); 

    
    // Calculate DeltaPt
    Double_t dEdx = calDelta(Pt, Alpha, MM);
    
    //Put the energy Loss
    Double_t E1 = Pt; // this is assumed as Gamma
    Double_t E2 = Pt-dEdx*d2; // this is assumed as Jet
    if(isPP ==1)E2 = Pt;

    
    // Smear Pt
    Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    Double_t Pt2 = rand.Gaus(E2, E2*ResPt);

    //Exp cut on Pt
    
    const Double_t MinGammaPt = 60.0;
    const Double_t MinJetPt = 30.0;
    
    if(Pt1 < MinGammaPt || Pt2 < MinJetPt || DeltaPhi < (7.0*pi)/8.0) continue; 

    Double_t PtXJ = Pt2/Pt1; 
    //cout << Pt1 << "  " << Pt2<<"   "<<PtDiff << endl;
    
    hAsymmetryOut->Fill(PtXJ);
  } 

  hAsymmetryOut->Scale(1.0/hAsymmetryOut->Integral());
  hAsymmetryOut->Scale(1.0/hAsymmetryOut->GetBinWidth(0));
  hAsymmetryOut->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  hAsymmetryOut->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  hAsymmetryOut->GetXaxis()->CenterTitle();
  hAsymmetryOut->GetYaxis()->CenterTitle();
  hAsymmetryOut->SetMarkerColor(kRed);
  return hAsymmetryOut;
}





TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin)
{

  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop


  TH1D *hAsymmetryOut = new TH1D(Form("hAsymmetryOutCent_%d ",CentBin),Form("hAsymmetryOutCent_%d ",CentBin), 17, 0.0, 1.0);

  Double_t RR = RA*sqrt(NPart/(2*Am));
  const Int_t NEvents = 5000000;
  
  for(int i=0; i< NEvents; i++) {

    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom();
    
    // Generate position 
    Double_t rr = rand.Uniform(0.0,1.0)*RR;
    Double_t Phi = rand.Uniform(0.0,1.0)*2.0*pi;
    
    // Smear Phi
    Double_t Phi1 = rand.Gaus(Phi, Phi*ResPhi);
    Double_t Phi2 = rand.Gaus(Phi+pi, (Phi+pi)*ResPhi);
    
    Double_t DeltaPhi = (Phi2 - Phi1); 
    
    // Calculate pathlength
    Double_t d1 = sqrt(RR*RR - rr*rr*sin(Phi1)) - rr*cos(Phi1);
    Double_t d2 = sqrt(RR*RR - rr*rr*sin(Phi2)) - rr*cos(Phi2); 

    
    // Calculate DeltaPt
    Double_t dEdx = calDelta(Pt, Alpha, MM);
    
    Double_t E1 = Pt-dEdx*d1;
    Double_t E2 = Pt-dEdx*d2;

    // Smear Pt
    Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    Double_t Pt2 = rand.Gaus(E2, E2*ResPt);

    //Exp cut on Pt
    Double_t L_Pt = TMath::Max(Pt1,Pt2);
    Double_t SubL_Pt = TMath::Min(Pt1,Pt2);

    
    if(L_Pt< 120.0 || SubL_Pt < 30.0 || DeltaPhi < (2.0*pi)/3.0) continue; 
    Double_t PtDiff = (L_Pt-SubL_Pt)/(L_Pt+SubL_Pt); 
    //cout << Pt1 << "  " << Pt2<<"   "<<PtDiff << endl;
    
    hAsymmetryOut->Fill(PtDiff);
  } 

  hAsymmetryOut->Scale(1.0/hAsymmetryOut->Integral());
  hAsymmetryOut->GetXaxis()->SetTitle("A_{J}");
  hAsymmetryOut->GetYaxis()->SetTitle("Event Fraction");
  hAsymmetryOut->GetXaxis()->CenterTitle();
  hAsymmetryOut->GetYaxis()->CenterTitle();
  hAsymmetryOut->SetMarkerColor(kRed);
  return hAsymmetryOut;
}





TH1D *Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, Int_t PtBin)
{

  const Double_t SLPtMin = 30.0;
  
  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop


  TH1D *hAsymmetryOut = new TH1D(Form("hAsymmetryOutPt_%d ",PtBin),Form("hAsymmetryOutPt_%d ",PtBin), 17, 0.0, 1.0);

  Double_t RR = RA*sqrt(NPart/(2*Am));
  const Int_t NEvents = 5000000;
  
  for(int i=0; i< NEvents; i++) {



    Double_t MinPtRandom = LPtMin-0.7*LPtMin;
    Double_t MaxPtRandom = 500.0;
    
    //Double_t MinPtRandom = rand.Gaus(LPtMin, LPtMin*ResPt);
    //Double_t MaxPtRandom = rand.Gaus(LPtMax, LPtMax*ResPt);
    
    
    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom(MinPtRandom, MaxPtRandom);
    

    //if(Pt < SLPtMin) continue;
    
    // Generate position
    Double_t rr = rand.Uniform(0.0,1.0)*RR;
    Double_t Phi = rand.Uniform(0.0,1.0)*2.0*pi;
    
    // Smear Phi
    Double_t Phi1 = rand.Gaus(Phi, Phi*ResPhi);
    Double_t Phi2 = rand.Gaus(Phi+pi, (Phi+pi)*ResPhi);
    
    Double_t DeltaPhi = (Phi2 - Phi1); 
    
    // Calculate pathlength
    Double_t d1 = sqrt(RR*RR - rr*rr*sin(Phi1)) - rr*cos(Phi1);
    Double_t d2 = sqrt(RR*RR - rr*rr*sin(Phi2)) - rr*cos(Phi2); 

    
    // Calculate DeltaPt
    Double_t dEdx = calDelta(Pt, Alpha, MM);
    
    Double_t E1 = Pt-dEdx*d1;
    Double_t E2 = Pt-dEdx*d2;

    // Smear Pt
    Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    Double_t Pt2 = rand.Gaus(E2, E2*ResPt);

    //Exp cut on Pt
    Double_t L_Pt = TMath::Max(Pt1,Pt2);
    Double_t SubL_Pt = TMath::Min(Pt1,Pt2);;


        
    if( (L_Pt < LPtMin || L_Pt > LPtMax) || (SubL_Pt < SLPtMin) || DeltaPhi < (2.0*pi)/3.0) continue; 


    Double_t PtDiff = (L_Pt-SubL_Pt)/(L_Pt+SubL_Pt); 
    //cout << Pt1 << "  " << Pt2<<"   "<<PtDiff << endl;
    
    hAsymmetryOut->Fill(PtDiff);
  } 

  hAsymmetryOut->Scale(1.0/hAsymmetryOut->Integral());
  hAsymmetryOut->GetXaxis()->SetTitle("A_{J}");
  hAsymmetryOut->GetYaxis()->SetTitle("Event Fraction");
  hAsymmetryOut->GetXaxis()->CenterTitle();
  hAsymmetryOut->GetYaxis()->CenterTitle();
  hAsymmetryOut->SetMarkerColor(kRed);
  return hAsymmetryOut;
}













