/**
 * PHRASE.h
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

#ifndef _PHRASE_H_
#define _PHRASE_H_

#include "syllable.h"


/**
 * the phrase is the overall entity.
 * It consists of a list of syllable .
 * All changes made are initiated by phrase.
 * The methods can be categorized into
 * - readIn methods
 * - printOut methods
 * - information methods (e.g. MeanF0())
 * - internal calculation (calcMeanF0())
 * - modification methods
 *   -# change duration parameters
 *   -# change intensity parameters
 *   -# change f0 parameters
 *   -# change articulation parameters
 *   -# change phonation parameters
 *
 */
class phrase {
  std::vector<syllable> syllableVec;
  uint meanF0; // avr. val of all f0Vals
  uint dur; // duration of phrase in msec
 private:
  void calcDur();
 public:
  // constructor
  
  /**
   *  returns the mean val of all f0Vals.
   * @return uint mean
   */
  uint MeanF0();
  /**
   * calculates the mean val of all f0Vals. To be done after an intonation
   * change or falsetto or creaky voice (they change pitch also)
   */
  void calcMeanF0();

  /**
   * returns range of f0Vals in SemiTones.
   * @return double f0range
  */
  double F0Range();

  /**
   * prints names of phones to outFile (debugging).
   *   @param ostream &outFile
  */
  void printSyllableVec(std::ostream &outFile);
  
  /**
   * reads in phones for syllables from inFile.
   *  the format of the pho-file is as followed:
   *  - comments are started by a '#' as first char of line
   *  - syllable-borders are denoted by a single '-' as first char of line, 
   *     followed by an integer denoting the accent-type: 0 for none, 
   *     1 for word-accent, 2 for sentence-accent
   *  - feature-flags have the syntax: <flag> <time of occurance in msec> 
   *  - possible feature-flags are:
   *    +/- voc, brt, nas, lar, spr for voiced, breathy, nasalized, 
   *    laryngealized, spread respectively
   *    these features can be valid in regions and are followed by a time value
   *   +rounded, +overshoot, +undershoot for the corresponding vowel qualities
   *     these features are valid for the whole phone
   *  - phone descriptors follow the mbrola-syntax: <name> 
   * <duration in msec> <intonation description>.
   *  @param istream &inFile 
  */
  void readPhoFile(std::istream &inFile, globalsT &kg);

  /**
   * assignes only names of phones and syllable borders.
   * It's used for resynthesis if you only want to read in the original 
   * intonation contour to print it to a new input-file in connection with
   * \see readF0FromDB 
   * @param istream inFile
   * @param globalsT glob
   */
  void readPhoList(std::istream &inFile, globalsT &kg);

  /**
   * assignes only f0-vals.
   * It's used for resynthesis if you only want to read in the original 
   * intonation contour to print it to a new input-file in connection with
   * \see readPhoList
   * @param string diphonBase, the directory containing the diphone-files.
   * @param globalsT glob, defaultparams for klattsynth
   */  
  void readF0FromDB(std::string diphonBase, globalsT &glob);

  /**
   *  reads in amplitudes, formantfreqs and formantbandwidths
   *  from diphon-database.
   *  It depends on flags whether there are 3 or 5 formantfreqs dynamic.
   *  It assignes f0-vals to frames as well as markers for steady state or
   *  time of burst.
   *
   * \see globalsT
   *
   * \todo write more methods to readin the formanttrack data, e.g for whole 
   * words, demisylables or whatever.
   * \todo write better code or even think of a more elegant way to readin
   * the information.
   * \todo write a method that generates formanttracks from rules.
   *
   * @param string diphonBase, the directory containing the diphone-files.
   * @param globalsT glob, defaultparams for klattsynth
  */
  void readPhonData(std::string diphonBase, globalsT &glob);


  /**
   * model voice-source and articulation-tract filter parameters 
   * for each phone for normal voice. They can later be overwritten 
   * by modelFeatures.
   * sideeffect: sets bool xxxDyn true: i.e. all changung parmaters are 
   * marked to be dynamic.
   * \see modelFeatures
   * @param globalsT glob, defaultparams for klattsynth
  */
  void modelKlattParameters(globalsT &glob);

