#include "TH1F.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TGraphAsymmErrors.h"

const Double_t sigma_alice_276tev  = 62.8 ;  // (mb)
const Double_t sigma_atlas_502tev  = 67.6 * pow(10.0, 6.0);  // (nb) 1710.07098


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++   CMS Data Functions for XJ (Z0+Jet) 5 TeV +++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



TGraphAsymmErrors *Data_CMS_XJ_Z0Jet_Cent_00_30_502TeV()
{

  // Study of Jet Quenching with Z0 + jet Correlations in Pb-Pb and pp Collisions at 5.02 TeV
  //Published in Phys.Rev.Lett. 119 (2017) no.8, 082301
  //CMS-HIN-15-013, CERN-EP-2017-002
  //DOI: 10.1103/PhysRevLett.119.082301
  //e-Print: arXiv:1702.01060 [nucl-ex] | PDF
  
  const Int_t NN = 10 ;
  Double_t XJ[NN] = {0.100, 0.300, 0.500, 0.700, 0.900, 1.100, 1.300, 1.500, 1.700, 1.900};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.074, 0.29, 0.78, 0.58, 0.530, 0.240, 0.10, 0.057, 0.00, 0.00};
  Double_t Error_EvFrac_High[NN] = {0.056, 0.12, 0.15, 0.11, 0.11, 0.08, 0.05, 0.042, 0.0, 0.0}; 
  Double_t Error_EvFrac_Low[NN] = {0.056, 0.12, 0.15, 0.11, 0.11, 0.08, 0.05, 0.042, 0.0, 0.0};
  

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{jZ}=p_{T}^{jet}/p_{T}^{Z}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{Z}}#frac{dN_{jZ}}{dx_{jZ}}");
  grf_local->GetYaxis()->SetTitleOffset(1.45);
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.2,1.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_Z0Jet_Cent_00_30_502TeV()
{
  const Int_t NN = 10 ;
  Double_t XJ[NN] = {0.100, 0.300, 0.500, 0.700, 0.900, 1.100, 1.300, 1.500, 1.700, 1.900};
  const Double_t XError_Syst = 0.10; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}
  Double_t EvFrac[NN] = {0.074, 0.29, 0.78, 0.58, 0.530, 0.240, 0.10, 0.057, 0.00, 0.00};
  
  Double_t SystError_EvFrac_High[NN] = {0.009, 0.04, 0.08, 0.06, 0.07, 0.04, 0.02, 0.011, 0.0, 0.0}; 
  Double_t SystError_EvFrac_Low[NN] = {0.009, 0.04, 0.08, 0.06, 0.07, 0.04, 0.02, 0.011, 0.0, 0.0};
  
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{jZ}=p_{T}^{jet}/p_{T}^{Z}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{Z}}#frac{dN_{jZ}}{dx_{jZ}}");
  grf_local->GetYaxis()->SetTitleOffset(1.45);
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.2,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}



