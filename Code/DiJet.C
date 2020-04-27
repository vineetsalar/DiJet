#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "TH1F.h"
#include <TMath.h>
#include <TLegend.h>
#include "TCanvas.h"
#include <TPad.h>
#include "TStyle.h"
#include <cstdlib>
#include <cmath>
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include <fstream>
#include <stdlib.h>
#include "TMath.h"
#include "TRandom3.h"
#include "TF1.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TLine.h"
#include <TSystem.h>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "TMinuit.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TMath.h"
#include <TFitResult.h>
#include "TMinuit.h"
using namespace std;


// Global Varaibles 
const Double_t pi       = 3.14159265358979312 ;
const Double_t sigma_alice_276tev  = 62.8 ;  // (mb)
const Double_t sigma_atlas_502tev  = 67.6 ;  // (mb) 1710.07098


const Double_t Am = 208.0 ;
const Double_t R0 = 1.1;
const Double_t RA = R0*pow(Am, 1.0/3.0);



Double_t NPartFunc(int CentLow, int CentHigh);
Double_t NCollFunc(int CentLow, int CentHigh);


//  Jet production in pp collisions at 2.76 TeV 
//      JET pT spectra in PbPb collisions @ 2.76 TeV     ///////
Double_t jet_00_rapidity_21_pp_276tev_dNdy ;
Double_t jet_00_rapidity_21_pp_276tev_nn     ; 
Double_t jet_00_rapidity_21_pp_276tev_pzero  ;
TGraphErrors *jet_atlas_yield_00_rapidity_21_pp_276tev() ;
Double_t tsallis_fitting_function(Double_t* x, Double_t* par);
void FitParaTsallisPP276TeV();






////

Double_t Npart_Jet_PbPb_276TeV_Cen_0_10  = 356.20 ;
Double_t Npart_Jet_PbPb_276TeV_Cen_10_20 = 266.70 ;
Double_t Npart_Jet_PbPb_276TeV_Cen_20_30 = 186.40 ;
Double_t Npart_Jet_PbPb_276TeV_Cen_30_40 = 129.30 ;
Double_t Npart_Jet_PbPb_276TeV_Cen_40_50 = 85.60  ;
Double_t Npart_Jet_PbPb_276TeV_Cen_50_60 = 53.00  ;
Double_t Npart_Jet_PbPb_276TeV_Cen_60_70 = 30.10  ;
Double_t Npart_Jet_PbPb_276TeV_Cen_70_80 = 15.10  ;


//const Double_t NPartCent[8] = {356.20, 266.70, 186.40, 129.30, 85.60, 53.00, 30.10, 15.10};


//CMS Data Functions 
TGraphErrors *Data_CMS_Aj_Cent_00_10_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_10_20_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_20_30_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_30_50_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_50_70_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_70_100_276TeV();
TGraphErrors *Data_CMS_Aj_pp_276TeV();