  /**
   * model voice-source and articulation-tract filter parameters 
   * for each phone according to it's assigned features.
   * sets bool xxxDyn true: i.e. all changung parmaters are 
   * marked to be dynamic.
   * @param globalsT glob, defaultparams for klattsynth
  */
  void modelFeatures(globalsT &kg); 
  
  /**
   * prints means of f0-contour per phon to outFile (debugging). 
   * @param ostream &outFile
   */
  void printPhonMeanF0(std::ostream &outFile);
  
  /**
   * prints phonfeatures to outFile (debugging).
   * @param ostream &outFile
   */
  void printPhonFeatures(std::ostream &outFile);
  
  /**
   * prints pho-file (mbrola-format).
   * It's used for resynthesis. If the global parameter copyDB is true,
   * the syllable borders get printed as well.
   * @param ostream &outFile 
   * @param globalsT glob, defaultparams for klattsynth
  */
  void printPhoFile(std::ostream &outFile, globalsT glob);

  /**
   * prints label-file (esps-format).
   * @param ostream &outFile 
   * @param globalsT glob, defaultparams for klattsynth
  */
  void printLabelFile(std::ostream &outFile, globalsT globals);
  
   /**
    * prints klatt-file (iles&simmons-format).
    * If used, the bool sensyn in the global paramters should be false.
    * \see printSenSynFile
    * @param ostream &outFile 
  */
  void printKlattFile(std::ostream &outFile);

   /**
    * prints klatt-file (sensymetrics-format).
    * If used, the bool sensyn in the global paramters should be true.
    * \see printKlattFile
   * @param globalsT glob, defaultparams for klattsynth
    * @param ostream &outFile 
  */
   void printSenSynFile(globalsT globals, std::ostream &outFile);

   /**
    *  fill a phrase with one syllable with one phone of duration dur
    * (in msec) with parameters taken from globals.
    * Useful for finding the right parameters for certain phones.
     * @param globalsT glob, defaultparams for klattsynth
     * @param uint duration of output in msec.
  */
  void makeTest(globalsT globals, uint dur);
  
  // modification-methods
  // duration modifications:

  /**
   * changes duration of all phones.
   *     if method = 0, then
   *     change duration of all phones in the utterance by factor <rate>
   *  if method = 1, then 
   *     phrasestressed vowels get 100% change,
   * wordstressed vowels get 90 % change,
   *	all others get 80 % change (phonetically adequate)
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   * @param uint method
   */
  void changeSpeechRate(uint rate, globalsT globals, int method);  

  /**
   * change duration of stressed syllables. 
   * By changing duration
   *  of vowel in syllable (the shortening/lengthening of syllables 
   *  effects primarily the vowels).
   *  The arg <both> decides whether word-accents are counted or not.
   * @param uint rate
   * @param uint both
   * @param globalsT glob, defaultparams for klattsynth
   */
  void changeDurStressed(uint rate, uint both, globalsT globals);
  
  /**
   * change duration of unstressed syllables. 
   * By changing duration
   *  of vowel in syllable (the shortening/lengthening of syllables 
   *  effects primarily the vowels).
   *  The arg <both> decides whether word-accents are counted or not.
   * @param uint rate
   * @param uint both
   * @param globalsT glob, defaultparams for klattsynth
   */
  void changeDurNonStressed(uint rate, uint both, globalsT globals);
  
  /**
   * change duration of specified phone-manners.
   * 
   * @param PHON_MANNER manner, i.e. short_vowel, liquide, ... 
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */  
  void changeDurManner(PHON_MANNER manner, uint rate, globalsT globals);

  // intensity modifications

  /**
   *  change intensity of stressed syllables.
   *  The arg <both> decides whether word-accents are counted or not.
   *  The dBval is added to intensity of the vowels in the syllables, so
   *  it can be negative to lower the intensity. If the result'd become 
   *  negative, it's set to zero. 
   * @param int dBval
   * @param uint both
   * @param globalsT glob, defaultparams for klattsynth
   */
  void changeStressedInt(int dBVal, uint both, globalsT globals);
 
