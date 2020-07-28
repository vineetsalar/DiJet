
// This is a comment

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <TMath.h>
#include <TLegend.h>
#include "TCanvas.h"
#include <TPad.h>
#include "TStyle.h"
#include <cstdlib>
#include <cmath>
#include "TGraphAsymmErrors.h"
//#include "TGraphMultiErrors.h" only works for root6.20 or more
#include "TMultiGraph.h"
#include "TLegend.h"
#include <fstream>
#include <stdlib.h>
#include "TMath.h"
#include "TRandom3.h"
#include "TF1.h"
#include "TH1D.h"
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


//
#include "DiJetDataFunctions.h"

// Global Varaibles 
const Double_t pi       = 3.14159265358979312 ;

const Double_t Am = 208.0 ;
const Double_t R0 = 1.1;
const Double_t RA = R0*pow(Am, 1.0/3.0);




Double_t FindJetPtResolution(Double_t JetPt, Int_t IsPbPb)
{

  Double_t Mean = 1.0;
  Double_t CC = 0.061;
  Double_t SS = 0.0;
  Double_t NN = 0.0;

  if(IsPbPb ==1){SS=1.24;NN=8.08;}
  else{SS=0.95;NN=0.001;}

  Double_t SigmaSquare = (CC*CC) + ((SS*SS)/JetPt) + ((NN*NN)/(JetPt*JetPt));
  Double_t Sigma = TMath::Sqrt(SigmaSquare);

  //cout<<" Sigma "<<Sigma<<endl;
  //TF1 *Func_CMS_JetPtResolution = new TF1("Func_CMS_JetPtResolution", "gaus",0.0,2.0);
  //Func_CMS_JetPtResolution->SetParNames("Mean", "Sigma");
  //Func_CMS_JetPtResolution->SetParameter(0,1.0);
  //Func_CMS_JetPtResolution->SetParameter(1,Mean);
  //Func_CMS_JetPtResolution->SetParameter(2,Sigma);

  //new TCanvas;
  //Func_CMS_JetPtResolution->Draw();

  TRandom3 rand(0);
  Double_t Reso = rand.Gaus(Mean, Sigma);
  
  // Double_t Reso = Func_CMS_JetPtResolution->GetRandom();

  return Reso;

}




Double_t calDelta(Double_t pT, Double_t alpha, Double_t MM) 
{

  Double_t Delta_pT = MM * pow(pT, alpha) ;
  return Delta_pT;
}