// Function to calculate Asymmetry as a function of Centrality
Double_t calDelta(Double_t pT, Double_t alpha, Double_t MM) ;
TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin);






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
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadTopMargin(0.03);
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



  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.04);
  
  // CMS Data Graphs
  TGraphErrors *grf_Data_CMS_Aj_Cent_00_10_276TeV = Data_CMS_Aj_Cent_00_10_276TeV();
  new TCanvas;
  grf_Data_CMS_Aj_Cent_00_10_276TeV->Draw("AP");
  tb->DrawLatex(0.80, 0.20, "0-10%") ;
  TGraphErrors *grf_Data_CMS_Aj_Cent_10_20_276TeV = Data_CMS_Aj_Cent_10_20_276TeV();
  new TCanvas;
  grf_Data_CMS_Aj_Cent_10_20_276TeV->Draw("AP");
  tb->DrawLatex(0.80, 0.20, "10-20%") ;
  TGraphErrors *grf_Data_CMS_Aj_Cent_20_30_276TeV = Data_CMS_Aj_Cent_20_30_276TeV();
  new TCanvas;
  grf_Data_CMS_Aj_Cent_20_30_276TeV->Draw("AP");
  tb->DrawLatex(0.80, 0.20, "20-30%") ;
  TGraphErrors *grf_Data_CMS_Aj_Cent_30_50_276TeV = Data_CMS_Aj_Cent_30_50_276TeV();
  new TCanvas;
  grf_Data_CMS_Aj_Cent_30_50_276TeV->Draw("AP");
  tb->DrawLatex(0.80, 0.20, "30-50%") ;
  TGraphErrors *grf_Data_CMS_Aj_Cent_50_70_276TeV = Data_CMS_Aj_Cent_50_70_276TeV();
  new TCanvas;
  grf_Data_CMS_Aj_Cent_50_70_276TeV->Draw("AP");
  tb->DrawLatex(0.80, 0.20, "50-70%") ;
  TGraphErrors *grf_Data_CMS_Aj_Cent_70_100_276TeV = Data_CMS_Aj_Cent_70_100_276TeV();
  new TCanvas;
  grf_Data_CMS_Aj_Cent_70_100_276TeV->Draw("AP");
  tb->DrawLatex(0.75, 0.20, "70-100%") ;
  TGraphErrors *grf_Data_CMS_Aj_pp_276TeV = Data_CMS_Aj_pp_276TeV();   
  new TCanvas;
  grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  tb->DrawLatex(0.75, 0.20, "pp") ;

  // Histograms
  TH1D *hAsymmetryDiff = new TH1D("hAsymmetryDiff", "hAsymmetryDiff", 17, 0.0, 1.0);
  hAsymmetryDiff->SetLineWidth(2);
  // Random distribution;
  TRandom3 rand(0); 
  // pp distribution fit 
  FitParaTsallisPP276TeV();
  //function for pp Jet pT distribution  
  TF1 *fJetpp276tev = new TF1("fJetpp276tev", tsallis_fitting_function, 30.0, 500.0, 3);
  fJetpp276tev->SetParNames("dN/dy", "nn", "pzero");
  fJetpp276tev->SetParameters(jet_00_rapidity_21_pp_276tev_dNdy, jet_00_rapidity_21_pp_276tev_nn, jet_00_rapidity_21_pp_276tev_pzero);


  Double_t ResPhi = 0.3; // relative
  Double_t RespT = 0.28;  // Relative
  
  //for Energy Loss
  Double_t alpha = 0.6;
  Double_t MM = 0.5;


  // Size of the system
  Double_t Npart = Npart_Jet_PbPb_276TeV_Cen_0_10;
  Double_t RR = RA*sqrt(Npart/(2*Am));
  int nn = 5000000;
  
  for(int i=1; i<= nn; i++) {

    // Generate pT 
    Double_t pT = fJetpp276tev->GetRandom();


    // if(pT<30.0) continue;
    
    // Generate position 
    Double_t rr = rand.Uniform(0.0,1.0)*RR;
    Double_t Phi = rand.Uniform(0.0,1.0)*2.0*pi;

    
    Double_t Phi1 = rand.Gaus(Phi, Phi*ResPhi);
    Double_t Phi2 = rand.Gaus(Phi+pi, (Phi+pi)*ResPhi);

    Double_t DeltaPhi = Phi2 - Phi1; 
    
    // Calculate pathlength
    Double_t d1 = sqrt(RR*RR - rr*rr*sin(Phi1)) - rr*cos(Phi1);
    Double_t d2 = sqrt(RR*RR - rr*rr*sin(Phi2)) - rr*cos(Phi2); 

    
    // Calculate DeltapT
    Double_t dEdx = calDelta(pT, alpha, MM);

    Double_t E1 = pT-dEdx*d1;
    Double_t E2 = pT-dEdx*d2;
    //for pp no energy loss
    E1 = pT;
    E2 = pT;

    
    // Smear pT
    Double_t pT1 = rand.Gaus(E1, E1*RespT);
    Double_t pT2 = rand.Gaus(E2, E2*RespT);

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
  hAsymmetryDiff->GetYaxis()->SetRangeUser(0,0.2);
  hAsymmetryDiff->SetLineColor(2);
  hAsymmetryDiff->SetMarkerColor(2);
  
  
  //grf_Data_CMS_Aj_Cent_00_10_276TeV->Draw("AP");
  //tb->DrawLatex(0.80, 0.20, "0-10%") ;
  
  grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  tb->DrawLatex(0.75, 0.20, "pp") ;

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


  //CentBins (0,10,20,30,50,70,100)
  const Int_t NCentBins = 6;
  const Int_t CentBins[NCentBins+1]={0,10,20,30,50,70,100};
  Double_t ANPartCent[NCentBins]={NPartFunc(0,10),NPartFunc(10,20),NPartFunc(20,30),NPartFunc(30,50),NPartFunc(50,70),NPartFunc(70,100)};
  TH1D *HistOutJetAsymCent[NCentBins];

  TGraphErrors *grf_Data_CMS_Aj_Cent_276TeV[NCentBins]={grf_Data_CMS_Aj_Cent_00_10_276TeV,grf_Data_CMS_Aj_Cent_10_20_276TeV,
							grf_Data_CMS_Aj_Cent_20_30_276TeV,grf_Data_CMS_Aj_Cent_30_50_276TeV,
							grf_Data_CMS_Aj_Cent_50_70_276TeV,grf_Data_CMS_Aj_Cent_70_100_276TeV};

    
  // Canvas defined outside the centrality loop
  
  TCanvas *Canv_Asym_DiJet_Centrality = new TCanvas("Canv_Asym_DiJet_Centrality","Canv_Asym_DiJet_Centrality",1600,800);//coulamXRows
  Canv_Asym_DiJet_Centrality->Divide(4,2);
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

  Canv_Asym_DiJet_Centrality->cd(7);
  gPad->SetTopMargin(0.1);
  gPad->SetBottomMargin(0.2);
  grf_Data_CMS_Aj_pp_276TeV->Draw("AP");
  hAsymmetryDiff->Draw("Psame");
  leg->Draw("same");
  tb->DrawLatex(0.6, 0.7, "pp") ;
  Canv_Asym_DiJet_Centrality->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Centrality.pdf");
  Canv_Asym_DiJet_Centrality->SaveAs("Figure/OutFigures/Fig_Asym_DiJet_Centrality.png");


  //integarted gen fractions
  //CanvasGenFractionMuonCut->cd(i+1);
  //gPad->SetTopMargin(0.1);
  //gPad->SetBottomMargin(0.2);
  //h->Draw();
  //graph_GenJetFracGraph->Draw("Bsame");
  //graph_GenMuonPtCut_GenJetFrac[i]->Draw("Bsame");  
  //lgd_GenMuonGenJetFrac->Draw("same");
  //sprintf(LatexChar,"#mu p_{T} > %.1f GeV/c",MuonPtCut[i]);
  //tb->DrawLatex(0.28,0.68,LatexChar);
  //CanvasGenFractionMuonCut->SaveAs("Plots/GenJets/GenJetFrac_GenMuPtCut_All.png");
  //CanvasGenFractionMuonCut->SaveAs("Plots/GenJets/GenJetFrac_GenMuPtCut_All.pdf");



  




  
  
}//void DiJet







TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin)
{

  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop


  TH1D *hAsymmetryOut = new TH1D(Form("hAsymmetryOut_%d ",CentBin),Form("hAsymmetryOut_%d ",CentBin), 17, 0.0, 1.0);

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
    Double_t SubL_Pt = TMath::Min(Pt1,Pt2);;

    
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



// Fitting ATLAS Jet yields with Tsallis function


// Fitting Functions 
Double_t tsallis_fitting_function(Double_t* x, Double_t* par)
{
  Double_t pT    = x[0] ; 
  Double_t dNdy  = par[0];
  Double_t nn    = par[1];
  Double_t pzero = par[2] ;

  // Double_t Mass  = par[3] ; 
  // Double_t MT = sqrt(pT*pT + Mass*Mass) ;
  Double_t MT = pT ; 
  
  Double_t Norm = 1.0;

  Double_t tsallis = dNdy * Norm * pow( (1 + pT/pzero), -nn) ;
  
  return tsallis ;
   
}


Double_t calDelta(Double_t pT, Double_t alpha, Double_t MM) 
{

  Double_t Delta_pT = MM * pow(pT, alpha) ;
  return Delta_pT;
}


void FitParaTsallisPP276TeV()
{

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
  

  TF1 *fitfunc_jet_00_rapidity_21_pp_276tev = new TF1("fitfunc_jet_00_rapidity_21_pp_276tev", tsallis_fitting_function, 0.0, 500.0, 3);

  fitfunc_jet_00_rapidity_21_pp_276tev->SetParNames("dN/dy", "nn", "pzero");
  fitfunc_jet_00_rapidity_21_pp_276tev->SetParameters(1000.0, 6.0, 0.1) ;
  fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(0, 750.0, 1100.0); 
  fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(1, 4.0,   500.0) ;
  // fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(2, 0.1, 2.0) ;
  fitfunc_jet_00_rapidity_21_pp_276tev->SetLineColor(1);
  fitfunc_jet_00_rapidity_21_pp_276tev->SetLineStyle(1);
  fitfunc_jet_00_rapidity_21_pp_276tev->SetLineWidth(4);
  gr_atlas_jet_yield_00_rapidity_21->Fit(fitfunc_jet_00_rapidity_21_pp_276tev,  "ME", "", 35.0, 360.0) ;
  fitfunc_jet_00_rapidity_21_pp_276tev->Draw("same");  

  TLegend *leg_jet_pp_yield = new TLegend(0.35, 0.74, 0.89, 0.94);
  leg_jet_pp_yield->SetBorderSize(0);
  leg_jet_pp_yield->SetFillStyle(1001);
  leg_jet_pp_yield->SetFillColor(10);
  leg_jet_pp_yield->SetTextSize(0.050);
  leg_jet_pp_yield->SetHeader("pp @ #sqrt{s} = 2.76 TeV"); 
  leg_jet_pp_yield->AddEntry(gr_atlas_jet_yield_00_rapidity_21,    "ATLAS, Jet",           "p");
  leg_jet_pp_yield->AddEntry(fitfunc_jet_00_rapidity_21_pp_276tev, "Tsallis Distribution", "l"); 
  leg_jet_pp_yield->Draw("same");

  TLatex *Latex_Jet_yield_pp_276TeV = new TLatex();
  Latex_Jet_yield_pp_276TeV->SetNDC();
  Latex_Jet_yield_pp_276TeV->SetTextAlign(12); 
  Latex_Jet_yield_pp_276TeV->SetTextColor(1);
  Latex_Jet_yield_pp_276TeV->SetTextSize(0.08);
  Latex_Jet_yield_pp_276TeV->DrawLatex(0.50, 0.70, "|y| < 2.1") ;
  
  jet_00_rapidity_21_pp_276tev_dNdy      = fitfunc_jet_00_rapidity_21_pp_276tev->GetParameter(0) ;
  Double_t jet_00_rapidity_21_pp_276tev_dNdy_err  = fitfunc_jet_00_rapidity_21_pp_276tev->GetParError(0)  ;
  jet_00_rapidity_21_pp_276tev_nn               = fitfunc_jet_00_rapidity_21_pp_276tev->GetParameter(1) ;
  Double_t jet_00_rapidity_21_pp_276tev_nn_err    = fitfunc_jet_00_rapidity_21_pp_276tev->GetParError(1)  ;
  jet_00_rapidity_21_pp_276tev_pzero            = fitfunc_jet_00_rapidity_21_pp_276tev->GetParameter(2) ;
  Double_t jet_00_rapidity_21_pp_276tev_pzero_err = fitfunc_jet_00_rapidity_21_pp_276tev->GetParError(2)  ;
  Double_t jet_00_rapidity_21_pp_276tev_Chi2      = fitfunc_jet_00_rapidity_21_pp_276tev->GetChisquare()  ;
  Double_t jet_00_rapidity_21_pp_276tev_NDF       = fitfunc_jet_00_rapidity_21_pp_276tev->GetNDF()        ;
  Double_t jet_00_rapidity_21_pp_276tev_Chi2_NDF  = jet_00_rapidity_21_pp_276tev_Chi2/jet_00_rapidity_21_pp_276tev_NDF ;

  cout<<"______________________________________________________________________________"<<endl;
  cout<<"dNdy        = "<< jet_00_rapidity_21_pp_276tev_dNdy  <<"   "<<"dNdy_err  = "<< jet_00_rapidity_21_pp_276tev_dNdy_err <<endl;
  cout<<"nn          = "<< jet_00_rapidity_21_pp_276tev_nn    <<"   "<<"nn_err    = "<< jet_00_rapidity_21_pp_276tev_nn_err   <<endl;
  cout<<"pzero       = "<< jet_00_rapidity_21_pp_276tev_pzero <<"   "<<"pzero_err = "<< jet_00_rapidity_21_pp_276tev_pzero_err <<endl;
  cout<<"Chi^{2}     = "<< jet_00_rapidity_21_pp_276tev_Chi2     <<endl;
  cout<<"NDF         = "<< jet_00_rapidity_21_pp_276tev_NDF      <<endl;
  cout<<"Chi^{2}_NDF = "<< jet_00_rapidity_21_pp_276tev_Chi2_NDF <<endl;
  cout<<"******************************************************************************"<<endl;

  

  gPad->SaveAs("Figure/Figure8_jet_atlas_pT_spectra_pp_276TeV.pdf") ;

}


TGraphErrors *jet_atlas_yield_00_rapidity_21_pp_276tev()
{
  //  Jet production in pp collisions at 2.76 TeV 
  //  Phys.Rev.Lett. 114 (2015) 072302, CERN-PH-EP-2014-172, arXiv:1411.2357 [hep-ex].
  
  Double_t sigma_alice_276tev1 = sigma_alice_276tev * pow(10.0, 6.0);   // Convert nb to (GeV/c)^{-2}

  int N_point = 12 ;
  Double_t pT[15] = {3.500000e+01 ,4.450000e+01 ,5.650000e+01 ,7.100000e+01 ,8.950000e+01 ,1.125000e+02 ,
		   1.415000e+02 ,1.785000e+02 ,2.250000e+02 ,2.835000e+02 ,3.570000e+02 ,4.495000e+02} ;
  Double_t pT_err[15] = {4.000000e+00 ,5.500000e+00 ,6.500000e+00 ,8.000000e+00 ,1.050000e+01 ,1.250000e+01 ,
		       1.650000e+01 ,2.050000e+01 ,2.600000e+01 ,3.250000e+01 ,4.100000e+01 ,5.150000e+01};

  Double_t yield[15] = {1.800000e+02 ,5.570000e+01 ,1.690000e+01 ,4.850000e+00 ,1.420000e+00 ,3.640000e-01 ,
		      8.820000e-02 ,1.970000e-02 ,4.060000e-03 ,7.350000e-04 ,1.140000e-04 ,1.410000e-05};

  Double_t stat_err[15] = {3.047427e+01 ,8.016544e+00 ,2.677197e+00 ,6.454510e-01 ,1.928954e-01 ,4.904014e-02 ,
			 1.137164e-02 ,2.372112e-03 ,4.984053e-04 ,9.266249e-05 ,1.485154e-05 ,2.036022e-06};


  for(int i=0; i<N_point; i++){
    yield[i]    = yield[i]/sigma_alice_276tev1 ; 
    stat_err[i] = stat_err[i]/sigma_alice_276tev1 ;
    
    // yield[i]    = yield[i]    * pow(10.0, 8.0) ;
    // stat_err[i] = stat_err[i] * pow(10.0, 8.0) ;
  }
  
  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, yield, pT_err, stat_err);
  gr_data->SetMarkerColor(2);
  gr_data->SetMarkerStyle(20);
  gr_data->SetMarkerSize(2);
  gr_data->Draw("sameP");
  

  return gr_data ;
			  
}