  // f0-contour modifications:
  /**
   *  all nonzero f0Vals get multiplied by <rate> in percent.
   *  (so rate=100 means no change).
   * \see syllable::changeMeanF0()
   * \see phon::changeMeanF0()
    * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void  changeMeanF0(uint rate, globalsT glob);

  /**
   *  smoothing function: all f0Vals get centerFiltered around winsize.
   * \see phon::smootheF0()
   * @param uint winsize
   * @param globalsT glob, defaultparams for klattsynth
   */
  void  smootheF0(uint winsize, globalsT glob);

  /**
   * change mean pitch of stressed syllables. 
   *  All nonzero f0Vals get multiplied by <rate> in percent.
   *  The arg <both> decides whether word-accents are counted or not.
   *  The last syllable is not affected (even if stressed), but has
   * to be provided specially.
   * @param uint rate
   * @param uint both
   * @param globalsT glob, defaultparams for klattsynth
   */
  void changeStressedAvrF0(uint rate, uint both, globalsT glob);

  /**
   *  change avr pitch of the syllables before stressed syllables. 
   *  All nonzero f0Vals get multiplied by <rate> in percent.
   *  The arg <both> decides whether word-accents are counted or not.
   *  The last syllable is not affected (even if stressed), but has
   * to be provided specially.
   * @param uint rate
   * @param uint both
   * @param globalsT glob, defaultparams for klattsynth
   */
  void changePreStressedAvrF0(uint rate, uint both, globalsT glob);

  /**
   * changes the F0-range of phrase.
   * The f0-contour gets expanded or compressed with the mean-f0
   * of the last syllable as reference. That's fine with declaration sentences.
   * \todo think about question sentences.
   * \see syllable::changeF0Range()
   * \see phon::changeF0Range()
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void  changeF0Range(uint rate, globalsT glob);

  /**
   * changes the F0-variability.
   * The f0-contour of each syllable gets expanded or compressed with 
   * the mean-f0 of the syllable as reference. 
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
  */
  void  changeVariability(uint rate, globalsT glob);

  /**
   *     changes pitch-contour of stressed syllables to <contour>.
   *  <contour> can be straight, rise or fall
   *  - straight: all nonzero f0Vals of acc. syllable become meanF0Val
   *  - rise: all nonzero f0Vals rise from firstVal to gradient (in ST/sec)
   *  - fall: all nonzero f0Vals fall from meanVal of first voiced phone to 
   * gradient
   *
   *  The arg <both> decides whether word-accents are counted or not.
   * \see CONTOUR_TYPE
   * \see phon::interpolateF0Vec()   
   * @param uint CONTOUR_TYPE contour
   * @param uint gradient
   * @param globalsT glob, defaultparams for klattsynth
  */
  void changePitchContourStressed(CONTOUR_TYPE contour, uint gradient, uint both, globalsT glob);

  /**
   *     changes pitch-contour of last syllable to <contour>.
   *  \<contour\> can be straight, rise or fall
   *  - straight: 
   *  - rise/fall: last syllable gets pitch-changed according to 
   * \<gradient (ST/sec)\>.
   * 
   * \see phon::interpolateF0Vec()   
   *
   * @param uint CONTOUR_TYPE contour
   * @param uint gradient
   * @param globalsT glob, defaultparams for klattsynth
  */
  void changeLastSylContour(CONTOUR_TYPE contour, uint gradient, globalsT glob);

  /**
   *   changes pitch-contour of whole phrase to <contour>.
   *  <contour> can be straight, rise or fall
   *  - straight: all syllable-meanF0Vals become meanF0Val
   *  - rise/fall: last syllable gets pitch-changed according to <rate>, 
   *  all syllables before get changed in percentage to distance from 
   *  last syllable 
   * @param uint CONTOUR_TYPE contour
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
  */
  void changePhraseContour(CONTOUR_TYPE contour, uint rate, globalsT glob);

  /**
   *  changes pitch-contour of regions of phrase divided by phraseaccents to <contour>.
   *  Like changePhraseContour(), but repeated for every accented syllable.
   *  A straight contour is not implemented, if rate>100 it's a rise and if
   *  rate<100 it's a fall.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
  */
  void changePhraseContourToAccent(uint rate, globalsT glob);

