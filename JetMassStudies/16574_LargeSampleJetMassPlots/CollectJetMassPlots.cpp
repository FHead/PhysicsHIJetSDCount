#include <iostream>
using namespace std;

#include "TH1D.h"
#include "TFile.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"

#include "PlotHelper3.h"
#include "SetStyle.h"

int main();
void HistogramStyling(TH1D *H1, TH1D *H2, TH1D *H3);
void Transcribe(TH1D *H, TGraphAsymmErrors &G);

int main()
{
   SetThesisStyle();

   PdfFileHelper PdfFile("JetMassPlots.pdf");
   PdfFile.AddTextPage("Jewel/qpythia Jet Mass Plots");

   TFile FOffS("Plots_Off_S_N.root");
   TFile FOnS("Plots_On_S_Y.root");
   TFile FVacS("Plots_Vac_S_N.root");
   TFile FOffSB("Plots_Off_SB_N.root");
   TFile FOnSB("Plots_On_SB_Y.root");
   TFile FVacSB("Plots_Vac_SB_N.root");
   TFile FQ1S("Plots_QPythia_Q1_N.root");
   TFile FQ1SB("Plots_QPythia_QB1_N.root");
   TFile FQ2S("Plots_QPythia_Q2_N.root");
   TFile FQ2SB("Plots_QPythia_QB2_N.root");
   TFile FQ4S("Plots_QPythia_Q4_N.root");
   TFile FQ4SB("Plots_QPythia_QB4_N.root");
   TFile FQV("Plots_QPythia_Vac_N.root");
   TFile FQVB("Plots_QPythia_VacB_N.root");

   string HistogramNames[] = {"HSD0CSPT0", "HSD0CSPT1", "HSD0CSPT2", "HSD0CSPT3", "HSD0CSPT4", "HSD0CSPT5",
      "HSD7CSPT0", "HSD7CSPT1", "HSD7CSPT2", "HSD7CSPT3", "HSD7CSPT4", "HSD7CSPT5"};
   string SD[] =
   {
      "Soft drop z_{cut} = 0.1, #beta = 0.0",
      "Soft drop z_{cut} = 0.1, #beta = 0.0",
      "Soft drop z_{cut} = 0.1, #beta = 0.0",
      "Soft drop z_{cut} = 0.1, #beta = 0.0",
      "Soft drop z_{cut} = 0.1, #beta = 0.0",
      "Soft drop z_{cut} = 0.1, #beta = 0.0",
      "Soft drop z_{cut} = 0.5, #beta = 1.5",
      "Soft drop z_{cut} = 0.5, #beta = 1.5",
      "Soft drop z_{cut} = 0.5, #beta = 1.5",
      "Soft drop z_{cut} = 0.5, #beta = 1.5",
      "Soft drop z_{cut} = 0.5, #beta = 1.5",
      "Soft drop z_{cut} = 0.5, #beta = 1.5"
   };
   string JetPT[] =
   {
      "120 < p_{T}^{jet} < 140 GeV",
      "140 < p_{T}^{jet} < 160 GeV",
      "160 < p_{T}^{jet} < 180 GeV",
      "180 < p_{T}^{jet} < 200 GeV",
      "200 < p_{T}^{jet} < 300 GeV",
      "300 < p_{T}^{jet} < 500 GeV",
      "120 < p_{T}^{jet} < 140 GeV",
      "140 < p_{T}^{jet} < 160 GeV",
      "160 < p_{T}^{jet} < 180 GeV",
      "180 < p_{T}^{jet} < 200 GeV",
      "200 < p_{T}^{jet} < 300 GeV",
      "300 < p_{T}^{jet} < 500 GeV"
   };
   double WorldMax[] = {25, 25, 25, 25, 25, 25, 35, 35, 35, 35, 35, 35};

   for(int iH = 0; iH < 12; iH++)
   {
      TCanvas C;

      TH1D *HOffS = (TH1D *)FOffS.Get(HistogramNames[iH].c_str());
      TH1D *HOnS = (TH1D *)FOnS.Get(HistogramNames[iH].c_str());
      TH1D *HVacS = (TH1D *)FVacS.Get(HistogramNames[iH].c_str());
      TH1D *HOffSB = (TH1D *)FOffSB.Get(HistogramNames[iH].c_str());
      TH1D *HOnSB = (TH1D *)FOnSB.Get(HistogramNames[iH].c_str());
      TH1D *HVacSB = (TH1D *)FVacSB.Get(HistogramNames[iH].c_str());
      TH1D *HQ1S = (TH1D *)FQ1S.Get(HistogramNames[iH].c_str());
      TH1D *HQ1SB = (TH1D *)FQ1SB.Get(HistogramNames[iH].c_str());
      TH1D *HQ2S = (TH1D *)FQ2S.Get(HistogramNames[iH].c_str());
      TH1D *HQ2SB = (TH1D *)FQ2SB.Get(HistogramNames[iH].c_str());
      TH1D *HQ4S = (TH1D *)FQ4S.Get(HistogramNames[iH].c_str());
      TH1D *HQ4SB = (TH1D *)FQ4SB.Get(HistogramNames[iH].c_str());
      TH1D *HQV = (TH1D *)FQV.Get(HistogramNames[iH].c_str());
      TH1D *HQVB = (TH1D *)FQVB.Get(HistogramNames[iH].c_str());

      HOffS->SetLineColor(kBlack);      HOffS->SetMarkerColor(kBlack);
      HOnS->SetLineColor(kBlue);        HOnS->SetMarkerColor(kBlue);
      HVacS->SetLineColor(kRed);        HVacS->SetMarkerColor(kRed);
      HOffSB->SetLineColor(kGreen);     HOffSB->SetMarkerColor(kGreen);
      HOnSB->SetLineColor(kYellow);     HOnSB->SetMarkerColor(kYellow);
      HVacSB->SetLineColor(kMagenta);   HVacSB->SetMarkerColor(kMagenta);
      HQ1S->SetLineColor(kBlue);        HQ1S->SetMarkerColor(kBlue);
      HQ1SB->SetLineColor(kYellow);     HQ1SB->SetMarkerColor(kYellow);
      HQ2S->SetLineColor(kBlue + 1);    HQ2S->SetMarkerColor(kBlue + 1);
      HQ2SB->SetLineColor(kYellow + 1); HQ2SB->SetMarkerColor(kYellow + 1);
      HQ4S->SetLineColor(kBlue + 2);    HQ4S->SetMarkerColor(kBlue + 2);
      HQ4SB->SetLineColor(kYellow + 2); HQ4SB->SetMarkerColor(kYellow + 2);
      HQV->SetLineColor(kRed);          HQV->SetMarkerColor(kRed);
      HQVB->SetLineColor(kMagenta);     HQVB->SetMarkerColor(kMagenta);

      TGraphAsymmErrors GOffS, GOnS, GVacS, GOffSB, GOnSB, GVacSB,
         GQ1S, GQ1SB, GQ2S, GQ2SB, GQ4S, GQ4SB, GQV, GQVB;

      Transcribe(HOffS, GOffS);
      Transcribe(HOnS, GOnS);
      Transcribe(HVacS, GVacS);
      Transcribe(HOffSB, GOffSB);
      Transcribe(HOnSB, GOnSB);
      Transcribe(HVacSB, GVacSB);
      Transcribe(HQ1S, GQ1S);
      Transcribe(HQ1SB, GQ1SB);
      Transcribe(HQ2S, GQ2S);
      Transcribe(HQ2SB, GQ2SB);
      Transcribe(HQ4S, GQ4S);
      Transcribe(HQ4SB, GQ4SB);
      Transcribe(HQV, GQV);
      Transcribe(HQVB, GQVB);

      TLegend Legend(0.55, 0.87, 0.85, 0.65);
      Legend.SetTextFont(42);
      Legend.SetTextSize(0.035);
      Legend.SetFillStyle(0);
      Legend.AddEntry(HOffS, "Recoil off", "lp");
      Legend.AddEntry(HOnS, "Recoil on", "lp");
      Legend.AddEntry(HVacS, "Vac (S)", "lp");
      Legend.AddEntry(HVacSB, "Vac (S+B)", "lp");
      
      TLegend Legend2(0.55, 0.87, 0.85, 0.65);
      Legend2.SetTextFont(42);
      Legend2.SetTextSize(0.035);
      Legend2.SetFillStyle(0);
      Legend2.AddEntry(HOffSB, "Recoil off", "lp");
      Legend2.AddEntry(HOnSB, "Recoil on", "lp");
      Legend2.AddEntry(HVacS, "Vac (S)", "lp");
      Legend2.AddEntry(HVacSB, "Vac (S+B)", "lp");
      
      TLegend Legend3(0.55, 0.87, 0.85, 0.65);
      Legend3.SetTextFont(42);
      Legend3.SetTextSize(0.035);
      Legend3.SetFillStyle(0);
      Legend3.AddEntry(HOffS, "Recoil off (S)", "lp");
      Legend3.AddEntry(HOnS, "Recoil on (S)", "lp");
      Legend3.AddEntry(HOffSB, "Recoil off (S+B)", "lp");
      Legend3.AddEntry(HOnSB, "Recoil on (S+B)", "lp");

      TLegend Legend4(0.55, 0.87, 0.85, 0.65);
      Legend4.SetTextFont(42);
      Legend4.SetTextSize(0.035);
      Legend4.SetFillStyle(0);
      Legend4.AddEntry(HQ1S, "Medium (S)", "lp");
      Legend4.AddEntry(HQ1SB, "Medium (S+B)", "lp");
      Legend4.AddEntry(HQV, "Vacuum (S)", "lp");
      Legend4.AddEntry(HQVB, "Vacuum (S+B)", "lp");

      TLegend Legend5(0.55, 0.87, 0.85, 0.65);
      Legend5.SetTextFont(42);
      Legend5.SetTextSize(0.035);
      Legend5.SetFillStyle(0);
      Legend5.AddEntry(HQ1S, "Medium (S)", "lp");
      Legend5.AddEntry(HQ1SB, "Medium (S+B)", "lp");
      Legend5.AddEntry("", "", "");
      Legend5.AddEntry("", "", "");

      TH2D HWorld("HWorld", ";M^{g} / p_{T}^{jet};#frac{1}{N} #frac{d N}{d M^{g} / p_{T}^{jet}}",
         100, 0.0, 0.30, 100, 0.0, WorldMax[iH]);
      HWorld.SetStats(0);

      TH2D HWorldRatio("HWorldRatio", ";M^{g} / p_{T}^{jet};Jewel / pp",
         100, 0.0, 0.30, 100, 0.0, 6.0);
      HWorldRatio.SetStats(0);

      TH2D HWorldRatio2("HWorldRatio2", ";M^{g} / p_{T}^{jet};q-pythia / pp",
         100, 0.0, 0.30, 100, 0.0, 10.0);
      HWorldRatio2.SetStats(0);

      TLatex Latex;
      Latex.SetNDC();
      Latex.SetTextFont(42);
      Latex.SetTextSize(0.035);
      Latex.SetTextAlign(13);

      HWorld.Draw();
      GOffS.Draw("p");
      GOnS.Draw("p");
      GVacS.Draw("p");
      GVacSB.Draw("p");
      Legend.Draw();

      Latex.DrawLatex(0.15, 0.85, "JEWEL 2.2.0");
      Latex.DrawLatex(0.15, 0.80, "Signal only");
      Latex.DrawLatex(0.15, 0.75, SD[iH].c_str());
      Latex.DrawLatex(0.15, 0.70, "CS anti-k_{T} R = 0.4, |#eta^{jet}| < 1.3");
      Latex.DrawLatex(0.15, 0.65, JetPT[iH].c_str());

      PdfFile.AddCanvas(C);

      HWorld.Draw();
      GOffSB.Draw("p");
      GOnSB.Draw("p");
      GVacS.Draw("p");
      GVacSB.Draw("p");
      Legend2.Draw();

      Latex.DrawLatex(0.15, 0.85, "JEWEL 2.2.0");
      Latex.DrawLatex(0.15, 0.80, "Signal + background");
      Latex.DrawLatex(0.15, 0.75, SD[iH].c_str());
      Latex.DrawLatex(0.15, 0.70, "CS anti-k_{T} R = 0.4, |#eta^{jet}| < 1.3");
      Latex.DrawLatex(0.15, 0.65, JetPT[iH].c_str());

      PdfFile.AddCanvas(C);
      
      HOffS->Divide(HVacS);
      HOnS->Divide(HVacS);
      HOffSB->Divide(HVacSB);
      HOnSB->Divide(HVacSB);

      Transcribe(HOffS, GOffS);
      Transcribe(HOnS, GOnS);
      Transcribe(HOffSB, GOffSB);
      Transcribe(HOnSB, GOnSB);

      TGraph GLine;
      GLine.SetPoint(0, 0, 1);
      GLine.SetPoint(1, 1, 1);

      HWorldRatio.Draw();
      GOffSB.Draw("p");
      GOnSB.Draw("p");
      GOffS.Draw("p");
      GOnS.Draw("p");
      GLine.Draw("l");
      Legend3.Draw();

      Latex.DrawLatex(0.15, 0.85, "JEWEL 2.2.0");
      Latex.DrawLatex(0.15, 0.80, "Signal + background");
      Latex.DrawLatex(0.15, 0.75, SD[iH].c_str());
      Latex.DrawLatex(0.15, 0.70, "CS anti-k_{T} R = 0.4, |#eta^{jet}| < 1.3");
      Latex.DrawLatex(0.15, 0.65, JetPT[iH].c_str());

      PdfFile.AddCanvas(C);

      HWorld.Draw();
      GQ1S.Draw("p");
      GQ1SB.Draw("p");
      GQ2S.Draw("p");
      GQ2SB.Draw("p");
      GQ4S.Draw("p");
      GQ4SB.Draw("p");
      GQV.Draw("p");
      GQVB.Draw("p");
      Legend4.Draw();

      Latex.DrawLatex(0.15, 0.85, "Q-Pythia");
      Latex.DrawLatex(0.15, 0.80, "S vs S+B");
      Latex.DrawLatex(0.15, 0.75, SD[iH].c_str());
      Latex.DrawLatex(0.15, 0.70, "CS anti-k_{T} R = 0.4, |#eta^{jet}| < 1.3");
      Latex.DrawLatex(0.15, 0.65, JetPT[iH].c_str());

      PdfFile.AddCanvas(C);
         
      HQ1S->Divide(HQV);
      HQ1SB->Divide(HQVB);
      HQ2S->Divide(HQV);
      HQ2SB->Divide(HQVB);
      HQ4S->Divide(HQV);
      HQ4SB->Divide(HQVB);

      Transcribe(HQ1S, GQ1S);
      Transcribe(HQ1SB, GQ1SB);
      Transcribe(HQ2S, GQ2S);
      Transcribe(HQ2SB, GQ2SB);
      Transcribe(HQ4S, GQ4S);
      Transcribe(HQ4SB, GQ4SB);
 
      HWorldRatio2.Draw();
      GQ1S.Draw("p");
      GQ1SB.Draw("p");
      GQ2S.Draw("p");
      GQ2SB.Draw("p");
      GQ4S.Draw("p");
      GQ4SB.Draw("p");
      GLine.Draw("l");
      Legend5.Draw();

      Latex.DrawLatex(0.15, 0.85, "Q-Pythia");
      Latex.DrawLatex(0.15, 0.80, "S vs S+B");
      Latex.DrawLatex(0.15, 0.75, SD[iH].c_str());
      Latex.DrawLatex(0.15, 0.70, "CS anti-k_{T} R = 0.4, |#eta^{jet}| < 1.3");
      Latex.DrawLatex(0.15, 0.65, JetPT[iH].c_str());

      PdfFile.AddCanvas(C);
   }

   FVacSB.Close();
   FOnSB.Close();
   FOffSB.Close();
   FVacS.Close();
   FOnS.Close();
   FOffS.Close();

   PdfFile.AddTimeStampPage();
   PdfFile.Close();

   return 0;
}

