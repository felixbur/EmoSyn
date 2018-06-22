/**
 * UTIL.h
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

#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <istream>
#include <string>
#include <cstdlib> 
#include <fstream>
#include <vector>
#include <string.h>
#include <strstream>
#include <math.h>
extern "C" {
#include <stdlib.h>
#include <stdio.h>
}

/**
 * just a shortcut.
 */
typedef unsigned int uint;

/// \see phrase::addWave()
#define LINEAR 1
/// \see phrase::addWave()
#define EXPONENTIAL 2
/// \see phrase::addWave()
#define LOGARITHMIC 3
/// \see phrase::addWave()
#define SYLLABLE_BASED 4

/// used for initialization.
const uint A_HIGH_INT = 100000;
/// used for error checking.
const uint maxVal = 10000;

/// all dB vals should be normaized to 60 dB
const uint MAX_DBVAL = 60;

/// max meaningful val for f0 in 10th of hertz
const uint maxF0 = 5000; 
/// min meaningful val for f0 in 10th of hertz
const uint minF0 = 500;  
/// max meaningful val for f1 in hertz
const uint maxF1 = 1000; 
/// min meaningful val for f1 in hertz
const uint minF1 = 200; 
/// max meaningful val for f2 in hertz
const uint maxF2 = 2500; 
/// min meaningful val for f2 in hertz
const uint minF2 = 500; 
/// max meaningful val for f3 in hertz
const uint maxF3 = 3800; 
/// min meaningful val for f3 in hertz
const uint minF3 = 2100; 
/// max meaningful val for f4 in hertz
const uint maxF4 = 4500; 
/// min meaningful val for f4 in hertz
const uint minF4 = 3000; 
/// max meaningful val for f5 in hertz
const uint maxF5 = 5000; 
/// min meaningful val for f5 in hertz
const uint minF5 = 3500; 

/// value for warning if freq-jump while concatenating formant-tracks is higher
const uint jumpTolerance = 50; 

/// min meaningful oq
const uint minOq = 10; 
/// min meaningful b1
const uint minB1 = 30; 
/// min meaningful b2
const uint minB2 = 30; 
/// min meaningful b3
const uint minB3 = 30; 
/// min meaningful b4
const uint minB4 = 40; 
/// min meaningful b5
const uint minB5 = 45; 
/// min meaningful b6
const uint minB6 = 50; 
/// min meaningful bnp
const uint minBnp = 30; 
/// min meaningful btp
const uint minBtp = 30; 

/// min meaningful change in speechrate
const uint MIN_SPEECHRATE = 70; 
/// max meaningful change in speechrate
const uint MAX_SPEECHRATE = 150; 


/** 
 * contour types for intonation over syllable or phrase.
 */
typedef enum {
  straight, /// 0=straight
  rise, /// 1=rise
  fall, /// 2=fall
} CONTOUR_TYPE;


/** 
 * global flags and values.
 * used as: 
 * - default values for the klatt synthesizer.
 * - interface to influence the behaviour of methods.
 *
 * the klatt-default params get initialized by emoSyn by 
 * reading a configuration-file
 * (defaultname "emosyn.conf", can be overwritten by 
 * option -kd \<configurationFileName\>)  
 *
 * the other control parameters have to be initialized by the main-program.
 * \todo read all control-parameters from configuration-file
 */