// CMS Data Functions for Aj

TGraphErrors *Data_CMS_Aj_Cent_00_10_276TeV()
{


  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  

  const Int_t NN = 14 ;

  Double_t AJ[NN] = {0.031, 0.092, 0.150, 0.211, 0.272, 0.334, 0.393, 0.451, 0.512, 0.570, 0.633, 0.690, 0.753, 0.811};
  Double_t Error_AJ[NN] = {0.0};


  Double_t EvFrac[NN] = {0.100, 0.116, 0.128, 0.112, 0.115, 0.105, 0.092, 0.083, 0.067, 0.051, 0.019, 0.000, 0.000, 0.000};
  Double_t Error_EvFrac[NN] = {0.0}; 





  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.8);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);


  





  
  return grf_local;
			  
}










TGraphErrors *Data_CMS_Aj_Cent_10_20_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  const Int_t NN = 13 ;
  Double_t AJ[NN] = {0.031, 0.092, 0.154, 0.211, 0.272, 0.332, 0.391, 0.453, 0.512, 0.571, 0.633, 0.690, 0.749};
  Double_t Error_AJ[NN] = {0.0};
  Double_t EvFrac[NN] = {0.116, 0.125, 0.129, 0.119, 0.112, 0.097, 0.093, 0.078, 0.059, 0.044, 0.019, 0.0, 0.0};
  Double_t Error_EvFrac[NN] = {0.0}; 

  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.8);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}


