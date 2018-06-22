/**
 * PHON.cc
 *
 * part of emoSyn
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

#include "phon.h"

void phon::setName(std::string newName) {
  name = newName;
  initMannerPlaceType(name);
}


void phon::setPhonFeatures(PHON_FEATURES newPhonFeatures) {
  phonFeatures = newPhonFeatures;
}


void phon::setSteadyStart(uint newSteadyStart) {
  steadyStart = newSteadyStart;
}
void phon::setSteadyEnd(uint newSteadyEnd) {
  steadyEnd = newSteadyEnd;
}
void phon::setBurstStart(uint newBurstStart) {
  burstStart = newBurstStart;
}
void phon::setAspStart(uint newAspStart) {
  aspStart = newAspStart;
}


void phon::setF0ValVec(std::vector<uint>& newF0ValVec) {
  f0ValVec = newF0ValVec;
  meanF0 = (uint) mean(f0ValVec);
}
void phon::setF0TimeVec(std::vector<uint>& newF0TimeVec) {
  f0TimeVec = newF0TimeVec;
}

uint phon::MeanF0() {
  return meanF0;
}


std::string phon::Name() {
  return name;
}

uint phon::Dur() {
  return dur;
}
PHON_TYPE phon::Type() {
  return type;
}
PHON_MANNER phon::Manner() {
  return manner;
}
PHON_PLACE phon::Place() {
  return place;
}
bool phon::Voiced() {
  return voiced;
}
bool phon::Diphtong() {
  return diphtong;
}
uint phon::FrameNum() {
  return frameNum;
}

PHON_FEATURES phon::PhonFeatures() {
  return phonFeatures;
}

std::vector <uint> phon::F0ValVec() {
  return f0ValVec;
}
std::vector <uint> phon::AmpVec() {return ampVec;}
std::vector <uint> phon::F0Vec() {return f0Vec;}
std::vector <uint> phon::F1Vec() {return f1Vec;}
std::vector <uint> phon::F2Vec() {return f2Vec;}
std::vector <uint> phon::F3Vec() {return f3Vec;}
std::vector <uint> phon::F4Vec() {return f4Vec;}
std::vector <uint> phon::F5Vec() {return f5Vec;}
std::vector <uint> phon::F6Vec() {return f6Vec;}
std::vector <uint> phon::B1Vec() {return b1Vec;}
std::vector <uint> phon::B2Vec() {return b2Vec;}
std::vector <uint> phon::B3Vec() {return b3Vec;}
std::vector <uint> phon::B4Vec() {return b4Vec;}
std::vector <uint> phon::B5Vec() {return b5Vec;}
std::vector <uint> phon::B6Vec() {return b6Vec;}
std::vector <uint> phon::A1Vec() {return a1Vec;}
std::vector <uint> phon::A2Vec() {return a2Vec;}
std::vector <uint> phon::A3Vec() {return a3Vec;}
std::vector <uint> phon::A4Vec() {return a4Vec;}
std::vector <uint> phon::A5Vec() {return a5Vec;}
std::vector <uint> phon::A6Vec() {return a6Vec;}
std::vector <uint> phon::B1PVec() {return b1pVec;}
std::vector <uint> phon::B2PVec() {return b2pVec;}
std::vector <uint> phon::B3PVec() {return b3pVec;}
std::vector <uint> phon::B4PVec() {return b4pVec;}
std::vector <uint> phon::B5PVec() {return b5pVec;}
std::vector <uint> phon::B6PVec() {return b6pVec;}
std::vector <uint> phon::AvVec() {return avVec;}
std::vector <uint> phon::AhVec() {return ahVec;}
std::vector <uint> phon::OqVec() {return oqVec;}
std::vector <uint> phon::AturbVec() {return aturbVec;}
std::vector <uint> phon::AfVec() {return afVec;}
std::vector <uint> phon::AbVec() {return abVec;}
std::vector <uint> phon::AvpVec() {return avpVec;}
std::vector <uint> phon::TlVec() {return tlVec;}
std::vector <uint> phon::FlVec() {return flVec;}
std::vector <uint> phon::GainVec() {return gainVec;}
std::vector <uint> phon::AnvVec() {return anvVec;}
std::vector <uint> phon::FnzVec() {return fnzVec;}
std::vector <uint> phon::BnzVec() {return bnzVec;}
std::vector <uint> phon::FnpVec() {return fnpVec;}
std::vector <uint> phon::BnpVec() {return bnpVec;}
std::vector <uint> phon::SqVec() {return sqVec;}
std::vector <uint> phon::DiVec() {return diVec;}
std::vector <uint> phon::Df1Vec() {return df1Vec;}
std::vector <uint> phon::Db1Vec() {return db1Vec;}
std::vector <uint> phon::FtpVec() {return ftpVec;}
std::vector <uint> phon::BtpVec() {return btpVec;}
std::vector <uint> phon::FtzVec() {return ftzVec;}
std::vector <uint> phon::BtzVec() {return btzVec;}
std::vector <uint> phon::A2fVec() {return a2fVec;}
std::vector <uint> phon::A3fVec() {return a3fVec;}
std::vector <uint> phon::A4fVec() {return a4fVec;}
std::vector <uint> phon::A5fVec() {return a5fVec;}
std::vector <uint> phon::A6fVec() {return a6fVec;}
std::vector <uint> phon::A1vVec() {return a1vVec;}
std::vector <uint> phon::A2vVec() {return a2vVec;}
std::vector <uint> phon::A3vVec() {return a3vVec;}
std::vector <uint> phon::A4vVec() {return a4vVec;}
std::vector <uint> phon::AtvVec() {return atvVec;}



std::vector <uint> phon::F0TimeVec() {
  return f0TimeVec;
}


uint  phon::SteadyStart() {
  return steadyStart;
}

uint  phon::SteadyEnd() {
  return steadyEnd;
}

uint phon::BurstStart() {
  return burstStart;
}

uint  phon::AspStart() {
  return aspStart;
}

void phon::initMannerPlaceType(std::string name) {
  char *c_tmp;
  c_tmp = (char *) malloc(100);
  strcpy(c_tmp, name.c_str());
  manner = classify_german(c_tmp); 
  switch(manner) {
  case long_vowel: 
    type = vowel;
    voiced = true;
    break;
  case short_vowel:
    type = vowel;
    voiced = true;
    break;
  case liquide: 
    type = consonant;
    voiced = true;
    break;
  case nasal: 
    type = consonant;
    voiced = true;
    break;
  case fricative_voiced: 
    type = consonant;
    voiced = true;
    break;
  case fricative_voiceless: 
    type = consonant;
    voiced = false;
    break;
  case stop_voiced: 
    type = consonant;
    voiced = true;
    break;
  case stop_voiceless: 
    type = consonant;
    voiced = false;
    break;
  case silence:
    type = consonant;
    voiced = false;
    break;
  default :
    error("phon::initMannerPlaceType: undefined phon-type/n", -3);
  }
  if (type == consonant) {
    if (name == "t") { 
      place = alveolar;
    }
    else if (name == "d") {
      place = alveolar;
    }
    else if (name == "p") { 
      place = bilabial;
    }
    else if (name == "b") { 
      place = bilabial;
    }
    else if (name == "k") {
      place = velar;
    }
    else if (name == "g") { 
      place = velar;
    }
    else if (name == "f") {
      place = labial;
    }
    else if (name == "v") { 
      place = labial;
    }
    else if (name == "s") {
      place = alveolar;
    }
    else if (name == "z") { 
      place = alveolar;
    }
    else if (name == "S") { 
      place = postalveolar;
    }
    else if (name == "j") {
      place = palatal;
    }
    else if (name == "C") {
      place = palatal;
    }
    else if (name == "x") {
      place = velar;
    }
    else if (name == "h") { 
      place = glottal;
    }
    else if (name == "?") { 
      place = glottal;
    }
    else if (name == "l") { 
      place = alveolar;
    }
    else if (name == "R") { 
      place = uvular;
      }
    else if (name == "m") {
      place = bilabial;
    }
    else if (name == "n") {
      place = alveolar;
    }
    else if (name == "N") { 
      place = velar;
    }
  } else {
    place = noPlace;
  }
  if (type == vowel) {
    if (name == "6") 
      formantQuadrant = bottomRight;
    else if (name == "@") 
      formantQuadrant = topLeft;
    else if (name == "I") 
      formantQuadrant = topLeft;
    else if (name == "Y") 
      formantQuadrant = topLeft;
    else if (name == "E") 
      formantQuadrant = bottomLeft;
    else if (name == "9") 
      formantQuadrant = topRight;
    else if (name == "U") 
      formantQuadrant = topRight;
    else if (name == "O") 
      formantQuadrant = bottomRight;
    else if (name == "a") 
      formantQuadrant = bottomLeft;
    else if (name == "i:") 
      formantQuadrant = topLeft;
    else if (name == "y:") 
      formantQuadrant = topLeft;
    else if (name == "e:") 
      formantQuadrant = topLeft;
    else if (name == "E:") 
      formantQuadrant = bottomLeft;
    else if (name == "2:") 
      formantQuadrant = bottomLeft;
    else if (name == "u:") 
      formantQuadrant = topRight;
    else if (name == "o:") 
      formantQuadrant = topRight;
    else if (name == "a:") 
      formantQuadrant = bottomLeft;
    else
      formantQuadrant = noQuadrant;
  } else {
    formantQuadrant = noQuadrant;
  }  
  if (type == vowel) {
    if (name == "aI" || name == "OY" || name == "aU" || name == "I6") 
      diphtong = true;
    else
      diphtong = false;
  } else {
    diphtong = false;
  }
}

void phon::modelIntonation(globalsT &glob) {
  f0Vec = modelTrack(name, frameNum, f0ValVec, f0TimeVec);
  glob.f0Dyn=true;
}

// constructor
phon::phon() {

}

phon::phon(std::string newname, uint newdur, globalsT klatt_globals) {
  name = newname;
  initMannerPlaceType(name);
  dur = newdur;
  frameNum = (uint) dur/klatt_globals.ui;

  steadyStart = 0;
  steadyEnd = frameNum;
  burstStart = frameNum;
  aspStart = frameNum;
  
  for (uint i=0; i<frameNum; i++){
    ampVec.push_back(60);
    f0Vec.push_back(klatt_globals.f0);
    f1Vec.push_back(klatt_globals.f1);
    f2Vec.push_back(klatt_globals.f2);
    f3Vec.push_back(klatt_globals.f3);
    f4Vec.push_back(klatt_globals.f4);
    f5Vec.push_back(klatt_globals.f5);
    f6Vec.push_back(klatt_globals.f6);
    b1Vec.push_back(klatt_globals.b1);
    b2Vec.push_back(klatt_globals.b2);
    b3Vec.push_back(klatt_globals.b3);
    b4Vec.push_back(klatt_globals.b4);
    b5Vec.push_back(klatt_globals.b5);
    b6Vec.push_back(klatt_globals.b6);
    a1Vec.push_back(klatt_globals.a1);
    a2Vec.push_back(klatt_globals.a2);
    a3Vec.push_back(klatt_globals.a3);
    a4Vec.push_back(klatt_globals.a4);
    a5Vec.push_back(klatt_globals.a5);
    a6Vec.push_back(klatt_globals.a6);
    b1pVec.push_back(klatt_globals.b1p);
    b2pVec.push_back(klatt_globals.b2p);
    b3pVec.push_back(klatt_globals.b3p);
    b4pVec.push_back(klatt_globals.b4p);
    b5pVec.push_back(klatt_globals.b5p);
    b6pVec.push_back(klatt_globals.b6p);
    avVec.push_back(klatt_globals.av);
    ahVec.push_back(klatt_globals.ah);
    oqVec.push_back(klatt_globals.oq);
    aturbVec.push_back(klatt_globals.aturb);
    afVec.push_back(klatt_globals.af);
    abVec.push_back(klatt_globals.ab);
    avpVec.push_back(klatt_globals.avp);
    tlVec.push_back(klatt_globals.tl);
    flVec.push_back(klatt_globals.fl);
    gainVec.push_back(klatt_globals.gain);
    anvVec.push_back(klatt_globals.anv);
    fnzVec.push_back(klatt_globals.fnz);
    bnzVec.push_back(klatt_globals.bnz);
    fnpVec.push_back(klatt_globals.fnp);
    bnpVec.push_back(klatt_globals.bnp);
    sqVec.push_back(klatt_globals.sq);
    diVec.push_back(klatt_globals.di);
    df1Vec.push_back(klatt_globals.df1);
    db1Vec.push_back(klatt_globals.db1);
    ftpVec.push_back(klatt_globals.ftp);
    btpVec.push_back(klatt_globals.btp);
    ftzVec.push_back(klatt_globals.ftz);
    btzVec.push_back(klatt_globals.btz);
    a2fVec.push_back(klatt_globals.a2f);
    a3fVec.push_back(klatt_globals.a3f);
    a4fVec.push_back(klatt_globals.a4f);
    a5fVec.push_back(klatt_globals.a5f);
    a6fVec.push_back(klatt_globals.a6f);
    a1vVec.push_back(klatt_globals.a1v);
    a2vVec.push_back(klatt_globals.a2v);
    a3vVec.push_back(klatt_globals.a3v);
    a4vVec.push_back(klatt_globals.a4v);
    atvVec.push_back(klatt_globals.atv);
  }
}

void phon::printName(std::ostream &outFile) {
  outFile << name;
}

void phon::printKlattFrames(std::ostream &outFile) {
  for (uint i=0; i<frameNum;i++) {
    if(f0Vec[i] > maxF0) std::cerr << "WARNING: phon:"+name+", f0Val="<<f0Vec[i]<<" > maxF0\n";
    if(f0Vec[i] < minF0 && f0Vec[i]!=0) std::cerr << "WARNING: phon:"+name+", f0Val="<<f0Vec[i]<<" < minF0\n";
    if(f1Vec[i] > maxF1) std::cerr << "WARNING: phon:"+name+", f1Val="<<f1Vec[i]<<" > maxF1\n";
    if(f2Vec[i] > maxF2) std::cerr << "WARNING: phon:"+name+", f2Val="<<f2Vec[i]<<" > maxF2\n";
    if(f3Vec[i] > maxF3) std::cerr << "WARNING: phon:"+name+", f3Val="<<f3Vec[i]<<" > maxF3\n";
    
    if (ampVec[i]>maxVal) warn ("unplausibel value for param: amp at phon: "+name+"\n");
    if (f0Vec[i]>maxVal) warn ("unplausibel value for param: f0 at phon: "+name+"\n");
    if (f1Vec[i]>maxVal) warn ("unplausibel value for param: f1 at phon: "+name+"\n");
    if (f2Vec[i]>maxVal) warn ("unplausibel value for param: f2 at phon: "+name+"\n");
    if (f3Vec[i]>maxVal) warn ("unplausibel value for param: f3 at phon: "+name+"\n");
    if (f4Vec[i]>maxVal) warn ("unplausibel value for param: f4 at phon: "+name+"\n");
    if (f5Vec[i]>maxVal) warn ("unplausibel value for param: f5 at phon: "+name+"\n");
    if (f6Vec[i]>maxVal) warn ("unplausibel value for param: f6 at phon: "+name+"\n");
    if (b1Vec[i]>maxVal) warn ("unplausibel value for param: b1 at phon: "+name+"\n");
    if (b2Vec[i]>maxVal) warn ("unplausibel value for param: b2 at phon: "+name+"\n");
    if (b3Vec[i]>maxVal) warn ("unplausibel value for param: b3 at phon: "+name+"\n");
    if (b4Vec[i]>maxVal) warn ("unplausibel value for param: b4 at phon: "+name+"\n");
    if (b5Vec[i]>maxVal) warn ("unplausibel value for param: b5 at phon: "+name+"\n");
    if (b6Vec[i]>maxVal) warn ("unplausibel value for param: b6 at phon: "+name+"\n");
    if (a1Vec[i]>maxVal) warn ("unplausibel value for param: a1 at phon: "+name+"\n");
    if (a2Vec[i]>maxVal) warn ("unplausibel value for param: a2 at phon: "+name+"\n");
    if (a3Vec[i]>maxVal) warn ("unplausibel value for param: a3 at phon: "+name+"\n");
    if (a4Vec[i]>maxVal) warn ("unplausibel value for param: a4 at phon: "+name+"\n");
    if (a5Vec[i]>maxVal) warn ("unplausibel value for param: a5 at phon: "+name+"\n");
    if (a6Vec[i]>maxVal) warn ("unplausibel value for param: a6 at phon: "+name+"\n");
    if (b1pVec[i]>maxVal) warn ("unplausibel value for param: b1p at phon: "+name+"\n");
    if (b2pVec[i]>maxVal) warn ("unplausibel value for param: b2p at phon: "+name+"\n");
    if (b3pVec[i]>maxVal) warn ("unplausibel value for param: b3p at phon: "+name+"\n");
    if (b4pVec[i]>maxVal) warn ("unplausibel value for param: b4p at phon: "+name+"\n");
    if (b5pVec[i]>maxVal) warn ("unplausibel value for param: b5p at phon: "+name+"\n");
    if (b6pVec[i]>maxVal) warn ("unplausibel value for param: b6p at phon: "+name+"\n");
    if (avVec[i]>maxVal) warn ("unplausibel value for param: av at phon: "+name+"\n");
    if (ahVec[i]>maxVal) warn ("unplausibel value for param: ah at phon: "+name+"\n");
    if (oqVec[i]>maxVal) warn ("unplausibel value for param: oq at phon: "+name+"\n");
    if (aturbVec[i]>maxVal) warn ("unplausibel value for param: aturb at phon: "+name+"\n");
    if (afVec[i]>maxVal) warn ("unplausibel value for param: af at phon: "+name+"\n");
    if (abVec[i]>maxVal) warn ("unplausibel value for param: ab at phon: "+name+"\n");
    if (avpVec[i]>maxVal) warn ("unplausibel value for param: avp at phon: "+name+"\n");
    if (tlVec[i]>maxVal) warn ("unplausibel value for param: tl at phon: "+name+"\n");
    if (flVec[i]>maxVal) warn ("unplausibel value for param: fl at phon: "+name+"\n");
    if (gainVec[i]>maxVal) warn ("unplausibel value for param: gain at phon: "+name+"\n");
    if (anvVec[i]>maxVal) warn ("unplausibel value for param: anv at phon: "+name+"\n");
    if (fnzVec[i]>maxVal) warn ("unplausibel value for param: fnz at phon: "+name+"\n");
    if (bnzVec[i]>maxVal) warn ("unplausibel value for param: bnz at phon: "+name+"\n");
    if (fnpVec[i]>maxVal) warn ("unplausibel value for param: fnp at phon: "+name+"\n");
    if (bnpVec[i]>maxVal) warn ("unplausibel value for param: bnp at phon: "+name+"\n");
    if (sqVec[i]>maxVal) warn ("unplausibel value for param: sq at phon: "+name+"\n");
    if (diVec[i]>maxVal) warn ("unplausibel value for param: di at phon: "+name+"\n");
    if (df1Vec[i]>maxVal) warn ("unplausibel value for param: df1 at phon: "+name+"\n");
    if (db1Vec[i]>maxVal) warn ("unplausibel value for param: db1 at phon: "+name+"\n");
    if (ftpVec[i]>maxVal) warn ("unplausibel value for param: ftp at phon: "+name+"\n");
    if (btpVec[i]>maxVal) warn ("unplausibel value for param: btp at phon: "+name+"\n");
    if (ftzVec[i]>maxVal) warn ("unplausibel value for param: ftz at phon: "+name+"\n");
    if (btzVec[i]>maxVal) warn ("unplausibel value for param: btz at phon: "+name+"\n");
    if (a2fVec[i]>maxVal) warn ("unplausibel value for param: a2f at phon: "+name+"\n");
    if (a3fVec[i]>maxVal) warn ("unplausibel value for param: a3f at phon: "+name+"\n");
    if (a4fVec[i]>maxVal) warn ("unplausibel value for param: a4f at phon: "+name+"\n");
    if (a5fVec[i]>maxVal) warn ("unplausibel value for param: a5f at phon: "+name+"\n");
    if (a6fVec[i]>maxVal) warn ("unplausibel value for param: a6f at phon: "+name+"\n");
    if (a1vVec[i]>maxVal) warn ("unplausibel value for param: a1v at phon: "+name+"\n");
    if (a2vVec[i]>maxVal) warn ("unplausibel value for param: a2v at phon: "+name+"\n");
    if (a3vVec[i]>maxVal) warn ("unplausibel value for param: a3v at phon: "+name+"\n");
    if (a4vVec[i]>maxVal) warn ("unplausibel value for param: a4v at phon: "+name+"\n");
    if (atvVec[i]>maxVal) warn ("unplausibel value for param: atv at phon: "+name+"\n");
    
    
    outFile <<f0Vec[i]<<" "<<avVec[i]
	    <<" "<<f1Vec[i]<<" "<<b1Vec[i]<<" "<<f2Vec[i]<<" "<<b2Vec[i]<<" "
	    <<f3Vec[i]<<" "<<b3Vec[i]<<" "<<f4Vec[i]<<" "<<b4Vec[i]<<" "<<f5Vec[i]<<" "
	    <<b5Vec[i]<<" "<<f6Vec[i]<<" "<<b6Vec[i]<<" "<<fnzVec[i]<<" "<<bnzVec[i]<<" "
	    <<fnpVec[i]<<" "<<bnpVec[i]<<" "<<ahVec[i]<<" "<<oqVec[i]<<" "
	    <<aturbVec[i]<<" "<<tlVec[i]<<" "<<afVec[i]<<" "<<flVec[i]<<" "
	    <<a1Vec[i]<<" "<<b1pVec[i]<<" "<<a2Vec[i]<<" "<<b2pVec[i]<<" "<<a3Vec[i]<<" "
	    <<b3pVec[i]<<" "<<a4Vec[i]<<" "<<b4pVec[i]<<" "<<a5Vec[i]<<" "<<b5pVec[i]<<" "
	    <<a6Vec[i]<<" "<<b6pVec[i]<<" "<<anvVec[i]<<" "<<abVec[i]<<" "<<avpVec[i]<<" "
	    <<gainVec[i]<<"\n"; 
  }
}

void phon::printSenSynFrames(uint start, std::ostream &outFile, globalsT glob) {
  uint time = start;
  for (uint i=0; i<frameNum;i++) {
    //    if(f0Vec[i] > maxF0) std::cerr << "WARNING: f0Val="<<f0Vec[i]<<" > maxF0\n";
    //    if(f0Vec[i] < minF0 && f0Vec[i]!=0) std::cerr << "WARNING: f0Val="<<f0Vec[i]<<" < minF0\n";
    if(f1Vec[i] > maxF1) std::cerr << "WARNING: f1Val="<<f1Vec[i]<<" > maxF1\n";
    if(f2Vec[i] > maxF2) std::cerr << "WARNING: f2Val="<<f2Vec[i]<<" > maxF2\n";
    if(f3Vec[i] > maxF3) std::cerr << "WARNING: f3Val="<<f3Vec[i]<<" > maxF3\n";
    //    fprintf((FILE *)outFile, "%5d", "time");
    outFile.width(4);
    outFile << time ;
    if (glob.f0Dyn) {outFile.width(5); outFile << f0Vec[i];}
    if (glob.avDyn) {outFile.width(5); outFile << avVec[i];}
    if (glob.oqDyn) {outFile.width(5); outFile << oqVec[i];}
    if (glob.sqDyn) {outFile.width(5); outFile << sqVec[i];}
    if (glob.tlDyn) {outFile.width(5); outFile << tlVec[i];}
    if (glob.flDyn) {outFile.width(5); outFile << flVec[i];}
    if (glob.diDyn) {outFile.width(5); outFile << diVec[i];}
    if (glob.ahDyn) {outFile.width(5); outFile << ahVec[i];}
    if (glob.afDyn) {outFile.width(5); outFile << afVec[i];}
    if (glob.f1Dyn) {outFile.width(5); outFile << f1Vec[i];}
    if (glob.b1Dyn) {outFile.width(5); outFile << b1Vec[i];}
    if (glob.df1Dyn) {outFile.width(5); outFile << df1Vec[i];}
    if (glob.db1Dyn) {outFile.width(5); outFile << db1Vec[i];}
    if (glob.f2Dyn) {outFile.width(5); outFile << f2Vec[i];}
    if (glob.b2Dyn) {outFile.width(5); outFile << b2Vec[i];}
    if (glob.f3Dyn) {outFile.width(5); outFile << f3Vec[i];}
    if (glob.b3Dyn) {outFile.width(5); outFile << b3Vec[i];}
    if (glob.f4Dyn) {outFile.width(5); outFile << f4Vec[i];}
    if (glob.b4Dyn) {outFile.width(5); outFile << b4Vec[i];}
    if (glob.f5Dyn) {outFile.width(5); outFile << f5Vec[i];}
    if (glob.b5Dyn) {outFile.width(5); outFile << b5Vec[i];}
    if (glob.f6Dyn) {outFile.width(5); outFile << f6Vec[i];}
    if (glob.b6Dyn) {outFile.width(5); outFile << b6Vec[i];}
    if (glob.fnpDyn) {outFile.width(5); outFile << fnpVec[i];}
    if (glob.bnpDyn) {outFile.width(5); outFile << bnpVec[i];}
    if (glob.fnzDyn) {outFile.width(5); outFile << fnzVec[i];}
    if (glob.bnzDyn) {outFile.width(5); outFile << bnzVec[i];}
    if (glob.ftpDyn) {outFile.width(5); outFile << ftpVec[i];}
    if (glob.btpDyn) {outFile.width(5); outFile << btpVec[i];}
    if (glob.ftzDyn) {outFile.width(5); outFile << ftzVec[i];}
    if (glob.btzDyn) {outFile.width(5); outFile << btzVec[i];}
    if (glob.a2fDyn) {outFile.width(5); outFile << a2fVec[i];}
    if (glob.a3fDyn) {outFile.width(5); outFile << a3fVec[i];}
    if (glob.a4fDyn) {outFile.width(5); outFile << a4fVec[i];}
    if (glob.a5fDyn) {outFile.width(5); outFile << a5fVec[i];}
    if (glob.a6fDyn) {outFile.width(5); outFile << a6fVec[i];}
    if (glob.abDyn) {outFile.width(5); outFile << abVec[i];}
    if (glob.b2pDyn) {outFile.width(5); outFile << b2pVec[i];}
    if (glob.b3pDyn) {outFile.width(5); outFile << b3pVec[i];}
    if (glob.b4pDyn) {outFile.width(5); outFile << b4pVec[i];}
    if (glob.b5pDyn) {outFile.width(5); outFile << b5pVec[i];}
    if (glob.b6pDyn) {outFile.width(5); outFile << b6pVec[i];}
    if (glob.anvDyn) {outFile.width(5); outFile << anvVec[i];}
    if (glob.a1vDyn) {outFile.width(5); outFile << a1vVec[i];}
    if (glob.a2vDyn) {outFile.width(5); outFile << a2vVec[i];}
    if (glob.a3vDyn) {outFile.width(5); outFile << a3vVec[i];}
    if (glob.a4vDyn) {outFile.width(5); outFile << a4vVec[i];}
    if (glob.atvDyn) {outFile.width(5); outFile << atvVec[i];}
    outFile << "\n"; 
    time += glob.ui;
  }
}

  /* *******************************************************************
     void changeMeanF0(uint rate)
     args: rate
     returns: none
     effect: change f0Vals by rate (100=no change)
     *******************************************************************
  */
