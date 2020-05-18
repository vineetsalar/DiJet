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
#include "TGraphAsymmErrors.h"
//#include "TGraphMultiErrors.h" only works for root6.20 or more
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
const Double_t sigma_atlas_502tev  = 67.6 * pow(10.0, 6.0);  // (nb) 1710.07098
//sigma_atlas_502tev  = sigma_atlas_502tev * pow(10.0, 6.0) ;

const Double_t Am = 208.0 ;
const Double_t R0 = 1.1;
const Double_t RA = R0*pow(Am, 1.0/3.0);




























//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++   CMS Data Functions for XJ (Gamma+Jet) +++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

TGraphAsymmErrors *Data_CMS_XJ_GammaJet_Cent_00_10_276TeV()
{

  // CMS jet quenching using isolated-photon + jet correlations in PbPb collisions at 2.76 TeV
  //Published in Phys.Lett. B718 (2013) 773-794
  //CMS-HIN-11-010, CERN-PH-EP-2012-089
  //DOI: 10.1016/j.physletb.2012.11.003
  //e-Print: arXiv:1205.0206 [nucl-ex] | PDF
  //cat Data_Aj_Cent_00_10.txt | awk '{printf "%.3f, ", $1}'
  //https://unix.stackexchange.com/questions/26723/print-odd-numbered-lines-print-even-numbered-lines
  //sed -n 1~2p filename | awk '{printf "%.3f, ", $2}' // print odd number of lines
  //sed -n 2~2p filename | awk '{printf "%.3f, ", $2}' // print even number of lines
  
  const Int_t NN = 15 ;
  Double_t XJ[NN] = {0.200, 0.330, 0.466, 0.584, 0.706, 0.820, 0.959, 1.071, 1.187, 1.317, 1.432, 1.563, 1.693, 1.809, 1.926};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.079, 0.041, 1.456, 1.717, 1.516, 0.835, 1.394, 0.433, 0.367, 0.262, 0.014, 0.015, 0.074, -0.012, 0.086};
  Double_t EvFrac_Max[NN] = {0.127, 0.138, 1.764, 2.015, 1.795, 1.046, 1.615, 0.606, 0.521, 0.368, 0.071, 0.053, 0.112, 0.017, 0.124};
  Double_t EvFrac_Min[NN] = {0.021, -0.093, 1.196, 1.438, 1.257, 0.623, 1.134, 0.241, 0.223, 0.147, -0.063, -0.053, -0.013, -0.060, 0.028};

  Double_t Error_EvFrac_High[NN] = {0.0}; 
  Double_t Error_EvFrac_Low[NN] = {0.0};
  
  for(int i=0; i<NN; i++){Error_EvFrac_High[i] = EvFrac_Max[i] - EvFrac[i]; Error_EvFrac_Low[i] =  EvFrac[i] - EvFrac_Min[i]; }

  //auto gr = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_GammaJet_Cent_00_10_276TeV()
{
  const Int_t NN = 15 ;
  Double_t XJ[NN] = {0.200, 0.330, 0.466, 0.584, 0.706, 0.820, 0.959, 1.071, 1.187, 1.317, 1.432, 1.563, 1.693, 1.809, 1.926};
  const Double_t XError_Syst = 0.025; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}
  Double_t EvFrac[NN] = {0.079, 0.041, 1.456, 1.717, 1.516, 0.835, 1.394, 0.433, 0.367, 0.262, 0.014, 0.015, 0.074, -0.012, 0.086};
  Double_t EvFracSyst_Max[NN] = {0.108, 0.070, 1.937, 2.140, 1.795, 0.960, 1.595, 0.510, 0.463, 0.330, 0.042, 0.034, 0.093, 0.008, 0.124};
  Double_t EvFracSyst_Min[NN] = {0.040, -0.007, 1.024, 1.313, 1.247, 0.719, 1.172, 0.337, 0.290, 0.176, -0.025, -0.024, 0.016, -0.060, 0.028};
  Double_t SystError_EvFrac_High[NN] = {0.0}; 
  Double_t SystError_EvFrac_Low[NN] = {0.0};
  for(int i=0; i<NN; i++){SystError_EvFrac_High[i] = EvFracSyst_Max[i] - EvFrac[i]; SystError_EvFrac_Low[i] =  EvFrac[i] - EvFracSyst_Min[i]; }
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}