TH1D *RAA_Jet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin)
{

  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop
  TH1D *hJetPt_PP = new TH1D(Form("hJetPt_PP_%d ",CentBin),Form("hJetPt_PP_%d ",CentBin), 25, 0.0, 500.0);
  hJetPt_PP->Sumw2();

  TH1D *hJetPt_PbPb = new TH1D(Form("hJetPt_PbPb_%d ",CentBin),Form("hJetPt_PbPb_%d ",CentBin), 25, 0.0, 500.0);
  hJetPt_PbPb->Sumw2();

  TH1D *hJetPt_Ratio = new TH1D(Form("hJetPt_Ratio_%d ",CentBin),Form("hJetPt_Ratio_%d ",CentBin), 25, 0.0, 500.0);
  hJetPt_Ratio->Sumw2();
  
  Double_t RR = RA*sqrt(NPart/(2*Am));

  Int_t MultEv = 2;
  const Int_t NEvents = MultEv*5000000;

  
  const Double_t MinPtRAA = 50.0;
  
  for(int i=0; i< NEvents; i++) {
    
    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom();
    
    //pt resolution : pT dependent
    Double_t Mean = 1.0;
    Double_t CC = 0.061;
    Double_t SS = 1.24;
    Double_t NN = 8.08;
    
    Double_t SigmaSquare = (CC*CC) + ((SS*SS)/Pt) + ((NN*NN)/(Pt*Pt));
    Double_t Sigma = TMath::Sqrt(SigmaSquare);
    Double_t Reso = rand.Gaus(Mean, Sigma);
    
    Double_t MultFac = 1.0;

   
    Reso = Reso*MultFac;
        
    //Double_t Pt1 = E1*Reso1;
    //Double_t Pt2 = E2*Reso2;


    Double_t pTppMeas = Pt*Reso;

    //Double_t pTppMeas = rand.Gaus(Pt, Pt*ResPt);

    if(pTppMeas>MinPtRAA) hJetPt_PP->Fill(pTppMeas,2);
    



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

    
    //dEdx = 0.0;

    //ELossFlacWidth relative 

    Double_t WW = 0.10;
    dEdx = rand.Gaus(dEdx, dEdx*WW);


    Double_t E1 = Pt-dEdx*d1;
    Double_t E2 = Pt-dEdx*d2;
    
    // Smear Pt
    // Fix Resolution
    //Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    //Double_t Pt2 = rand.Gaus(E2, E2*ResPt);

    //pt resolution : pT dependent
    //Double_t Mean = 1.0;
    //Double_t CC = 0.061;
    //Double_t SS = 0.0;
    //Double_t NN = 0.0;

    
    //if(IsPP==0){SS=1.24;NN=8.08;}
    //if(IsPP==1){SS=1.24;NN=8.08;}
    
    Double_t SigmaSquare1 = (CC*CC) + ((SS*SS)/E1) + ((NN*NN)/(E1*E1));
    Double_t Sigma1 = TMath::Sqrt(SigmaSquare1);
    Double_t Reso1 = rand.Gaus(Mean, Sigma1);
    
    Double_t SigmaSquare2 = (CC*CC) + ((SS*SS)/E2) + ((NN*NN)/(E2*E2));
    Double_t Sigma2 = TMath::Sqrt(SigmaSquare2);
    Double_t Reso2 = rand.Gaus(Mean, Sigma2);

    //Double_t MultFac = 2.8;

   
    Reso1 = Reso1*MultFac;
    Reso2 = Reso2*MultFac;
    
    Double_t Pt1 = E1*Reso1;
    Double_t Pt2 = E2*Reso2;

    if(Pt1 > MinPtRAA) hJetPt_PbPb->Fill(Pt1);
    if(Pt2 > MinPtRAA) hJetPt_PbPb->Fill(Pt2);

  } 

  hJetPt_Ratio->Divide(hJetPt_PbPb,hJetPt_PP,1.0,1.0,"B");
  
  hJetPt_Ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hJetPt_Ratio->GetYaxis()->SetTitle("R_{AA}");
  hJetPt_Ratio->GetXaxis()->CenterTitle();
  hJetPt_Ratio->GetYaxis()->CenterTitle();
  hJetPt_Ratio->SetMarkerColor(kRed);
  return hJetPt_Ratio;
}