void phon::changeMeanF0(uint rate) {
  changeMean(f0Vec, rate); // change all
}

  /* *******************************************************************
     void changeAvrInt(uint rate)
     args: rate
     returns: none
     effect: if vowel : change avVec
             else if voiceless : change afVec
	     else change avVec by rate/2 and afVec by rate/2
     *******************************************************************
  */
void phon::changeAvrInt(int dBVal) {
  if (dBVal<0) {
    for (uint i=0; i<frameNum; i++) {
      if (ampVec[i]-dBVal>0)
	ampVec[i] -= dBVal;
      else
	ampVec[i] = 0;
    }
  } else if  (dBVal>0) {
    for (uint i=0; i<frameNum; i++) {
      if (ampVec[i]+dBVal<MAX_DBVAL)
	ampVec[i] += dBVal;
      else
	ampVec[i] = MAX_DBVAL;
    }
  }
}

void phon::smootheF0(uint winsize) {
  smoothe(f0Vec, winsize);
}


  /* *******************************************************************
     void changeF0Range(uint rate, uint meanF0)
     args: rate, meanF0
     returns: none
     effect:  change Range of f0Contour compressing/expanding at <rate>
     in relation to <meanF0>
     *******************************************************************
  */
void phon::changeF0Range(uint rate, uint meanF0) {
  changeContrast(f0Vec, rate, meanF0);
}

  /* *******************************************************************
     void interpolateF0Vec(uint start, uint end)
     args: end, start
     returns: none
     effect:  interpolate f0Contour linear from start to end
     *******************************************************************
  */