typedef struct {
  /** 
   * true if 4 formant-frequencies are dynamic
   */
  bool use4Freq;
  /** 
   * true if 5 formant-frequencies are dynamic
   */
  bool use5Freq;
  /** 
   * selects algorithm to change the duration of 
   * phones. 1=TIME_ALIGNED, 2=STEADY_STATE_CUT
   * \see phon::changeDur()
   */
  uint changeDurMethod;
  /** 
   * prints out lot's of stuff (debugging).
   */
  bool verbose;
  /** 
   * supresses warnings.
   */
  bool warningsOff;
  /** 
   * should be true if emoSyn is used to generate a mbrola-file 
   * from a database (first step for copysynthesis).
   */
  bool copyDB;
  /** 
   * could be used to control different behaviour if real synthesis is done
   * or copysynthesis. As up to now there is only copy-synthesis, it's not
   * used. 
   */
  bool copysynthesis;
  /**
   * true if output for sensyn, else output for iles&simmons
   */
  bool senSyn; 
  uint 
  /// default f0
  f0, 
  /// default formant-freq
    f1, 
  /// default formant-freq
    f2, 
  /// default formant-freq
    f3,
  /// default formant-freq
    f4, 
  /// default formant-freq
    f5, 
  /// default formant-freq
    f6,
  /// default bandwidth
    b1, 
  /// default bandwidth
    b2, 
  /// default bandwidth
    b3, 
  /// default bandwidth
    b4, 
  /// default bandwidth
    b5, 
  /// default bandwidth
    b6,
    /// parallel formant-parameters
  /// default amplitude (s&i only)
    a1, 
  /// default amplitude (s&i only)
    a2, 
  /// default amplitude (s&i only)
    a3, 
  /// default amplitude (s&i only)
    a4, 
  /// default amplitude (s&i only)
    a5, 
    /// default amplitude (s&i only)
    a6,
    /// default bandwidth parallel branch (s&i only)
    b1p, 
  /// default bandwidth parallel branch (sensyn only)
    b2p,  
    /// default bandwidth parallel branch (sensyn only)
    b3p, 
    /// default bandwidth parallel branch (sensyn only)
    b4p, 
  /// default bandwidth parallel branch (sensyn only)
    b5p, 
  /// default bandwidth parallel branch (sensyn only)
    b6p,
    /// voiced amplitude of cascade branch (0-70)
    av, 
    /// Amplitude of aspiration, in dB (asp in s&i)
    ah, 
    /// Open quotient (voicing open-time/period), in % (kopen in s&i)
    oq, 
    /// amp. of turbulence(0-80) /// i&s only
    aturb, 
    /// amp. of frication, par. branch(0-80)
    af, 
    /// amp. of bypass frication, par. branch(0-80)
    ab, 
    /// amp. of voicing, par. branch(0-70)
    avp; 
  /// Extra tilt of voicing spectrum, dB down @ 3 kHz (tilt in s&i)
  int tl; 
  /// Flutter (random fluct in f0), in % of maximum, (skew in s&i)
  uint fl, 
    /// overall gain(0-80)
    gain, 
    /// Amp of voice-excited parallel nasal formant, in dB (anp in s&i)
    anv, 
    /// freq of nasal zero
    fnz, 
    /// bw of nasal zero
    bnz, 
    /// freq of nasal pole
    fnp, 
    /// bw of nasal pole
    bnp, 
    /// Update interval for parameter reset, in msec (framesize)
    ui, 
    /// Output sampling rate, in samples/sec
    sr, 
    /// Number of formants in cascade branch
    nf, 
    /// Source switch (1=impulse, 2=natural, 3=LF model) (sensyn only)
    ss, 
    /// Random seed (initial value of random #generator) (sensyn only)
    rs, 
    /// Same noise burst, reset RS if AF=AH=0, 0=no,1=yes (sensyn only)
    sb, 
    /// 0=Cascade, 1=Parallel tract excitation by AV (sensyn only)
    cp, 
    /// Output selector (0=normal,1=voicing source,...) (sensyn only)
    os, 
    /// Overall gain scale factor for AV, in dB (sensyn only)
    gv, 
    /// Overall gain scale factor for AH, in dB (sensyn only)
    gh, 
    /// Overall gain scale factor for AF, in dB (sensyn only)
    gf, 
    /// Speed quotient (rise/fall time, LF model), in % (sensyn only)
    sq, 
    /// Diplophonia (alt periods closer), in % of max (sensyn only)
    di, 
    /// Change in F1 during open portion of period, in Hz (sensyn only)
    df1, 
    /// Change in B1 during open portion of period, in Hz (sensyn only)
    db1, 
    /// Frequency of tracheal pole, in Hz (sensyn only)
    ftp, 
    /// Bandwidth of tracheal pole, in Hz (sensyn only)
    btp, 
    /// Frequency of tracheal zero, in Hz (sensyn only)
    ftz, 
    /// Bandwidth of tracheal zero, in Hz (sensyn only)
    btz, 
    /// Amp of fric-excited parallel 2-6th formant, in dB (sensyn only)
    a2f, 
    /// Amp of fric-excited parallel 2-6th formant, in dB (sensyn only)
    a3f, 
    /// Amp of fric-excited parallel 2-6th formant, in dB (sensyn only)
    a4f, 
    /// Amp of fric-excited parallel 2-6th formant, in dB (sensyn only)
    a5f, 
    /// Amp of fric-excited parallel 2-6th formant, in dB (sensyn only)
    a6f, 
    ///  Amp of voice-excited parallel 1-4th formant, in dB  (sensyn only)
    a1v, 
    ///  Amp of voice-excited parallel 1-4th formant, in dB  (sensyn only)
    a2v, 
    ///  Amp of voice-excited parallel 1-4th formant, in dB (sensyn only) 
    a3v, 
    ///  Amp of voice-excited parallel 1-4th formant, in dB (sensyn only) 
    a4v, 
    /// Amp of voice-excited par tracheal formant, in dB (sensyn only)
    atv; 

  bool  
  /// true if parameter is dynamic
  f0Dyn,  
    /// true if parameter is dynamic
    f1Dyn,  
    /// true if parameter is dynamic
    f2Dyn,  
    /// true if parameter is dynamic
    f3Dyn,  
    /// true if parameter is dynamic
    f4Dyn,  
    /// true if parameter is dynamic
    f5Dyn,  
    /// true if parameter is dynamic
    f6Dyn,  
    /// true if parameter is dynamic
    b1Dyn,  
    /// true if parameter is dynamic
    b2Dyn,  
    /// true if parameter is dynamic
    b3Dyn,  
    /// true if parameter is dynamic
    b4Dyn,  
    /// true if parameter is dynamic
    b5Dyn,  
    /// true if parameter is dynamic
    b6Dyn,  
    /// true if parameter is dynamic
    b2pDyn,  
    /// true if parameter is dynamic
    b3pDyn,  
    /// true if parameter is dynamic
    b4pDyn,  
    /// true if parameter is dynamic
    b5pDyn,  
    /// true if parameter is dynamic
    b6pDyn,  
    /// true if parameter is dynamic
    avDyn,  
    /// true if parameter is dynamic
    ahDyn,  
    /// true if parameter is dynamic
    oqDyn,  
    /// true if parameter is dynamic
    aturbDyn,  
    /// true if parameter is dynamic
    afDyn,  
    /// true if parameter is dynamic
    abDyn,  
    /// true if parameter is dynamic
    tlDyn,  
    /// true if parameter is dynamic
    flDyn,  
    /// true if parameter is dynamic
    anvDyn,  
    /// true if parameter is dynamic
    fnzDyn,  
    /// true if parameter is dynamic
    bnzDyn,  
    /// true if parameter is dynamic
    fnpDyn,  
    /// true if parameter is dynamic
    bnpDyn,  
    /// true if parameter is dynamic
    sqDyn,  
    /// true if parameter is dynamic
    diDyn,  
    /// true if parameter is dynamic
    df1Dyn,  
    /// true if parameter is dynamic
    db1Dyn,  
    /// true if parameter is dynamic
    ftpDyn,  
    /// true if parameter is dynamic
    btpDyn,  
    /// true if parameter is dynamic
    ftzDyn,  
    /// true if parameter is dynamic
    btzDyn,  
    /// true if parameter is dynamic
    a2fDyn,  
    /// true if parameter is dynamic
    a3fDyn,  
    /// true if parameter is dynamic
    a4fDyn,  
    /// true if parameter is dynamic
    a5fDyn,  
    /// true if parameter is dynamic
    a6fDyn,  
    /// true if parameter is dynamic
    a1vDyn,  
    /// true if parameter is dynamic
    a2vDyn,  
    /// true if parameter is dynamic
    a3vDyn,  
    /// true if parameter is dynamic
    a4vDyn,  
    /// true if parameter is dynamic
    atvDyn; 

} globalsT;

