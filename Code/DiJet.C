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

//RAA histograms
//


// Global Varaibles 
const Double_t pi       = 3.14159265358979312 ;
const Double_t sigma_alice_276tev  = 62.8 ;  // (mb)
const Double_t sigma_atlas_502tev  = 67.6 * pow(10.0, 6.0);  // (nb) 1710.07098
//sigma_atlas_502tev  = sigma_atlas_502tev * pow(10.0, 6.0) ;

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


//CMS Data Functions AJ as a func of CENT
TGraphErrors *Data_CMS_Aj_Cent_00_10_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_10_20_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_20_30_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_30_50_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_50_70_276TeV();
TGraphErrors *Data_CMS_Aj_Cent_70_100_276TeV();
TGraphErrors *Data_CMS_Aj_pp_276TeV();

//CMS Data Functions AJ as a func of PT
TGraphErrors *Data_CMS_Aj_Pt_120_150_276TeV();
TGraphErrors *Data_CMS_Aj_Pt_150_180_276TeV();
TGraphErrors *Data_CMS_Aj_Pt_180_220_276TeV();
TGraphErrors *Data_CMS_Aj_Pt_220_260_276TeV();
TGraphErrors *Data_CMS_Aj_Pt_260_300_276TeV();
TGraphErrors *Data_CMS_Aj_Pt_300_500_276TeV();


//ATLAS Data Functions RAA as a func of Cent
              
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_zero_ten();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_ten_twenty();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_twenty_thirty();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_thirty_forty();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_forty_fifty();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_fifty_sixty();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_sixty_seventy();
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_seventy_eighty();


// ATLAS Data : JetRAA spectra in in PbPb collissions @ 5.02 TeV
// CERN-EP-2018-105, arXiv:1805.05635 [nucl-ex].
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_zero0_ten10()        ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_ten10_twenty20()     ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_twenty20_thirty30()  ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_thirty30_forty40()   ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_forty40_fifty50()    ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_fifty50_sixty60()    ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_sixty60_seventy70()  ;
TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_seventy70_eighty80() ;
TGraphErrors *jet_production_atlas_yield_in_pp_collision_502tev();



// Function to calculate Asymmetry as a function of Centrality
Double_t calDelta(Double_t pT, Double_t alpha, Double_t MM) ;


TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin);
TH1D *Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, , Int_t PtBin);





void DiJet()
{

  // RAA histogram

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



  TLatex *tb = new TLatex();
  tb->SetNDC();
  tb->SetTextAlign(12); 
  tb->SetTextColor(1);
  tb->SetTextSize(0.04);
  
  // CMS Data Graphs
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
  hAsymmetryDiff->SetLineWidth(2);

  TH1D *hist_Pt_Initial = new TH1D("hist_Pt_Initial", "hist_Pt_Initial", 25, 0.0, 500.0);
  TH1D *hist_Pt_Final = new TH1D("hist_Pt_Final", "hist_Pt_Final", 25, 0.0, 500.0);
  TH1D *hist_Pt_Ratio = new TH1D("hist_Pt_Ratio", "hist_Pt_Ratio", 25, 0.0, 500.0);


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
  //Double_t RespT = 0.0;  // Relative
  
  //for Energy Loss
  //Double_t alpha = 0.5;
  //Double_t MM = 0.55;

  //Double_t alpha = 0.0;
  //Double_t MM = 6.0;


  Double_t alpha = 0.5;
  Double_t MM = 0.2;
  //Double_t alpha = 0.55;
  //Double_t MM = 0.4;

  


  // Size of the system
  Double_t Npart = Npart_Jet_PbPb_276TeV_Cen_0_10;
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
  hAsymmetryDiff->GetYaxis()->SetRangeUser(0,0.2);
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



  //hist_Pt_Final->Scale(1.0/ hist_Pt_Final->Integral());
  //hist_Pt_Initial->Scale(1.0/hist_Pt_Initial->Integral());


 

  new TCanvas;
  gPad->SetLogy(1);
  hist_Pt_Final->SetMarkerColor(2);
  hist_Pt_Initial->Draw("P");
  TH1D *temp_hist = (TH1D*)hist_Pt_Final->Clone("temp_hist");
  temp_hist->SetMarkerColor(2);
  temp_hist->Draw("Psame");
  
  hist_Pt_Final->Divide(hist_Pt_Final,hist_Pt_Initial,1.0,1.0,"B");

  new TCanvas;
  grf_Data_ATLAS_RAA_Cent_00_10_276TeV->Draw("AP");
  hist_Pt_Final->Draw("Psame");
  










  
  return;

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

  // make here pt functions
  TGraphErrors *grf_Data_CMS_Aj_Pt_120_150_276TeV = Data_CMS_Aj_Pt_120_150_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_150_180_276TeV = Data_CMS_Aj_Pt_150_180_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_180_220_276TeV = Data_CMS_Aj_Pt_180_220_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_220_260_276TeV = Data_CMS_Aj_Pt_220_260_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_260_300_276TeV = Data_CMS_Aj_Pt_260_300_276TeV();
  TGraphErrors *grf_Data_CMS_Aj_Pt_300_500_276TeV = Data_CMS_Aj_Pt_300_500_276TeV();
  




  
  
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





TH1D *Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, , Int_t PtBin)
{

  const Double_t SLPtMin = 30.0;
  
  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop


  TH1D *hAsymmetryOut = new TH1D(Form("hAsymmetryOut_%d ",CentBin),Form("hAsymmetryOut_%d ",PtBin), 17, 0.0, 1.0);

  Double_t RR = RA*sqrt(NPart/(2*Am));
  const Int_t NEvents = 5000000;
  
  for(int i=0; i< NEvents; i++) {

    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom();

    if(Pt < SLPtMin) continue;
    
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
  //fitfunc_jet_00_rapidity_21_pp_276tev->SetParameters(1000.0, 6.0, 0.1) ;
  //fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(0, 750.0, 1100.0); 
  //fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(1, 4.0,   500.0) ;

  fitfunc_jet_00_rapidity_21_pp_276tev->SetParameters(1.0, 6.0, 10) ;
  fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(0, 0.00001, 100.0);
  fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(1, 4.0,   10.0) ;
  fitfunc_jet_00_rapidity_21_pp_276tev->SetParLimits(2, 0.5, 50.0) ;
  
  fitfunc_jet_00_rapidity_21_pp_276tev->SetLineColor(1);
  fitfunc_jet_00_rapidity_21_pp_276tev->SetLineStyle(1);
  fitfunc_jet_00_rapidity_21_pp_276tev->SetLineWidth(4);

  fitfunc_jet_00_rapidity_21_pp_276tev->SetParNames("dN/dy", "nn", "pzero");


  //dNdy  = 0.00252839  
  //nn    = 7.28245 
  //pzero = 22.6085  


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
  grf_local->SetMarkerSize(1.5);

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
  grf_local->SetMarkerSize(1.5);
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
  grf_local->SetMarkerSize(1.5);
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
  grf_local->SetMarkerSize(1.5);
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
  grf_local->SetMarkerSize(1.5);
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
  grf_local->SetMarkerSize(1.5);
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
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}

//================================================//
//======= AJ in different Pt bins ================//
//================================================//

TGraphErrors *Data_CMS_Aj_Pt_120_150_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  const Int_t NN = 12 ;

  Double_t AJ[NN] = {0.026, 0.082, 0.147, 0.208, 0.268, 0.329, 0.390, 0.449, 0.510, 0.571, 0.630, 0.689};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.101, 0.114, 0.123, 0.114, 0.115, 0.101, 0.096, 0.086, 0.067, 0.049, 0.013, 0.000};
  Double_t Error_EvFrac[NN] = {0.0}; 

  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.5);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}