TH1D *XJ_Z0Jet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin, Int_t isPP)
{
  //if(isPP ==2) {ResPhi = 0.0;ResPt=0.0;}
  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop
  TH1D *hAsymmetryOut = new TH1D(Form("hXJZ0OutCent_%d ",CentBin),Form("hXJZ0OutCent_%d ",CentBin), 10, 0.0, 2.0);
  hAsymmetryOut->Sumw2();


  Double_t RR = RA*sqrt(NPart/(2*Am));

  const Int_t NEvents = 50000;

  const Int_t PrintOutTher = NEvents/10;

  
  for(int i=0; i< NEvents; i++) {

    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom();

    // Generate position 
    Double_t rr = rand.Uniform(0.0,1.0)*RR;
    Double_t Phi = rand.Uniform(0.0,1.0)*2.0*pi;
    

    if(i%PrintOutTher==0) cout<<" Random generated pT : "<< Pt<< " phi "<<Phi<<endl;
    
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
    Double_t E1 = Pt; // this is assumed as Z0
    Double_t E2 = Pt-dEdx*d2; // this is assumed as Jet

    if(isPP ==1 || isPP ==2) E2 = Pt; // no energy loss for PP

    if(i%PrintOutTher==0) cout<<" After energy loss pT1 : "<< E1 << " pT2 "<< E2 <<endl;
	
    // Smear Pt
    //pt resolution fixed
    //Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    //Double_t Pt2 = rand.Gaus(E2, E2*ResPt);


    //pt resolution : pT dependent
    Double_t Mean = 1.0;
    Double_t CC = 0.061;
    Double_t SS = 0.0;
    Double_t NN = 0.0;


    if(isPP==0){SS=1.24;NN=8.08;}
    if(isPP==1){SS=1.24;NN=8.08;}
    if(isPP==2){SS=0.95;NN=0.001;}

    Double_t SigmaSquare1 = (CC*CC) + ((SS*SS)/E1) + ((NN*NN)/(E1*E1));
    Double_t Sigma1 = TMath::Sqrt(SigmaSquare1);
    Double_t Reso1 = rand.Gaus(Mean, Sigma1);

    Double_t SigmaSquare2 = (CC*CC) + ((SS*SS)/E2) + ((NN*NN)/(E2*E2));
    Double_t Sigma2 = TMath::Sqrt(SigmaSquare2);
    Double_t Reso2 = rand.Gaus(Mean, Sigma2);
  
    Double_t Pt1 = E1*Reso1;
    Double_t Pt2 = E2*Reso2;

    if(i%PrintOutTher==0) cout<<" resolution relative "<< Sigma1 <<"   "<< Sigma2 <<endl;
    if(i%PrintOutTher==0) cout<<" After energy loss + reso pT1 : "<< Pt1 << " pT2 "<< Pt2 <<endl<<endl;
    

    //Exp cut on Pt
    const Double_t MinZ0Pt = 60.0;
    const Double_t MinJetPt = 30.0;
    
    if(Pt1 < MinZ0Pt || Pt2 < MinJetPt || DeltaPhi < (7.0*pi)/8.0) continue;

    //if(Pt1 < MinZ0Pt || Pt2 < MinJetPt) continue; 

    Double_t PtXJ = Pt2/Pt1; 
    //cout << Pt1 << "  " << Pt2<<"   "<<PtDiff << endl;
    
    hAsymmetryOut->Fill(PtXJ);
  } 


  const Double_t NumberZ0 = 536.0;

  //hAsymmetryOut->Scale(1.0/hAsymmetryOut->Integral());
  hAsymmetryOut->Scale(1.0/hAsymmetryOut->GetBinWidth(0));
  hAsymmetryOut->Scale(1.0/NumberZ0);

  hAsymmetryOut->GetXaxis()->SetTitle("X_{J#gamma}=p_{T}^{Jet}/p_{T}^{#gamma}");
  hAsymmetryOut->GetYaxis()->SetTitle("#frac{1}{N_{J#gamma}}#frac{dN_{J#gamma}}{dx_{J#gamma}}");
  hAsymmetryOut->GetXaxis()->CenterTitle();
  hAsymmetryOut->GetYaxis()->CenterTitle();
  hAsymmetryOut->SetMarkerColor(kRed);
  return hAsymmetryOut;

}






