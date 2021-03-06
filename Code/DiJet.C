#include "DiJet.h"
//#include "DiJetDataFunctions.h"

void DiJetAsymCalculations(Double_t Alpha, Double_t MM);
void Z0JetCalculations(Double_t Alpha, Double_t MM);
void GammaJetCalculations(Double_t Alpha, Double_t MM);
void JetRAACalculations(Double_t Alpha, Double_t MM);
void TestDataFunctions();





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

  //TestDataFunctions();

    

  //return;
  
  // Random distribution;
  TRandom3 rand(0);
  
  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative
  
  //On 19.May.2020
  //Double_t alpha = 0.55;
  //Double_t MM = 0.4;

  Double_t alpha = 0.45;
  Double_t MM = 0.6;


  DiJetAsymCalculations(alpha, MM);
  JetRAACalculations(alpha, MM);
  GammaJetCalculations(alpha,MM);
  Z0JetCalculations(alpha, MM);


  return;


  //Fit_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV();
  //Fit_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV();
  



  /*
    what is the M and alpha value in paper.
    What is the value of resolution ?
    

We should implement freeze out.
    d1eff = Min(d1, tauF)
    d2eff =Min(d2, tauF)
    tauF can be 5 fm
    Also we can try to put expansion as in our quakonia paper as
    R --> R+0.5 *a*tau^2   where a = 0.1
  */
  
   
}//void DiJet