TGraphErrors *Data_CMS_Aj_Pt_150_180_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  const Int_t NN = 12 ;

  Double_t AJ[NN] = {0.032, 0.093, 0.151, 0.211, 0.272, 0.332, 0.390, 0.450, 0.511, 0.571, 0.629, 0.689};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.113, 0.125, 0.127, 0.114, 0.107, 0.109, 0.088, 0.072, 0.055, 0.044, 0.031, 0.003};
  Double_t Error_EvFrac[NN] = {0.0}; 

  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.5);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}



TGraphErrors *Data_CMS_Aj_Pt_180_220_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  const Int_t NN = 13 ;

  Double_t AJ[NN] = {0.028, 0.089, 0.154, 0.210, 0.271, 0.331, 0.388, 0.448, 0.513, 0.570, 0.630, 0.691, 0.752};
  Double_t Error_AJ[NN] = {0.0};
  
  Double_t EvFrac[NN] = {0.115, 0.136, 0.149, 0.125, 0.115, 0.089, 0.084, 0.059, 0.050, 0.029, 0.023, 0.009, 0.001};
  Double_t EvFrac_Max[NN] = {0.122, 0.143, 0.158, 0.130, 0.123, 0.094, 0.091, 0.065, 0.055, 0.033, 0.029, 0.015, 0.004};
  
  Double_t Error_EvFrac[NN] = {0.0}; 
  for(int i=0; i<NN; i++){Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i];}

  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.5);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}


TGraphErrors *Data_CMS_Aj_Pt_220_260_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  const Int_t NN = 13 ;

  Double_t AJ[NN] = {0.031, 0.091, 0.148, 0.204, 0.268, 0.329, 0.389, 0.450, 0.510, 0.562, 0.631, 0.687, 0.750};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.174, 0.136, 0.164, 0.125, 0.108, 0.074, 0.055, 0.047, 0.040, 0.029, 0.012, 0.001, 0.005};
  Double_t EvFrac_Max[NN] = {0.194, 0.155, 0.181, 0.139, 0.122, 0.085, 0.068, 0.059, 0.048, 0.033, 0.016, 0.006, 0.011};

  Double_t Error_EvFrac[NN] = {0.0}; 
  for(int i=0; i<NN; i++){Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i];}
  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.5);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}