/**
 *   returns artihmetic mean of \<vec\>.
 *  @param const vector\<uint>\& vec
 *   @return double
 */
double mean(const std::vector<uint>& vec);

/** 
 * sets elems of vec to the percentage of rate.
 * @param vec
 * @param rate
 */
void changeMean(std::vector<uint>& Vals, uint rate);

/**
 * a F0-smoothing function.
 * filters vector by replacing each elem by mean of 
 * +-winsize surrounding elems.
 *  @param vec
 *  @param winsize
 */
void smoothe(std::vector<uint>& Vals, uint winsize);

/** 
 * Expands or compresses valus around a mean value.
 * Depending whether elem of <Vals> is higher or lower then <mean>
 * it gets added or subtracted the percentage of <rate> and distance to <mean>
 * @param vector<uint>& Vals
 * @param short rate
 * @param double mean
 */
void changeContrast(std::vector<uint>& Vals, short rate, double mean);

/**
 *  changes elems of vec to the linear interpolated values 
 * between start and end
 * @param vector\<uint\>& resultVec
 * @param  uint start
 * @param uint end
 */
void interpolateLinear(std::vector<uint>&, uint start, uint end);

/**
 *  returns vec with size length as the linear interpolated 
 * values between start and end.
 * @return vector\<uint\>& resultVec
 * @param  uint length
 * @param  uint start
 * @param uint end
 */