TGraphAsymmErrors *Data_CMS_XJ_Z0Jet_PP_502TeV()
{

  // Study of Jet Quenching with Z0 + jet Correlations in Pb-Pb and pp Collisions at 5.02 TeV
  //Published in Phys.Rev.Lett. 119 (2017) no.8, 082301
  //CMS-HIN-15-013, CERN-EP-2017-002
  //DOI: 10.1103/PhysRevLett.119.082301
  //e-Print: arXiv:1702.01060 [nucl-ex] | PDF
  
  const Int_t NN = 10 ;
  Double_t XJ[NN] = {0.100, 0.300, 0.500, 0.700, 0.900, 1.100, 1.300, 1.500, 1.700, 1.900};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.032, 0.230, 0.640, 0.730, 0.730, 0.460, 0.190, 0.063, 0.030, 0.021};
  Double_t Error_EvFrac_High[NN] = {0.015, 0.040, 0.070, 0.070, 0.070, 0.060, 0.040, 0.021, 0.015, 0.012}; 
  Double_t Error_EvFrac_Low[NN] = {0.015, 0.040, 0.070, 0.070, 0.070, 0.060, 0.040, 0.021, 0.015, 0.012};
  

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{jZ}=p_{T}^{jet}/p_{T}^{Z}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{Z}}#frac{dN_{jZ}}{dx_{jZ}}");
  grf_local->GetYaxis()->SetTitleOffset(1.45);
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.2,1.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_Z0Jet_PP_502TeV()
{
  const Int_t NN = 10 ;
  Double_t XJ[NN] = {0.100, 0.300, 0.500, 0.700, 0.900, 1.100, 1.300, 1.500, 1.700, 1.900};
  const Double_t XError_Syst = 0.10; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}
  Double_t EvFrac[NN] = {0.032, 0.230, 0.640, 0.730, 0.730, 0.460, 0.190, 0.063, 0.030, 0.021};
  
  Double_t SystError_EvFrac_High[NN] = {0.002, 0.010, 0.020, 0.020, 0.030, 0.030, 0.010, 0.004, 0.002, 0.001}; 
  Double_t SystError_EvFrac_Low[NN] = {0.002, 0.010, 0.020, 0.020, 0.030, 0.030, 0.010, 0.004, 0.002, 0.001};
  
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{jZ}=p_{T}^{jet}/p_{T}^{Z}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{Z}}#frac{dN_{jZ}}{dx_{jZ}}");
  grf_local->GetYaxis()->SetTitleOffset(1.45);
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.2,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}





TGraphAsymmErrors *Data_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV()
{

  // Study of Jet Quenching with Z0 + jet Correlations in Pb-Pb and pp Collisions at 5.02 TeV
  //Published in Phys.Rev.Lett. 119 (2017) no.8, 082301
  //CMS-HIN-15-013, CERN-EP-2017-002
  //DOI: 10.1103/PhysRevLett.119.082301
  //e-Print: arXiv:1702.01060 [nucl-ex] | PDF
  
  const Int_t NN = 10 ;
  Double_t XJ[NN] = {0.100, 0.300, 0.500, 0.700, 0.900, 1.100, 1.300, 1.500, 1.700, 1.900};
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};

 
  Double_t EvFrac[NN] = {0.044, 0.240, 0.550, 0.740, 0.840, 0.460, 0.160, 0.029, 0.037, 0.029};
  Double_t Error_EvFrac_High[NN] = {0.018, 0.040, 0.060, 0.070, 0.080, 0.060, 0.030, 0.015, 0.016, 0.015}; 
  Double_t Error_EvFrac_Low[NN] = {0.018, 0.040, 0.060, 0.070, 0.080, 0.060, 0.030, 0.015, 0.016, 0.015};
  

  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, Error_EvFrac_Low,Error_EvFrac_High);
  grf_local->SetMarkerColor(1);
  grf_local->SetMarkerStyle(20);
  grf_local->SetMarkerSize(1.5);
  grf_local->GetXaxis()->SetTitle("X_{jZ}=p_{T}^{jet}/p_{T}^{Z}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{Z}}#frac{dN_{jZ}}{dx_{jZ}}");
  grf_local->GetYaxis()->SetTitleOffset(1.45);
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.2,1.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  
  return grf_local;
			  
}