TH1D *XJ_GammaJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin, Int_t isPP)
{

  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop
  TH1D *hAsymmetryOut = new TH1D(Form("hXJOutCent_%d ",CentBin),Form("hXJOutCent_%d ",CentBin), 20, 0.0, 2.0);
  hAsymmetryOut->Sumw2();
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
    // pt resolution fixed given as function parameter 
    //Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    //Double_t Pt2 = rand.Gaus(E2, E2*ResPt);



    //pt resolution : pT dependent
    Double_t Mean = 1.0;
    Double_t CC = 0.061;
    Double_t SS = 0.0;
    Double_t NN = 0.0;


    if(isPP==0){SS=1.24;NN=8.08;}
    if(isPP==1){SS=0.95;NN=0.001;}
    
    Double_t SigmaSquare1 = (CC*CC) + ((SS*SS)/E1) + ((NN*NN)/(E1*E1));
    Double_t Sigma1 = TMath::Sqrt(SigmaSquare1);
    Double_t Reso1 = rand.Gaus(Mean, Sigma1);

    Double_t SigmaSquare2 = (CC*CC) + ((SS*SS)/E2) + ((NN*NN)/(E2*E2));
    Double_t Sigma2 = TMath::Sqrt(SigmaSquare2);
    Double_t Reso2 = rand.Gaus(Mean, Sigma2);
  
    Double_t Pt1 = E1*Reso1;
    Double_t Pt2 = E2*Reso2;


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





TH1D *Asym_DiJet_Centrality(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Int_t CentBin, Int_t IsPP)
{

  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Centrality Loop
  TH1D *hAsymmetryOut = new TH1D(Form("hAsymmetryOutCent_%d ",CentBin),Form("hAsymmetryOutCent_%d ",CentBin), 17, 0.0, 1.0);
  hAsymmetryOut->Sumw2();

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
    //smearing dEdx
    Double_t WW = 0.5;
    Double_t dEdx1 = rand.Gaus(dEdx, dEdx*WW);
    Double_t dEdx2 = rand.Gaus(dEdx, dEdx*WW);
    if(IsPP ==1 ){dEdx =0.0;} // no energy loss for pp
    Double_t E1 = Pt-dEdx1*d1;
    Double_t E2 = Pt-dEdx2*d2;
    
    // Smear Pt
    // Fix Resolution
    //Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    //Double_t Pt2 = rand.Gaus(E2, E2*ResPt);

    //pt resolution : pT dependent
    Double_t Mean = 1.0;
    Double_t CC = 0.061;
    Double_t SS = 0.0;
    Double_t NN = 0.0;

    
    if(IsPP==0){SS=1.24;NN=8.08;}
    // true pp no smearing
    //if(IsPP==1){SS=0.95;NN=0.001;}
    //pp smeared to match PbPb
    if(IsPP==1){SS=1.24;NN=8.08;}
    
    Double_t SigmaSquare1 = (CC*CC) + ((SS*SS)/E1) + ((NN*NN)/(E1*E1));
    Double_t Sigma1 = TMath::Sqrt(SigmaSquare1);
    Double_t Reso1 = rand.Gaus(Mean, Sigma1);
    
    Double_t SigmaSquare2 = (CC*CC) + ((SS*SS)/E2) + ((NN*NN)/(E2*E2));
    Double_t Sigma2 = TMath::Sqrt(SigmaSquare2);
    Double_t Reso2 = rand.Gaus(Mean, Sigma2);

    Double_t MultFac = 15.0;

    //Double_t MultFac = 1.0;


    Reso1 = Reso1*MultFac;
    Reso2 = Reso2*MultFac;
    
    Double_t Pt1 = E1*Reso1;
    Double_t Pt2 = E2*Reso2;

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





TH1D *Asym_DiJet_Pt(TF1 *JetPtFuncPP,  Double_t ResPt, Double_t ResPhi, Double_t Alpha, Double_t MM, Double_t NPart, Double_t LPtMin, Double_t LPtMax, Int_t PtBin, Int_t IsPP)
{

  const Double_t SLPtMin = 30.0;
  
  //initialize the random number generator
  TRandom3 rand(0);
  
  //Histogram Name should come from the Pt Loop
  
  
  TH1D *hAsymmetryOut = new TH1D(Form("hAsymmetryOutPt_%d ",PtBin),Form("hAsymmetryOutPt_%d ",PtBin), 17, 0.0, 1.0);
  hAsymmetryOut->Sumw2();
  Double_t RR = RA*sqrt(NPart/(2*Am));
    
  const Int_t NEvents = 5000000;
  
  
  //Int_t Trial = 0;

  for(int i=0; i< NEvents; i++) {
    //do{
    
    Double_t MinPtRandom = LPtMin-0.7*LPtMin;
    Double_t MaxPtRandom = 500.0;
    // Generate Pt 
    Double_t Pt = JetPtFuncPP->GetRandom(MinPtRandom, MaxPtRandom);
    //Double_t Pt = JetPtFuncPP->GetRandom();
        
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
    
    if(IsPP ==1 ){dEdx =0.0;} // no energy loss for pp

    Double_t E1 = Pt-dEdx*d1;
    Double_t E2 = Pt-dEdx*d2;
    
    // Smear Pt
    // Fix Resolution
    //Double_t Pt1 = rand.Gaus(E1, E1*ResPt);
    //Double_t Pt2 = rand.Gaus(E2, E2*ResPt);
    
    //pt resolution : pT dependent
    Double_t Mean = 1.0;
    Double_t CC = 0.061;
    Double_t SS = 0.0;
    Double_t NN = 0.0;

    
    if(IsPP==0){SS=1.24;NN=8.08;}
    if(IsPP==1){SS=0.95;NN=0.001;}
    
    Double_t MultFac = 1.8; 
    Double_t SigmaSquare1 = (CC*CC) + ((SS*SS)/E1) + ((NN*NN)/(E1*E1));
    Double_t Sigma1 = TMath::Sqrt(SigmaSquare1);
    Double_t Reso1 = rand.Gaus(Mean, Sigma1);
    
    Double_t SigmaSquare2 = (CC*CC) + ((SS*SS)/E2) + ((NN*NN)/(E2*E2));
    Double_t Sigma2 = TMath::Sqrt(SigmaSquare2);
    Double_t Reso2 = rand.Gaus(Mean, Sigma2);

    Reso1 =  Reso1*MultFac;
    Reso2 =  Reso2*MultFac;
    

    
    Double_t Pt1 = E1*Reso1;
    Double_t Pt2 = E2*Reso2;
    
    //Exp cut on Pt
    Double_t L_Pt = TMath::Max(Pt1,Pt2);
    Double_t SubL_Pt = TMath::Min(Pt1,Pt2);;
        
    if( (L_Pt < LPtMin || L_Pt > LPtMax) || (SubL_Pt < SLPtMin) || DeltaPhi < (2.0*pi)/3.0) continue; 


    Double_t PtDiff = (L_Pt-SubL_Pt)/(L_Pt+SubL_Pt);
    
    //cout << Pt1 << "  " << Pt2<<"   "<<PtDiff << endl;
    //if(Trial%10==0)cout<<" Trial "<<Trial<<endl;    
    hAsymmetryOut->Fill(PtDiff);

    //Trial++;
  } 
  //while(Trial < NEvents);



  hAsymmetryOut->Scale(1.0/hAsymmetryOut->Integral());
  hAsymmetryOut->GetXaxis()->SetTitle("A_{J}");
  hAsymmetryOut->GetYaxis()->SetTitle("Event Fraction");
  hAsymmetryOut->GetXaxis()->CenterTitle();
  hAsymmetryOut->GetYaxis()->CenterTitle();
  hAsymmetryOut->SetMarkerColor(kRed);
  return hAsymmetryOut;
}



void Fit_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV()
{

  TLatex *Latex_local = new TLatex();
  Latex_local->SetNDC();
  Latex_local->SetTextAlign(12); 
  Latex_local->SetTextColor(1);

  TGraphErrors *grf_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV = Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV();

  

  TF1 *FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV = new TF1("FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV", tsallis_fitting_function, 30.0, 700.0, 3);
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetParNames("dN/dy", "nn", "pzero");
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetParameters(5.0, 6.0, 10) ;
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetParLimits(0, 0.01, 100.0);
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetParLimits(1, 4.0,   10.0) ;
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetParLimits(2, 0.5, 100.0) ;

  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetLineColor(1);
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetLineStyle(4);
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->SetLineWidth(2);

 
  new TCanvas;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.15);
  grf_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->Draw("AP");
  
  TFitResultPtr fp = grf_Data_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->Fit(FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV,  "SE", "", 40.0, 700.0) ;
  FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->Draw("same");  
  
  Latex_local->DrawLatex(0.60, 0.80, "CMS Z^{0}+Jet 7 TeV") ;
  
  Double_t dNdy      = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetParameter(0) ;
  Double_t dNdy_err  = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetParError(0)  ;
  Double_t nn               = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetParameter(1) ;
  Double_t nn_err    = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetParError(1)  ;
  Double_t pzero            = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetParameter(2) ;
  Double_t pzero_err = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetParError(2)  ;
  Double_t Chi2      = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetChisquare()  ;
  Double_t NDF       = FitFunc_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV->GetNDF()        ;
  Double_t Chi2_NDF  = Chi2/NDF ;
  Int_t FitStatus = fp;
  cout<<endl<<endl;

  cout<<"______________________________________________________________________________"<<endl;
  cout<<" Fitted CMS Z0+Jet Data with Tsallis Function "<<endl;
  cout<<" Fit Status   "<< FitStatus <<endl;
  cout<<"dNdy        = "<< dNdy  <<"   "<<" dNdy_err  = "<< dNdy_err <<endl;
  cout<<"nn          = "<< nn    <<"   "<<" nn_err    = "<< nn_err   <<endl;
  cout<<"pzero       = "<< pzero <<"   "<<" pzero_err = "<< pzero_err <<endl;
  cout<<"Chi^{2}     = "<< Chi2     <<endl;
  cout<<"NDF         = "<< NDF      <<endl;
  cout<<"Chi^{2}_NDF = "<< Chi2_NDF <<endl;
  cout<<"Prob        = "<< TMath::Prob(Chi2,NDF) <<endl;
  cout<<"******************************************************************************"<<endl;


  gPad->SaveAs("Figure/Fig_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV.png");
  gPad->SaveAs("Figure/Fig_CMS_JetYield_Z0PlusJet_JetPt_PP7TeV.pdf");


  
}




void Fit_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV()
{

  TLatex *Latex_local = new TLatex();
  Latex_local->SetNDC();
  Latex_local->SetTextAlign(12); 
  Latex_local->SetTextColor(1);

  TGraphErrors *grf_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV = Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV();

  

  TF1 *FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV = new TF1("FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV", tsallis_fitting_function, 50.0, 450.0, 3);
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetParNames("dN/dy", "nn", "pzero");
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetParameters(94.0, 7.0, 35) ;
  
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetParLimits(0, 90.0, 120.0);
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetParLimits(1, 4.0,   10.0) ;
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetParLimits(2, 10.0, 50.0) ;

  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetLineColor(1);
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetLineStyle(4);
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->SetLineWidth(2);

 
  new TCanvas;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.15);
  grf_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->Draw("AP");
  
  TFitResultPtr fp = grf_Data_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->Fit(FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV,  "S", "", 80.0, 450.0) ;
  FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->Draw("same");  

  Latex_local->DrawLatex(0.60, 0.80, "CMS #gamma+Jet 8 TeV") ;
  
  Double_t dNdy      = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetParameter(0) ;
  Double_t dNdy_err  = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetParError(0)  ;
  Double_t nn               = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetParameter(1) ;
  Double_t nn_err    = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetParError(1)  ;
  Double_t pzero            = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetParameter(2) ;
  Double_t pzero_err = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetParError(2)  ;
  Double_t Chi2      = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetChisquare()  ;
  Double_t NDF       = FitFunc_CMS_JetYield_GammaPlusJet_GammaPt_PP8TeV->GetNDF()        ;
  Double_t Chi2_NDF  = Chi2/NDF ;
  Int_t FitStatus = fp;
  cout<<endl<<endl;

  cout<<"______________________________________________________________________________"<<endl;
  cout<<" Fitted CMS Gamma+Jet Data with Tsallis Function "<<endl;
  cout<<" Fit Status = "<< FitStatus <<endl;
  cout<<"dNdy        = "<< dNdy  <<"   "<<" dNdy_err  = "<< dNdy_err <<endl;
  cout<<"nn          = "<< nn    <<"   "<<" nn_err    = "<< nn_err   <<endl;
  cout<<"pzero       = "<< pzero <<"   "<<" pzero_err = "<< pzero_err <<endl;
  cout<<"Chi^{2}     = "<< Chi2     <<endl;
  cout<<"NDF         = "<< NDF      <<endl;
  cout<<"Chi^{2}_NDF = "<< Chi2_NDF <<endl;
  cout<<"Prob        = "<< TMath::Prob(Chi2,NDF) <<endl;
  cout<<"******************************************************************************"<<endl;


  gPad->SaveAs("Figure/Fig_CMS_JetYield_GammaPlusJet_JetPt_PP7TeV.png");
  gPad->SaveAs("Figure/Fig_CMS_JetYield_GammaPlusJet_JetPt_PP7TeV.pdf");
  
}