void phon::interpolateF0Vec(uint start, uint end) {
  interpolateLinear(f0Vec, start, end);
}

void phon::changeDur(uint newDur, globalsT glob) {
  uint leftBorder, rightBorder;
  uint oldFrameNum = frameNum;
  uint newFrameNum;
  
  newFrameNum = msec2frames(newDur, glob);

  if (manner == stop_voiced || manner == stop_voiceless) {
    leftBorder = 0; 
    rightBorder = burstStart;
  } else {
    leftBorder = steadyStart;
    rightBorder = steadyEnd; 
  }
  //  if (name=="_")
  //    cout << name<<": "<<oldFrameNum<<" "<<newFrameNum<<" "<<rightBorder<<" "<<leftBorder<<"\n";

  if (oldFrameNum-newFrameNum <= rightBorder-leftBorder || newFrameNum>oldFrameNum) {
    // cout <<"change\n";
    dur = newDur;
    std::vector<uint> tmpTimeVec;
    for (uint i=0; i<frameNum; i++) {
      tmpTimeVec.push_back(i*(100/frameNum));
    }
    frameNum = newFrameNum;
    
    f0Vec = modelTrack(name, frameNum, f0Vec, tmpTimeVec);
    
    
    if (glob.changeDurMethod == TIME_ALIGNED && (manner!=stop_voiced || manner!=stop_voiceless)) {
      ampVec = modelTrack(name, frameNum, ampVec, tmpTimeVec);
      f1Vec = modelTrack(name, frameNum, f1Vec, tmpTimeVec);
      f2Vec = modelTrack(name, frameNum, f2Vec, tmpTimeVec);
      f3Vec = modelTrack(name, frameNum, f3Vec, tmpTimeVec);
      if (glob.use4Freq)
	f4Vec = modelTrack(name, frameNum, f4Vec, tmpTimeVec);
      if (glob.use5Freq) {
	f5Vec = modelTrack(name, frameNum, f5Vec, tmpTimeVec);
      }
    } else if (glob.changeDurMethod == STEADY_STATE_CUT || (manner==stop_voiced || manner==stop_voiceless)) {
      ampVec = change_valNum(name, frameNum, leftBorder, rightBorder, ampVec);  
      f1Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f1Vec);
      f2Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f2Vec);
      f3Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f3Vec);
      if (glob.use4Freq)
	f4Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f4Vec);
      if (glob.use5Freq) {
	f5Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f5Vec);
      }
    } else {
      error("phon::changeDur(): durChangeMethod not defined", -3);
    }

    if (manner == stop_voiced || manner == stop_voiceless) {
      leftBorder = 0; 
      rightBorder = burstStart;
    } else {
      leftBorder = 0;
      rightBorder = frameNum; 
    }
    
    if (!glob.use4Freq)
      f4Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f4Vec);
    if (!glob.use5Freq) {
      f5Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f5Vec);
    }

    b1Vec = change_valNum(name, frameNum, leftBorder, rightBorder, b1Vec);
    b2Vec = change_valNum(name, frameNum, leftBorder, rightBorder, b2Vec);
    b3Vec = change_valNum(name, frameNum, leftBorder, rightBorder, b3Vec);
    b4Vec = change_valNum(name, frameNum, leftBorder, rightBorder, b4Vec);
    b5Vec = change_valNum(name, frameNum, leftBorder, rightBorder, b5Vec);
    f6Vec = change_valNum(name, frameNum, leftBorder, rightBorder, f6Vec);
    b6Vec = change_valNum(name, frameNum, leftBorder, rightBorder, b6Vec);
    a1Vec = change_valNum(name, frameNum, leftBorder, rightBorder, a1Vec); 
    a2Vec = change_valNum(name, frameNum, leftBorder, rightBorder, a2Vec);
    a3Vec = change_valNum(name, frameNum, leftBorder, rightBorder, a3Vec);
    a4Vec = change_valNum(name, frameNum, leftBorder, rightBorder, a4Vec);
    a5Vec = change_valNum(name, frameNum, leftBorder, rightBorder, a5Vec);
    a6Vec = change_valNum(name, frameNum, leftBorder, rightBorder, a6Vec);
    b1pVec = change_valNum(name, frameNum, leftBorder, rightBorder, b1pVec);
    b2pVec = change_valNum(name, frameNum, leftBorder, rightBorder, b2pVec);
    b3pVec = change_valNum(name, frameNum, leftBorder, rightBorder, b3pVec);
    b4pVec = change_valNum(name, frameNum, leftBorder, rightBorder, b4pVec);
    b5pVec = change_valNum(name, frameNum, leftBorder, rightBorder, b5pVec);
    b6pVec = change_valNum(name, frameNum, leftBorder, rightBorder, b6pVec);
    oqVec = change_valNum(name, frameNum, leftBorder, rightBorder, oqVec);  
    avVec = change_valNum(name, frameNum, leftBorder, rightBorder, avVec);
    ahVec = change_valNum(name, frameNum, leftBorder, rightBorder, ahVec); 
    aturbVec = change_valNum(name, frameNum, leftBorder, rightBorder, aturbVec); 
    afVec = change_valNum(name, frameNum, leftBorder, rightBorder, afVec); 
    abVec = change_valNum(name, frameNum, leftBorder, rightBorder, abVec); 
    avpVec = change_valNum(name, frameNum, leftBorder, rightBorder, avpVec); 
    tlVec = change_valNum(name, frameNum, leftBorder, rightBorder, tlVec); 
    flVec = change_valNum(name, frameNum, leftBorder, rightBorder, flVec); 
    gainVec = change_valNum(name, frameNum, leftBorder, rightBorder, gainVec); 
    anvVec = change_valNum(name, frameNum, leftBorder, rightBorder, anvVec); 
    fnzVec = change_valNum(name, frameNum, leftBorder, rightBorder, fnzVec); 
    bnzVec = change_valNum(name, frameNum, leftBorder, rightBorder, bnzVec); 
    fnpVec = change_valNum(name, frameNum, leftBorder, rightBorder, fnpVec); 
    bnpVec = change_valNum(name, frameNum, leftBorder, rightBorder, bnpVec);  
    sqVec = change_valNum(name, frameNum, leftBorder, rightBorder, sqVec);
    diVec = change_valNum(name, frameNum, leftBorder, rightBorder, diVec); 
    df1Vec = change_valNum(name, frameNum, leftBorder, rightBorder, df1Vec); 
    db1Vec = change_valNum(name, frameNum, leftBorder, rightBorder, db1Vec);
    ftpVec = change_valNum(name, frameNum, leftBorder, rightBorder, ftpVec); 
    btpVec = change_valNum(name, frameNum, leftBorder, rightBorder, btpVec); 
    ftzVec = change_valNum(name, frameNum, leftBorder, rightBorder, ftzVec); 
    btzVec = change_valNum(name, frameNum, leftBorder, rightBorder, btzVec); 
    a2fVec = change_valNum(name, frameNum, leftBorder, rightBorder, a2fVec); 
    a3fVec = change_valNum(name, frameNum, leftBorder, rightBorder, a3fVec); 
    a4fVec = change_valNum(name, frameNum, leftBorder, rightBorder, a4fVec); 
    a5fVec = change_valNum(name, frameNum, leftBorder, rightBorder, a5fVec); 
    a6fVec = change_valNum(name, frameNum, leftBorder, rightBorder, a6fVec); 
    a1vVec = change_valNum(name, frameNum, leftBorder, rightBorder, a1vVec); 
    a2vVec = change_valNum(name, frameNum, leftBorder, rightBorder, a2vVec); 
    a3vVec = change_valNum(name, frameNum, leftBorder, rightBorder, a3vVec); 
    a4vVec = change_valNum(name, frameNum, leftBorder, rightBorder, a4vVec); 
    atvVec = change_valNum(name, frameNum, leftBorder, rightBorder, atvVec); 
    
    if (manner == stop_voiced || manner == stop_voiceless) { 
      burstStart = burstStart - (oldFrameNum-frameNum);
      aspStart = aspStart - (oldFrameNum-frameNum);
    }
  }
}
void phon::setSoundSource(globalsT &glob) {
  // cout << name <<"\n";
  switch(type) {
  case vowel:
    // set amplitude of voicing 
    avVec = ampVec;  glob.avDyn = true; 

    // model noise in higher freqs
    glob.b4pDyn = true;
    glob.b5pDyn = true;
    glob.b6pDyn = true;
    glob.a4fDyn = true;
    glob.a5fDyn = true;
    glob.a6fDyn = true;
    for (uint i=0; i<frameNum; i++) {
      afVec[i] = ampVec[i]>22 ? ampVec[i]-22 : 0;
      if (afVec[i] > maxVal) std::cout <<"phon::setSoundSource: afVec[i] > maxVal\n";
      b4pVec[i] = 70;
      b5pVec[i] = 70;
      b6pVec[i] = 100;
      a4fVec[i]= 35;
      a5fVec[i]= 35;
      a6fVec[i]= 35;
    }

    // model phraryngeal interaction
    // following klattalk, chpt. 3, p. 27
    glob.df1Dyn = true;
    glob.db1Dyn=true;
    for (uint i=0; i<frameNum; i++) {
      df1Vec[i] = f1Vec[i]/10;
      db1Vec[i] = b1Vec[i]*6;
    }

    // model dependence of BW1 from F1 
    // following fujimura&lindqvist
    glob.b1Dyn=true;
    for (uint i=0; i<frameNum; i++) {
      b1Vec[i] = F12BW(f1Vec[i]);
    }    
    break;
  case consonant:
    switch (manner) {
    case liquide: 
      avVec = ampVec; glob.avDyn = true;
      break;
    case nasal: 
      avVec = ampVec; glob.avDyn = true;
      break;
    case fricative_voiced:
      if (name=="h") {
	// phonFeatures.breathy=true;
	glob.avDyn = true;
	glob.ahDyn = true;
	for (uint i=0; i<frameNum; i++) { 
	  avVec[i] = ampVec[i]>18 ? ampVec[i]-18 : 0; 
	  ahVec[i] = ampVec[i]>12 ? ampVec[i]-12 : 0;
	}
	glob.ahDyn = true;
      } else {
	afVec = ampVec; glob.afDyn = true;
	for (uint i=0; i<frameNum; i++) 
	  avVec[i] = ampVec[i]-6; 
	glob.avDyn = true;
	avpVec = ampVec; // for i&s
      }
      break;
    case fricative_voiceless: 
      afVec = ampVec; glob.afDyn = true;
      break;
    case stop_voiced: 
      if (burstStart>frameNum || aspStart>frameNum) {
	error("phon::setSoundSource: wrong burst/asp-start at phon: "+name+"\n",-5);
      } 
      glob.afDyn = true;
      for (uint i=burstStart; i<aspStart; i++) {
	afVec[i] = ampVec[i]>6 ? ampVec[i]-6 : 0;
      }
      glob.ahDyn = true; glob.avDyn = true;
      for (uint i=aspStart; i<frameNum; i++) {
	ahVec[i] = ampVec[i];
	avVec[i] = ampVec[i]>6 ? ampVec[i]-6 : 0;	
	avpVec[i] = ampVec[i]; // for i&s 
      } 
      break;
    case stop_voiceless: 
      // cout <<name<<" l:"<<frameNum<<":, bS:"<<burstStart<<", aS:"<<aspStart<<"\n";
      if (burstStart>frameNum || aspStart>frameNum) 
	error("phon::setSoundSource: wrong burst/asp-start at phon: "+name+"\n",-5);
      for (uint i=burstStart; i<aspStart; i++) {
	afVec[i] = ampVec[i]; glob.afDyn = true; 
      }
      for (uint i=aspStart; i<frameNum; i++) {
	ahVec[i] = ampVec[i]; 
      }  
      break;
    case silence:
      for (uint i=0; i<frameNum; i++) {
	f0Vec[i] = 0;
	avVec[i] = 0;
      }
      break;
    default :
      error("phon::setSoundSource: undefined phon-type/n", -3);
    }
  }
}