void JetRAACalculations(Double_t Alpha, Double_t MM)
{

  //latex for the function
  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.06);


  //legend for the function
  TLegend* leg= new TLegend(0.61,0.69,0.84,0.84);
  leg->SetBorderSize(0);
  leg->SetFillStyle(1001);
  leg->SetFillColor(10);
  leg->SetTextSize(0.035);

  TLine *l1 = new TLine(0,1.0,400.0,1.0);
  l1->SetLineWidth(2);
  
  //pp Jet yield function 
  const Double_t lc_jet_00_rapidity_21_pp_276tev_dNdy = 1035.26;
  const Double_t lc_jet_00_rapidity_21_pp_276tev_nn = 9.17592;
  const Double_t lc_jet_00_rapidity_21_pp_276tev_pzero = 29.1867;

  //function for pp Jet pT distribution  
  TF1 *fJetpp276tev = new TF1("fJetpp276tev", tsallis_fitting_function, 30.0, 500.0, 3);
  fJetpp276tev->SetParNames("dN/dy", "nn", "pzero");
  fJetpp276tev->FixParameter(0, lc_jet_00_rapidity_21_pp_276tev_dNdy);
  fJetpp276tev->FixParameter(1, lc_jet_00_rapidity_21_pp_276tev_nn);
  fJetpp276tev->FixParameter(2, lc_jet_00_rapidity_21_pp_276tev_pzero);
  
  new TCanvas ;
  gPad->SetTicks(1);
  gPad->SetLogy(1);
  TGraphErrors *gr_atlas_jet_yield_00_rapidity_21 = jet_atlas_yield_00_rapidity_21_pp_276tev() ;
  gr_atlas_jet_yield_00_rapidity_21->Draw("AP");
  fJetpp276tev->Draw("same");



  //============================= RAA as a function of Centrality (ATLAS 2.76 TeV) ==================================//  
  //CentBins (0,10,20,30,40,50,60,70,80)
  const Int_t NCentBins = 8;
  const Int_t CentBins[NCentBins+1]={0,10,20,30,40,50,60,70,80};
  Double_t ANPartCent[NCentBins]={NPartFunc(0,10),NPartFunc(10,20),NPartFunc(20,30),NPartFunc(30,40),
				  NPartFunc(40,50),NPartFunc(50,60),NPartFunc(60,70),NPartFunc(70,80)};
  TH1D *HistOutJetRAACent[NCentBins];
  

  
  TGraphErrors *grf_Data_ATLAS_RAA_Cent_276TeV[NCentBins]={jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_zero_ten(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_ten_twenty(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_twenty_thirty(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_thirty_forty(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_forty_fifty(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_fifty_sixty(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_sixty_seventy(),
							   jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_seventy_eighty()};
  
  

  TGraphErrors *grf_Data_ATLAS_RAA_Cent_502TeV[NCentBins]={jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_zero0_ten10(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_ten10_twenty20(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_twenty20_thirty30(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_thirty30_forty40(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_forty40_fifty50(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_fifty50_sixty60(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_sixty60_seventy70(),
							   jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_seventy70_eighty80()};
  

  
  
  // Canvas defined outside the centrality loop
  
  TCanvas *Canv_ATLAS_RAA_Cent_276TeV = new TCanvas("Canv_ATLAS_RAA_Cent_276TeV","Canv_ATLAS_RAA_Cent_276TeV",1600,800);//coulamXRows
  Canv_ATLAS_RAA_Cent_276TeV->Divide(4,2);
  char LatexChar[400];

  
  leg->AddEntry(grf_Data_ATLAS_RAA_Cent_276TeV[0],"ATLAS Data","P");

  TH1D *hist_Ghost_ATLAS_RAA_Cent_276TeV = new TH1D("hist_Ghost_ATLAS_RAA_Cent_276TeV","hist_Ghost_ATLAS_RAA_Cent_276TeV",100,0.0,500);
  hist_Ghost_ATLAS_RAA_Cent_276TeV->SetMarkerStyle(20);
  hist_Ghost_ATLAS_RAA_Cent_276TeV->SetMarkerColor(2);
  leg->AddEntry(hist_Ghost_ATLAS_RAA_Cent_276TeV,"Calculated","P");
 
  
  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative



  for(int i=0; i < NCentBins; i++) {
    cout<<" calculation for centrality "<<CentBins[i]<<"  "<<CentBins[i+1]<<"% "<<endl;
    
    HistOutJetRAACent[i] = RAA_Jet_Centrality(fJetpp276tev,  RespT, ResPhi, Alpha, MM, ANPartCent[i], i);
    Canv_ATLAS_RAA_Cent_276TeV->cd(i+1);
    
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    grf_Data_ATLAS_RAA_Cent_276TeV[i]->GetYaxis()->SetRangeUser(0.0,2.0);
    grf_Data_ATLAS_RAA_Cent_276TeV[i]->Draw("AP");
    HistOutJetRAACent[i]->GetYaxis()->SetRangeUser(0.0,2.0);
    HistOutJetRAACent[i]->Draw("Psame");
    tb->DrawLatex(0.20,0.80,Form("Cent. %0d - %0d %%",CentBins[i],CentBins[i+1]));
    tb->DrawLatex(0.2, 0.74, Form("#alpha=%.2f",Alpha)) ;
    tb->DrawLatex(0.2, 0.68, Form("m=%.2f",MM)) ;
    l1->Draw("same");
    leg->Draw("same");
 }


   Canv_ATLAS_RAA_Cent_276TeV->SaveAs("Figure/OutFigures/Fig_RAA_Jet_Centrality_276TeV.pdf");
   Canv_ATLAS_RAA_Cent_276TeV->SaveAs("Figure/OutFigures/Fig_RAA_Jet_Centrality_276TeV.png");


   TCanvas *Canv_ATLAS_RAA_Cent_502TeV = new TCanvas("Canv_ATLAS_RAA_Cent_502TeV","Canv_ATLAS_RAA_Cent_502TeV",1600,800);//coulamXRows
   Canv_ATLAS_RAA_Cent_502TeV->Divide(4,2);

   
  for(int i=0; i < NCentBins; i++) {
    
    Canv_ATLAS_RAA_Cent_502TeV->cd(i+1);
    
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    grf_Data_ATLAS_RAA_Cent_502TeV[i]->GetYaxis()->SetRangeUser(0.0,2.0);
    grf_Data_ATLAS_RAA_Cent_502TeV[i]->Draw("AP");
    HistOutJetRAACent[i]->GetYaxis()->SetRangeUser(0.0,2.0);
    HistOutJetRAACent[i]->Draw("Psame");
    //leg->Draw("same");
    tb->DrawLatex(0.20,0.80,Form("Cent. %0d - %0d %%",CentBins[i],CentBins[i+1]));
    tb->DrawLatex(0.2, 0.74, Form("#alpha=%.2f",Alpha)) ;
    tb->DrawLatex(0.2, 0.68, Form("m=%.2f",MM)) ;
    l1->Draw("same");
    leg->Draw("same");
 }


   Canv_ATLAS_RAA_Cent_502TeV->SaveAs("Figure/OutFigures/Fig_RAA_Jet_Centrality_502TeV.pdf");
   Canv_ATLAS_RAA_Cent_502TeV->SaveAs("Figure/OutFigures/Fig_RAA_Jet_Centrality_502TeV.png");




  
}

void DiJetAsymCalculations(Double_t Alpha, Double_t MM)
{

  cout<<" DiJet Calculations "<<endl;
  //Latex for function
  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.06);

  //Legend for function

  TLegend* leg= new TLegend(0.58,0.74,0.88,0.84);
  leg->SetBorderSize(0);
  leg->SetFillStyle(1001);
  leg->SetFillColor(10);
  leg->SetTextSize(0.035);
  
  // We will put resolution pT and resolution phi here as of now, ultimatily we should make function where we can choose
  // whether we want to use pT dependent or fixed resolution
  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  //++++++++++++++++++++++++++++++++++++++++++++++++ DiJet Calculations ++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  
  const Double_t lc_jet_00_rapidity_21_pp_276tev_dNdy = 1035.26;
  const Double_t lc_jet_00_rapidity_21_pp_276tev_nn = 9.17592;
  const Double_t lc_jet_00_rapidity_21_pp_276tev_pzero = 29.1867;

  //function for pp Jet pT distribution  
  TF1 *fJetpp276tev = new TF1("fJetpp276tev", tsallis_fitting_function, 30.0, 500.0, 3);
  fJetpp276tev->SetParNames("dN/dy", "nn", "pzero");
  fJetpp276tev->FixParameter(0, lc_jet_00_rapidity_21_pp_276tev_dNdy);
  fJetpp276tev->FixParameter(1, lc_jet_00_rapidity_21_pp_276tev_nn);
  fJetpp276tev->FixParameter(2, lc_jet_00_rapidity_21_pp_276tev_pzero);
  
  fJetpp276tev->SetLineColor(1);
  fJetpp276tev->SetLineStyle(4);
  fJetpp276tev->SetLineWidth(2);
  
  new TCanvas ;
  gPad->SetTicks(1);
  gPad->SetLogy(1);
  TGraphErrors *gr_atlas_jet_yield_00_rapidity_21 = jet_atlas_yield_00_rapidity_21_pp_276tev() ;
  gr_atlas_jet_yield_00_rapidity_21->Draw("AP");
  fJetpp276tev->Draw("same");
  tb->DrawLatex(0.55, 0.80, "ATLAS Jet 2.76 TeV") ;
  gPad->SaveAs("Figure/Fig_ATLAS_JetYield_JetPt_PP276TeV.png");
  gPad->SaveAs("Figure/Fig_ATLAS_JetYield_JetPt_PP276TeV.pdf");
  
  //return;
  //============================= Aj as a function of Centrality ==================================//  
  //CentBins (0,10,20,30,50,70,100)
  const Int_t NCentBins = 6;
  const Int_t CentBins[NCentBins+1]={0,10,20,30,50,70,100};
  Double_t ANPartCent[NCentBins]={NPartFunc(0,10),NPartFunc(10,20),NPartFunc(20,30),NPartFunc(30,50),NPartFunc(50,70),NPartFunc(70,100)};
  TH1D *HistOutJetAsymCent[NCentBins];

 
  TGraphErrors *grf_Data_CMS_Aj_Cent_276TeV[NCentBins]={Data_CMS_Aj_Cent_00_10_276TeV(),Data_CMS_Aj_Cent_10_20_276TeV(),
							Data_CMS_Aj_Cent_20_30_276TeV(),Data_CMS_Aj_Cent_30_50_276TeV(),
							Data_CMS_Aj_Cent_50_70_276TeV(),Data_CMS_Aj_Cent_70_100_276TeV()};
  



  // Canvas defined outside the centrality loop
  TCanvas *Canv_Asym_DiJet_Centrality = new TCanvas("Canv_Asym_DiJet_Centrality","Canv_Asym_DiJet_Centrality",600,1200);//coulamXRows
  Canv_Asym_DiJet_Centrality->Divide(2,4); // C X R
  char LatexChar[400];

  leg->AddEntry(grf_Data_CMS_Aj_Cent_276TeV[0],"Data","P");
  TH1D *hist_Ghost = new TH1D("hist_Ghost_1","hist_Ghost_1",100,0.0,500);
  hist_Ghost->SetMarkerStyle(20);
  hist_Ghost->SetMarkerColor(2);
  leg->AddEntry(hist_Ghost,"Calculated","P");
  
  
  for(int i=0; i < NCentBins; i++) {
    cout<<" calculation for centrality "<<CentBins[i]<<"  "<<CentBins[i+1]<<"% "<<endl;
    //TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin, Int_t IsPP)
    HistOutJetAsymCent[i] = Asym_DiJet_Centrality(fJetpp276tev,  RespT, ResPhi, Alpha, MM, ANPartCent[i], i, 0);

    Canv_Asym_DiJet_Centrality->cd(i+1);
    
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    grf_Data_CMS_Aj_Cent_276TeV[i]->GetYaxis()->SetRangeUser(0.0,0.32);
    grf_Data_CMS_Aj_Cent_276TeV[i]->Draw("AP");
    HistOutJetAsymCent[i]->GetYaxis()->SetRangeUser(0.0,0.32);
    HistOutJetAsymCent[i]->Draw("Psame");
    leg->Draw("same");
   
    tb->DrawLatex(0.60,0.70,Form("Cent. %0d - %0d %%",CentBins[i],CentBins[i+1]));
    tb->DrawLatex(0.2, 0.80, Form("#alpha=%.2f",Alpha)) ;
    tb->DrawLatex(0.2, 0.74, Form("m=%.2f",MM)) ;
  }

  TGraphErrors *grf_Data_CMS_Aj_pp_276TeV = Data_CMS_Aj_pp_276TeV();
  TH1D *HistOutJetAsymCent_PP = Asym_DiJet_Centrality(fJetpp276tev,  RespT, ResPhi, Alpha, MM, ANPartCent[5], 6, 1);

  Canv_Asym_DiJet_Centrality->cd(7);

  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  HistOutJetAsymCent_PP->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.6, 0.7, "pp") ;

  Canv_Asym_DiJet_Centrality->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Centrality.pdf");
  Canv_Asym_DiJet_Centrality->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Centrality.png");

 

  //=============================================== AJ as a function of pT =================================================//
  const Int_t NPtBins = 6;
  const Int_t APtBins[NPtBins+1]={120,150,180,220,260,300,500};

  TH1D *HistOutJetAsymPt[NPtBins];

  TGraphErrors *grf_Data_CMS_Aj_Pt_276TeV[NPtBins]={Data_CMS_Aj_Pt_120_150_276TeV(),Data_CMS_Aj_Pt_150_180_276TeV(),
						    Data_CMS_Aj_Pt_180_220_276TeV(),Data_CMS_Aj_Pt_220_260_276TeV(),
						    Data_CMS_Aj_Pt_260_300_276TeV(),Data_CMS_Aj_Pt_300_500_276TeV()};
  

  TCanvas *Canv_Asym_DiJet_Pt = new TCanvas("Canv_Asym_DiJet_Pt","Canv_Asym_DiJet_Pt",800,1200);//coulamXRows
  Canv_Asym_DiJet_Pt->Divide(2,3);
  
  
  for(int i=0; i< NPtBins; i++) {
    cout<<" calculation for Pt "<<APtBins[i]<<"  "<<APtBins[i+1]<<" GeV/c "<<endl;


    //calculating AJ as a function of pT DiJet 

    //Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, Int_t PtBin, Int_t IsPP)
    HistOutJetAsymPt[i] = Asym_DiJet_Pt(fJetpp276tev,  RespT, ResPhi, Alpha, MM, NPartFunc(0,20), APtBins[i], APtBins[i+1], i,0);
    
    Canv_Asym_DiJet_Pt->cd(i+1);
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    grf_Data_CMS_Aj_Pt_276TeV[i]->GetYaxis()->SetRangeUser(0.0,0.32);
    grf_Data_CMS_Aj_Pt_276TeV[i]->Draw("AP");
    HistOutJetAsymPt[i]->GetYaxis()->SetRangeUser(0.0,0.32);
    HistOutJetAsymPt[i]->Draw("EPsame");
    leg->Draw("same");
    tb->DrawLatex(0.60,0.70,Form("%0d < p_{T} < %0d",APtBins[i],APtBins[i+1]));
    tb->DrawLatex(0.60, 0.64, Form("#alpha=%.2f",Alpha)) ;
    tb->DrawLatex(0.60, 0.58, Form("m=%.2f",MM)) ;
    gPad->Update();
    
  }
  Canv_Asym_DiJet_Pt->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Pt.pdf");
  Canv_Asym_DiJet_Pt->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Pt.png");





}


void Z0JetCalculations(Double_t Alpha, Double_t MM)
{

  //Function Latex
  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.04);



  //Function Legend
  TLegend* leg= new TLegend(0.58,0.74,0.88,0.84);
  leg->SetBorderSize(0);
  leg->SetFillStyle(1001);
  leg->SetFillColor(10);
  leg->SetTextSize(0.035);


 

  // We will put resolution pT and resolution phi here as of now, ultimatily we should make function where we can choose
  // whether we want to use pT dependent or fixed resolution
  
  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative




  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  //++++++++++++++++++++++++++++++++++++++++++++++++ Z0 + Jet Calculations ++++++++++++++++++++++++++++++++++++++++++++++++//
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  // CMS Data Graphs XJ (Jet +Z0)
  TGraphAsymmErrors *grf_Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV = Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV = Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV();
  
  TGraphAsymmErrors *grf_Data_CMS_XJ_Z0Jet_PP_502TeV = Data_CMS_XJ_Z0Jet_PP_502TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Z0Jet_PP_502TeV = Data_Syst_CMS_XJ_Z0Jet_PP_502TeV();
  
  TGraphAsymmErrors *grf_Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV = Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV();
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV = Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV();

  leg->AddEntry(grf_Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV,"CMS Data","P");


  TH1D *hist_Ghost = new TH1D("hist_Ghost_2","hist_Ghost_2",100,0.0,500);
  hist_Ghost->SetMarkerStyle(20);
  hist_Ghost->SetMarkerColor(2);
  leg->AddEntry(hist_Ghost,"Calculated","P");


  
  TCanvas *Canv_CMS_XJ_Z0Jet_502TeV = new TCanvas("Canv_CMS_XJ_Z0Jet_502TeV","Canv_CMS_XJ_Z0Jet_502TeV",1200,400);//coulamXRows
  Canv_CMS_XJ_Z0Jet_502TeV->Divide(3,1);
  char LatexChar_XJ_Z0Jet[400];

  //function for random generation of Jet pT : Z0 + Jet
  //cout<<endl<<endl;
  //cout<<" Fitting CMS Z0 + Jet Yield 7 TeV "<<endl;
  //Fit_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV();

  TF1 *Func_Z0Jet_JetPt_7TeV = new TF1("Func_Z0Jet_JetPt_7TeV", tsallis_fitting_function, 50.0, 450.0, 3);
  Func_Z0Jet_JetPt_7TeV->SetParNames("dN/dy", "nn", "pzero");
  Func_Z0Jet_JetPt_7TeV->SetParameter(0, 0.181431);
  Func_Z0Jet_JetPt_7TeV->SetParameter(1, 6.91081);
  Func_Z0Jet_JetPt_7TeV->SetParameter(2, 63.6729);

  
  // Calculating XJ as a function of Centrality for Z0+Jet events
  TH1D *HistOutJetZ0_XJ_Cent_00_30 = XJ_Z0Jet_Centrality(Func_Z0Jet_JetPt_7TeV,  RespT, ResPhi, Alpha, MM, NPart_FiveTeV(0,30), 0, 0) ;

  Canv_CMS_XJ_Z0Jet_502TeV->cd(1);
  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV->GetYaxis()->SetRangeUser(0.0,2.5);
  grf_Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV->Draw("2");
  HistOutJetZ0_XJ_Cent_00_30->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.75, 0.70, "0-30%") ;
  tb->DrawLatex(0.3, 0.8, Form("#alpha=%.2f",Alpha)) ;
  tb->DrawLatex(0.3, 0.74, Form("m=%.2f",MM)) ;
 
  // Calculating XJ for pp (with pT smearing)
  TH1D *HistOutJetZ0_XJ_PP = XJ_Z0Jet_Centrality(Func_Z0Jet_JetPt_7TeV,  RespT, ResPhi, Alpha, MM, NPart_FiveTeV(0,30), 1, 1) ;

  Canv_CMS_XJ_Z0Jet_502TeV->cd(2);
  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_Z0Jet_PP_502TeV->GetYaxis()->SetRangeUser(0.0,2.5);
  grf_Data_CMS_XJ_Z0Jet_PP_502TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_Z0Jet_PP_502TeV->Draw("2");
  HistOutJetZ0_XJ_PP->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.75, 0.70, "pp") ;
  //tb->DrawLatex(0.2, 0.74, Form("#alpha=%.2f",Alpha)) ;
  //tb->DrawLatex(0.2, 0.68, Form("m=%.2f",MM)) ;
 
  // Calculating XJ for pp wihout any pT smearing
  TH1D *HistOutJetZ0_XJ_PP_UnS = XJ_Z0Jet_Centrality(Func_Z0Jet_JetPt_7TeV,  RespT, ResPhi, Alpha, MM, NPart_FiveTeV(0,30), 2, 2) ;

  Canv_CMS_XJ_Z0Jet_502TeV->cd(3);
  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  gPad->SetLeftMargin(0.2);
  grf_Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV->GetYaxis()->SetRangeUser(0.0,2.5);
  grf_Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV->Draw("AP");
  grf_Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV->Draw("2");
  HistOutJetZ0_XJ_PP_UnS->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.50, 0.70, "pp (unsmeared)") ;

  //tb->DrawLatex(0.2, 0.74, Form("#alpha=%.2f",Alpha)) ;
  //tb->DrawLatex(0.2, 0.68, Form("m=%.2f",MM)) ;
 
  Canv_CMS_XJ_Z0Jet_502TeV->SaveAs("Figure/OutFigures/Fig_XJ_Z0Jet_Centrality.pdf");
  Canv_CMS_XJ_Z0Jet_502TeV->SaveAs("Figure/OutFigures/Fig_XJ_Z0Jet_Centrality.png");


  return;

  


}











void GammaJetCalculations(Double_t Alpha, Double_t MM)
{


  
  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.06);


  //Function Legend
  TLegend* leg= new TLegend(0.58,0.74,0.88,0.84);
  leg->SetBorderSize(0);
  leg->SetFillStyle(1001);
  leg->SetFillColor(10);
  leg->SetTextSize(0.035);


  
  // We will put resolution pT and resolution phi here as of now, ultimatily we should make function where we can choose
  // whether we want to use pT dependent or fixed resolution
  
  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  //++++++++++++++++++++++++++++++++++++++++++++++++ Gamma + Jet Calculations ++++++++++++++++++++++++++++++++++++++++++++++++//
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
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


  leg->AddEntry(grf_Data_CMS_XJ_GammaJet_Cent_00_10_276TeV,"CMS Data","P");

  TH1D *hist_Ghost = new TH1D("hist_Ghost_3","hist_Ghost_3",100,0.0,500);
  hist_Ghost->SetMarkerStyle(20);
  hist_Ghost->SetMarkerColor(2);
  leg->AddEntry(hist_Ghost,"Calculated","P");


  
  // XJ Calculations as a function of Centrality Gamma+Jet events
  //CentBins (0,10,30,50,100)
  const Int_t NCentBins_XJ = 4;
  const Int_t CentBins_XJ[NCentBins_XJ+1]={0,10,30,50,100};
  Double_t ANPartCent_XJ[NCentBins_XJ]={NPartFunc(0,10),NPartFunc(10,30),NPartFunc(30,50),NPartFunc(50,100)};

  //Array for data graphs
  TGraphAsymmErrors *grf_Data_CMS_XJ_Cent_276TeV[NCentBins_XJ]={grf_Data_CMS_XJ_GammaJet_Cent_00_10_276TeV,grf_Data_CMS_XJ_GammaJet_Cent_10_30_276TeV,
								grf_Data_CMS_XJ_GammaJet_Cent_30_50_276TeV,grf_Data_CMS_XJ_GammaJet_Cent_50_100_276TeV};
  //Array for data graphs syst.
  TGraphAsymmErrors *grf_Data_Syst_CMS_XJ_Cent_276TeV[NCentBins_XJ]={grf_Data_Syst_CMS_XJ_GammaJet_Cent_00_10_276TeV,grf_Data_Syst_CMS_XJ_GammaJet_Cent_10_30_276TeV,
								grf_Data_Syst_CMS_XJ_GammaJet_Cent_30_50_276TeV,grf_Data_Syst_CMS_XJ_GammaJet_Cent_50_100_276TeV};
  // Histogram output from the calculation function
  TH1D *HistOutJetGamma_XJ[NCentBins_XJ];

  // Canvas defined outside the centrality loop
  TCanvas *Canv_CMS_XJ_Cent_276TeV = new TCanvas("Canv_CMS_XJ_Cent_276TeV","Canv_CMS_XJ_Cent_276TeV",1200,800);//coulamXRows
  Canv_CMS_XJ_Cent_276TeV->Divide(3,2);
  char LatexChar_XJ[400];

  //=============== Define a fitting function to be used for pT generation =======================================//
  //cout<<endl<<endl;
  //cout<<" Fitting CMS Gamma + Jet Yield 8 TeV "<<endl;
  //Fit_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV();

  //function for random generation of Jet pT : Gamma + Jet  
  TF1 *Func_GammaJet_JetPt_8TeV = new TF1("Func_GammaJet_JetPt_8TeV", tsallis_fitting_function, 50.0, 450.0, 3);
  Func_GammaJet_JetPt_8TeV->SetParNames("dN/dy", "nn", "pzero");
  Func_GammaJet_JetPt_8TeV->SetParameter(0, 94.5497);
  Func_GammaJet_JetPt_8TeV->SetParameter(1, 7.12841);
  Func_GammaJet_JetPt_8TeV->SetParameter(2, 34.9877);

  for(int i=0; i< NCentBins_XJ; i++) {
    cout<<" XJ calculation for centrality "<<CentBins_XJ[i]<<"  "<<CentBins_XJ[i+1]<<"% "<<endl;
    HistOutJetGamma_XJ[i] = XJ_GammaJet_Centrality(Func_GammaJet_JetPt_8TeV,  RespT, ResPhi, Alpha, MM, ANPartCent_XJ[i], i,0);
    Canv_CMS_XJ_Cent_276TeV->cd(i+1);
    gPad->SetTopMargin(0.1);
    gPad->SetBottomMargin(0.2);
    gPad->SetLeftMargin(0.2);
    
    grf_Data_CMS_XJ_Cent_276TeV[i]->Draw("AP");
    grf_Data_Syst_CMS_XJ_Cent_276TeV[i]->Draw("2");
    HistOutJetGamma_XJ[i]->GetYaxis()->SetRangeUser(0.0,3.0);
    HistOutJetGamma_XJ[i]->Draw("Psame");
    leg->Draw("same");
    tb->DrawLatex(0.60,0.70,Form("%0d - %0d %%",CentBins_XJ[i],CentBins_XJ[i+1]));
    tb->DrawLatex(0.3, 0.80, Form("#alpha=%.2f",Alpha)) ;
    tb->DrawLatex(0.3, 0.74, Form("m=%.2f",MM)) ;
   
  }
  
  Canv_CMS_XJ_Cent_276TeV->cd(5);
  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  gPad->SetLeftMargin(0.2);
  //This need to be coded better
  //This is pp calculation , here CentBin is given by hand also isPP is given by hand
  TH1D *HistOutJetGamma_XJ_PP = XJ_GammaJet_Centrality(Func_GammaJet_JetPt_8TeV,  RespT, ResPhi, Alpha, MM, ANPartCent_XJ[3], 4,1);
  grf_Data_CMS_XJ_GammaJet_PP_276TeV->Draw("AP");
  HistOutJetGamma_XJ_PP->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.6, 0.7, "pp") ;
  
  Canv_CMS_XJ_Cent_276TeV->SaveAs("Figure/OutFigures/Fig_XJ_GammaJet_Centrality.pdf");
  Canv_CMS_XJ_Cent_276TeV->SaveAs("Figure/OutFigures/Fig_XJ_GammaJet_Centrality.png");
  
  return;


}

void TestDataFunctions()
{


  
  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.04);

  //Test Data Graph
  TGraphErrors *grf_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV = Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV();
  new TCanvas;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.15);
  grf_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->Draw("AP");


  TGraphErrors *grf_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV = Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV();
  new TCanvas;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.15);
  grf_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->Draw("AP");

    
  cout<<endl<<endl;
  cout<<" Fitting ATLAS Jet Yield 2.76 TeV "<<endl;
  FitParaTsallisPP276TeV();
  
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

}