TGraphAsymmErrors *Data_Syst_CMS_XJ_Z0Jet_PP_UnSmeared_502TeV()
{
  const Int_t NN = 10 ;
  Double_t XJ[NN] = {0.100, 0.300, 0.500, 0.700, 0.900, 1.100, 1.300, 1.500, 1.700, 1.900};
  const Double_t XError_Syst = 0.10; // width of syst box
  Double_t Error_XJ_Low[NN] = {0.0};
  Double_t Error_XJ_High[NN] = {0.0};
  for(int i=0; i<NN; i++){Error_XJ_Low[i]=XError_Syst;Error_XJ_High[i]=XError_Syst;}
  Double_t EvFrac[NN] = {0.044, 0.240, 0.550, 0.740, 0.840, 0.460, 0.160, 0.029, 0.037, 0.029};
  
  Double_t SystError_EvFrac_High[NN] = {0.002, 0.010, 0.020, 0.020, 0.030, 0.030, 0.010, 0.002, 0.003, 0.002}; 
  Double_t SystError_EvFrac_Low[NN] = {0.002, 0.010, 0.020, 0.020, 0.030, 0.030, 0.010, 0.002, 0.003, 0.002};
  
  TGraphAsymmErrors *grf_local = new TGraphAsymmErrors(NN, XJ, EvFrac, Error_XJ_Low, Error_XJ_High, SystError_EvFrac_Low, SystError_EvFrac_High);
  grf_local->SetLineColor(1);
  grf_local->SetFillStyle(0000);
  grf_local->GetXaxis()->SetTitle("X_{jZ}=p_{T}^{jet}/p_{T}^{Z}");
  grf_local->GetYaxis()->SetTitle("#frac{1}{N_{Z}}#frac{dN_{jZ}}{dx_{jZ}}");
  grf_local->GetYaxis()->SetTitleOffset(1.45);
  grf_local->GetXaxis()->CenterTitle();
  grf_local->GetYaxis()->CenterTitle();
  grf_local->GetYaxis()->SetRangeUser(-0.2,3.0);
  grf_local->GetXaxis()->SetLimits(0.0,2.0);
  return grf_local;
}





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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++   CMS Data Functions for AJ ++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++   ATLAS Data Functions for Jet RAA +++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//





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
// CERN-EP-2018-105, arXiv:1805.05635 [nucl-ex].



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




