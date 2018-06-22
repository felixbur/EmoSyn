/**
 * PHON.h
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

#ifndef _PHON_H_
#define _PHON_H_

#include "util.h" 

/** 
 * The central first formant-centerfreq for vowels.
*/
const uint center_F1 = 500;
/** 
 * The central second formant-centerfreq for vowels.
*/
const uint center_F2 = 1500;

#define USE_F0_ALTERNATING 1
#define USE_FLUTTER 2

#define TIME_ALIGNED 1
#define STEADY_STATE_CUT 2

/**
 * typedef: coarticulation affect the successors, the predecessors or both.
 */
typedef enum {
  progressive,
  regressive,
  both
} CO_TYPE;

/**
 * A strucure to describe features a phone could have. 
 * Most of the features are parameterized by a strat and stop time and a
 * rate (sterngth of feature).
 */
typedef struct {
  /// true if phon is voiceless but has voiced parts
  /// or if phon is voiced but has voiceless parts
  bool voiced; 
  /// start of voiced/voiceless part (in frameNums)
  uint vocStart; 
  /// stop of voiced/voiceless part (in frameNums)
  uint vocStop; 
  /// true if phon should be breathy.
  bool breathy;
  /// start of breathy part in frameNums
  uint brtStart; 
  /// end of breathy part in frameNums
  uint brtStop;
  /// how breathy? (0-100)
  uint brtRate; 
  /// true if phon should be nasalized
  bool nasalized;
  /// start of nasalized part in frameNums
  uint nasStart; 
  /// end of nasalized part in frameNums
  uint nasStop;
  /// true if phon should be  laryngealized
  bool laryngealized;
  /// start of laryngealized part in frameNums
  uint larStart; 
  /// end of laryngealized part in frameNums
  uint larStop;
  /// how much? (0-100)
  uint larRate; 
  /// true if phonation of phon is creaky
  bool creaky;
  /// start of creaky part in frameNums
  uint creakyStart; 
  ///  end  of creaky part in frameNums
  uint creakyStop;
  /// how creaky? (0-100)
  uint creakyRate; 
  /// true if phon is affected by spread lips
  bool spread;
  /// how much? (0-15)
  uint spreadRate;
 ///vowel features
  /// true if phon is affected by rounded lips
  bool rounded; 
  /// how much? (0-15)
  uint roundedRate;
  /// true if phon is affected by formant-target undershoot
  bool undershoot;
  /// how much? (0-80)
  uint undershootRate;
  /// true if phon is affected by formant-target overshoot
  bool overshoot;
  /// how much? (0-80)
  uint overshootRate;
  /// true if phon is affected by headSize
  bool headSize;
  /// how much? (0-20)
  uint headSizeRate;
  /// true if phonation of phon is falsetto
  bool falsett;
  /// how much? (0-100)
  uint falsettRate;  
  /// true if phonation of phon is whispery
  bool whisper;
  /// how much? (0-100)
  uint whisperRate;  
  /// true if phonation of phon is tense
  bool tense;
  /// how much? (0-100)
  uint tenseRate;  
  /// true if phonation of phon is lax
  bool lax;
  /// true if phon shows jitter
  bool jitter;
  /// how much? if method=1(0-10),if method=2(0-300)
  uint jitterRate;
  /// method=1->USE_F0_ALTERNATING, method=2->USE_FLUTTER
  uint jitterMethod;
  /// true if phon is affected by coarticulation
  bool coarticulation;
  /// how much?
  uint coarticulationRate;
  /// progressive, regressive or both
  CO_TYPE coarticulationType;
} PHON_FEATURES;

/**
 * typedef: each phone is either vowel or consonant.
 */
typedef enum {
  vowel,
  consonant
} PHON_TYPE;


/**
 * typedef: quadrant in the vowelchart, consonants and diphtongs are noQuadrant.
 */
typedef enum {
  noQuadrant,
  topLeft,
  topRight,
  bottomRight,
  bottomLeft
} FORMANT_QUADRANT;