TGraphErrors *Data_CMS_Aj_Cent_20_30_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  const Int_t NN = 13 ;
  Double_t AJ[NN] = {0.030, 0.090, 0.151, 0.212, 0.273, 0.329, 0.392, 0.453, 0.509, 0.572, 0.633, 0.690, 0.747};
  Double_t Error_AJ[NN] = {0.0};
  Double_t EvFrac[NN] = {0.122, 0.136, 0.137, 0.124, 0.109, 0.102, 0.085, 0.070, 0.051, 0.039, 0.014, 0.002, 0.0};
  Double_t Error_EvFrac[NN] = {0.0}; 

  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.8);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}



TGraphErrors *Data_CMS_Aj_Cent_30_50_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  const Int_t NN = 12;
  Double_t AJ[NN] = {0.029, 0.092, 0.149, 0.208, 0.272, 0.329, 0.390, 0.449, 0.510, 0.569, 0.630, 0.689};
  Double_t Error_AJ[NN] = {0.0};
  Double_t EvFrac[NN] = {0.140, 0.151, 0.142, 0.129, 0.109, 0.093, 0.082, 0.060, 0.050, 0.035, 0.011, 0.003};
  Double_t Error_EvFrac[NN] = {0.0}; 

  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.8);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}


TGraphErrors *Data_CMS_Aj_Cent_50_70_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  const Int_t NN = 12;
  Double_t AJ[NN] = {0.028, 0.089, 0.149, 0.208, 0.268, 0.330, 0.391, 0.449, 0.509, 0.570, 0.628, 0.690};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.147, 0.163, 0.157, 0.131, 0.117, 0.087, 0.070, 0.057, 0.039, 0.022, 0.009, 0.003};

  Double_t EvFrac_Max[NN] = {0.155, 0.172, 0.166, 0.138, 0.124, 0.092, 0.076, 0.062, 0.043, 0.026, 0.013, 0.008};

  Double_t Error_EvFrac[NN] = {0.0}; 



  for(int i=0; i<NN; i++){

    Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i]; 
    
  }



  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.8);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}