TGraphErrors *Data_CMS_Aj_Pt_260_300_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  const Int_t NN = 14 ;

  Double_t AJ[NN] = {0.034, 0.095, 0.154, 0.209, 0.273, 0.333, 0.389, 0.449, 0.509, 0.568, 0.628, 0.684, 0.748, 0.804};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.155, 0.207, 0.182, 0.108, 0.077, 0.085, 0.046, 0.041, 0.041, 0.017, 0.006, 0.002, 0.002, 0.002};
  Double_t EvFrac_Max[NN] = {0.184, 0.238, 0.211, 0.128, 0.093, 0.106, 0.060, 0.056, 0.056, 0.027, 0.014, 0.008, 0.008, 0.008};

  Double_t Error_EvFrac[NN] = {0.0}; 
  for(int i=0; i<NN; i++){Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i];}
  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.5);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}



TGraphErrors *Data_CMS_Aj_Pt_300_500_276TeV()
{
  // CMS Jet momentum dependence of jet quenching in PbPb collisions at 2.76 TeV
  //1202.5022
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  
  const Int_t NN = 13 ;

  Double_t AJ[NN] = {0.030, 0.086, 0.151, 0.208, 0.269, 0.330, 0.389, 0.449, 0.508, 0.569, 0.632, 0.691, 0.751};
  Double_t Error_AJ[NN] = {0.0};

  Double_t EvFrac[NN] = {0.228, 0.179, 0.168, 0.119, 0.119, 0.039, 0.030, 0.030, 0.021, 0.021, 0.020, 0.010, 0.008};
  Double_t EvFrac_Max[NN] = {0.277, 0.222, 0.212, 0.154, 0.154, 0.060, 0.047, 0.047, 0.033, 0.033, 0.035, 0.021, 0.021};

  Double_t Error_EvFrac[NN] = {0.0}; 
  for(int i=0; i<NN; i++){Error_EvFrac[i] = EvFrac_Max[i] - EvFrac[i];}
  
  TGraphErrors *grf_local = new TGraphErrors(NN, AJ, EvFrac, Error_AJ, Error_EvFrac);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);

  grf_local->GetXaxis()->SetTitle("A_{J}");
  grf_local->GetYaxis()->SetTitle("Event Fraction");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(0.0,0.5);
  grf_local->GetXaxis()->SetLimits(0.0,1.0);
  
  return grf_local;
			  
}




//////////////////////////////////////////////////////////////////////////////////////////////////
// =============================== ATLAS Data Jet RAA 2.76 TeV =================================// 
//////////////////////////////////////////////////////////////////////////////////////////////////


// Rapidity : 0.0 - 2.1 and Centrality : 0 - 10 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_zero_ten()
{
  int N_point         = 9 ;
  double pT[15]       = {56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0, 283.5, 357.0 }; 
  double pT_err[15]   = {6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0, 32.5, 41.0 } ;
  double raa[15]      = {0.472, 0.491, 0.453, 0.478, 0.511, 0.565, 0.598, 0.595, 0.563 } ;
  double stat_err[15] = {0.011799999999999998, 0.010802, 0.008154, 0.007647999999999999, 0.008176000000000001,
			 0.0113, 0.017342, 0.031534999999999994, 0.053485 };
  double syst_err[15] = {0.05435587740070064, 0.08343822336315654, 0.06473622013988768, 0.052501723552660626,
			 0.05534391863610671, 0.06402723990615243, 0.07539070218534909, 0.09135526996293097,
			 0.13564678562354507 };
  
  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);
  
  return gr_data ;

}


// Rapidity : 0.0 - 2.1 and Centrality : 10 - 20 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_ten_twenty()
{
  int N_point         = 8 ;
  double pT[15]       = {56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0, 283.5 }; 
  double pT_err[15]   = {6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0, 32.5 };
  double raa[15]      = {0.525, 0.529, 0.496, 0.543, 0.58, 0.651, 0.653, 0.657 }; 
  double stat_err[15] = {0.0126, 0.013754000000000002, 0.008928, 0.008688000000000001, 0.009859999999999999,
			 0.014322000000000001, 0.022202, 0.040077 };
  double syst_err[15] = {0.07913406346195044, 0.07710708064762925, 0.04466754705600028, 0.0552073737194589,
			 0.05947475094525406, 0.0699484277521661, 0.0784823419948717, 0.10211014442747597 };
  
  
  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);
  return gr_data ;

}


// Rapidity : 0.0 - 2.1 and Centrality : 20 - 30 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_twenty_thirty()
{
  int N_point         =  8 ;
  double pT[15]       = {56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0, 283.5 };
  double pT_err[15]   = {6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0, 32.5 };
  double raa[15]      = {0.525, 0.612, 0.569, 0.603, 0.646, 0.668, 0.678, 0.693 };
  double stat_err[15] = {0.0105, 0.011016, 0.008535, 0.007839, 0.010336000000000001, 0.014696, 0.025764000000000002,
			 0.043658999999999996 };
  double syst_err[15] = {0.04394033596821945, 0.04984325783894949, 0.052726992205131516, 0.05972135866672828,
			 0.06435405180717063, 0.07073864527964895, 0.07955745719918404, 0.09429384914192442 };
  
  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);

  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);

  return gr_data ;

}