/**
 * typedef: manner of articulation.
 */
typedef enum {
  long_vowel, 
  short_vowel,
  liquide, 
  nasal, 
  fricative_voiced, 
  fricative_voiceless, 
  stop_voiced, 
  stop_voiceless, 
  silence,
  noManner
} PHON_MANNER;

/**
 * typedef: place of articulation.
 */
typedef enum {
  noPlace,
  bilabial,
  labial,
  labiodental,
  alveolar,
  postalveolar,
  palatal,
  velar,
  uvular,
  glottal
} PHON_PLACE;

/**
 * phone is the basic entity of emoSyn.
 */
class phon {
  /// The name of the phone in Sampa. 
  /// Possible phone-names are language dependend
  std::string name;
  /// duration of phon in msec.
  uint dur; 
  /// number of frames, should be dur/framesize.
  uint frameNum;
  /// The mean f0-Value.
  uint meanF0;
  /// vowel/consonant
  PHON_TYPE type;              
  /// long_vowel, short_vowel, nasal, stop, ...
  PHON_MANNER manner;          
  /// bilabial, labial, labiodental, ...
  PHON_PLACE place;            
  /// spread, nasalized, laryngealized, ...
  PHON_FEATURES phonFeatures;  
  /// true if phone is normally voiced 
  bool voiced; 
  /// true if phone is diphtong
  bool diphtong;
  /// the quadrant for vowels in the vowel-chart.
  /// currently not used.
  FORMANT_QUADRANT formantQuadrant;

  /// the originale frameNumber from diphone-inventory
  uint origValNum;
  /// time of start of steady state (in frameNums).
  uint steadyStart;
  /// time of end of steady state (in frameNums).
  uint steadyEnd;
  /// stops: time of start of burst (in frameNums).
  uint burstStart;
  /// stops: time of start of aspiration (in frameNums).
  uint aspStart;

  /// intonation description
  std::vector<uint> f0ValVec; 
  /// intonation description, comes from mbrola-format.
  std::vector<uint> f0TimeVec; 

  /// each frame one f0-val
  std::vector<uint> f0Vec; 
  /// each frame one amplitude-val in dB, normalized to 60 dB.
  std::vector<uint> ampVec;

  /// cascade formant-parameters
  std::vector<uint> f1Vec;
  /// cascade formant-parameters
  std::vector<uint> f2Vec;
  /// cascade formant-parameters
  std::vector<uint> f3Vec;
  /// cascade formant-parameters
  std::vector<uint> f4Vec;
  /// cascade formant-parameters
  std::vector<uint> f5Vec;
  /// cascade formant-parameters
  std::vector<uint> f6Vec;
  /// cascade formant-parameters
  std::vector<uint> b1Vec;
  /// cascade formant-parameters
  std::vector<uint> b2Vec;
  /// cascade formant-parameters
  std::vector<uint> b3Vec;
  /// cascade formant-parameters
  std::vector<uint> b4Vec;
  /// cascade formant-parameters
  std::vector<uint> b5Vec;
   /// cascade formant-parameters
 std::vector<uint> b6Vec;


  /// parallel formant-parameters, amplitudes of formants
  std::vector<uint> a1Vec; 
  /// parallel formant-parameters, amplitudes of formants
  std::vector<uint> a2Vec;
  /// parallel formant-parameters, amplitudes of formants
  std::vector<uint> a3Vec;
  /// parallel formant-parameters, amplitudes of formants
  std::vector<uint> a4Vec;
  /// parallel formant-parameters, amplitudes of formants
  std::vector<uint> a5Vec;
  /// parallel formant-parameters, amplitudes of formants
  std::vector<uint> a6Vec;
  /// parallel formant-parameters, bandwidths for parallel branch
  std::vector<uint> b1pVec; 
  /// parallel formant-parameters, bandwidths for parallel branch
  std::vector<uint> b2pVec;
  /// parallel formant-parameters, bandwidths for parallel branch
  std::vector<uint> b3pVec;
  /// parallel formant-parameters, bandwidths for parallel branch
  std::vector<uint> b4pVec;
  /// parallel formant-parameters, bandwidths for parallel branch
  std::vector<uint> b5pVec;
  /// parallel formant-parameters, bandwidths for parallel branch
  std::vector<uint> b6pVec;