void phon::setArticulationTractFilter(globalsT &glob) {
  
  switch(type) {
  case vowel:
    // modeling is done by the cascade tract
    break;
  case consonant:
    switch (manner) {
    case liquide: 
      break;
    case nasal: 
      
      glob.fnzDyn = true;
      glob.fnpDyn = true;     
      glob.bnpDyn = true;
      glob.bnzDyn = true;

      glob.ftpDyn = true;
      glob.ftzDyn = true;
      glob.btpDyn = true;
      glob.btzDyn = true;

      glob.tlDyn=true;

      for (uint i=0; i<frameNum; i++) {
	// fnzVec[i] = 1800;	
	fnzVec[i] = f1Vec[i] + (int) ((double)(f2Vec[i]-f1Vec[i])*0.75);
	// fnpVec[i] = 900;
	fnpVec[i] = f1Vec[i] + (int) (f2Vec[i]-f1Vec[i])/2; 
	bnpVec[i] = 500; bnzVec[i] = 30;
	 
	ftpVec[i] = 2700;
	ftzVec[i] = 3200;
	// btpVec[i] = 50;
	// btzVec[i] = 500;

	a1Vec[i]=50; a2Vec[i]=50; a3Vec[i]=50; // for i&s
	switch (place) {
	case bilabial:
	  break;
	case alveolar:
	  break;
	case velar:
	  break;
	default:
	  error ("phon::setArticulationTractFilter: nasal with unknown place\n", -3);
	}
      }
      
      break;

    case silence:
      
      break;
    default : // fricativss and stops
      switch (place) {
      case bilabial:
	for (uint i=0; i<frameNum; i++) 
	  abVec[i] = 60; glob.abDyn=true;
	break;
      case labial:
	for (uint i=0; i<frameNum; i++) {
	  if (voiced) {
	    a1Vec[i] = 50; a2Vec[i] = 45; a3Vec[i] = 45; // for i&s
	    a2fVec[i] = 45; glob.a2fDyn=true; 
	    a3fVec[i] = 45; glob.a3fDyn=true;
	    b2pVec[i] = 100; glob.b2pDyn=true; 
	    b3pVec[i] = 200; glob.b3pDyn=true; 	    
	  } else 
	    abVec[i] = 60; glob.abDyn=true;
	}
	break;
      case alveolar:
       	if (manner == fricative_voiced || manner == fricative_voiceless) {
	  glob.a5fDyn=true; glob.a6fDyn=true; glob.f5Dyn=true; glob.f6Dyn=true; glob.b5pDyn=true; glob.b6pDyn=true;
	  for (uint i=0; i<frameNum; i++) {
	    a5Vec[i] = 60; a6Vec[i] = 60; // for i&s
	    if (glob.sr==16000) {
	      a5fVec[i] = 60; a6fVec[i] = 60;
	      f5Vec[i] = 5000; f6Vec[i] = 6500;
	      b5pVec[i] = 500; b6pVec[i] = 1000;  
	    }  else { // sr is 10 kHz
	      f5Vec[i] = 3500; f6Vec[i] = 4500;
	      b5pVec[i] = 500; b6pVec[i] = 500;  
	      a5fVec[i] = 50; a6fVec[i] = 60;
	    } 
	  }
	  if (voiced) {
	    for (uint i=0; i<frameNum; i++) {
	      a1Vec[i] = 40; a2Vec[i] = 35; a3Vec[i] = 40; // for i&s
	    }
	  }
	} else { // stop
	  if (burstStart>frameNum || aspStart>frameNum) 
	    error("phon::setArticulationTractFilter: wrong burst/asp-start",-5);
	  for (uint i=burstStart; i<aspStart; i++) {
	    // abVec[i] = 60;
	       
	    f1Vec[i] = 500;
	    f2Vec[i] = 1500;
	    f3Vec[i] = 2500;
	    a1Vec[i] = 50;a2Vec[i] = 50;a3Vec[i] = 50;a4Vec[i] = 40;a5Vec[i] = 40;a6Vec[i] = 40; // for i&s
	    a2fVec[i] = 50; glob.a2fDyn=true;
	    a3fVec[i] = 50; glob.a3fDyn=true;
	    a4fVec[i] = 40; glob.a4fDyn=true;
	    a5fVec[i] = 40; glob.a5fDyn=true;
	    a6fVec[i] = 40; glob.a6fDyn=true;
	    b2pVec[i] = 110; glob.b2pDyn=true; 
	    b3pVec[i] = 250; glob.b3pDyn=true; 
	    b4pVec[i] = 300; glob.b4pDyn=true; 
	    b5pVec[i] = 300; glob.b5pDyn=true; 
	    b6pVec[i] = 300; glob.b6pDyn=true; 
	   	  }
	}
	break;
      case postalveolar:
	glob.f4Dyn=true; glob.f5Dyn=true; glob.f6Dyn=true;
	glob.a3fDyn=true;glob.a4fDyn=true;glob.a5fDyn=true;
	glob.b3pDyn=true; glob.b4pDyn=true; glob.b5pDyn=true; glob.b6pDyn=true;
	for (uint i=0; i<frameNum; i++) {
	  a3Vec[i]=50; a4Vec[i]=50; a5Vec[i]=60; a6Vec[i]=60; // for i&s
	  if (glob.sr==16000) {	  
	    b3pVec[i] = 200; b4pVec[i] = 200; b5pVec[i] = 600; b6pVec[i] = 600;
	  } else {
	    a3fVec[i] = 0; a4fVec[i] = 60; a5fVec[i] = 60; a6fVec[i] = 60;
	    b4pVec[i] = 320; b5pVec[i] = 500; b6pVec[i] = 1500;
	    f4Vec[i] = 2000; f5Vec[i] = 3500; f6Vec[i] = 4500;
	  }
	}
	break;
      case palatal:
	for (uint i=0; i<frameNum; i++) {
	  a4Vec[i] = 60;a5Vec[i] = 50;a6Vec[i] = 30; // for i&s

	  a4fVec[i] = 60; glob.a4fDyn=true;
	  a5fVec[i] = 50; glob.a5fDyn=true;
	  a6fVec[i] = 30; glob.a6fDyn=true;
	  //	  f4Vec[i] = 3000;
	  f5Vec[i] = 4000; glob.f5Dyn=true;
	  f6Vec[i] = 5500; glob.f6Dyn=true;
	  b4pVec[i] = 1000; glob.b4pDyn=true;
	  b5pVec[i] = 1000; glob.b5pDyn=true;
	  b6pVec[i] = 1000; glob.b6pDyn=true;
	}
	break;
      case velar:
	for (uint i=0; i<frameNum; i++) {
	  a2Vec[i] = 50;// for i&s
	  // ahVec[i] = ampVec[i];
	  a2fVec[i] = 50; glob.a2fDyn=true;
	  f2Vec[i] = 1200; glob.f2Dyn=true;
	  b2pVec[i] = 200; glob.b2pDyn=true;
	  a5fVec[i] = 40; glob.a5fDyn=true;
	  f5Vec[i] = 4000; glob.f5Dyn=true;
	  b5pVec[i] = 200; glob.b5pDyn=true;
	}
	break;
      case uvular:
	break;
      case glottal:
	for (uint i=0; i<frameNum; i++) {
	  a1Vec[i] = 30;a2Vec[i] = 30;a3Vec[i] = 30; // for i&s
	  /*
	    a2fVec[i] = 30; glob.a2fDyn=true;
	    a3fVec[i] = 30; glob.a3fDyn=true;
	    b2pVec[i] = 200; glob.b2pDyn=true;
	    b3pVec[i] = 200; glob.b3pDyn=true;
	  */
	}
	break;
      default :
	error("phon::setArticulationTractFilter: wrong place of articulation\n", -3);
      } // switch place
    } // switch manner
  } // switch type
}
void phon::modelFeatures(uint sylMeanF0, globalsT &glob, phon *prevpP, phon *nextpP) {
  /// model features
  //  cout << name <<": act:"<<manner<<", prev:"<<prevManner <<", next:"<<nextManner<<"\n";
  if (phonFeatures.undershoot) { 
    uint rate = phonFeatures.undershootRate;
    for (uint i=0; i<frameNum; i++) {
      int f1Diff = (int)(f1Vec[i] - center_F1)* (int)rate/100;
      int f2Diff = (int)(f2Vec[i] - center_F2)* (int)rate/100;
      f1Vec[i] = checkMinF1(checkMaxF1(f1Vec[i]-f1Diff));
      f2Vec[i] = checkMinF2(checkMaxF2(f2Vec[i]-f2Diff));
    }
  }
  if (phonFeatures.overshoot) { 
    uint rate = phonFeatures.overshootRate;
    for (uint i=0; i<frameNum; i++) {
      int f1Diff = (int)(f1Vec[i] - center_F1)* (int)rate/100;
      int f2Diff = (int)(f2Vec[i] - center_F2)* (int)rate/100;
      f1Vec[i] = checkMinF1(checkMaxF1(f1Vec[i]+f1Diff)); 
      f2Vec[i] = checkMinF2(checkMaxF2(f2Vec[i]+f2Diff)); 
   }
  }
  if (phonFeatures.spread) { 
    uint rate = phonFeatures.spreadRate;
    for (uint i=0; i<frameNum; i++) {
      int f1Diff = (int)(f1Vec[i])* (int)rate/100;
      int f2Diff = (int)(f2Vec[i])* (int)rate/100;
      f1Vec[i] = checkMinF1(checkMaxF1(f1Vec[i]+f1Diff));
      f2Vec[i] = checkMinF2(checkMaxF2(f2Vec[i]+f2Diff));
    }
  }
  if (phonFeatures.rounded) { 
    uint rate = phonFeatures.roundedRate;
    for (uint i=0; i<frameNum; i++) {
      int f1Diff = (int)(f1Vec[i])* (int)rate/100;
      int f2Diff = (int)(f2Vec[i])* (int)rate/100;
      int f3Diff = (int)(f3Vec[i])* (int)rate/100;
      int f4Diff = (int)(f4Vec[i])* (int)rate/100;
      int f5Diff = (int)(f5Vec[i])* (int)rate/100;
      
      f1Vec[i] = checkMinF1(checkMaxF1(f1Vec[i]-f1Diff/2));
      f2Vec[i] = checkMinF2(checkMaxF2(f2Vec[i]-f2Diff/2));
      f3Vec[i] = checkMinF3(checkMaxF3(f3Vec[i]-f3Diff));
      //f4Vec[i] = checkMinF4(checkMaxF4(f4Vec[i]-f4Diff));
      //f5Vec[i] = checkMinF5(checkMaxF5(f5Vec[i]-f5Diff));
    }
  }
  if (phonFeatures.headSize) { 
    uint rate = phonFeatures.headSizeRate;
    changeMean(f0Vec, rate);
    changeMean(f1Vec, rate);
    changeMean(f2Vec, rate);
    changeMean(f3Vec, rate);
    changeMean(f4Vec, rate);
    changeMean(f5Vec, rate);
  }
  if (phonFeatures.coarticulation) { 
    uint rate = phonFeatures.coarticulationRate;
    PHON_MANNER pManner, nManner;
    PHON_PLACE pPlace, nPlace;
    bool first=false, last=false;
    uint coFrames = frameNum/2 * rate/100;
    if (prevpP != NULL) {
      pManner=(*prevpP).Manner();
      pPlace=(*prevpP).Place();
    } else
      first = true;
    if (nextpP != NULL) {
      nManner=(*nextpP).Manner();
      nPlace=(*nextpP).Place();      
   } else
      last = true;
    CO_TYPE coType = phonFeatures.coarticulationType;

    if (!first && (coType==progressive || coType==both)) {
      if (manner==fricative_voiceless && (pManner==long_vowel||pManner==short_vowel) ) {
	glob.b1Dyn = true;
	glob.avDyn = true;
	for (uint i=0; i<coFrames; i++) {	  
	  b1Vec[i] = 300;
	  avVec[i] = ampVec[i];
	  f0Vec[i] = (*prevpP).F0Vec()[(*prevpP).FrameNum()-1];
	}
      }
      if ((manner==long_vowel||manner==short_vowel)) {
	if (pManner==fricative_voiceless||pManner==fricative_voiced) {
	  if (pPlace==alveolar)
	    for (uint i=0; i<coFrames; i++) {
	      afVec[i] = ampVec[i]>6 ? ampVec[i]-6 : 0;
	      f5Vec[i] = 3500; f6Vec[i] = 4500;
	      b5pVec[i] = 500; b6pVec[i] = 500;
	      a5fVec[i]= 50; a6fVec[i]= 60;
	    }
	  if (pPlace==postalveolar)
	    for (uint i=0; i<coFrames; i++) {
	      afVec[i] = ampVec[i]>6 ? ampVec[i]-6 : 0;
	      f4Vec[i] = 2000; f5Vec[i] = 3500; f6Vec[i] = 4500;
	      b4pVec[i] = 320; b5pVec[i] = 500; b6pVec[i] = 1500;
	      a4fVec[i]= 60; a5fVec[i]= 60; a6fVec[i]= 60;
	    }
	}
	if (pManner==nasal) {
	  uint lastFnp =  (*prevpP).FnpVec()[(*prevpP).FrameNum()-1];
	  uint lastFnz =  (*prevpP).FnzVec()[(*prevpP).FrameNum()-1];
	  uint lastBnp =  (*prevpP).BnpVec()[(*prevpP).FrameNum()-1];
	  uint lastBnz =  (*prevpP).BnzVec()[(*prevpP).FrameNum()-1];
	  for (uint i=0; i<coFrames; i++) {
	    fnpVec[i] = lastFnp;
	    bnpVec[i] = lastBnp;
	    fnzVec[i] = lastFnz;
	    bnzVec[i] = lastBnz;
	  }
	}
      }
    }
    if (!last && (coType==regressive || coType==both)) {
      if (manner==fricative_voiceless && (nManner==long_vowel||pManner==short_vowel) ) {
	// cout <<name<<" "<<frameNum-coFrames<<"\n";
	glob.b1Dyn = true;
	glob.avDyn = true;
	for (uint i=frameNum-coFrames; i<frameNum; i++) {
	  avVec[i] = ampVec[i];
	  f0Vec[i] = (*nextpP).F0Vec()[0];
	  b1Vec[i] = 300;
	}
      }
      if ((manner==long_vowel||manner==short_vowel)) {
	if  (nManner==fricative_voiceless||nManner==fricative_voiced) {
	//      glob.b4pDyn = true;
	  glob.b5pDyn = true;
	  glob.b6pDyn = true;
	  glob.a4fDyn = true;
	  glob.a5fDyn = true;
	  glob.a6fDyn = true;
	  for (uint i=frameNum-coFrames; i<frameNum; i++) {
	    afVec[i] = ampVec[i]>6 ? ampVec[i]-6 : 0;
	    f4Vec[i] = 2000; f5Vec[i] = 3500; f6Vec[i] = 4500;
	    b4pVec[i] = 320; b5pVec[i] = 500; b6pVec[i] = 1500;
	    a4fVec[i]= 60; a5fVec[i]= 60; a6fVec[i]= 60;
	  }
	}
	if  (nManner==nasal) {
	  uint nextFnp =  (*nextpP).FnpVec()[0];
	  uint nextFnz =  (*nextpP).FnzVec()[0];
	  uint nextBnp =  (*nextpP).BnpVec()[0];
	  uint nextBnz =  (*nextpP).BnzVec()[0];
	  for (uint i=0; i<frameNum-coFrames; i++) {
	    fnpVec[i] = nextFnp;
	    bnpVec[i] = nextBnp;
	    fnzVec[i] = nextFnz;
	    bnzVec[i] = nextBnz;
	  }

	}
      }
    }
  }
  if (phonFeatures.jitter) {
    if (phonFeatures.jitterMethod==USE_FLUTTER) {
      glob.flDyn = true;
      for (uint i=0; i<frameNum; i++) {
	if (f0Vec[i]>0)
	  flVec[i] = phonFeatures.jitterRate;
      }
    } else if (phonFeatures.jitterMethod==USE_F0_ALTERNATING) {
      addJitterVec(f0Vec, phonFeatures.jitterRate);
    } else {
      error ("modelPhonFeatures: no jitter-method defined\n", -5);
    }
  }
  if (phonFeatures.voiced && voiced) { /// voiced with vowels means absence of voicing
    uint voiceLessStart = phonFeatures.vocStop;
    uint voiceLessEnd = phonFeatures.vocStart==0 ? 
      frameNum : phonFeatures.vocStart;
    for (uint i=voiceLessStart; i<voiceLessEnd; i++) {
      if (type == vowel) {
	avVec[i] = 0;
	aturbVec[i] = 60; /// for i&s
      } else if (type == consonant) {
	avpVec[i] = 0; /// for i&s 
      }
    }
  }
  if (phonFeatures.voiced && !voiced) {
   
    uint voiceStart = phonFeatures.vocStart;
    uint voiceEnd = phonFeatures.vocStop>frameNum ? frameNum : phonFeatures.vocStop;
    glob.avDyn = true;
    if (glob.senSyn) {
      for (uint i=voiceStart; i<voiceEnd; i++) {
	avVec[i] = ampVec[i]-6; 
	f0Vec[i] = sylMeanF0;
	//	f0Vec[i] = (*nextpP).F0Vec()[0];
	//	f0Vec[i] = (*prevpP).F0Vec()[(*prevpP).FrameNum()-1];
      }
    } else {
      for (uint i=voiceStart; i<voiceEnd; i++) {
	avpVec[i] = ampVec[i]>6 ? ampVec[i]-6 : 0; /// for i&s 
	a1Vec[i] = 50; a2Vec[i] = 50; a3Vec[i] = 50; /// for i&s 
      }
    }
  }
  
  if (phonFeatures.breathy) {
    uint brtStart = phonFeatures.brtStart;
    uint brtEnd = phonFeatures.brtStop>frameNum ? 
      frameNum : phonFeatures.brtStop;
    uint rate = phonFeatures.brtRate;

    if ((*nextpP).Manner()==stop_voiced && brtEnd==frameNum)
      brtEnd /= 2;
    
    glob.btpDyn = true;
    glob.ahDyn=true;
    glob.oqDyn=true;
    glob.tlDyn=true;

    glob.btpDyn = true;
    glob.fnpDyn = true;
    glob.fnzDyn = true;
    glob.bnpDyn = true;

    uint oqAdd = (100-glob.oq)*rate/100;
    uint tlAdd = (24-glob.tl)*rate/100;
    uint b1Add = (200-glob.ah)*rate/100;
    uint avSub = 6*rate/100; /// max. 6 dB less amplitude
    uint ahAdd;

    uint btpSub = (glob.btp-minBtp)*rate/100;
    uint bnpSub = (glob.bnp-minBnp)*rate/100;

    // cout << tlAdd<<" "<<oqAdd<<"\n";
    for (uint i=brtStart; i<brtEnd; i++) {
      /// broaden first bandwidth
      b1Vec[i] += b1Add;
      oqVec[i] += oqAdd; /// open period longer
      ahAdd = ampVec[i]>3 ? (ampVec[i]-3)*rate/100 : 0;
      ahVec[i] += ahAdd; /// noisy parts in higher freqs
      tlVec[i] += tlAdd;   /// periodical spectrum more damped
      avVec[i] = avVec[i]>avSub ? avVec[i]-avSub : 0;

      /// model tracheal coupling, following klattalk, p. 27
      /// with tracheal poles at 550 and 2100 Hz
      fnpVec[i] = 550;
      fnzVec[i] = 550;
      btpVec[i] -= btpSub;
      bnpVec[i] -= bnpSub;
      if (!glob.senSyn)
	aturbVec[i] = ampVec[i]+6; /// for i&s
    }
  } 

  if (phonFeatures.nasalized) {
    uint nasStart = phonFeatures.nasStart;
    uint nasEnd = phonFeatures.nasStop>frameNum ? 
      frameNum : phonFeatures.nasStop;
    for (uint i=nasStart; i<nasEnd; i++) {
      //     fnzVec[i] = f2Vec[i] - f1Vec[i];
    }	      
  }

  if (phonFeatures.laryngealized) {
    glob.diDyn=true;
    uint larStart = phonFeatures.larStart;
    uint larEnd = phonFeatures.larStop>frameNum ? 
      frameNum : phonFeatures.larStop;
 
    if (glob.senSyn) { 
     uint rate = phonFeatures.larRate;
      glob.diDyn = true;
      glob.b1Dyn = true;
      glob.oqDyn = true;
      uint b1Add = 250*rate/100; /// max. 300 Hz broader
      uint oqAdd = (100-glob.oq)*rate/100;
    for (uint i=larStart; i<larEnd; i++) { 
	diVec[i]= rate;
	oqVec[i] += oqAdd;
	b1Vec[i] += b1Add;
      }
    } else {  /// i&s version
      std::cout << "phon::modelFeatures: generating output for i&s version, not tested\n";
      for (uint i=larStart; i<larEnd; i++) {
	/// halve the fundamental freq
	f0Vec[i] = checkMinF0((uint) f0Vec[i]/2);
	/// lower the amplitude
	avVec[i] = avVec[i] - 3;
      }
    }	      
  }  
  if (phonFeatures.creaky) {
    glob.diDyn=true;
    uint creakyStart = phonFeatures.creakyStart;
    uint creakyEnd = phonFeatures.creakyStop>frameNum ? 
      frameNum : phonFeatures.creakyStop;
 
    if (glob.senSyn) {
      uint rate = phonFeatures.creakyRate;
      glob.diDyn = true;
      glob.b1Dyn = true;
      glob.oqDyn = true;
      uint b1Add = 250*rate/100; /// max. 300 Hz broader
      uint oqAdd = (100-glob.oq)*rate/200;
      uint avSub = 6*rate/100; /// max. 6 dB less amplitude
    for (uint i=creakyStart; i<creakyEnd; i++) { 
	diVec[i]= rate;
	oqVec[i] += oqAdd;
	avVec[i] = avVec[i]>avSub ? avVec[i]-avSub : 0;
	b1Vec[i] += b1Add;
      }
    } else {  /// i&s version
      std::cout << "phon::modelFeatures: generating output for i&s version, not tested\n";
      for (uint i=creakyStart; i<creakyEnd; i++) {
	/// halve the fundamental freq
	f0Vec[i] = checkMinF0((uint) f0Vec[i]/2);
	/// lower the amplitude
	avVec[i] = avVec[i] - 3;
      }
    }	      
  }  
  if (phonFeatures.tense) { 
    glob.oqDyn=true;
    glob.tlDyn=true;
    glob.b1Dyn=true;
    glob.b2Dyn=true;
    glob.b3Dyn=true;
    glob.b4Dyn=true;
    glob.b5Dyn=true;
    glob.b6Dyn=true;
    uint rate = phonFeatures.tenseRate;
    uint avAdd = 6*rate/100; /// max. 6 dB louder
    uint oqSub = (glob.oq-minOq)*rate/100;
    uint tlSub = glob.tl*rate/100;
    uint b1Sub = (glob.b1-minB1)*rate/100;
    uint b2Sub = (glob.b2-minB2)*rate/100;
    uint b3Sub = (glob.b3-minB3)*rate/100;
    uint b4Sub = (glob.b4-minB4)*rate/100;
    uint b5Sub = (glob.b5-minB5)*rate/100;
    uint b6Sub = (glob.b6-minB6)*rate/100;
    // cout << tlSub<<" "<<oqSub<<"\n";
    // cout << b1Sub<<" "<<oqSub<<"\n";

    for (uint i=0; i<frameNum; i++) {
      avVec[i] += avAdd; /// energy higher
      oqVec[i] = oqVec[i] > oqSub ? oqVec[i]-oqSub : 0; /// open period shorter
      tlVec[i] = tlVec[i] > tlSub ? tlVec[i]-tlSub : 0;   /// periodical spectrum less damped
      b1Vec[i] -= b1Sub;
      b2Vec[i] -= b2Sub;
      b3Vec[i] -= b3Sub;
      b4Vec[i] -= b4Sub;
      b5Vec[i] -= b5Sub;
      b6Vec[i] -= b6Sub;
    }
  } 
  if (phonFeatures.falsett) { 
    glob.oqDyn=true;
    glob.tlDyn=true;
    glob.b1Dyn=true;
    glob.b2Dyn=true;
    glob.b3Dyn=true;
    glob.b4Dyn=true;
    glob.b5Dyn=true;
    glob.b6Dyn=true;
    glob.flDyn=true;
    uint rate = phonFeatures.falsettRate;
      uint oqAdd = (100-glob.oq)*phonFeatures.brtRate/100;
      uint tlAdd = (24-glob.tl)*phonFeatures.brtRate/100;
      // cout << tlAdd<<" "<<oqAdd<<"\n";
    for (uint i=0; i<frameNum; i++) {
      f0Vec[i] += (uint)((double)f0Vec[i] * (double)rate/100.0);
      oqVec[i] += oqAdd; /// open period longer
      tlVec[i] += tlAdd;   /// periodical spectrum more damped
      // flVec[i] += rate;
      
      b1Vec[i] = 200;
      b2Vec[i] = 200;
      b3Vec[i] = 200;
      b4Vec[i] = 200;
      b5Vec[i] = 200;
      b6Vec[i] = 1000;
    }
  } 
  if (phonFeatures.whisper) { 
    glob.oqDyn=true;
    glob.tlDyn=true;
    glob.b1Dyn=true;
    glob.b2Dyn=true;
    glob.b3Dyn=true;
    glob.b4Dyn=true;
    glob.b5Dyn=true;
    glob.b6Dyn=true;
    uint rate = phonFeatures.whisperRate;
    uint oqAdd = (100-glob.oq)*rate/100;
    uint tlAdd = (24-glob.tl)*rate/100;
    // cout << tlAdd<<" "<<oqAdd<<"\n";
    for (uint i=0; i<frameNum; i++) {
      //   ahVec[i] += avVec[i]*rate/100;
      avVec[i] = avVec[i]>avVec[i]*rate/100?avVec[i]-avVec[i]*rate/100:0;

      oqVec[i] += oqAdd; /// open period longer
      tlVec[i] += tlAdd;   /// periodical spectrum more damped
      b1Vec[i] = 200;
      b2Vec[i] = 200;
      b3Vec[i] = 200;
      b4Vec[i] = 200;
      b5Vec[i] = 200;
      b6Vec[i] = 1000;
    }
    /*
      if (type==vowel&&(*prevpP).Manner()==stop_voiced) {
	cout<<"here\n";
	for (uint i=0; i<frameNum; i++) {
	  // avVec[i] = 0;
	  // f0Vec[i] = 0;
	  ahVec[i] = 0;
	}	
      }
    */
  } 
  //  printVec(avVec);  
}
void initPhonFeatures(PHON_FEATURES &phonFeatures) {

  phonFeatures.voiced = false;
  phonFeatures.vocStart = 0;
  phonFeatures.vocStop = 0;
  phonFeatures.breathy = false;
  phonFeatures.brtStart = 0;
  phonFeatures.brtStop = 0;
  phonFeatures.brtRate = 0;
  phonFeatures.nasalized = false;
  phonFeatures.nasStart = 0;
  phonFeatures.nasStop = 0;
  phonFeatures.laryngealized = false;
  phonFeatures.larStart = 0;
  phonFeatures.larStop = 0;
  phonFeatures.larRate = 0;
  phonFeatures.creaky = false;
  phonFeatures.creakyStart = 0;
  phonFeatures.creakyStop = 0;
  phonFeatures.creakyRate = 0;
  phonFeatures.spread = false;
  phonFeatures.spreadRate = 0;
  phonFeatures.rounded = false;
  phonFeatures.roundedRate = 0;
  phonFeatures.tense = false;
  phonFeatures.tenseRate = 0;
  phonFeatures.falsett = false;
  phonFeatures.falsettRate = 0;
  phonFeatures.whisper = false;
  phonFeatures.whisperRate = 0;
  phonFeatures.lax = false;
  phonFeatures.undershoot = false;
  phonFeatures.undershootRate = 0;
  phonFeatures.overshoot = false;
  phonFeatures.overshootRate = 0;
  phonFeatures.jitter = false;
  phonFeatures.jitterRate = 0;  
  phonFeatures.jitterMethod = 0;  
  phonFeatures.coarticulation = false;
  phonFeatures.coarticulationRate = 0;  
  phonFeatures.coarticulationType = regressive;  
  phonFeatures.headSize = false;
  phonFeatures.headSizeRate = 0;  
}