// Rapidity : 0.0 - 2.1 and Centrality : 30 - 40 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_thirty_forty()
{
  int N_point         = 9 ;
  double pT[15]       = {44.5, 56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0, 283.5 };
  double pT_err[15]   = {5.5, 6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0, 32.5 };
  double raa[15]      = {0.542, 0.636, 0.676, 0.646, 0.676, 0.726, 0.768, 0.781, 0.786 } ;
  double stat_err[15] = {0.01084, 0.010812, 0.012168000000000002, 0.008398000000000001, 0.008788,
			 0.011616000000000001, 0.019200000000000002, 0.032021, 0.049518 };
  double syst_err[15] = {0.050102029699404395, 0.052299158234143696, 0.06069712111789158, 0.05365690155049955,
			 0.05949952161152222, 0.06826330577989904, 0.08064, 0.09072047052898259,
			 0.10676299077864015 };

  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);
  
  return gr_data ;

}


// Rapidity : 0.0 - 2.1 and Centrality : 40 - 50 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_forty_fifty()
{
  int N_point         = 9 ;
  double pT[15]       = {44.5, 56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0, 283.5 } ;
  double pT_err[15]   = {5.5, 6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0, 32.5 } ;
  double raa[15]      = {0.633, 0.707, 0.747, 0.716, 0.745, 0.776, 0.766, 0.725, 0.679 } ;
  double stat_err[15] = {0.01266, 0.013432999999999999, 0.013446, 0.01074, 0.011175000000000001, 0.01552,
			 0.024512000000000003, 0.041325, 0.061789000000000004 };
  double syst_err[15] = {0.058046479660699486, 0.05817196687408807, 0.06816144756385387, 0.060733515623583,
			 0.06801160452452214, 0.07559132267661416, 0.08290512519742071, 0.10722649509333035,
			 0.11789403304238939 };;

  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);
  
  return gr_data ;

}


// Rapidity : 0.0 - 2.1 and Centrality : 50 - 60 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_fifty_sixty()
{
  int N_point         = 9 ;
  double pT[15]       = {44.5, 56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0, 283.5 };
  double pT_err[15]   = {5.5, 6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0, 32.5 };
  double raa[15]      = {0.696, 0.762, 0.797, 0.756, 0.818, 0.809, 0.759, 0.677, 0.623 };
  double stat_err[15] = {0.015312, 0.016764, 0.017534, 0.013608, 0.015541999999999999, 0.021843, 0.033396,
			 0.05348300000000001, 0.081613 };
  double syst_err[15] = {0.07291077549992181, 0.06435630234872106, 0.0687132337836024, 0.06296622294532203,
			 0.07997178997621598, 0.08381255617746067, 0.09553154035186497, 0.12123026731802583,
			 0.1683506930131266 };

  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);

  return gr_data ;

}



// Rapidity : 0.0 - 2.1 and Centrality : 60 - 70 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_sixty_seventy()
{
  int N_point         = 8 ;
  double pT[15]       = {44.5, 56.5, 71.0, 89.5, 112.5, 141.5, 178.5, 225.0 } ;
  double pT_err[15]   = {5.5, 6.5, 8.0, 10.5, 12.5, 16.5, 20.5, 26.0 } ;
  double raa[15]      = {0.762, 0.773, 0.806, 0.791, 0.809, 0.825, 0.812, 0.768 } ;
  double stat_err[15] = {0.017526, 0.018552, 0.017732000000000005, 0.016611, 0.020225, 0.030525000000000004,
			 0.049532, 0.077568 };
  double syst_err[15] = {0.0842587336007372, 0.06169489225211436, 0.06025624950160772, 0.0649680231036777,
			 0.08105356425228935, 0.08651886355009525, 0.0994559132882505, 0.13203794072917072 };

  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);
  return gr_data ;

}



// Rapidity : 0.0 - 2.1 and Centrality : 70 - 80 % 
TGraphErrors *jet_atlas_raa_pbpb_276tev_00_rapidity_21_centrality_seventy_eighty()
{
  int N_point         =  7 ;
  double pT[15]       = {44.5, 56.5, 71.0, 89.5, 112.5, 141.5, 178.5 } ;
  double pT_err[15]   = {5.5, 6.5, 8.0, 10.5, 12.5, 16.5, 20.5 } ;
  double raa[15]      = {0.823, 0.795, 0.812, 0.809, 0.814, 0.819, 0.801 } ;
  double stat_err[15] = {0.024689999999999997, 0.026235, 0.023548, 0.02427, 0.030931999999999998,
			 0.047501999999999996, 0.078498 };
  double syst_err[15] = {0.10341675352668928, 0.07952384642357285, 0.07091415012534523, 0.06899304539589479,
			 0.08790069371739907, 0.09622465819113102, 0.11634094161558088 };

  for(int i=0; i<N_point; i++){
    stat_err[i] = sqrt(stat_err[i]*stat_err[i] + syst_err[i]*syst_err[i]);
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, raa, pT_err, stat_err);
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,400.0);
  
  return gr_data ;

}



