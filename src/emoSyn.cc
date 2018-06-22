/** 
 * emoSyn
 * program to modify pho-files and generate klatt-files
 * thereby simulating emotional speech
 * last change
 * date: Mon Dez 27 11:41:30 MET 1999
 *
 * documentation:
 * date: Wen Sep 27 16:37:07 MEST 2000
 *
 * Copyright (C) 2000  Felix Burkhardt
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * author's contact: felixbur@gmx.de
*/

/**
 * \mainpage emoSyn documentation
 * emoSyn (acronym for emotion-synthesizer) is a program that converts
 * speechsignal-descriptions into parameter-values usable with a 
 * klatt-style formant synthesizer (up to now either the free 
 * Iles & Simmons version (http://www.cs.cmu.edu/afs/cs.cmu.edu/project/ai-repository/ai/areas/speech/systems/klatt/0.html) or the commercial 
 * sensymetrics version (http://www.sens.com/Sensyn.htm)). 
 * It can also be used to modify MBROLA's 
 * (http://www.festvox.org/mbrola/) PHO-Files in order to simulate 
 * emotional arousal.
 *
 * The main documentation-page for emoSyn is located at 
 * http://www.kgw.tu-berlin.de/~felixbur/emoSyn.html .
 *
 *
 * This is the documentation of the source-code.
 * You could regard emoSyn as an example application to learn how to use
 * the classes phrase, syllable and phon.
 * 
 * To use this documentation it might be a good idea to start with 
 * emoSyn (the main program, under File List) and work your way down.
 * 
 * 
 *
 * Copyright (C) 2000  Felix Burkhardt
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * author's contact: felixbur@gmx.de
 */

extern "C" {
#include "parse_argument.h"
}

#include "phrase.h"

/**
 * version number.
 */
const  std::string version ="0.01";


void usage();

void initKlattDefaults(globalsT &glob,  std::string fileName);