  /// voice-source parameters
  /// voiced amplitude of cascade branch (0-70)
  std::vector <uint> avVec;
  /// amp. of aspiration (0-70)
  std::vector <uint> ahVec; 
  /// amp. of turbulence(0-80)
  std::vector <uint> aturbVec; 
  /// open perc in glottal period
  std::vector <uint> oqVec; 
  /// amp. of frication, par. branch(0-80)
  std::vector <uint> afVec; 
  /// amp. of bypass frication, par. branch(0-80)
  std::vector <uint> abVec; 
  /// amp. of voicing, par. branch(0-70)
  std::vector <uint> avpVec; 
  ///  spectral tl in dB(0-24)
  std::vector <uint> tlVec; 
  /// spectral skew(0-40)
  std::vector <uint> flVec;  
  /// overall gain(0-80)
  std::vector <uint> gainVec; 

  /// nasal parameters
  /// amp. of nasal formant, parallel branch
  std::vector <uint> anvVec; 
  /// freq of nasal zero
  std::vector <uint> fnzVec; 
  /// bw of nasal zero
  std::vector <uint> bnzVec; 
  /// freq of nasal pole
  std::vector <uint> fnpVec; 
  /// bw of nasal pole
  std::vector <uint> bnpVec; 
  /// speed quotient, glottal source parameter
  std::vector <uint> sqVec; 
  /// diplophonic double pulsing
  std::vector <uint> diVec; 
  /// delta f1, for pharyngeal interactions
  std::vector <uint> df1Vec; 
  /// delta b1, for pharyngeal interactions
  std::vector <uint> db1Vec; 
  /// freq of tracheal pole
  std::vector <uint> ftpVec; 
  /// bw of tracheal pole
  std::vector <uint> btpVec; 
  /// freq of tracheal zero
  std::vector <uint> ftzVec; 
  /// bw of tracheal zero
  std::vector <uint> btzVec; 
  /// amplitude of 2. formant (parallel branch)
  std::vector <uint> a2fVec; 
  /// amplitude of 3. formant (parallel branch)
  std::vector <uint> a3fVec; 
  /// amplitude of 4. formant (parallel branch)
  std::vector <uint> a4fVec; 
  /// amplitude of 5. formant (parallel branch)
  std::vector <uint> a5fVec; 
  /// amplitude of 6. formant (parallel branch)
  std::vector <uint> a6fVec; 
  /// amplitude of 1. formant (parallel branch, voicing), not used.
  std::vector <uint> a1vVec; 
  /// amplitude of 2. formant (parallel branch, voicing), not used.
  std::vector <uint> a2vVec; 
  /// amplitude of 3. formant (parallel branch, voicing), not used.
  std::vector <uint> a3vVec; 
  /// amplitude of 4. formant (parallel branch, voicing), not used.
  std::vector <uint> a4vVec; 
  /// amplitude of tracheal formant (parallel branch, voicing), not used.
  std::vector <uint> atvVec; 
 
 public:

  /**
   * A constructor.
   * creates a phon with name newname, duration newdur and all 
   * klattparameter-frames are initialized to klatt_global-defaults 
   * side-effects:
   * frameNum, type, manner and place are defined
   */
  phon(std::string newname, uint newdur, globalsT glob);

  /** 
   * the empty Constructor.
   */
  phon();  


  /**
   * Set/change name of phon, defines type, manner and place of 
   * articulation of phone.
   *
   * @param string newName, new name of phon
   *
  **/
  void setName(std::string newName);

  /**
   * Set/change phone features
   *
   * @param string newPhonFeatures
   *
  **/ 
  void setPhonFeatures(PHON_FEATURES newPhonFeatures);