TGraphAsymmErrors *Data_CMS_XJ_GammaJet_Cent_10_30_276TeV()
{

  
  const Int_t NN =  13;
  Double_t XJ[NN] = {0.177, 0.308, 0.430, 0.555, 0.674, 0.800, 0.935, 1.056, 1.191, 1.310, 1.436, 1.562, 1.702};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.027, 0.420, 1.342, 1.456, 1.465, 1.444, 0.962, 0.538, 0.056, 0.045, 0.092, 0.014, -0.016};
  Double_t EvFrac_Max[NN] = {0.075, 0.526, 1.554, 1.687, 1.695, 1.636, 1.135, 0.682, 0.142, 0.151, 0.159, 0.081, 0.022};
  Double_t EvFrac_Min[NN] = {-0.002, 0.305, 1.121, 1.225, 1.243, 1.223, 0.770, 0.384, -0.040, -0.080, 0.005, -0.044, -0.074};

  Double_t Error_EvFrac_High[NN] = {0.0}; 
  Double_t Error_EvFrac_Low[NN] = {0.0};
  
  for(int i=0; i<NN; i++){Error_EvFrac_High[i] = EvFrac_Max[i] - EvFrac[i]; Error_EvFrac_Low[i] =  EvFrac[i] - EvFrac_Min[i]; }

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_GammaJet_Cent_10_30_276TeV()
{
  const Int_t NN = 13;
  Double_t XJ[NN] = {0.177, 0.308, 0.430, 0.555, 0.674, 0.800, 0.935, 1.056, 1.191, 1.310, 1.436, 1.562, 1.702};
  const Double_t XError_Syst = 0.025; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}

  Double_t EvFrac[NN] = {0.027, 0.420, 1.342, 1.456, 1.465, 1.444, 0.962, 0.538, 0.056, 0.045, 0.092, 0.014, -0.016};
  Double_t EvFracSyst_Max[NN] = {0.085, 0.564, 1.746, 1.793, 1.715, 1.636, 1.097, 0.634, 0.085, 0.074, 0.121, 0.052, 0.012};
  Double_t EvFracSyst_Min[NN] = {-0.002, 0.266, 0.948, 1.120, 1.205, 1.223, 0.799, 0.422, 0.017, -0.003, 0.034, -0.015, -0.045};
  Double_t SystError_EvFrac_High[NN] = {0.0}; 
  Double_t SystError_EvFrac_Low[NN] = {0.0};
  for(int i=0; i<NN; i++){SystError_EvFrac_High[i] = EvFracSyst_Max[i] - EvFrac[i]; SystError_EvFrac_Low[i] =  EvFrac[i] - EvFracSyst_Min[i]; }
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}


TGraphAsymmErrors *Data_CMS_XJ_GammaJet_Cent_30_50_276TeV()
{

  
  const Int_t NN =  14;
  Double_t XJ[NN] = {0.181, 0.312, 0.431, 0.562, 0.681, 0.806, 0.931, 1.049, 1.187, 1.306, 1.444, 1.562, 1.826, 1.931};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.061, 0.070, 0.777, 1.283, 1.322, 1.283, 1.322, 1.341, 0.137, 0.385, -0.035, 0.089, 0.061, -0.045};
  Double_t EvFrac_Max[NN] = {0.118, 0.156, 1.025, 1.608, 1.637, 1.637, 1.656, 1.666, 0.299, 0.576, 0.089, 0.166, 0.127, 0.013};
  Double_t EvFrac_Min[NN] = {0.003, -0.035, 0.500, 0.930, 0.997, 0.959, 1.025, 1.006, -0.016, 0.185, -0.150, -0.025, 0.013, -0.102};

  Double_t Error_EvFrac_High[NN] = {0.0}; 
  Double_t Error_EvFrac_Low[NN] = {0.0};
  
  for(int i=0; i<NN; i++){Error_EvFrac_High[i] = EvFrac_Max[i] - EvFrac[i]; Error_EvFrac_Low[i] =  EvFrac[i] - EvFrac_Min[i]; }

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_GammaJet_Cent_30_50_276TeV()
{
  const Int_t NN = 14;
  Double_t XJ[NN] = {0.181, 0.312, 0.431, 0.562, 0.681, 0.806, 0.931, 1.049, 1.187, 1.306, 1.444, 1.562, 1.826, 1.931};
  const Double_t XError_Syst = 0.025; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}

  Double_t EvFrac[NN] = {0.061, 0.070, 0.777, 1.283, 1.322, 1.283, 1.322, 1.341, 0.137, 0.385, -0.035, 0.089, 0.061, -0.045};
  Double_t EvFracSyst_Max[NN] = {0.099, 0.108, 0.920, 1.455, 1.484, 1.484, 1.599, 1.694, 0.194, 0.538, 0.003, 0.118, 0.108, -0.006};
  Double_t EvFracSyst_Min[NN] = {0.022, 0.022, 0.615, 1.083, 1.150, 1.102, 1.064, 0.978, 0.089, 0.223, -0.073, 0.032, 0.003, -0.092};
  Double_t SystError_EvFrac_High[NN] = {0.0}; 
  Double_t SystError_EvFrac_Low[NN] = {0.0};
  for(int i=0; i<NN; i++){SystError_EvFrac_High[i] = EvFracSyst_Max[i] - EvFrac[i]; SystError_EvFrac_Low[i] =  EvFrac[i] - EvFracSyst_Min[i]; }
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}