//=================== ATLAS 5 TeV Jet RAA ===============================//




TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_zero0_ten10()
{
  int N_point               = 15 ;
  double pT[20]             = {1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,1.495000e+02 ,1.675000e+02 ,
			       1.880000e+02 ,2.110000e+02 ,2.370000e+02 ,2.660000e+02 ,2.985000e+02 ,
			       3.350000e+02 ,3.760000e+02 ,4.495000e+02 ,5.655000e+02 ,8.145000e+02 } ;
  double pT_err_minus[20]   = {6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,9.500000e+00 ,
			       1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,1.500000e+01 ,1.750000e+01 ,
			       1.900000e+01 ,2.200000e+01 ,5.150000e+01 ,6.450000e+01 ,1.845000e+02 } ;
  double pT_err_plus[20]    = {6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,9.500000e+00 ,
			       1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,1.500000e+01 ,1.750000e+01 ,
			       1.900000e+01 ,2.200000e+01 ,5.150000e+01 ,6.450000e+01 ,1.845000e+02 } ;
  double RAA[20]            = {4.381000e-01 ,4.633000e-01 ,4.847000e-01 ,5.023000e-01 ,5.151000e-01 ,
			       5.350000e-01 ,5.570000e-01 ,5.720000e-01 ,5.610000e-01 ,5.630000e-01 ,
			       5.890000e-01 ,5.890000e-01 ,5.930000e-01 ,5.600000e-01 ,6.200000e-01 } ;
  double stat_err_minus[20] = {1.679613e-02 ,1.733522e-02 ,1.784124e-02 ,1.797081e-02 ,1.779522e-02 ,
			       1.832184e-02 ,2.043747e-02 ,2.169539e-02 ,2.242075e-02 ,2.378424e-02 ,
			       2.845505e-02 ,3.459321e-02 ,3.759907e-02 ,6.461958e-02 ,1.617890e-01 } ;
  double stat_err_plus[20]  = {1.714235e-02 ,1.740402e-02 ,1.763576e-02 ,1.777020e-02 ,1.779522e-02 ,
			       1.832184e-02 ,2.043747e-02 ,2.169539e-02 ,2.242075e-02 ,2.378424e-02 ,
			       2.845505e-02 ,3.459321e-02 ,3.759907e-02 ,6.461958e-02 ,1.617890e-01 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);

  return gr_data ; 
  
}


TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_ten10_twenty20()     
{
  int N_point               =  12 ;
  double pT[20]             = {1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,1.495000e+02 ,1.675000e+02 ,
			       1.880000e+02 ,2.110000e+02 ,2.370000e+02 ,2.660000e+02 ,2.985000e+02 ,
			       3.570000e+02 ,5.140000e+02 } ;
  double pT_err_minus[20]   = {6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,9.500000e+00 ,
			       1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,1.500000e+01 ,1.750000e+01 ,
			       4.100000e+01 ,1.160000e+02 } ;
  double pT_err_plus[20]    = {6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,9.500000e+00 ,
			       1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,1.500000e+01 ,1.750000e+01 ,
			       4.100000e+01 ,1.160000e+02 } ;
  double RAA[20]            = {5.047000e-01 ,5.279000e-01 ,5.506000e-01 ,5.702000e-01 ,5.860000e-01 ,
			       5.950000e-01 ,6.140000e-01 ,6.500000e-01 ,6.480000e-01 ,6.400000e-01 ,
			       6.820000e-01 ,6.600000e-01 } ;
  double stat_err_minus[20] = {1.929093e-02 ,1.950359e-02 ,1.986706e-02 ,2.004969e-02 ,2.023092e-02 ,
			       2.045214e-02 ,2.180115e-02 ,2.392258e-02 ,2.520496e-02 ,2.793367e-02 ,
			       3.074557e-02 ,4.417341e-02 } ;
  double stat_err_plus[20]  = {1.923408e-02 ,1.933753e-02 ,1.975601e-02 ,1.999550e-02 ,2.023092e-02 ,
			       2.045214e-02 ,2.180115e-02 ,2.392258e-02 ,2.520496e-02 ,2.793367e-02 ,
			       3.074557e-02 ,4.417341e-02 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
   gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);
  return gr_data ; 

}

TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_twenty20_thirty30()  
{
  int N_point               =  14 ;
  double pT[20]             = {8.400000e+01 ,9.450000e+01 ,1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,
			       1.495000e+02 ,1.675000e+02 ,1.880000e+02 ,2.110000e+02 ,2.370000e+02 ,
			       2.660000e+02 ,2.985000e+02 ,3.570000e+02 ,5.140000e+02 } ;
  double pT_err_minus[20]   = {5.000000e+00 ,5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,
			       8.500000e+00 ,9.500000e+00 ,1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,
			       1.500000e+01 ,1.750000e+01 ,4.100000e+01 ,1.160000e+02 } ;
  double pT_err_plus[20]    = {5.000000e+00 ,5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,
			       8.500000e+00 ,9.500000e+00 ,1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,
			       1.500000e+01 ,1.750000e+01 ,4.100000e+01 ,1.160000e+02 } ;
  double RAA[20]            = {5.380000e-01 ,5.620000e-01 ,5.769000e-01 ,5.980000e-01 ,6.170000e-01 ,
			       6.270000e-01 ,6.450000e-01 ,6.710000e-01 ,6.830000e-01 ,7.020000e-01 ,
			       7.230000e-01 ,7.480000e-01 ,7.170000e-01 ,8.000000e-01 } ;
  double stat_err_minus[20] = {2.508007e-02 ,2.549529e-02 ,2.524837e-02 ,2.539705e-02 ,2.539705e-02 ,
			       2.594244e-02 ,2.594244e-02 ,2.687024e-02 ,2.783900e-02 ,2.941105e-02 ,
			       3.162293e-02 ,3.602791e-02 ,3.870413e-02 ,5.834389e-02 } ;
  double stat_err_plus[20]  = {2.508007e-02 ,2.549529e-02 ,2.528774e-02 ,2.539705e-02 ,2.539705e-02 ,
			       2.557362e-02 ,2.594244e-02 ,2.687024e-02 ,2.783900e-02 ,2.941105e-02 ,
			       3.162293e-02 ,3.602791e-02 ,3.837981e-02 ,5.834389e-02 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);



  return gr_data ; 

}

TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_thirty30_forty40()   
{
  int N_point               =  13 ;
  double pT[20]             = {8.400000e+01 ,9.450000e+01 ,1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,
			       1.495000e+02 ,1.675000e+02 ,1.880000e+02 ,2.110000e+02 ,2.370000e+02 ,
			       2.835000e+02 ,3.570000e+02 ,5.140000e+02 } ;
  double pT_err_minus[20]   = {5.000000e+00 ,5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,
			       8.500000e+00 ,9.500000e+00 ,1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,
			       3.250000e+01 ,4.100000e+01 ,1.160000e+02 } ;
  double pT_err_plus[20]    = {5.000000e+00 ,5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,
			       8.500000e+00 ,9.500000e+00 ,1.100000e+01 ,1.200000e+01 ,1.400000e+01 ,
			       3.250000e+01 ,4.100000e+01 ,1.160000e+02 } ;
  double RAA[20]            = {6.060000e-01 ,6.200000e-01 ,6.470000e-01 ,6.720000e-01 ,6.920000e-01 ,
			       7.110000e-01 ,7.250000e-01 ,7.370000e-01 ,7.540000e-01 ,7.820000e-01 ,
			       7.780000e-01 ,7.600000e-01 ,7.400000e-01 } ;
  double stat_err_minus[20] = {3.422704e-02 ,3.441642e-02 ,3.415392e-02 ,3.489255e-02 ,3.489255e-02 ,
			       3.519219e-02 ,3.537640e-02 ,3.606231e-02 ,3.731608e-02 ,3.945238e-02 ,
			       3.965463e-02 ,5.236879e-02 ,7.773345e-02 } ;
  double stat_err_plus[20]  = {3.444546e-02 ,3.463365e-02 ,3.415392e-02 ,3.464809e-02 ,3.464809e-02 ,
			       3.519219e-02 ,3.537640e-02 ,3.606231e-02 ,3.731608e-02 ,3.945238e-02 ,
			       3.965463e-02 ,5.236879e-02 ,7.773345e-02 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);


  return gr_data ; 

}

TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_forty40_fifty50()    
{
  int N_point               =  14 ;
  double pT[20]             = {5.300000e+01 ,5.950000e+01 ,6.650000e+01 ,7.450000e+01 ,8.400000e+01 ,
			       9.450000e+01 ,1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,1.495000e+02 ,
			       1.675000e+02 ,1.880000e+02 ,2.250000e+02 ,3.245000e+02 } ;
  double pT_err_minus[20]   = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 ,7.350000e+01 } ;
  double pT_err_plus[20]    = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 ,7.350000e+01 } ;
  double RAA[20]            = {6.120000e-01 ,6.400000e-01 ,6.610000e-01 ,6.820000e-01 ,7.020000e-01 ,
			       7.330000e-01 ,7.380000e-01 ,7.440000e-01 ,7.660000e-01 ,7.840000e-01 ,
			       7.760000e-01 ,8.010000e-01 ,8.360000e-01 ,8.480000e-01 } ;
  double stat_err_minus[20] = {4.932839e-02 ,4.689659e-02 ,4.674709e-02 ,4.666144e-02 ,4.661856e-02 ,
			       4.713056e-02 ,4.617673e-02 ,4.617673e-02 ,4.648968e-02 ,4.683257e-02 ,
			       4.703499e-02 ,4.794048e-02 ,4.821089e-02 ,5.154891e-02 } ;
  double stat_err_plus[20]  = {4.851072e-02 ,4.660783e-02 ,4.674709e-02 ,4.666144e-02 ,4.682190e-02 ,
			       4.713056e-02 ,4.636044e-02 ,4.617673e-02 ,4.648968e-02 ,4.667215e-02 ,
			       4.703499e-02 ,4.794048e-02 ,4.821089e-02 ,5.169420e-02 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);

  return gr_data ; 

}

TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_fifty50_sixty60()    
{
  int N_point               =  14 ;
  double pT[20]             = {5.300000e+01 ,5.950000e+01 ,6.650000e+01 ,7.450000e+01 ,8.400000e+01 ,
			       9.450000e+01 ,1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,1.495000e+02 ,
			       1.675000e+02 ,1.880000e+02 ,2.250000e+02 ,3.245000e+02 } ;
  double pT_err_minus[20]   = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 ,7.350000e+01 } ;
  double pT_err_plus[20]    = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 ,7.350000e+01 } ;
  double RAA[20]            = {7.020000e-01 ,7.230000e-01 ,7.500000e-01 ,7.810000e-01 ,7.910000e-01 ,
			       7.930000e-01 ,8.020000e-01 ,8.150000e-01 ,8.500000e-01 ,8.620000e-01 ,
			       8.600000e-01 ,8.730000e-01 ,8.840000e-01 ,9.600000e-01 } ;
  double stat_err_minus[20] = {6.460193e-02 ,6.400320e-02 ,6.347763e-02 ,6.217242e-02 ,6.163124e-02 ,
			       6.204361e-02 ,6.069110e-02 ,6.103614e-02 ,6.286820e-02 ,6.204361e-02 ,
			       6.246127e-02 ,6.390156e-02 ,6.376841e-02 ,7.316017e-02 } ;
  double stat_err_plus[20]  = {6.423714e-02 ,6.400320e-02 ,6.347763e-02 ,6.217242e-02 ,6.163124e-02 ,
			       6.204361e-02 ,6.078166e-02 ,6.103614e-02 ,6.286820e-02 ,6.172852e-02 ,
			       6.234108e-02 ,6.390156e-02 ,6.376841e-02 ,7.316017e-02 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);


  return gr_data ; 

}

TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_sixty60_seventy70()  
{
  int N_point               =  14 ;
  double pT[20]             = {5.300000e+01 ,5.950000e+01 ,6.650000e+01 ,7.450000e+01 ,8.400000e+01 ,
			       9.450000e+01 ,1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,1.495000e+02 ,
			       1.675000e+02 ,1.880000e+02 ,2.250000e+02 ,3.245000e+02 } ;
  double pT_err_minus[20]   = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 ,7.350000e+01 } ;
  double pT_err_plus[20]    = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 ,7.350000e+01 } ;
  double RAA[20]            = {7.820000e-01 ,8.190000e-01 ,8.280000e-01 ,8.330000e-01 ,8.610000e-01 ,
			       8.810000e-01 ,8.670000e-01 ,8.690000e-01 ,9.090000e-01 ,9.240000e-01 ,
			       8.740000e-01 ,8.570000e-01 ,9.180000e-01 ,8.600000e-01 } ;
  double stat_err_minus[20] = {8.313657e-02 ,8.216258e-02 ,8.169266e-02 ,8.158241e-02 ,8.182109e-02 ,
			       8.291978e-02 ,7.931387e-02 ,7.975393e-02 ,7.992303e-02 ,8.052136e-02 ,
			       8.124463e-02 ,8.279909e-02 ,8.459131e-02 ,9.338999e-02 } ;
  double stat_err_plus[20]  = {8.495110e-02 ,8.274473e-02 ,8.145361e-02 ,8.137991e-02 ,8.182109e-02 ,
			       8.299813e-02 ,7.939578e-02 ,7.955306e-02 ,7.972258e-02 ,8.052136e-02 ,
			       8.133689e-02 ,8.288963e-02 ,8.451444e-02 ,9.338999e-02 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);

  return gr_data ; 

}