  /**
   * The intonation-contour gets changed according to the wave-model.
   *  The whole intonationContour is changed: the phrase-accented
   *  syllables get displaced according to accRate, the syllable between
   *  phrase-accents  get displaced according to nonAccRate and the other
   *  syllables get displaced by interpolation.
   *  The method decides about the interpolation, 
   *  - method=1 : linear interpolation
   *  - method=4 : syllable countour is kept, i.e. whole syllable gets shifted.
   *
   *  \todo implement method=2:exponential or method=3:logarithmic interpolation
   * @param uint accRate
   * @param uint nonAccRate
   * @param uint method
  * @param globalsT glob, defaultparams for klattsynth
  */
  void addWave(uint accRate, uint nonAccRate, uint method, globalsT glob);


  // voice/speaking-style modifications: 
  /**
   * enhance the vowel precision.
   * All formantVals in f1 and f2 of vowels in syllables with accent
   *  get displaced away from the center freqencies by adding the 
   *  percentage by rate and distance to center frequency.
   *
   * @param ACCENT_TYPE accent
   * @param uint rate
  * @param globalsT glob, defaultparams for klattsynth
  */ 
  void overshootVowels(ACCENT_TYPE accent, uint rate, globalsT glob);

  /**
   * blur the vowel precision.
   * all formantVals in f1 and f2 of vowels in syllables with <accent>
   *   get displaced towards the center freqencies by subtracting the 
   *   percentage by <rate> and distance to center frequency.
   * @param ACCENT_TYPE accent
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */ 
  void undershootVowels(ACCENT_TYPE accent, uint rate, globalsT glob);


  /**
   * adds spread Lips characteristices.
   * The first 2 formants get shifted upwards according to rate.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */ 
  void spread(uint rate, globalsT glob);

  /**
   * adds rounded Lips characteristices.
   * All formants get lowered acording to rate.
   * \todo find a better model for rounded lips characteristics.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */ 
  void rounded(uint rate, globalsT glob);

  /**
   * experiment: shift formant-values to model different head-sizes.
   * not really implemented yet.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
  */
  void headSize(uint rate, globalsT glob);

  /**
   * model coarticulation effects.
   *  Each phone gets features added at the borders from the 
   *  neighboring phones, depending on coType:
   * - regressiv,
   * - progrssive,
   * - both.
   *
   * results in very disturbed output up to now.
   * \todo find a better modelling with better smoothing.
   * @param uint rate
   * @param CO_TYPE coType
   * @param globalsT glob, defaultparams for klattsynth
  */
  void coarticulation(uint rate, CO_TYPE coType, globalsT glob);

/**
 * should model assimilation of voicing.
 *   Adds voicing to unvoiced fricatives in VCV-environment.
 * Doesn't work very well.
 *  \todo  find a better modelling with better smoothing.
 * @param globalsT glob, defaultparams for klattsynth
 */
void assimilateConsonants(globalsT glob);


/**
 * add Jitter (F0-Flutter).
 *    Simulates Jitter at all voiced phones in syllables with stress-type=accent.
 *    If method = 1, all nonzero f0Vals get displaced about rate 
 *    alternating down and up. (0 > rate < 10)
 *    If method = 2, the klattSyn parameter skew/FL is set to rate (0 > rate < 300)
 * @param ACCENT_TYPE stress type of affected syllables
 * @param uint rate
 * @param globalsT glob, defaultparams for klattsynth
  */
  void addJitter(ACCENT_TYPE accent, uint rate, uint method, globalsT glob);
 
  /**
   * simulates breathy phonation at all vowels.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void addBreathy(uint rate, globalsT glob);
  
  /**
   * simulates tense phonation at all vowels.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void addTense(uint rate, globalsT glob);

  /**
   * simulates whispery phonation at all vowels.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void addWhisper(uint rate, globalsT glob);

  /**
   * simulates laryngealization (creaky voice) at first half of 
   *  vowels after unvoiced sounds.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void addLaryngealized(uint rate, globalsT glob);

  /**
   * simulates creaky phonation at all vowels.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void addCreaky(uint rate, globalsT glob);

  /**
   * simulates falsetto phonation at all vowels.
   * @param uint rate
   * @param globalsT glob, defaultparams for klattsynth
   */
  void addFalsett(uint rate, globalsT glob);
 
  
};

#endif /* _PHRASE_H_ */




