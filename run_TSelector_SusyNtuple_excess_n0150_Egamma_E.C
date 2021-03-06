// Ask me if you have questions/problems. Thomas M.
// Version 0.1.5
// Start with root runSelector.C
// please read all comments with // !!! up to line 115
// You have to make some changes at various places
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TBranch.h"
#include "TFileCollection.h"


#include <TH2.h>
#include <map>
#include <TColor.h>
#include <TH1.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/stat.h> 
#include <iostream>
#include <math.h>
#include "string.h"
#include "TSystem.h"
#include "TProof.h"
#include "TDSet.h"
#include "TError.h" // for debugging with ddd

void throwException(string str){
	// necessary because cint does not handle thrown errors correctly
	cout <<"Exception raised "<< str<<endl;
	throw(str);
	abort();
}; 


void run_TSelector_SusyNtuple_excess_n0150_Egamma_E() {

//  TString options = TString(""); //TString(tag.c_str()) ;
// //     TString outputfile = "test.root";
//     string richtigerString = InputPath;
// //     int Position = richtigerString.find("mc12_8TeV.");
// //     outputfile = "histos_ZTauTau_" +  richtigerString.substr(Position+10,6)  + "_proof.root";
//     
//     int Position = -1;
//     Position = richtigerString.find("45_bg");
//     if (Position>0){
//       outputfile = "histos_test_" +  richtigerString.substr(Position+6,2)  + ".root";
//     }
//     else{
//       Position = richtigerString.find("45_signal");
//       if (Position>0){
//       outputfile = "histos_test_" +  richtigerString.substr(Position+3,2)  + ".root";
//       }
//     }
//     if(outputfile == ""){
//       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//       cout << "EMPTY OUPTPUTFILE STRING" << endl;
//       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//       abort();
//     }
//     cout << "outputfile= " << outputfile << endl;
    
      cout<<"Have you set up RootCore via  \"source RootCore/scripts/setup.sh\" ?"<<endl;  

      gSystem->Setenv("ROOTCOREDIR", "/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/RootCore");
      gSystem->SetIncludePath("-I$ROOTCOREDIR/include/");

      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+"); 

      TString selectorName = "TSelector_SusyNtuple_excess"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;
      
      ch = new TChain("susyNt");

      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");
//       ch->Add(InputPath);
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WH/user.gerbaudo.mc12_8TeV.177501.Herwigpp_sM_wA_noslep_notauhad_WH_2Lep_1.SusyNt.e2149_s1581_s1586_r3658_r3549_p1512_n0150.140109072637/*");
   ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226164728/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226165014/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226165107/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226165202/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226165309/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226204343/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231012857/*");
  ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Egamma/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231211129/*");
  

  
     

	    


      Long64_t nEntries = ch->GetEntries();
      ch->ls();

      cout << "all entries: " << nEntries << endl;


      TSelector_SusyNtuple_excess* SusyNtupleObject = new TSelector_SusyNtuple_excess();
      SusyNtupleObject->buildSumwMap(ch);
//       TString options="NtSys_NOM";
      ch->Process(SusyNtupleObject);
      delete SusyNtupleObject;
      
      if (ch) {delete ch; ch=0;}

  abort();
  }