extern "C" void exitErr(char *msg, char *str, int ErrNum) {
  fprintf(stderr, "ERROR: ");
  fprintf(stderr, msg, str);
  exit(ErrNum);
}

extern "C" PHON_MANNER classify_german(char *phone) {
  char *possible_phones[] = {"_",     /* 0 silence */
                             "?", "p", "t", "k",  /* 1-4   stop_voiceless */
                             "b", "d", "g",  /* 5-7   stop_voiced */
                             "f", "s", "S", "x", "C", /* 8-12  fricative_voiceless */
                             "pf", "ts", "tS",  /* 13-15 fricative_voiceless */
                             "v", "z", "Z",  "h",  /* 16-19 fricative_voiced */
                             "m", "n", "N",   /* 20-22 nasal */
                             "l", "R",        /* 23-24 liquide */
                             "j",             /* 25    semi vowel */
                             "6", "@", "I", "Y", "E", "9", "U", "O", "a",   /* 26-34 short vowel */
                             "i:", "y:", "e:", "E:", "2:", "u:", "o:", "a:",/* 35-42 long vowel */
                             "aI", "OY", "aU", "I6", "NA"};  /* 43-46 long_vowel */
  
  int index;
  
  for(index=0;; index++) {
    if (strcmp(phone, possible_phones[index])==0)
      break;
    else if (strcmp("NA", possible_phones[index])==0) {
      exitErr("classify_german: %s: no such Phone\n", phone, -1);
    }
  }
  
  if (index >= 0 && index <= 0)
    return silence;
  else if (index >= 1 && index <= 4)
    return stop_voiceless;
  else if (index >= 5 && index <= 7)
    return stop_voiced;
  else if (index >= 8 && index <= 15)
    return fricative_voiceless;
  else if (index >= 16 && index <= 19)
    return fricative_voiced;
  else if (index >= 20 && index <= 22)
    return nasal;
  else if (index >= 23 && index <= 24)
    return liquide;
  else if (index >= 25 && index <= 34)
    return short_vowel;
  else if (index >= 35 && index <= 46)
    return long_vowel;
  else {
    fprintf(stderr, "something's wrong in classify_german\n");
    exit(-3);
  }
}