void HistogramStyling(TH1D *H1, TH1D *H2, TH1D *H3)
{
   if(H1 == NULL || H2 == NULL || H3 == NULL)
      return;

   H1->SetLineColor(kBlack);
   H2->SetLineColor(kBlue);
   H3->SetLineColor(kRed);

   H1->SetMarkerColor(kBlack);
   H2->SetMarkerColor(kBlue);
   H3->SetMarkerColor(kRed);
}

void Transcribe(TH1D *H, TGraphAsymmErrors &G)
{
   if(H == NULL)
      return;

   for(int i = 1; i <= H->GetNbinsX(); i++)
   {
      double x = H->GetXaxis()->GetBinCenter(i);
      double y = H->GetBinContent(i);
      double ey = H->GetBinError(i);
      double l = H->GetXaxis()->GetBinLowEdge(i);
      double r = H->GetXaxis()->GetBinUpEdge(i);

      G.SetPoint(i - 1, x, y);
      G.SetPointError(i - 1, x - l, r - x, ey, ey);
   }

   G.SetMarkerSize(H->GetMarkerSize());
   G.SetMarkerColor(H->GetMarkerColor());
   G.SetMarkerStyle(H->GetMarkerStyle());
   G.SetLineWidth(H->GetLineWidth());
   G.SetLineColor(H->GetLineColor());
   G.SetLineStyle(H->GetLineStyle());
}