TGraphErrors *Data_CMS_Aj_Cent_70_100_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  const Int_t NN = 12;
  Double_t AJ[NN] = {0.032, 0.093, 0.153, 0.214, 0.273, 0.331, 0.391, 0.449, 0.512, 0.572, 0.631, 0.689};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.211, 0.148, 0.177, 0.156, 0.068, 0.094, 0.057, 0.042, 0.022, 0.017, 0.002, 0.004};

  Double_t EvFrac_Max[NN] = {0.233, 0.169, 0.197, 0.175, 0.081, 0.107, 0.069, 0.049, 0.027, 0.023, 0.007, 0.007};

  Double_t Error_EvFrac[NN] = {0.0}; 



  for(int i=0; i<NN; i++){

    Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i]; 
    
  }



  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.8);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}




TGraphErrors *Data_CMS_Aj_pp_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  const Int_t NN = 12;
  Double_t AJ[NN] = {0.033, 0.090, 0.153, 0.212, 0.271, 0.330, 0.391, 0.453, 0.511, 0.570, 0.632, 0.690};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.169, 0.183, 0.156, 0.130, 0.120, 0.079, 0.058, 0.052, 0.029, 0.014, 0.007, 0.002};

  Double_t EvFrac_Max[NN] = {0.177, 0.190, 0.163, 0.136, 0.125, 0.083, 0.062, 0.057, 0.033, 0.020, 0.012, 0.007};

  Double_t Error_EvFrac[NN] = {0.0}; 



  for(int i=0; i<NN; i++){

    Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i]; 
    
  }



  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(4);
  grf_local->SetMarkerStyle(24);
  grf_local->SetMarkerSize(1.8);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}