  /**
   * Set/change start of steady-state in framenumbers
   *
   * @param uint newSteadyStart
   *
  **/ 
 void setSteadyStart(uint newSteadyStart);

  /**
   * Set/change end of steady-state in framenumbers
   *
   * @param uint newSteadyEnd
   *
  **/ 
 void setSteadyEnd(uint newSteadyEnd);

  /**
   * Set/change start of burst in framenumbers (stops only)
   * 
   * @param uint newBurstStart
   *
  **/ 
  void setBurstStart(uint newBurstStart);

  /**
   * Set/change start of Aspiration in framenumbers (stops only)
   * 
   * @param uint newAspStart 
   *
  **/ 
  void setAspStart(uint newAspStart);

  /**
   * set/change f0 vals. (together with f0TimeVec: intonation description)
   * this is the original f0-std::vector that comes from the mbrola-file, it's
   * filled up with values (each frame one f0-value) after reading and 
   * stored in f0Vec.
   *  defines mean-val of f0-vals
   * \see setF0TimeVec
   * \see setF0Vec
   *  @param std::vector\<uint\>& newF0ValVec
  */
  void setF0ValVec(std::vector<uint>& newF0ValVec);

  /**
   * set/change location of f0 vals.
   * (together with f0ValVec: intonation description)
   * \see setF0ValVec
   *  @param std::vector\<uint\>& newF0TimeVec
  */
  void setF0TimeVec(std::vector<uint>& newF0TimeVec);
  