TGraphErrors *jet_nuclear_modification_factor_raa_atlas_PbPb_502tev_cen_seventy70_eighty80() 
{
  int N_point               = 13 ;
  double pT[20]             = {5.300000e+01 ,5.950000e+01 ,6.650000e+01 ,7.450000e+01 ,8.400000e+01 ,
			       9.450000e+01 ,1.060000e+02 ,1.185000e+02 ,1.330000e+02 ,1.495000e+02 ,
			       1.675000e+02 ,1.880000e+02 ,2.250000e+02 } ;
  double pT_err_minus[20]   = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 } ;
  double pT_err_plus[20]    = {3.000000e+00 ,3.500000e+00 ,3.500000e+00 ,4.500000e+00 ,5.000000e+00 ,
			       5.500000e+00 ,6.000000e+00 ,6.500000e+00 ,8.000000e+00 ,8.500000e+00 ,
			       9.500000e+00 ,1.100000e+01 ,2.600000e+01 } ;
  double RAA[20]            = {8.210000e-01 ,8.530000e-01 ,8.750000e-01 ,8.600000e-01 ,8.570000e-01 ,
			       8.800000e-01 ,9.070000e-01 ,9.050000e-01 ,9.170000e-01 ,9.330000e-01 ,
			       9.260000e-01 ,9.000000e-01 ,9.600000e-01 } ;
  double stat_err_minus[20] = {1.024407e-01 ,1.013661e-01 ,1.012970e-01 ,1.021963e-01 ,1.033929e-01 ,
			       1.057454e-01 ,9.926273e-02 ,9.935336e-02 ,1.000554e-01 ,1.013464e-01 ,
			       1.034171e-01 ,1.057454e-01 ,1.099186e-01 } ;
  double stat_err_plus[20]  = {1.016026e-01 ,1.006980e-01 ,1.011142e-01 ,1.023674e-01 ,1.036826e-01 ,
			       1.057454e-01 ,9.889939e-02 ,9.925769e-02 ,9.995044e-02 ,1.012625e-01 ,
			       1.034171e-01 ,1.057454e-01 ,1.099186e-01 } ;

  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    
    pT_err[i]   = (pT_err_minus[i]   + pT_err_plus[i])/2.0  ;
    stat_err[i] = (stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }

  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, RAA, pT_err, stat_err) ;
  gr_data->SetMarkerColor(1);
  gr_data->SetMarkerStyle(21);
  gr_data->SetMarkerSize(1.5);
  gr_data->GetXaxis()->SetTitle("p_{T} GeV/c");
  gr_data->GetYaxis()->SetTitle("R_{AA}");
  gr_data->GetXaxis()->CenterTitle();
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetYaxis()->SetRangeUser(0.0,1.5);
  gr_data->GetXaxis()->SetLimits(0.0,500.0);



  return gr_data ; 

}




TGraphErrors *jet_production_atlas_yield_in_pp_collision_502tev()
{
  //  sigma_atlas_502tev  = sigma_atlas_502tev * pow(10.0, 6.0) ; // For convert mb to nb 
  
  int N_point               = 14 ;
  double pT[20]             = {4.500000e+01 ,5.650000e+01 ,7.100000e+01 ,8.950000e+01 ,1.130000e+02 ,
			       1.420000e+02 ,1.790000e+02 ,2.255000e+02 ,2.835000e+02 ,3.570000e+02 ,
			       4.495000e+02 ,5.660000e+02 ,7.155000e+02 ,9.000000e+02  } ;
  double pT_err_minus[20]   = {5.000000e+00 ,6.500000e+00 ,8.000000e+00 ,1.050000e+01 ,1.300000e+01 ,
			       1.600000e+01 ,2.100000e+01 ,2.550000e+01 ,3.250000e+01 ,4.100000e+01 ,
			       5.150000e+01 ,6.500000e+01 ,8.450000e+01 ,1.000000e+02  } ;
  double pT_err_plus[20]    = {5.000000e+00 ,6.500000e+00 ,8.000000e+00 ,1.050000e+01 ,1.300000e+01 ,
			       1.600000e+01 ,2.100000e+01 ,2.550000e+01 ,3.250000e+01 ,4.100000e+01 ,
			       5.150000e+01 ,6.500000e+01 ,8.450000e+01 ,1.000000e+02  } ;
  double yield[20]          = {1.361100e+02 ,4.362000e+01 ,1.374900e+01 ,4.051000e+00 ,1.154300e+00 ,
			       3.131000e-01 ,8.267000e-02 ,2.019000e-02 ,4.644000e-03 ,9.610000e-04 ,
			       1.850000e-04 ,3.610000e-05 ,4.500000e-06 ,4.800000e-07  } ;
  double stat_err_minus[20] = {2.131543e+01 ,5.729302e+00 ,1.627702e+00 ,4.307865e-01 ,1.187099e-01 ,
			       2.999033e-02 ,7.973544e-03 ,1.850432e-03 ,4.265993e-04 ,8.832327e-05 ,
			       1.772005e-05 ,3.781534e-06 ,7.141428e-07 ,1.489966e-07  } ;
  double stat_err_plus[20]  = {2.238793e+01 ,6.016444e+00 ,1.684001e+00 ,4.455581e-01 ,1.211684e-01 ,
			       3.106944e-02 ,8.042207e-03 ,1.879787e-03 ,4.314881e-04 ,8.929726e-05 ,
			       1.868154e-05 ,3.871692e-06 ,7.874008e-07 ,1.489966e-07  } ;
  
  double pT_err[20], stat_err[20] ;
  for(int i=0; i<N_point; i++){
    yield[i]          = yield[i]/sigma_atlas_502tev ;
    stat_err_minus[i] = stat_err_minus[i]/sigma_atlas_502tev ;
    stat_err_plus[i]  = stat_err_plus[i]/sigma_atlas_502tev  ;

    pT_err[i]   = (pT_err_minus[i]    + pT_err_plus[i])/2.0 ;
    stat_err[i] = ( stat_err_minus[i] + stat_err_plus[i])/2.0 ;
  }
    
  TGraphErrors *gr_data = new TGraphErrors(N_point, pT, yield, pT_err, stat_err) ;
  gr_data->SetMarkerColor(2) ;
  gr_data->SetMarkerStyle(20) ;
  //  gr_data->SetMarkerSize(2) ;

  return gr_data ; 

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