std::vector<uint> interpolateLinear(uint length, uint start, uint end);

/**
 * returns frequency, that is <semiTone> away from <freq>.
 * the following formula is used: ST(f1,f2) = 12/ln(2) * ln(f1/f2)
 * @param uint freq
 * @param double semitone
 * @return double
 */
double ST2Hz(uint freq, double semiTone);

/**
 * returns distance between freq1 and freq2 in Semitones.
 * the following formula is used: ST(f1,f2) = 12/ln(2) * ln(f1/f2)
 * @param uint freq1
 * @param uint freq2
 * @return double
 */
double Hz2ST(uint freq1, uint freq2);



/**
 * returns frequency, that is <gradient> (in ST/sec) away from
 *  <freq> after <time> (in msec)
 * the following formula is used: ST(f1,f2) = 12/ln(2) * ln(f1/f2)
 * @param uint freq
 * @param uint time
 * @param uint gradient
 * @return double
 */
double gradient2Hz (uint freq, uint time, double gradient);

/**
 * returns MaxF0 if <freq> > MaxF0, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMaxF0(uint freq);
/**
 * returns MaxF1 if <freq> > MaxF1, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMaxF1(uint freq);
/**
 * returns MaxF2 if <freq> > MaxF2, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMaxF2(uint freq);
/**
 * returns MaxF3 if <freq> > MaxF3, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMaxF3(uint freq);
/**
 * returns MaxF4 if <freq> > MaxF4, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMaxF4(uint freq);
/**
 * returns MaxF5 if <freq> > MaxF5, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMaxF5(uint freq);

/**
 * returns MinF0 if <freq> < MinF0, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMinF0(uint freq);
/**
 * returns MinF1 if <freq> < MinF1, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMinF1(uint freq);
/**
 * returns MinF2 if <freq> < MinF2, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMinF2(uint freq);
/**
 * returns MinF3 if <freq> < MinF3, else <freq>
 * @param uint freq
 * @return uint
 */uint checkMinF0(uint freq);
uint checkMinF3(uint freq);
/**
 * returns MinF4 if <freq> < MinF4, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMinF4(uint freq);
/**
 * returns MinF5 if <freq> < MinF5, else <freq>
 * @param uint freq
 * @return uint
 */
uint checkMinF5(uint freq);

/**
 * All nonzero elements of vector get alternating subtracted or added
 * their percentage with rate. Used for Jitter simulation.
 * However, there's a more sophisticated Jittersimulation already implmented
 * in the klatt-formantsynthesizer (param FL (sensyn) or skew (s&i)).
 * @param vector\<uint\>& vals 
 * @param uint rate
 */
void addJitterVec(std::vector<uint>& vals, uint rate);

/**
 * prints \<msg\> to stderr and exits program with \<errNo\>.
 * @param string msg
 * @param int errNo
 */
void error(std::string msg, int errNo);

/**
 * prints \<msg\> to stderr.
 * @param string msg
 */
void warn(std::string msg);

/**
 * prints elems of vec to stdout, seperated by tabs
 * @param vector\<uint\>& vals 
 */
void printVec(std::vector<uint> vec);

/**
 * prints elems of vec to stdout, seperated by tabs
 * @param vector\<int\>& vals 
 */
void printVec(std::vector<int> vec);