  /**
   * set/change f0-vals. 
   * defines mean-val of f0-vals
   * changes bool f0Dyn in globals to true
   * @param std::vector\<uint\>& newF0ValVec
   * @param globalsT &kg
   */
  void setF0Vec(std::vector<uint>& newF0Vec, globalsT &kg) {
    f0Vec = newF0Vec;
    meanF0 = (uint) mean(f0Vec);
    kg.f0Dyn=true;
    if (kg.copyDB)
      dur = newF0Vec.size()*kg.ui;
  }
  /**
   * set/change Amp-vals, 
   * changes bool ampDyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setAmpVec(std::vector<uint> newVec, globalsT &kg) {ampVec = newVec;}
  /**
   * set/change F1-vals, 
   * changes bool f1Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setF1Vec(std::vector<uint> newVec, globalsT &kg) {f1Vec = newVec; kg.f1Dyn=true;}
  /**
   * set/change f2-vals, 
   * changes bool f2Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setF2Vec(std::vector<uint> newVec, globalsT &kg) {f2Vec = newVec; kg.f2Dyn=true;}
  /**
   * set/change f3-vals, 
   * changes bool f3Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setF3Vec(std::vector<uint> newVec, globalsT &kg) {f3Vec = newVec; kg.f3Dyn=true;}
  /**
   * set/change f4-vals, 
   * changes bool f4Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setF4Vec(std::vector<uint> newVec, globalsT &kg) {f4Vec = newVec; kg.f4Dyn=true;}
  /**
   * set/change f5-vals, 
   * changes bool f5Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setF5Vec(std::vector<uint> newVec, globalsT &kg) {f5Vec = newVec; kg.f5Dyn=true;}
  /**
   * set/change f6-vals, 
   * changes bool f6Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setF6Vec(std::vector<uint> newVec, globalsT &kg) {f6Vec = newVec; kg.f6Dyn=true;}
  /**
   * set/change b1-vals, 
   * changes bool b1Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB1Vec(std::vector<uint> newVec, globalsT &kg) {b1Vec = newVec; kg.b1Dyn=true;}
  /**
   * set/change b2-vals, 
   * changes bool b2Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB2Vec(std::vector<uint> newVec, globalsT &kg) {b2Vec = newVec; kg.b2Dyn=true;}
  /**
   * set/change b3-vals, 
   * changes bool b3Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB3Vec(std::vector<uint> newVec, globalsT &kg) {b3Vec = newVec; kg.b3Dyn=true;}
  /**
   * set/change b4-vals, 
   * changes bool b4Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB4Vec(std::vector<uint> newVec, globalsT &kg) {b4Vec = newVec; kg.b4Dyn=true;}
  /**
   * set/change b5-vals, 
   * changes bool b5Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB5Vec(std::vector<uint> newVec, globalsT &kg) {b5Vec = newVec; kg.b5Dyn=true;}
  /**
   * set/change b6-vals, 
   * changes bool b6Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB6Vec(std::vector<uint> newVec, globalsT &kg) {b6Vec = newVec; kg.b6Dyn=true;}
  /**
   * set/change a1-vals, (iles&simmons-version only) 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setA1Vec(std::vector<uint> newVec, globalsT &kg) {a1Vec = newVec;}
  /**
   * set/change a2-vals,  (iles&simmons-version only) 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setA2Vec(std::vector<uint> newVec, globalsT &kg) {a2Vec = newVec;}
  /**
   * set/change a3-vals,  (iles&simmons-version only) 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setA3Vec(std::vector<uint> newVec, globalsT &kg) {a3Vec = newVec;}
  /**
   * set/change a4-vals,  (iles&simmons-version only) 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setA4Vec(std::vector<uint> newVec, globalsT &kg) {a4Vec = newVec;}
  /**
   * set/change a5-vals,  (iles&simmons-version only) 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setA5Vec(std::vector<uint> newVec, globalsT &kg) {a5Vec = newVec;}
  /**
   * set/change a6-vals,  (iles&simmons-version only) 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setA6Vec(std::vector<uint> newVec, globalsT &kg) {a6Vec = newVec;}
  /**
   * set/change b1p-vals, 
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB1pVec(std::vector<uint> newVec, globalsT &kg) {b1pVec = newVec;}
  /**
   * set/change b2p-vals, 
   * changes bool Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB2pVec(std::vector<uint> newVec, globalsT &kg) {b2pVec = newVec; kg.b2pDyn=true;}
  /**
   * set/change b3p-vals, 
   * changes bool Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB3pVec(std::vector<uint> newVec, globalsT &kg) {b3pVec = newVec; kg.b3pDyn=true;}
  /**
   * set/change b4p-vals, 
   * changes bool Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB4pVec(std::vector<uint> newVec, globalsT &kg) {b4pVec = newVec; kg.b4pDyn=true;}
  /**
   * set/change b5p-vals, 
   * changes bool Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB5pVec(std::vector<uint> newVec, globalsT &kg) {b5pVec = newVec; kg.b5pDyn=true;}
  /**
   * set/change b6p-vals, 
   * changes bool Dyn to true
   * @param std::vector\<uint\>& newVec
   * @param globalsT &kg
   */
  void setB6pVec(std::vector<uint> newVec, globalsT &kg) {b6pVec = newVec; kg.b6pDyn=true;}
  
  
  /** 
   * returns mean of f0 vals.
   * @return uint MeanF0
   */
  uint MeanF0();
  
  /** 
   * returns name of phon (in Sampa).
   * @return string name
   */
  std::string Name();

  /** 
   * returns type of phon (vowel or consonant).
   * @return PHON_TYPE
   */
  PHON_TYPE Type();
  /** 
   * returns manner of phon (manner of articulation).
   * @return PHON_MANNER
   */
  PHON_MANNER Manner();
  /** 
   * returns place of phon (place of articulation).
   * @return PHON_PLACE
   */
  PHON_PLACE Place();

  /** 
   * returns true if phone is fundamentally voiced.
   * @return bool
   */
   bool Voiced();

   /** 
   * returns true if phone is diphtong.
   * @return bool
   */
  bool Diphtong();

  /**
   *  sets manner, place, type, formantQuadrant and voiced according to name.
   * This is done by the consturctor.
   * \see phon(string newname, uint newdur, globalsT glob)
   * @param string
  */
  void initMannerPlaceType(std::string name);