//  Jet production in pp collisions at 2.76 TeV 
// JET pT spectra in PbPb collisions @ 2.76 TeV     ///////
Double_t jet_00_rapidity_21_pp_276tev_dNdy ;
Double_t jet_00_rapidity_21_pp_276tev_nn     ; 
Double_t jet_00_rapidity_21_pp_276tev_pzero  ;




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

  cout<<" ATLAS pp Jet Distribution "<<endl;
  for(int i=0; i<N_point; i++){
    yield[i]    = yield[i]/sigma_alice_276tev1 ; 
    stat_err[i] = stat_err[i]/sigma_alice_276tev1 ;


    //cout<<" yield "<<  yield[i]*
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


  gr_atlas_jet_yield_00_rapidity_21->Fit(fitfunc_jet_00_rapidity_21_pp_276tev,  "ME", "", 35.0, 500.0) ;
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



TGraphErrors *Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV()
{

  // We had taken data from PHYSICAL REVIEW C 96, 014912 (2017) 
  //Jet Yield for Z0+Jet Root_s = 7 TeV
  //R = 0.5, |y_Jet| < 2.4
  //71 < M_{ll} << 111 GeV
  // |p_{T}^{l}| > 20 GeV, |y^{l}|<2.4

  Double_t sigma_alice_276tev1 = sigma_alice_276tev * pow(10.0, 6.0);   // Convert nb to (GeV/c)^{-2}

  const Int_t NN = 17 ;


  Double_t Pt[NN] = {40.0, 60.0, 80.0, 100.0, 120.0, 140.0, 160.0, 180.0, 200.0, 220.0, 240.0, 260.0, 295.0, 330.0, 375.0, 450.0, 600.0} ;

  Double_t PtBins_LowEdge[NN] = {30.0, 50.0, 70.0, 90.0, 110.0, 130.0, 150.0, 170.0, 190.0, 210.0, 230.0, 250.0, 270.0, 310.0, 350.0, 400.0, 500.0} ;
  Double_t PtBins_HighEdge[NN] = {50.0, 70.0, 90.0, 110.0, 130.0, 150.0, 170.0, 190.0, 210.0, 230.0, 250.0, 270.0, 310.0, 350.0, 400.0, 500.0, 700.0} ;

  Double_t Err_Pt[NN] = {0.0};

  Double_t DSigmaDPt[NN] = {1.689625, 0.685474, 0.308851, 0.157826, 0.087711, 0.050834, 0.030086, 0.019776, 0.012999, 0.008544, 0.005735,
			0.003691, 0.002231, 0.001266, 0.000675, 0.000280, 0.000060};

  Double_t Err_DSigmaDPt[NN] = {0.0};


  Double_t Yield[NN] = {0.0};
  Double_t Err_Yield[NN] = {0.0};
  
  for(Int_t i=0;i<NN;i++){
    Err_Pt[i] = (PtBins_HighEdge[i] - PtBins_LowEdge[i])*0.5;
  
    //yield[i]    = yield[i]/sigma_alice_276tev1 ; 
    //stat_err[i] = stat_err[i]/sigma_alice_276tev1 ;
  }
  
  TGraphErrors *gr_data = new TGraphErrors(NN, Pt, DSigmaDPt, Err_Pt, Err_DSigmaDPt);
  gr_data->GetYaxis()->SetTitle("d#sigma/dp_{T}^{J}(pb/GeV)");
  gr_data->GetXaxis()->SetTitle("p_{T}^{J}(GeV/c)");
  gr_data->GetYaxis()->SetRangeUser(0.00001,10.0);
  gr_data->GetXaxis()->SetLimits(0.0,700.0);
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetXaxis()->CenterTitle();
  gr_data->SetMarkerColor(2);
  gr_data->SetMarkerStyle(20);
  gr_data->SetMarkerSize(1.2);
 
  return gr_data ;
			  
}






TGraphErrors *Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV()
{

  // We had taken data from PHYSICAL REVIEW C 96, 014912 (2017) 
  //Gamma Yield for Gamma+Jet Root_s = 8 TeV
  //Pt Jet > 30 GeV
  //R = 0.5, |y_Jet| < 2.4
  //71 < M_{ll} << 111 GeV
  // |p_{T}^{l}| > 20 GeV, |y^{l}|<2.4

  Double_t sigma_alice_276tev1 = sigma_alice_276tev * pow(10.0, 6.0);   // Convert nb to (GeV/c)^{-2}

  const Int_t NN = 14 ;


  Double_t Pt[NN] = {106.8, 117.7, 131.1, 145.0, 161.4, 178.4, 197.2, 219.7, 242.8, 269.5, 299.9, 331.5, 368.0, 406.3} ;

  Double_t PtBins_LowEdge[NN] = {101.3, 111.0, 124.4, 137.7, 152.9, 169.3, 187.5, 208.1, 230.6, 254.9, 284.1, 314.5, 348.5, 385.6} ;
  Double_t PtBins_HighEdge[NN] = {112.3, 123.8, 137.8, 152.3, 169.3, 188.2, 207.6, 230.7, 255.6, 284.1, 314.5, 348.0, 386.2, 429.4} ;

  Double_t Err_Pt[NN] = {0.0};

  Double_t DSigmaDPt[NN] = {8.435452, 5.512890, 3.144394, 1.952722, 1.212673, 0.792528, 0.422295, 0.271330, 0.157414, 0.091325, 0.052089,
			    0.029710, 0.016660, 0.009184};

  Double_t Err_DSigmaDPt[NN] = {0.0};


  Double_t Yield[NN] = {0.0};
  Double_t Err_Yield[NN] = {0.0};
  
  for(Int_t i=0;i<NN;i++){
    Err_Pt[i] = (PtBins_HighEdge[i] - PtBins_LowEdge[i])*0.5;
  
    //yield[i]    = yield[i]/sigma_alice_276tev1 ; 
    //stat_err[i] = stat_err[i]/sigma_alice_276tev1 ;
  }
  
  TGraphErrors *gr_data = new TGraphErrors(NN, Pt, DSigmaDPt, Err_Pt, Err_DSigmaDPt);
  gr_data->GetYaxis()->SetTitle("d#sigma/dp_{T}^{#gamma}(pb/GeV)");
  gr_data->GetXaxis()->SetTitle("p_{T}^{#gamma}(GeV/c)");
  gr_data->GetYaxis()->SetRangeUser(0.001,100.0);
  gr_data->GetXaxis()->SetLimits(0.0,450.0);
  gr_data->GetYaxis()->CenterTitle();
  gr_data->GetXaxis()->CenterTitle();
  gr_data->SetMarkerColor(2);
  gr_data->SetMarkerStyle(20);
  gr_data->SetMarkerSize(1.2);
 
  return gr_data ;
			  










}