/**
 * returns part of <vec> from index <start> to <end> (inclusive).
 * @param vector\<uint\>& vals 
 * @param uint start
 * @param  uint end
 * @return vector\<uint\>& vals 
 */
std::vector<uint> subVec(std::vector<uint> vec, uint start, uint end);


/**
 *  models F0-contour of phone name from mbrola-style f0-description.
 *  returns f0vector as an interpolated version of f0ValVec and  f0TimeVec.
 * @param string name
 * @param uint valNum
 * @param vector\<uint\> f0ValVec
 * @param vector\<uint\> f0TimeVec
 * @return vector\<uint\> 
*/
std::vector<uint> modelTrack(std::string name, uint valNum, std::vector<uint> f0ValVec, std::vector<uint> f0TimeVec);
/**
 *  models F0-contour of phone name from mbrola-style f0-description.
 *  returns f0vector as an interpolated version of f0ValVec and  f0TimeVec.
 * @param string name
 * @param uint valNum
 * @param vector\<int\> f0ValVec
 * @param vector\<uint\> f0TimeVec
 * @return vector\<int\>
*/
std::vector<int> modelTrack(std::string name, uint valNum, std::vector<int> f0ValVec, std::vector<uint> f0TimeVec);

/**
 * resizes vector orig (of ints) to length valNum.
 * For shortening, frames are deleted around the middle between left and right.
 * If those borders are overshot, a warning is delivered (containing name).
 * For lengthening, the middle frame between left and right is repeated.
 * @param string name
 * @param uint valNum
 * @param uint leftBorder
 * @param uint reightBorder
 * @param vector\<int\> origVec
 * @return vector\<int\>
*/
std::vector<int> change_valNum(std::string name, uint valNum, uint left, uint right, std::vector<int> orig);

/**
 * resizes vector orig (of uints) to length valNum.
 * For shortening, frames are deleted around the middle between left and right.
 * If those borders are overshot, a warning is delivered (containing name).
 * For lengthening, the middle frame between left and right is repeated.
 * @param string name
 * @param uint valNum
 * @param uint leftBorder
 * @param uint reightBorder
 * @param vector\<uint\> origVec
 * @return vector\<uint\>
*/
std::vector<uint> change_valNum(std::string name, uint valNum, uint left, uint right, std::vector<uint> orig);

/**
 * resizes vector orig (of uints) to length valNum.
 * This could be changed if stops should be dealt with differently than other
 * phones. It's not used currently.
 *
 * For shortening, frames are deleted around the middle between left and right.
 * If those borders are overshot, a warning is delivered (containing name).
 * For lengthening, the middle frame between left and right is repeated.
 * @param string name
 * @param uint valNum
 * @param uint leftBorder
 * @param uint reightBorder
 * @param vector\<uint\> origVec
 * @return vector\<uint\>
*/
std::vector<uint> change_valNum_stop(std::string name, uint valNum, uint left, uint right, std::vector<uint> orig);


/** 
 * returns substrings of buffer seperated by whitespace as vector.
 * @param string buffer
 * @return vector\<string\>
*/ 
std::vector<std::string> string2vec(std::string buffer);

/**
 * returns framenumbers from msec.
 * framesize is taken from glob.ui.
 * @param uint dur(in mesec)
 * @param globalsT glob
 * @return uint framenumber
 */
uint msec2frames(uint dur, globalsT glob);

/**
 * returns framenumbers as fraction of dur determined by rate.
 * framesize is taken from glob.ui.
 * @param uint dur(in mesec)
 * @param uint rate (in percent)
 * @param globalsT glob
 * @return uint framenumber
 */
uint calcNewDur(uint dur, int rate, globalsT glob);

/** 
 * returns Bandwidth of F1 as parabolic function of F1.
 * It's implmented, but I didn't hear a difference.
 * data comes from:
 * author = 	 {Fujimura, O.  and Lindqvist, J. },
 * title = 	 {Sweep-Tone Measurements of Vocal-Tract Characteristics},
 * journal = 	 JASA,
 * year = 	 {1971},
 * volume = 	 {49},
 * number = 	 {2},
 * pages = 	 {541-558},
 *
 * @param uint f1
 * @return uint bw1
 */
uint F12BW(uint f1);

#endif /* _UTIL_H */