TGraphAsymmErrors *Data_CMS_XJ_GammaJet_Cent_50_100_276TeV()
{

  
  const Int_t NN = 8;
  Double_t XJ[NN] = {0.305, 0.508, 0.704, 0.902, 1.103, 1.302, 1.501, 1.702};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.245, 1.627, 1.375, 0.609, 0.689, 0.451, 0.098, 0.053};
  Double_t EvFrac_Max[NN] = {0.379, 2.007, 1.722, 0.926, 0.958, 0.672, 0.185, 0.140};
  Double_t EvFrac_Min[NN] = {0.100, 1.238, 1.029, 0.292, 0.429, 0.230, 0.031, -0.062};

  Double_t Error_EvFrac_High[NN] = {0.0}; 
  Double_t Error_EvFrac_Low[NN] = {0.0};
  
  for(int i=0; i<NN; i++){Error_EvFrac_High[i] = EvFrac_Max[i] - EvFrac[i]; Error_EvFrac_Low[i] =  EvFrac[i] - EvFrac_Min[i]; }

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_GammaJet_Cent_50_100_276TeV()
{
  const Int_t NN = 8;
  Double_t XJ[NN] = {0.305, 0.508, 0.704, 0.902, 1.103, 1.302, 1.501, 1.702};
  const Double_t XError_Syst = 0.025; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}

  Double_t EvFrac[NN] = {0.245, 1.627, 1.375, 0.609, 0.689, 0.451, 0.098, 0.053};
  Double_t EvFracSyst_Max[NN] = {0.283, 1.834, 1.577, 0.724, 0.872, 0.605, 0.147, 0.082};
  Double_t EvFracSyst_Min[NN] = {0.197, 1.421, 1.174, 0.484, 0.516, 0.297, 0.070, 0.005};
  Double_t SystError_EvFrac_High[NN] = {0.0}; 
  Double_t SystError_EvFrac_Low[NN] = {0.0};
  for(int i=0; i<NN; i++){SystError_EvFrac_High[i] = EvFracSyst_Max[i] - EvFrac[i]; SystError_EvFrac_Low[i] =  EvFrac[i] - EvFracSyst_Min[i]; }
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}


TGraphAsymmErrors *Data_CMS_XJ_GammaJet_PP_276TeV()
{

  
  const Int_t NN =  8;
  Double_t XJ[NN] = {0.306, 0.508, 0.703, 0.903, 1.105, 1.296, 1.502, 1.902};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.475, 0.728, 1.135, 0.955, 1.199, 0.615, 0.147, -0.098};
  Double_t EvFrac_Max[NN] = {0.802, 1.132, 1.664, 1.426, 1.881, 1.038, 0.387, 0.027};
  Double_t EvFrac_Min[NN] = {0.129, 0.334, 0.597, 0.292, 0.535, 0.192, -0.161, -0.165};

  Double_t Error_EvFrac_High[NN] = {0.0}; 
  Double_t Error_EvFrac_Low[NN] = {0.0};
  
  for(int i=0; i<NN; i++){Error_EvFrac_High[i] = EvFrac_Max[i] - EvFrac[i]; Error_EvFrac_Low[i] =  EvFrac[i] - EvFrac_Min[i]; }

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.5,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
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
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
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
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
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
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
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
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
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
  grf_local->GetYaxis()->SetRangeUser(0.0,0.32);
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