  /** 
   * returns duration of phon in msec.
   * @return uint
   */
  uint Dur();

  /** 
   * returns number of frames of phon (klattSynth).
   * uses ui (update interval) from globalsT
   * \see globalsT
   * @return uint
   */
  uint FrameNum();

  /** 
   * returns original number of f0 vals (from mbrola-file).
   * @return uint
   */
  uint DataFrameNum();
  
  /** 
   * returns struct PhonFeatures for the phone.
   * @return PHON_FEATURES
   */
  PHON_FEATURES PhonFeatures();

  /** 
   * returns original f0 vals (from mbrola-file).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F0ValVec();

  /** 
   * returns original locations of f0 vals (from mbrola-file).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F0TimeVec();

  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AmpVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F0Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F1Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F2Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F3Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F4Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F5Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> F6Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B1Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B2Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B3Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B4Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B5Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B6Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A1Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A2Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A3Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A4Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A5Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A6Vec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B1PVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B2PVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B3PVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B4PVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B5PVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> B6PVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AvVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AhVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> OqVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AturbVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AfVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AbVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AvpVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> TlVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> FlVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> GainVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AnvVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> FnzVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> BnzVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> FnpVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> BnpVec();
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> SqVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> DiVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> Df1Vec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> Db1Vec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> FtpVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> BtpVec(); 
   /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
 std::vector <uint> FtzVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> BtzVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A2fVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A3fVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A4fVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A5fVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A6fVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A1vVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A2vVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A3vVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> A4vVec(); 
  /** 
   * returns parameter std::vector (length==frameNum).
   * @return std::vector \<uint\>
   */
  std::vector <uint> AtvVec(); 


  /** 
   * returns start of steady-state in framenumbers.
   * @return uint
   */
  uint SteadyStart();
  /** 
   * returns end of steady-state in framenumbers.
   * @return uint
   */
  uint SteadyEnd();
  /** 
   * returns start of burst in framenumbers (stops only).
   * @return  uint
   */
  uint BurstStart();
  /** 
   * returns start of Aspiration in framenumbers (stops only).
   * @return uint
   */
  uint AspStart();

  
  
  /** 
   *  prints name of phon to outFile (debugging).
   *  @param ostream &outFile
  */
  void printName(std::ostream &outFile);

  /** 
   *  prints all parameters (frames) of the phone in sensyn-format.
   * the paramter start gives the start time of the phone. Used by
   * printSenSynFile().
   * \see phrase::printSenSynFile()
   *  @param uint start
   *  @param ostream &outFile
   *  @param globalsT glob
  */
  void printSenSynFrames(uint start, std::ostream &outFile, globalsT glob);

  /** 
   *  prints KlattFrames of phone in simmons&iles format to outFile
   * \see phrase::printKlattFile()
   *  @param ostream &outFile
  */
  void printKlattFrames(std::ostream &outFile);
 
  /**
   * models voice-source parameters.
   * Parameters (val-std::vectors are filled) are set according 
   * to place and manner of articulation. <br>
   *
   * Some of the modeling depends on the actual klatt-synthesizer that's used.
   * I did all the testing with the sensyn synthesizer, so there's still
   * work to do for the Simmons&Iles synthesizer.
   *
   * It's not easy to get data for this in the literature, I did lot's
   * of experiments and I only cared about the parameters for phones that
   * occured in my testsentence.
   * However, you get some information from <br>
   * author = 	 {Klatt, D. H. }, <br>
   * title = 	 {Software for a Cascade/Parallel Formant Synthesizer}, <br>
   * journal = 	 JASA, <br>
   *  year = 	 {1980}, <br>
   * volume = 	 {67},<br>
   * number = 	 {3},<br>
   * pages = 	 {971-959}, <br>
   *
   * or (in German and difficult to get) <br>
   * author = 	 {Simpson, A. }, <br>
   * booktitle = 	 {Phonetische Datenbanken des Deutschen in der Empirischen Sprachforschung und der Phonologischen Theoriebildung}, <br>
   * title = 	 {Wissensbasierte Gewinnung von Steuerparametern f"ur die Formantsynthese}, <br>
   * publisher = 	 {Institut f"ur Phonetik und digitale Sprachverarbeitung der Universit"at Kiel}, <br>
   * year = 	 {1998}, <br>
   * editor = {Kohler, K. J. }, <br>
   * series = {Arbeitsberichte 33}, <br>
   *
   * or even <br>
   * author = {Kent, R.D. and Read, C.}, <br>
   * title = {The Acoustic Analysis of Speech}, <br>
   * year = {1992}, <br>
   * publisher = {Singular Publishing Group, San Diego}, <br>
   *
   * \see phrase::modelKlattParameters(globalsT &globals)
   * \see setArticulationTractFilter()
   * \todo model more phones, this is language-specific.
   * \todo do some testing with the Simmons & Iles synthesizer.
   * @param globalsT globals
  */
  void setSoundSource(globalsT &glob);