// Glaubar Centrality Functions 2.76 TeV
//////////////////////////////////////////////////////////////////////////////////////////////////
Double_t NPartFunc(int CentLow, int CentHigh)
{

  Double_t CentToBin = 2.5;
  Double_t BinLow=CentLow/CentToBin;
  Double_t BinHigh=CentHigh/CentToBin;
  
  Double_t NpartArray[40]={393.622,368.96,342.32,316.49,293.49,271.98,249.65,230.53,212.28,194.50,178.54,
			 163.25,149.05,135.92,123.28,111.67,100.79,90.71,80.93,72.60,64.15,56.61,49.95,
			 43.39,37.83,32.70,27.86,23.79,20.20,16.85,14.04,11.60,9.55,7.72,6.44,4.96,4.22,
			 3.50,3.17,2.79};
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NpartArray[i];
  }
  Double_t NPart = sum/(BinHigh-BinLow);
  return NPart;
}

Double_t NCollFunc(int CentLow, int CentHigh)
{

  Double_t CentToBin = 2.5;
  Double_t BinLow=CentLow/CentToBin;
  Double_t BinHigh=CentHigh/CentToBin;
  
  Double_t NCollArray[40]={1747.8600, 1567.5300, 1388.3900, 1231.7700, 1098.2000, 980.4390, 861.6090, 766.0420, 676.5150, 593.4730,
			   521.9120, 456.5420, 398.5460, 346.6470, 299.3050, 258.3440, 221.2160, 188.6770, 158.9860, 134.7000,
			   112.5470, 93.4537, 77.9314, 63.5031, 52.0469, 42.3542, 33.9204, 27.3163, 21.8028, 17.2037,
			   13.5881, 10.6538, 8.3555, 6.4089, 5.1334, 3.7322, 3.0663, 2.4193, 2.1190, 1.7695};
  
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NCollArray[i];
  }
  Double_t NColl = sum/(BinHigh-BinLow);
  return NColl;
}