// Gaussian Function 
Double_t Gaussian_Function(Double_t* x, Double_t* par)
{

  //Gaussian Function
  //f_{g}(x) = 1.0/(2.0*Pi*Sigma^{2})^{1.0/2.0} exp[-(x-a)^{2}/(2.0*Sigma^{2})]

  Double_t pT    = x[0] ; 
  Double_t a  = par[0]; 
  Double_t Sigma    = par[1];

  const Double_t Root_Pi =   1.7724539; //TMath::Sqrt(TMath::Pi())
  const Double_t Root_2 = 1.4142136;   //TMath::Sqrt(2)

  Double_t NormFac = (Root_2*Root_Pi);

  Double_t gauss = 1.0/(NormFac*Sigma) * TMath::Exp(-(((pT-a)*(pT-a))/(2.0*Sigma*Sigma)));
  
  return gauss;
   
}






/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
//++++++++++++++++++++++++++++++++ Glaubar Centrality Functions 2.76 TeV ++++++++++++++++++++++//
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
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



/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
//++++++++++++++++++++++++++++++++ Glaubar Centrality Functions 5.02 TeV ++++++++++++++++++++++//
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
Double_t NPart_FiveTeV(int CentLow, int CentHigh)
{
  Double_t CentToBin = 0.5;

  Double_t BinLow=CentLow/CentToBin;
  Double_t BinHigh=CentHigh/CentToBin;

  
  const int nbins = 200;
  Double_t NpartArray[nbins]={401.99, 398.783, 396.936, 392.71, 387.901, 383.593, 377.914, 374.546, 367.507, 361.252, 356.05, 352.43, 345.701, 341.584, 
			      335.148, 330.581, 325.135, 320.777, 315.074, 310.679, 306.687, 301.189, 296.769, 291.795, 287.516, 283.163, 277.818, 274.293, 
			      269.29, 265.911, 260.574, 256.586, 252.732, 249.194, 245.011, 241.292, 236.715, 232.55, 229.322, 225.328, 221.263, 218.604, 214.728, 
			      210.554, 206.878, 203.924, 200.84, 196.572, 193.288, 189.969, 186.894, 183.232, 180.24, 177.36, 174.008, 171.222, 168.296, 165.319, 
			      162.013, 158.495, 156.05, 154.218, 150.559, 148.455, 145.471, 142.496, 139.715, 137.395, 134.469, 131.926, 129.817, 127.045, 124.467, 
			      122.427, 119.698, 117.607, 114.543, 112.662, 110.696, 108.294, 105.777, 103.544, 101.736, 99.943, 97.4951, 95.4291, 93.2148, 91.2133, 
			      89.5108, 87.2103, 85.7498, 83.5134, 81.9687, 79.7456, 78.1684, 76.4873, 74.7635, 72.761, 71.0948, 69.6102, 67.7806, 66.2215, 64.5813, 
			      63.0269, 61.4325, 59.8065, 58.2423, 57.2432, 55.8296, 54.2171, 52.8809, 51.3254, 49.9902, 48.6927, 47.5565, 46.136, 44.8382, 43.6345, 
			      42.3964, 41.4211, 39.9681, 39.178, 37.9341, 36.9268, 35.5626, 34.5382, 33.6912, 32.8156, 31.6695, 30.6552, 29.7015, 28.8655, 27.9609, 
			      27.0857, 26.105, 25.3163, 24.4872, 23.6394, 23.0484, 22.2774, 21.4877, 20.5556, 19.9736, 19.3296, 18.5628, 17.916, 17.2928, 16.6546, 16.1131, 
			      15.4013, 14.8264, 14.3973, 13.7262, 13.2853, 12.8253, 12.2874, 11.7558, 11.2723, 10.8829, 10.4652, 9.96477, 9.6368, 9.09316, 8.84175, 
			      8.48084, 8.05694, 7.64559, 7.29709, 7.07981, 6.70294, 6.45736, 6.10284, 5.91788, 5.5441, 5.33311, 5.06641, 4.96415, 4.6286, 4.38214, 
			      4.2076, 4.01099, 3.81054, 3.63854, 3.43403, 3.23244, 3.08666, 2.86953, 2.74334, 2.62787, 2.48354, 2.38115, 2.26822, 2.23137, 2.1665, 
			      2.14264, 2.10636, 2.07358, 2.05422, 2.04126, 2.00954};
  
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NpartArray[i];
  }
  Double_t NPart = sum/(BinHigh-BinLow);
  return NPart;
}