  /**
   * models ArticulationTractFilter parameters.
   * Parameters (val-std::vectors are filled) are set according 
   * to place and manner of articulation.  <br>
   *
   * Some of the modeling depends on the actual klatt-synthesizer that's used.
   * I did all the testing with the sensyn synthesizer, so there's still
   * work to do for the Simmons&Iles synthesizer.
   *
   * It's not easy to get data for this in the literature, I did lot's
   * of experiments and I only cared about the parameters for phones that
   * occured in my testsentence.
   * However, you get some information from <br>
   * author = 	 {Klatt, D. H. }, <br>
   * title = 	 {Software for a Cascade/Parallel Formant Synthesizer}, <br>
   * journal = 	 JASA, <br>
   *  year = 	 {1980}, <br>
   * volume = 	 {67},<br>
   * number = 	 {3},<br>
   * pages = 	 {971-959}, <br>
   *
   * or (in German and difficult to get) <br>
   * author = 	 {Simpson, A. }, <br>
   * booktitle = 	 {Phonetische Datenbanken des Deutschen in der Empirischen Sprachforschung und der Phonologischen Theoriebildung}, <br>
   * title = 	 {Wissensbasierte Gewinnung von Steuerparametern f"ur die Formantsynthese}, <br>
   * publisher = 	 {Institut f"ur Phonetik und digitale Sprachverarbeitung der Universit"at Kiel}, <br>
   * year = 	 {1998}, <br>
   * editor = {Kohler, K. J. }, <br>
   * series = {Arbeitsberichte 33}, <br>
   *
   * or even <br>
   * author = {Kent, R.D. and Read, C.}, <br>
   * title = {The Acoustic Analysis of Speech}, <br>
   * year = {1992}, <br>
   * publisher = {Singular Publishing Group, San Diego}, <br>
   *
   * \see phrase::modelKlattParameters(globalsT &globals)
   * \see setSoundSource()
   * \todo model more phones, this is language-specific.
   * \todo do some testing with the simmons & Iles synthesizer.
   * @param globalsT globals
  */
  void setArticulationTractFilter(globalsT &glob);
 