int main(int argc, char **argv) {

  char *inFileName, *outFileName, *modFileName, *testConfFile;
  globalsT glob;
  char *klattDefaultFileName = "emoSyn.conf";
  char *diphonBaseName = "diphonDB/";
   std::string buffer;
  int argNum;
  phrase inPhrase;

  argNum = argc-1;

  if (RETURN_OK==
      parse_argument_string(argc, argv, "-kd", &klattDefaultFileName))
    argNum -= 2;

  if (parse_argument_flag(argc, argv, "-h"))
    usage();

  if (parse_argument_flag(argc, argv, "-v")) {
     std::cerr<<"version: "<<version<<"\n";
    exit(0);
  }

  initKlattDefaults(glob,  std::string(klattDefaultFileName));

  if (parse_argument_flag(argc, argv, "-vb")) {
    glob.verbose = true;
    argNum -= 1;
  }

  
  if (RETURN_OK== parse_argument_string(argc, argv, "-db", &diphonBaseName))
    argNum -= 2;
  
  if (parse_argument_string(argc, argv, "-ko", &outFileName)==RETURN_OK)
    glob.senSyn=false;
  if (parse_argument_string(argc, argv, "-so", &outFileName)==RETURN_OK)
    glob.senSyn=true;

  if (RETURN_OK==parse_argument_flag(argc, argv, "-use4Freq")) {
    glob.use4Freq = true;
    argNum--;
  }
  if (RETURN_OK==parse_argument_flag(argc, argv, "-use5Freq")) {
    glob.use5Freq = true;
    argNum--;
  }

  if (RETURN_OK==parse_argument_flag(argc, argv, "-testKlatt")) {
    initKlattDefaults(glob, "klattInit.asc");
    glob.senSyn=false;
    inPhrase.makeTest(glob, 1000);
     std::ofstream outFile("klattTest.par");
    if (outFile.good()) {
      inPhrase.printKlattFile(outFile);
    }
    outFile.close();
    return 0;
  }
  if (RETURN_OK==parse_argument_string(argc, argv, "-testSensyn", &testConfFile)) {
    initKlattDefaults(glob,  std::string(testConfFile));
    inPhrase.makeTest(glob, 1000);
     std::ofstream outFile("klattTest.doc");
    if (outFile.good()) {
      inPhrase.printSenSynFile(glob, outFile);
    }
    outFile.close();
    return 0;
  }

  // this is to create a pho-file from a database, first step for copysynthesis
  if (parse_argument_string(argc, argv, "-makePhoFromDB", &inFileName)==RETURN_OK) {
    argNum -= 2;
     std::ifstream inFile(inFileName);
    glob.copyDB = true;
    if (inFile.good()) {
      inPhrase.readPhoList(inFile, glob);
      inFile.close();
    } else {
      error("couldn't open Pho-File: " +  std::string(inFileName) + "\n", -1);
    }
    inPhrase.readF0FromDB(diphonBaseName, glob);
    inPhrase.printPhoFile( std::cout, glob);
    return 0;
  }  

  // here start's 'the real thing',
  // readin the pho-file
  if (parse_argument_string(argc, argv, "-i", &inFileName)==RETURN_OK) {
    argNum -= 2;
     std::ifstream inFile(inFileName);
    if (inFile.good()) {
      inPhrase.readPhoFile(inFile, glob);
      inFile.close();
      inPhrase.calcMeanF0();
    } else {
      error("couldn't open Pho-File: " +  std::string(inFileName) + "\n", -1);
    }
  } else {
    usage();
  }  
  


  // read in diphon values and assign to phones
  inPhrase.readPhonData(diphonBaseName, glob);

   std::cout << "original phrase has mean F0-Val of "<<inPhrase.MeanF0()/10<<" Hz and F0-Range of "<<inPhrase.F0Range()<<" Semitones\n";
  
  if (parse_argument_string(argc, argv, "-mf", &modFileName)==RETURN_OK) {
    argNum -= 2;
     std::ifstream modFile(modFileName);
    if (modFile.good()) {
      while  (getline(modFile, buffer)) {
	if (buffer != "") {
	   std::vector< std::string> bufferVec;
	  bufferVec = string2vec(buffer);
	  if (bufferVec.size()>=1) {
	     std::string argName = bufferVec[0];
	    if (argName != "#"&&bufferVec.size()>=1) {
	      // modify duration parameters
	      if (argName == "-changeSpeechRate") {
		if (bufferVec.size()>=4) {
		  uint rate = atoi(bufferVec[1].c_str());
		  if (rate < MIN_SPEECHRATE || rate > MAX_SPEECHRATE)
		    error ("emoSyn:rate < MIN_SPEECHRATE || rate > MAX_SPEECHRATE", -3);
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  int method = atoi(bufferVec[3].c_str());
		  if (rate!=100) {
		    inPhrase.changeSpeechRate(rate, glob, method);
		  }
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      
	      if (argName  == "-changeDurStressed") {
		if (bufferVec.size()>=4) {
		  int rate = atoi(bufferVec[1].c_str());
		  int both = atoi(bufferVec[2].c_str());
		  glob.changeDurMethod = atoi(bufferVec[3].c_str());
		  if (rate!=100) 
		    inPhrase.changeDurStressed(rate, both, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
		
	      }
	      if (argName == "-changeDurNonStressed") {
		if (bufferVec.size()>=4) {
		  int rate = atoi(bufferVec[1].c_str());
		  int both = atoi(bufferVec[2].c_str());
		  glob.changeDurMethod = atoi(bufferVec[3].c_str());
		  if (rate!=100) 
		    inPhrase.changeDurNonStressed(rate, both, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }	
	      if (argName == "-changeDurVowels") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100) {
		    inPhrase.changeDurManner(long_vowel, rate, glob); 
		    inPhrase.changeDurManner(short_vowel, rate, glob); 
		  }  
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurLiquides") {
		if (bufferVec.size()>=3) { 
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		if (rate!=100)
		  inPhrase.changeDurManner(liquide, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurNasals") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changeDurManner(nasal, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurFricV") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changeDurManner(fricative_voiced, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurFricVL") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changeDurManner(fricative_voiceless, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurPlosV") {
		if (bufferVec.size()>=3) { 
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changeDurManner(stop_voiced, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurPlosVL") {
		if (bufferVec.size()>=3) { 
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changeDurManner(stop_voiceless, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeDurSilence") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  glob.changeDurMethod = atoi(bufferVec[2].c_str());
		  if (rate!=100) 
		    inPhrase.changeDurManner(silence, rate, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      // modify intensity
	      if (argName == "-stressedIntensity") {
		if (bufferVec.size()>=3) {
		  int dBVal = atoi(bufferVec[1].c_str());
		  int both = atoi(bufferVec[2].c_str());
		  if (dBVal!=0) 
		    inPhrase.changeStressedInt(dBVal, both, glob); 
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      
	      // modify pitch-contour
	      if (argName == "-changeMeanF0") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=100)
		    inPhrase.changeMeanF0(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeStressedMeanF0") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  int both = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changeStressedAvrF0(rate, both, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changePreStressedMeanF0") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  int both = atoi(bufferVec[2].c_str());
		  if (rate!=100)
		    inPhrase.changePreStressedAvrF0(rate, both, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-smootheF0") {
		if (bufferVec.size()>=2) {
		  int winsize = atoi(bufferVec[1].c_str());
		  if (winsize>0)
		    inPhrase.smootheF0(winsize, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }	    
	      if (argName == "-changePitchContourStressed") {
		if (bufferVec.size()>=4) {
		  CONTOUR_TYPE contType = (CONTOUR_TYPE) atoi(bufferVec[1].c_str());
		  uint gradient = atoi(bufferVec[2].c_str());
		  int both = atoi(bufferVec[3].c_str());
		  if (gradient!=0 || contType == straight)
		    inPhrase.changePitchContourStressed(contType, gradient, both, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeLastSylContour") {
		if (bufferVec.size()>=3) {
		  CONTOUR_TYPE contType = (CONTOUR_TYPE) atoi(bufferVec[1].c_str());
		  uint gradient = atoi(bufferVec[2].c_str());
		  if (gradient!=0 || contType == straight)
		    inPhrase.changeLastSylContour(contType, gradient, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeF0Range") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=100)
		    inPhrase.changeF0Range(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changeF0Variability") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=100)
		    inPhrase.changeVariability(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changePhraseContour") {
		if (bufferVec.size()>=3) {
		  CONTOUR_TYPE contType = (CONTOUR_TYPE) atoi(bufferVec[1].c_str());		
		  int rate = atoi(bufferVec[2].c_str());
		  if (rate!=100 || contType == straight)
		    inPhrase.changePhraseContour(contType, rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-changePhraseContourToAccent") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=100)
		    inPhrase.changePhraseContourToAccent(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-addWaves") {
		if (bufferVec.size()>=4) {
		  int accRate = atoi(bufferVec[1].c_str());
		  int nonAccRate = atoi(bufferVec[2].c_str());
		  int method = atoi(bufferVec[3].c_str());
		  if (accRate!=100||nonAccRate!=100)
		    inPhrase.addWave(accRate, nonAccRate, method, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      // voice/speaking-style modifications: 
	      if (argName == "-overshootVowels") {
		if (bufferVec.size()>=3) {
		  ACCENT_TYPE accent = (ACCENT_TYPE) atoi(bufferVec[1].c_str());
		  int rate = atoi(bufferVec[2].c_str());
		  if (rate!=0)
		    inPhrase.overshootVowels(accent, rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-undershootVowels") {
		if (bufferVec.size()>=3) {
		  ACCENT_TYPE accent = (ACCENT_TYPE) atoi(bufferVec[1].c_str());
		  int rate = atoi(bufferVec[2].c_str());
		  if (rate!=0)
		    inPhrase.undershootVowels(accent, rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-spreadLips") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.spread(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-roundedLips") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.rounded(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-headSize") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.headSize(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-coarticulation") {
		if (bufferVec.size()>=3) {
		  int rate = atoi(bufferVec[1].c_str());
		  CO_TYPE coType  = (CO_TYPE) atoi(bufferVec[2].c_str());
		  if (rate!=0)
		    inPhrase.coarticulation(rate, coType, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-assimilateConsonants") {
		inPhrase.assimilateConsonants(glob);
	      }
	      if (argName == "-jitter") {
		if (bufferVec.size()>=4) {
		  ACCENT_TYPE accent = (ACCENT_TYPE) atoi(bufferVec[1].c_str());
		  int rate = atoi(bufferVec[2].c_str());
		  int method = atoi(bufferVec[3].c_str());
		  if (rate!=0)
		    inPhrase.addJitter(accent, rate, method, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-tense") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.addTense(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-breathy") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.addBreathy(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-whispery") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.addWhisper(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-creaky") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.addCreaky(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-laryngealized") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.addLaryngealized(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	      if (argName == "-falsetto") {
		if (bufferVec.size()>=2) {
		  int rate = atoi(bufferVec[1].c_str());
		  if (rate!=0)
		    inPhrase.addFalsett(rate, glob);
		} else
		  error("missing argument in modFile at arg: "+argName+"\n", -1);
	      }
	    }
	  }
	}
      }
      modFile.close();
    } else {
      error("couldn't open Mod-File: " +  std::string(modFileName) + "\n", -1);
    } 
  }
 
  inPhrase.modelKlattParameters(glob);
   
  inPhrase.modelFeatures(glob);

   std::cout << "modified phrase has mean F0-Val of "<<inPhrase.MeanF0()/10<<" Hz and F0-Range of "<<inPhrase.F0Range()<<" Semitones\n";
 
  if (RETURN_OK==parse_argument_flag(argc, argv, "-printSylStats")) {
    argNum -= 1;    
    inPhrase.printSyllableVec( std::cerr);
  }  

  // inPhrase.printPhonFeatures( std::cout);
  

  if (parse_argument_string(argc, argv, "-ko", &outFileName)==RETURN_OK) {
     std::ofstream outFile(outFileName);
    if (outFile.good()) {
      inPhrase.printKlattFile(outFile);
      outFile.close();
    } else {
      error("problems writing to: " +  std::string(outFileName) + "\n", -1);
    }
    argNum -= 2;
  }
  if (parse_argument_string(argc, argv, "-so", &outFileName)==RETURN_OK) {
     std::ofstream outFile(outFileName);
    if (outFile.good()) {
      inPhrase.printSenSynFile(glob, outFile);
      outFile.close();
    } else {
      error("problems writing to: " +  std::string(outFileName) + "\n", -1);
    }
    argNum -= 2;
  }
  if (parse_argument_flag(argc, argv, "-po")==RETURN_OK) {
    inPhrase.printPhoFile( std::cout, glob);
    argNum--;
  }
  /*						  
    if (parse_argument_flag(argc, argv, "-lo")==RETURN_OK) {
    inPhrase.printLabelFile( std::cout, glob);
    argNum--;
  }
  */
  if (parse_argument_string(argc, argv, "-lo", &outFileName)==RETURN_OK) {
     std::ofstream outFile(outFileName);
    if (outFile.good()) {
      inPhrase.printLabelFile(outFile, glob);
      outFile.close();
    } else {
      error("problems writing to: " +  std::string(outFileName) + "\n", -1);
    }
    argNum -= 2;
  }
  if (argNum != 0)
    warn("unrecognized argument\n");
  return 0;
}

void usage() {
   std::cout << "\n"
       << "emoSyn: program to modify pho-files and generate klatt-files\n"
       << "usage:\n<-i pho-file>\t\t:input file\n"
       << "[-v]\t:print version and exit\n"    
       << "[-h]\t:print usage and exit\n"    
       << "[-vb]\t:verbose mode\n"    
       << "[-printSylStats]\n"    
       << "[-mf modFileName]\t:file with modification parameters\n"    
       << "[-po]\t\t\t:output stdout pho-file\n"    
       << "[-lo <OF>]\t\t:output to <OF> esps label-file\n"
       << "<-kd klatt-defaultfile>\t:file with default parameters\n"    
       << "<-db diphon-base name>\t:name of dir with diphon-files\n"    
       << "[-testKlatt]\t\t:output 1 sec test-paramfile to klattTest.par\n"
       << "[-testSensyn parFile]\t:output 1 sec test-paramfile to klattTest.doc\n"
       << "[-makePhoFromDB phonFile]\t\n"
       <<"[-so klatt-file]\t:output senSyn-parameter-file\n"
       <<"[-ko klatt-file]\t:output klatt-parameter-file\n"
       <<"[-use4Freq -use5Freq -use3BW -use5BW]\n"
       << "\n";
  exit(1);
}
/**
* reads in the default valus for the klatt-parameters from file named fileName 
*
* @param globalsT &glob
* @param  std::string fileName
*/
void initKlattDefaults(globalsT &glob,  std::string fileName){
   std::string buffer, token;
  int lineCounter=0;

  glob.use4Freq = true; // default is
  glob.use5Freq = true; // usage of all 5 formantfreqs
  glob.changeDurMethod = TIME_ALIGNED;
  glob.verbose = false;
  glob.warningsOff = true;
  glob.copyDB = false;
  glob.copysynthesis = true;
  
  glob.senSyn=true; // default is output for sensyn-synthesizer
  
  
  glob.f0Dyn = false; glob.f1Dyn = false; glob.f2Dyn = false; glob.f3Dyn = false; glob.f4Dyn = false; glob.f5Dyn = false; glob.f6Dyn = false; glob.b1Dyn = false; glob.b2Dyn = false; glob.b3Dyn = false; glob.b4Dyn = false; glob.b5Dyn = false; glob.b6Dyn = false; glob.b2pDyn = false; glob.b3pDyn = false; glob.b4pDyn = false; glob.b5pDyn = false; glob.b6pDyn = false; glob.avDyn = false; glob.ahDyn = false; glob.oqDyn = false; glob.aturbDyn = false; glob.afDyn = false; glob.abDyn = false; glob.tlDyn = false; glob.flDyn = false; glob.anvDyn = false; glob.fnzDyn = false; glob.bnzDyn = false; glob.fnpDyn = false; glob.bnpDyn = false; glob.sqDyn = false; glob.diDyn = false; glob.df1Dyn = false; glob.db1Dyn = false; glob.ftpDyn = false; glob.btpDyn = false; glob.ftzDyn = false; glob.btzDyn = false; glob.a2fDyn = false; glob.a3fDyn = false; glob.a4fDyn = false; glob.a5fDyn = false; glob.a6fDyn = false; glob.a1vDyn = false; glob.a2vDyn = false; glob.a3vDyn = false; glob.a4vDyn = false; glob.atvDyn = false;
  
  std::ifstream inFile(fileName.c_str());
  if (inFile.good()) {
    while  (getline(inFile, buffer)) {
      if (buffer != "") {
	std::istrstream ist(buffer.c_str());
	ist>>token; 
	if (token != "#") {
	  ist>>token; // sec. entry is value
	  switch (lineCounter) {
	  case 0: glob.ui = atoi(token.c_str());
	    break;
	  case 1: glob.sr = atoi(token.c_str());
	    break;
	  case 2: glob.nf = atoi(token.c_str());
	    break;
	  case 3: glob.ss = atoi(token.c_str());
	    break;
	  case 4: glob.rs = atoi(token.c_str());
	    break;
	  case 5: glob.sb = atoi(token.c_str());
	    break;
	  case 6: glob.cp = atoi(token.c_str());
	    break;
	  case 7: glob.os = atoi(token.c_str());
	    break;
	  case 8: glob.gv = atoi(token.c_str());
	    break;
	  case 9: glob.gh = atoi(token.c_str());
	    break;
	  case 10: glob.gf = atoi(token.c_str());
	    break;
	  case 11: glob.f0 = atoi(token.c_str());
	    break;
	  case 12: glob.av = atoi(token.c_str());
	    break;
	  case 13: glob.ah = atoi(token.c_str());
	    break;
	  case 14: glob.af = atoi(token.c_str());
	    break;
	  case 15: glob.tl = atoi(token.c_str());
	    break;
	  case 16: glob.oq = atoi(token.c_str());
	    break;
	  case 17: glob.sq = atoi(token.c_str());
	    break;
	  case 18: glob.fl = atoi(token.c_str());
	    break;
	  case 19: glob.di = atoi(token.c_str());
	    break;
	  case 20: glob.aturb = atoi(token.c_str());
	    break;
	  case 21: glob.avp = atoi(token.c_str());
	    break;
	  case 22: glob.gain = atoi(token.c_str());
	    break;
	  case 23: glob.fnz = atoi(token.c_str());
	    break;
	  case 24: glob.bnz = atoi(token.c_str());
	    break;
	  case 25: glob.fnp = atoi(token.c_str());
	    break;
	  case 26: glob.bnp = atoi(token.c_str());
	    break;
	  case 27: glob.ftp = atoi(token.c_str());
	    break;
	  case 28: glob.btp = atoi(token.c_str());
	    break;
	  case 29: glob.ftz = atoi(token.c_str());
	    break;
	  case 30: glob.btz = atoi(token.c_str());
	    break;
	  case 31: glob.df1 = atoi(token.c_str());
	    break;
	  case 32: glob.db1 = atoi(token.c_str());
	    break;
	  case 33: glob.f1 = atoi(token.c_str());
	    break;
	  case 34: glob.f2 = atoi(token.c_str());
	    break;
	  case 35: glob.f3 = atoi(token.c_str());
	    break;
	  case 36: glob.f4 = atoi(token.c_str());
	    break;
	  case 37: glob.f5 = atoi(token.c_str());
	    break;
	  case 38: glob.f6 = atoi(token.c_str());
	    break;
	  case 39: glob.b1 = atoi(token.c_str());
	    break;
	  case 40: glob.b2 = atoi(token.c_str());
	    break;
	  case 41: glob.b3 = atoi(token.c_str());
	    break;
	  case 42: glob.b4 = atoi(token.c_str());
	    break;
	  case 43: glob.b5 = atoi(token.c_str());
	    break;
	  case 44: glob.b6 = atoi(token.c_str());
	    break;
	  case 45: glob.anv = atoi(token.c_str());
	    break;
	  case 46: glob.ab = atoi(token.c_str());
	    break;
	  case 47: glob.a2f = atoi(token.c_str());
	    break;
	  case 48: glob.a3f = atoi(token.c_str());
	    break;
	  case 49: glob.a4f = atoi(token.c_str());
	    break;
	  case 50: glob.a5f = atoi(token.c_str());
	    break;
	  case 51: glob.a6f = atoi(token.c_str());
	    break;
	  case 52: glob.b2p = atoi(token.c_str());
	    break;
	  case 53: glob.b3p = atoi(token.c_str());
	    break;
	  case 54: glob.b4p = atoi(token.c_str());
	    break;
	  case 55: glob.b5p = atoi(token.c_str());
	    break;
	  case 56: glob.b6p = atoi(token.c_str());
	    break;
	  case 57: glob.a1v = atoi(token.c_str());
	    break;
	  case 58: glob.a2v = atoi(token.c_str());
	    break;
	  case 59: glob.a3v = atoi(token.c_str());
	    break;
	  case 60: glob.a4v = atoi(token.c_str());
	    break;
	  case 61: glob.atv = atoi(token.c_str());
	    break;
	  case 62: glob.a1 = atoi(token.c_str());
	    break;
	  case 63: glob.b1p = atoi(token.c_str());
	    break;
	  case 64: glob.a2 = atoi(token.c_str());
	    break;
	  case 65: glob.a3 = atoi(token.c_str());
	    break;
	  case 66: glob.a4 = atoi(token.c_str());
	    break;
	  case 67: glob.a5 = atoi(token.c_str());
	    break;
	  case 68: glob.a6 = atoi(token.c_str());
	    break;
	  case 69: glob.copysynthesis = (bool) atoi(token.c_str());
	    break;	    
  default: 
	    error ("something's wrong in klatt init-file: "+fileName+" (might be a space in an empty line)\n", -3);
	  }
	  //  std::cout << lineCounter << " " << token << "\n";
	  lineCounter++;
	} 
      } 
    }
    inFile.close();

  } else {
    error("can't open klatt-init file: "+fileName+"\n", -1);
  } // if (inFile.good())
  
}