Double_t NColl_FiveTeV(int CentLow, int CentHigh)
{

  Double_t CentToBin = 0.5;

  Double_t BinLow=CentLow/CentToBin;
  Double_t BinHigh=CentHigh/CentToBin;
  
  const int nbins = 200;
  Double_t NCollArray[nbins]={1976.95, 1944.02, 1927.29, 1891.9, 1845.3, 1807.2, 1760.45, 1729.18, 1674.8, 1630.3, 1590.52, 
			   1561.72, 1516.1, 1486.5, 1444.68, 1410.88, 1376.4, 1347.32, 1309.71, 1279.98, 1255.31, 1219.89, 1195.13, 1165.96, 1138.92, 1113.37, 
			   1082.26, 1062.42, 1030.6, 1009.96, 980.229, 955.443, 936.501, 915.97, 892.063, 871.289, 847.364, 825.127, 806.584, 789.163, 765.42, 
			   751.187, 733.001, 708.31, 690.972, 677.711, 660.682, 640.431, 623.839, 607.456, 593.307, 576.364, 560.967, 548.909, 530.475, 519.575, 
			   505.105, 490.027, 478.133, 462.372, 451.115, 442.642, 425.76, 416.364, 405.154, 392.688, 380.565, 371.167, 360.28, 348.239, 340.587, 
			   328.746, 320.268, 311.752, 300.742, 292.172, 281.361, 274.249, 267.025, 258.625, 249.931, 240.497, 235.423, 228.63, 219.854, 214.004, 
			   205.425, 199.114, 193.618, 185.644, 180.923, 174.289, 169.641, 161.016, 157.398, 152.151, 147.425, 140.933, 135.924, 132.365, 127.017, 
			   122.127, 117.817, 113.076, 109.055, 105.16, 101.323, 98.098, 95.0548, 90.729, 87.6495, 84.0899, 80.2237, 77.2201, 74.8848, 71.3554, 
			   68.7745, 65.9911, 63.4136, 61.3859, 58.1903, 56.4155, 53.8486, 52.0196, 49.2921, 47.0735, 45.4345, 43.8434, 41.7181, 39.8988, 38.2262, 
			   36.4435, 34.8984, 33.4664, 31.8056, 30.351, 29.2074, 27.6924, 26.7754, 25.4965, 24.2802, 22.9651, 22.0059, 21.0915, 19.9129, 19.1041, 
			   18.1487, 17.3218, 16.5957, 15.5323, 14.8035, 14.2514, 13.3782, 12.8667, 12.2891, 11.61, 11.0026, 10.3747, 9.90294, 9.42648, 8.85324, 
			   8.50121, 7.89834, 7.65197, 7.22768, 6.7755, 6.34855, 5.98336, 5.76555, 5.38056, 5.11024, 4.7748, 4.59117, 4.23247, 4.00814, 3.79607, 
			   3.68702, 3.3767, 3.16309, 2.98282, 2.8095, 2.65875, 2.50561, 2.32516, 2.16357, 2.03235, 1.84061, 1.72628, 1.62305, 1.48916, 1.38784, 
			   1.28366, 1.24693, 1.18552, 1.16085, 1.12596, 1.09298, 1.07402, 1.06105, 1.02954};
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NCollArray[i];
  }
  Double_t NColl = sum/(BinHigh-BinLow);
  return NColl;
}