  /**
   * models phone-features changing voice-source 
   * and/or ArticulationTractFilter parameters.
   * For voiceless phones which should become voiced, sylMeanF0 is used.
   * For coarticulation prev- and nextManner are used. <br>
   * I didn't find much information in the literature about modeling
   * phonetic settings with a formant-synthesizer, so most of it I thought up
   * theoretically from acoustic source-filter theory and did some 
   * experiments.
   * Here's some of the literature I used:
   *
   * the one for acoustic theory: <br>
   * author = {Fant, G. }, <br>
   * title = {Acoustic Theory of Speech Production}, <br>
   * publisher = {Mouton, 's-Gravenhage}, <br>
   * year = {1960} <br>
   *
   * this one was (I think) never published, but it's very valuable,
   * they ship it with the sensyn synthesizer <br>
   *   author = {Klatt, D. H. }, <br>
   * title ={KLATTALK, The Conversion of English Text to Speech}, <br>
   * chapter = {3: Description of the Cascade/Parallel Formant Synthesizer}, <br>
   * publisher = {unpublished}, <br>
   * year = {1990}, <br>
   *
   * and, of course: <br>
   *   author = {Klatt, D. H.  and Klatt, L. C. }, <br>
   * title = {Analysis, Synthesis and Perception of Voice Qualtity Variations among Female and Male Talkers}, <br>
   * journal = JASA, <br>
   * year = {1990}, <br>
   * volume = {87}, <br>
   * number = {2}, <br>
   * pages = {820-856}, <br>
   *
   * \see phrase::modelFeatures()
   * \todo model the features more adequately.
   * \todo model more features. 
   * @param uint sylMeanF0 
   * @param globalsT globals 
   * @param  phon *prevManner
   * @param  phon *nextManner
  */
  void modelFeatures(uint sylMeanF0, globalsT &glob, phon *prevpP, phon *nextpP);

  /** 
   * models Intonation by filling the gaps in f0ValVec. 
   *  f0Vec gets set/changed. f0Dyn is true.
   * \see f0ValVec
   * \see f0TimeVec
   * @param globalsT globals 
   */
  void modelIntonation(globalsT &kg);

  // **********************************
  // modification-methods

  /**
   *    set/change duration of phon in msek.
   *  Set/change frameNumber of phon.
   * 
   *  shortens or lengthens all valVecs, algorithm depends on 
   * glob.changeDurMethod.
   * if glob.changeDurMethod==STEADY_STATE_CUT -\> frames in the steady state
   * get repeated/deleted.
   * if glob.changeDurMethod==TIME_ALIGNED -\> the contour gets 
   * expnaded/compressed.
   *  Expects valVecs, steadyStart, steadyEnd and burstStart to be set.
   *
   * \see globalsT
   * \see steadyStart
   * \see steadyEnd
   * \see burstStart
   * \see aspStart
   *
   *  @param uint newDur
   *  @param globalsT glob
   */
  void changeDur(uint newDur, globalsT glob);

  /**
   * add/subtract \<dbVal\> from ampVal.
   * \see syllable::changeAvrInt()
   * @param int dBVal
  */
  void changeAvrInt(int dBVal);

  /**
   * change f0Vals by rate (100=no change)
   * 
   * \see syllable::changeMeanF0()
   * \see phrase::changeMeanF0()
   * 
   * @param uint rate
   */
  void changeMeanF0(uint rate);
  /**
   *  smoothing function: all f0Vals get centerFiltered around winsize.
   * \see phrase::smootheF0()
   * @param uint winsize
   *
   */
  void smootheF0(uint winsize);
  /**
   * change Range of f0Contour compressing/expanding at <rate>
   * in relation to <meanF0>
   * \see phrase::changeF0Range()
   * \see syllable::changeF0Range()
   * @param uint rate
   * @param uint meanF0
  */
  void changeF0Range(uint rate, uint meanF0);
  /**
   * interpolate f0Contour linear from start to end.
   *  \see phrase::changePitchContourStressed()
   *  \see phrase::changeLastSylContour()
   *  @param uint end
   *  @param uint start
   *
  */
  void interpolateF0Vec(uint start, uint end);
  
};

/**
 * sets all features to default values (zero).
 */
void initPhonFeatures(PHON_FEATURES &phonFeatures);


/**
 * categorizes the phones (language dependend).
 * \todo provide for more languages. 
 *
 * @param char *phone phone-name in Sampa
 * @return PHON_MANNER
 */
extern "C" PHON_MANNER classify_german(char *phone);
/**
 * prints and error message and exits the program.
 * example: exitErr("classify_german: \%s: no such Phone\n", phone, -1);
 * @param char *msg, the actual message
 * @param char *str, a variable to be placed in the message
 * @param int ErrNum, exit code
 */
extern "C" void exitErr(char *msg, char *str, int ErrNum);

#endif /* _PHON_H */

