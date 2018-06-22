/**
 * SYLLABLE.cc
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

#include "syllable.h"

void syllable::printPhonVec(std::ostream &outFile) {
  for (unsigned int i=0; i<phonVec.size(); i++) {
    phonVec[i].printName(outFile);
    outFile << " ";
  }
}

void syllable::addPhon(phon newPhon) {

  phonVec.push_back(newPhon);
  phonNum++;

}

void syllable::replacePhon(phon newPhon, uint loc) {
  if (phonNum > loc) {
    phonVec[loc] = newPhon;
  } else {
    error ("attempt to replace nonexistent phone in syllable\n", -3);
  }
}

phon syllable::getPhon(uint loc) {
  phon returnPhon;
  if (phonNum > loc) {
    returnPhon = phonVec[loc];
  } else {
    error ("attempt to get nonexistent phone in syllable\n", -3);
  }
  return returnPhon;
}

void syllable::erasePhon(uint loc) {
  std::vector <phon> tmpVec(0);
  if (loc >= phonNum|| loc < 0) 
    error ("attempt to erase nonexistent phone in syllable\n", -3);
  else {
    for (uint i=0; i<loc; i++)
      tmpVec.push_back(phonVec[i]);
    for (uint i=loc+1; i<phonNum; i++)
      tmpVec.push_back(phonVec[i]);
  }
  phonVec = tmpVec;
  phonNum--;
}

std::vector<phon>& syllable::PhonVec() {
  return phonVec;
}

uint syllable::PhonNum() {
  return phonNum;
}

uint syllable::MeanF0() {
  return meanF0;
}
void syllable::calcMeanF0() {
  uint f0Sum=0, f0Num=0;
  for (uint i=0; i<phonVec.size(); i++) {
    if (phonVec[i].Voiced()) {
      for (uint j=0; j<phonVec[i].F0Vec().size(); j++) {
	f0Sum += phonVec[i].F0Vec()[j];
      }
      f0Num +=  phonVec[i].FrameNum();
    }
  }
  meanF0 = f0Num>0 ? (uint) f0Sum/f0Num : 0;
}


void syllable::clearPhonVec() {
  phonVec.erase(phonVec.begin(), phonVec.end());
  phonNum = 0;
}


void syllable::changeF0Range (uint rate, uint mean) {
  for (uint pho=0; pho<phonNum; pho++) 
    phonVec[pho].changeF0Range(rate, mean);
  calcMeanF0();
}
void syllable::changeF0Range (uint rate) {
  for (uint pho=0; pho<phonNum; pho++) 
    phonVec[pho].changeF0Range(rate, meanF0);
  calcMeanF0();
}
void syllable::changeMeanF0 (uint rate) {
  for (uint pho=0; pho<phonNum; pho++) 
    phonVec[pho].changeMeanF0(rate);
  calcMeanF0();
}
void syllable::changeAvrInt (int dBVal) {
  for (uint pho=0; pho<phonNum; pho++) 
    phonVec[pho].changeAvrInt(dBVal);
}
