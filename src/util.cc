/**
 * UTIL.cc
 * utility-function, defines and so on for emoSyn
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

#include "util.h"

uint checkMaxF0(uint freq) { 
  if (freq > maxF0)
    return maxF0;
  return freq;
}
uint checkMaxF1(uint freq) { 
  if (freq > maxF1)
    return maxF1;
  return freq;
}
uint checkMaxF2(uint freq) { 
  if (freq > maxF2)
    return maxF2;
  return freq;
}
uint checkMaxF3(uint freq) { 
  if (freq > maxF3)
    return maxF3;
  return freq;
}
uint checkMaxF4(uint freq) { 
  if (freq > maxF4)
    return maxF4;
  return freq;
}
uint checkMaxF5(uint freq) { 
  if (freq > maxF5)
    return maxF5;
  return freq;
}

uint checkMinF0(uint freq) {
  if (freq < minF0)
    return minF0;
  return freq;
}
uint checkMinF1(uint freq) {
  if (freq < minF1)
    return minF1;
  return freq;
}
uint checkMinF2(uint freq) {
  if (freq < minF2)
    return minF2;
  return freq;
}
uint checkMinF3(uint freq) {
  if (freq < minF3)
    return minF3;
  return freq;
}
uint checkMinF4(uint freq) {
  if (freq < minF4)
    return minF4;
  return freq;
}
uint checkMinF5(uint freq) {
  if (freq < minF5)
    return minF5;
  return freq;
}

double mean(const std::vector<uint>& vec) {
  uint sum=0;
  
  for (uint i=0; i < vec.size(); i++) {
    sum += vec[i];
  }
  if (vec.size()>0)
    return sum/vec.size();
  else
    return 0;
};
void changeMean(std::vector<uint>& vals, uint rate) {
  double changeFac = (double)rate/100.0;
  //cout << changeFac<<"\n";
  for (uint i=0; i < vals.size(); i++) {
    if (vals[i]!= 0) {
      //cout << vals[i]<<" ";
      vals[i] = checkMinF0(checkMaxF0( (uint) ((double)vals[i] * changeFac) ));
      // cout <<(double)vals[i] * changeFac <<" ";
    }
    //  cout << vals[i]<<" ";
  }
}
void smoothe(std::vector<uint>& vals, uint winsize) {
  uint sum;
  uint denom = 2*winsize+1;
  if (vals.size()>winsize+2)
    for (uint i=winsize; i < vals.size()-winsize; i++) {
      sum = 0;
      for (uint j=1; j<=winsize; j++) {
	sum += vals[i-j];
	sum += vals[i+j];
      }
      sum += vals[i];
      vals[i] = sum/denom;
    }
}

void addJitterVec(std::vector<uint>& vals, uint rate) {
  for (uint i=0; i < vals.size(); i++) {
    if (vals[i] != 0) {
      if (i%2==0)
	vals[i] = checkMaxF0(vals[i] + (uint) (vals[i] * (rate/100.0)));
      else
	vals[i] = checkMinF0(vals[i] - (uint) (vals[i] * (rate/100.0)));
      // cout <<  (vals[i] * (rate/100.0)) << " ";
    }
  }
}
void changeContrast(std::vector<uint>& vals, short rate, double mean) {
  uint newVal;
  double Rate = (rate-100) / 100.0;
  for (uint i=0; i < vals.size(); i++) {
    // distance between pitchVal and Mean in %
    if (vals[i] != 0) {
      double dist = (double)  vals[i]-mean;             // (vals[i] * 100.0 / mean - 100);
      if (Rate > 0) { // enhance range
	
	if (vals[i] > mean) {
	  vals[i] = checkMaxF0(vals[i] + (uint)(dist * Rate));
	} else {
	  vals[i] = checkMinF0(vals[i] + (uint)(dist * Rate));
	}
      } else {        // reduce range 
	if (vals[i] > mean) {
	  if ((newVal = vals[i] + (uint)(dist * Rate)) < mean)
	    vals[i] = (uint) mean;
	  else
	    vals[i] = newVal;
	} else {
	  if ((newVal = vals[i] + (uint)(dist * Rate)) > mean)
	    vals[i] = (uint) mean;
	  else
	    vals[i] = newVal;      
	}  
      }
    }
  }
}
void interpolateLinear(std::vector<uint>& vec, uint start, uint end) {
  double step;
  short length = vec.size();
 
  if (start < end) {
    step = (double)(end-start) / (double) length;
    for (short i=0; i < length; i++) {
      if (vec[i] != 0) {
	vec[i] = checkMaxF0(start + (uint) (i * step));
	// cout << vec[i]<<" "<<step<<"\n";
      }
    }
  } else if (start > end) {
    step = (double)(start-end) / (double) length;
    for (short i=0; i < length; i++)
      if (vec[i] != 0)
	vec[i] = checkMinF0(start - (uint)(i * step));
  } else
    for (short i=0; i < length; i++)
      if (vec[i] != 0)
	vec[i] = start;
}
std::vector <uint> interpolateLinear(uint length, uint start, uint end) {
  double step;
  std::vector <uint> resultVec(0);
  
  if (start < end) {
    step = (double)(end-start) / (double) length;
    for (uint i=0; i < length; i++) {
      resultVec.push_back(start + (uint) (i * step));
    }
  } else if (start > end) {
    step = (double)(start-end) / (double) length;
    for (uint i=0; i < length; i++)
      resultVec.push_back(start - (uint)(i * step));
  } else
    for (uint i=0; i < length; i++)
      resultVec.push_back(start);
  return resultVec;
}

// calculate Herz from SemiTones
double ST2Hz (uint freq, double semiTone) {
  // ST(f1,f2) = 12/ln(2) * ln(f1/f2)
  const double _12_LN2 = 17.31234;
  double Exp;
  Exp = semiTone/_12_LN2;
  return exp(Exp) * freq;
}

// calculate Herz from SemiTones
double Hz2ST (uint freq1, uint freq2) {
  double result;
  // ST(f1,f2) = 12/ln(2) * ln(f1/f2)
  const double _12_LN2 = 17.31234;
  result = _12_LN2 * log((double)freq1/(double)freq2);
  return result>0?result:-result;
}

// calculate Herz from duration and gradient
double gradient2Hz (uint freq, uint time, double gradient) {
  const double _12_LN2 = 17.31234;
  double Exp;
  double semiTone = (time*0.001)*gradient;
  Exp = semiTone/_12_LN2;
  return exp(Exp) * freq;
}

void error (std::string msg, int errNo) {
  std::cerr << std::endl << "ERROR: " << msg << std::endl;
  exit(errNo);
}

void warn (std::string msg) {
  std::cerr << "WARNING: " << msg;
}

void printVec(std::vector<uint> vec) {
  for (uint i=0; i<vec.size(); i++)
    std::cout << vec[i] << "\t";
  std::cout << "\n";
}
void printVec(std::vector<int> vec) {
  for (uint i=0; i<vec.size(); i++)
    std::cout << vec[i] << "\t";
  std::cout << "\n";
}

std::vector<uint> subVec(std::vector<uint> vec, uint start, uint end) {
  std::vector<uint> returnVec;
  if (start<0 || start>end || end>=vec.size())
    error("subVec(): borders ot of range", -3);
  for (uint i=start; i<=end; i++)
    returnVec.push_back(vec[i]);
  return returnVec;
}


std::vector<uint> modelTrack(std::string name, uint valNum, std::vector<uint> f0ValVec, std::vector<uint> f0TimeVec) {
  std::vector<uint> returnVec, tmpF0TimeVec, tmpF0ValVec ; // vector with new f0Vals

  uint actTargetVal, nextTargetVal, start, end;
  double step;

  if (f0ValVec.size()>0 && f0TimeVec.size()>0) {
    if (f0TimeVec[0]!=0) {
      tmpF0TimeVec.push_back(0);
      tmpF0ValVec.push_back(f0ValVec[0]);
    }
    for (uint i=0; i< f0ValVec.size(); i++) {
      tmpF0TimeVec.push_back(f0TimeVec[i]);
      tmpF0ValVec.push_back(f0ValVec[i]);    
    }
    if (f0TimeVec[f0TimeVec.size()-1]!=100) {
      tmpF0TimeVec.push_back(100);
      tmpF0ValVec.push_back(f0ValVec[f0ValVec.size()-1]);
    }

    for (uint i=0; i<tmpF0TimeVec.size()-1; i++) {
      actTargetVal = (uint) rint(tmpF0TimeVec[i] * valNum * 0.01);
      nextTargetVal = (uint) rint(tmpF0TimeVec[i+1] * valNum * 0.01);
      start  = tmpF0ValVec[i];
      end  = tmpF0ValVec[i+1];
      
      if (actTargetVal > nextTargetVal) {
	error("wrong intonation description at phone:"+name+"\n", -3);
      }
      else if (actTargetVal == nextTargetVal) {
      } else {
	if (start == end) {
	  
	  for (uint j=actTargetVal; j < nextTargetVal; j++)
	    returnVec.push_back(end);
	  
	}
	else {
	  uint len = nextTargetVal-actTargetVal;
	  if (len==1) {
	    returnVec.push_back(start);
	  } else {
	    if (start < end) {
	      step = (end-start) / len;
	      for (uint j=1; j <= len; j++)
		returnVec.push_back(start + (uint) rint(j * step));
	    } else if (start > end) {
	      step = (start-end) / len;
	      for (uint j=1; j <= len; j++)
		returnVec.push_back(start - (uint) rint(j * step));
	    }
	  }
	}
      }
    }
  } else { // no intonation-description -> set f0Vals to zero
    for (uint j=0; j < valNum; j++)
      returnVec.push_back(0);
  }
  
  if (returnVec.size()!=valNum)
    error ("modelIntonation: uncorrect number of f0-vals at phone: "+name+"\n", -1);
  
  return returnVec;
  
}
std::vector<int> modelTrack(std::string name, uint valNum, std::vector<int> f0ValVec, std::vector<uint> f0TimeVec) {
  std::vector<int> returnVec, tmpF0TimeVec, tmpF0ValVec ; // vector with new f0Vals

  uint actTargetVal, nextTargetVal, start, end;
  double step;

  if (f0ValVec.size()>0 && f0TimeVec.size()>0) {
    if (f0TimeVec[0]!=0) {
      tmpF0TimeVec.push_back(0);
      tmpF0ValVec.push_back(f0ValVec[0]);
    }
    for (uint i=0; i< f0ValVec.size(); i++) {
      tmpF0TimeVec.push_back(f0TimeVec[i]);
      tmpF0ValVec.push_back(f0ValVec[i]);    
    }
    if (f0TimeVec[f0TimeVec.size()-1]!=100) {
      tmpF0TimeVec.push_back(100);
      tmpF0ValVec.push_back(f0ValVec[f0ValVec.size()-1]);
    }

    for (uint i=0; i<tmpF0TimeVec.size()-1; i++) {
      actTargetVal = (uint) rint(tmpF0TimeVec[i] * valNum * 0.01);
      nextTargetVal = (uint) rint(tmpF0TimeVec[i+1] * valNum * 0.01);
      start  = tmpF0ValVec[i];
      end  = tmpF0ValVec[i+1];
      
      if (actTargetVal > nextTargetVal) {
	error("wrong intonation description at phone:"+name+"\n", -3);
      }
      else if (actTargetVal == nextTargetVal) {
      } else {
	if (start == end) {
	  
	  for (uint j=actTargetVal; j < nextTargetVal; j++)
	    returnVec.push_back(end);
	  
	}
	else {
	  uint len = nextTargetVal-actTargetVal;
	  if (len==1) {
	    returnVec.push_back(start);
	  } else {
	    if (start < end) {
	      step = (end-start) / len;
	      for (uint j=1; j <= len; j++)
		returnVec.push_back(start + (uint) rint(j * step));
	    } else if (start > end) {
	      step = (start-end) / len;
	      for (uint j=1; j <= len; j++)
		returnVec.push_back(start - (uint) rint(j * step));
	    }
	  }
	}
      }
    }
  } else { // no intonation-description -> set f0Vals to zero
    for (uint j=0; j < valNum; j++)
      returnVec.push_back(0);
  }
  
  if (returnVec.size()!=valNum)
    error ("modelIntonation: uncorrect number of f0-vals at phone: "+name+"\n", -1);
  
  return returnVec;
  
}

std::vector<int> change_valNum(std::string name, uint valNum, uint leftBorder, uint rightBorder, std::vector<int> origVec) { 
  int frameDiffNum;
  uint midFrame;
  std::vector<int> returnVec(0);
  
  frameDiffNum = origVec.size() - valNum;
  //  cout <<   origVec.size() << "\n";
  // cout << name << " "<<  origVec.size() <<" "<<valNum<<" "<<frameDiffNum<< "\t";
  if (frameDiffNum > (int) (rightBorder-leftBorder)) {
    warn("dur change of phone "+name+" extends steady-state, ignoring borders!\n");
    midFrame =  origVec.size()/ 2;
  } else
    midFrame = rightBorder - (uint) rint((rightBorder-leftBorder) / 2);
  
  //  cout <<" "<<leftBorder<<" "<<rightBorder<< " "<<midFrame<<"\n";
  
  if (frameDiffNum > 0) { // delete Frames
    if (frameDiffNum%2==0)
      for (uint frame=0; frame < midFrame - (int) frameDiffNum/2; frame++) 
	returnVec.push_back(origVec[frame]);
    else
      for (uint frame=0; frame < midFrame - (int) frameDiffNum/2-1; frame++) 
	returnVec.push_back(origVec[frame]);      
    for (uint frame=midFrame + (int) frameDiffNum/2; 
	 frame < origVec.size(); frame++) 
      returnVec.push_back(origVec[frame]);
    
  } else if  (frameDiffNum < 0) { // insert Frames
    for (uint frame=0; frame < midFrame; frame++) 
      returnVec.push_back(origVec[frame]);
    for (uint frame=0; frame < (uint) -frameDiffNum; frame++) 
      returnVec.push_back(origVec[midFrame]);
    for (uint frame=midFrame; frame < origVec.size(); frame++) 
      returnVec.push_back(origVec[frame]);
  } else { // no change
    return origVec;  
  }
  if (returnVec.size() != valNum)
    error("something went wrong in change_valNum (int) at phone: "+name+"\n", -3);
  return returnVec;
}

std::vector<uint> change_valNum(std::string name, uint valNum, uint leftBorder, uint rightBorder, std::vector<uint> origVec) { 
  int frameDiffNum;
  uint midFrame;
  std::vector<uint> returnVec(0);
  
  frameDiffNum = origVec.size() - valNum;
  //  cout <<   origVec.size() << "\n";
  // cout << name<<" "<< origVec.size() <<" "<<valNum<<" "<<frameDiffNum<< "\n";
  if (frameDiffNum>(int)(rightBorder-leftBorder)) {
    warn("dur change of phone "+name+" extends steady-state, ignoring borders!\n");
    midFrame =  origVec.size()/ 2;
  } else
    midFrame = rightBorder - (uint) rint((rightBorder-leftBorder) / 2);
  
  
  if (frameDiffNum > 0) { // delete Frames
    
    if (frameDiffNum%2==0)
      for (uint frame=0; frame < midFrame - (int) frameDiffNum/2; frame++) 
	returnVec.push_back(origVec[frame]);
    else
      for (uint frame=0; frame < midFrame - (int) frameDiffNum/2-1; frame++) 
	returnVec.push_back(origVec[frame]);      
    for (uint frame=midFrame + (int) frameDiffNum/2; 
	 frame < origVec.size(); frame++) 
      returnVec.push_back(origVec[frame]);

  } else if  (frameDiffNum < 0) { // insert Frames

    for (uint frame=0; frame < midFrame; frame++) 
      returnVec.push_back(origVec[frame]);
    for (uint frame=0; frame < (uint) -frameDiffNum; frame++) 
      returnVec.push_back(origVec[midFrame]);
    for (uint frame=midFrame; frame < origVec.size(); frame++) 
      returnVec.push_back(origVec[frame]);

  } else { // no change
    return origVec;  
  }
  // cout << name << " "<<  origVec.size() <<" "<<valNum<<" "<<returnVec.size() << "\t";
  // cout <<name<<" lB:"<<leftBorder<<" rB:"<<rightBorder<< " midFr:"<<midFrame<<" frDiffNum:"<<(int) frameDiffNum<< " orgSize:"<<  origVec.size() <<" newSize:"<<valNum<<" actSize:"<<returnVec.size() <<"\n";

  if (returnVec.size() != valNum)
    error("something went wrong in change_valNum (uint) at phone: "+name+"\n", -3);
  return returnVec;
}

std::vector<uint> change_valNum_stop(std::string name, uint valNum, uint leftBorder, uint rightBorder, std::vector<uint> origVec) { 
  int frameDiffNum;
  uint midFrame;
  std::vector<uint> returnVec(0);
  
  frameDiffNum = origVec.size() - valNum;
  //  cout <<   origVec.size() << "\n";
  // cout << name<<" "<< origVec.size() <<" "<<valNum<<" "<<frameDiffNum<< "\n";
  if (frameDiffNum>(int)(rightBorder-leftBorder)) {
    warn("dur change of phone "+name+" extends steady-state, ignoring borders!\n");
    midFrame =  origVec.size()/ 2;
  } else
    midFrame = rightBorder - (uint) rint((rightBorder-leftBorder) / 2);
  
  
  if (frameDiffNum > 0) { // delete Frames
    
    if (frameDiffNum%2==0)
      for (uint frame=0; frame < midFrame - (int) frameDiffNum/2; frame++) 
	returnVec.push_back(origVec[frame]);
    else
      for (uint frame=0; frame < midFrame - (int) frameDiffNum/2-1; frame++) 
	returnVec.push_back(origVec[frame]);      
    for (uint frame=midFrame + (int) frameDiffNum/2; 
	 frame < origVec.size(); frame++) 
      returnVec.push_back(origVec[frame]);

  } else if  (frameDiffNum < 0) { // insert Frames

    for (uint frame=0; frame < midFrame; frame++) 
      returnVec.push_back(origVec[frame]);
    for (uint frame=0; frame < (uint) -frameDiffNum; frame++) 
      returnVec.push_back(origVec[midFrame]);
    for (uint frame=midFrame; frame < origVec.size(); frame++) 
      returnVec.push_back(origVec[frame]);

  } else { // no change
    return origVec;  
  }
  //  cout << name << " "<<  origVec.size() <<" "<<valNum<<" "<<returnVec.size() << "\t";
  // cout <<name<<" lB:"<<leftBorder<<" rB:"<<rightBorder<< " midFr:"<<midFrame<<" frDiffNum:"<<(int) frameDiffNum<< " orgSize:"<<  origVec.size() <<" newSize:"<<valNum<<" actSize:"<<returnVec.size() <<"\n";

  if (returnVec.size() != valNum)
    error("something went wrong in change_valNum at phone: "+name+"\n", -3);
  return returnVec;
}

std::vector<std::string> string2vec(std::string buffer) {
  std::vector<std::string> returnVec;
  std::string token;

  std::istrstream ist(buffer.c_str());
  while (ist >> token)
    returnVec.push_back(token);
  
  return returnVec;
}

uint msec2frames(uint dur, globalsT glob) {
  return (uint) rint(dur/glob.ui);
}

uint frames2msec(uint frames, globalsT glob) {
  return (uint) frames * glob.ui;
}

uint calcNewDur(uint dur, int rate, globalsT glob) {
  uint newDur;
  
  newDur = dur*rate/100;
  uint middle = glob.ui/2+1;

  if (newDur % glob.ui==0)
    return newDur;
  else if (newDur % glob.ui < middle)
    return newDur - newDur % glob.ui;
  else 
    return newDur+(glob.ui - newDur % glob.ui);
}


uint F12BW(uint f1) {
  // parameters of parabel describing BW1 as Function of F1
  double a=0.0004094,
    b=-0.44975,
    c=153.575;
  if (f1>maxF1 || f1<minF1) {
    std::cerr<<"WARNING: F12BW: unlikely F1 value: "<<f1<<" yields weired BW1 value\n";
  }
  return (uint) ((double)f1*(double)f1*a + (double)f1*b + c);
}


