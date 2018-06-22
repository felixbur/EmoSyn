/**
 * SYLLABLE.h
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

#ifndef _SYLLABLE_H_
#define _SYLLABLE_H_

#include "phon.h"

/**
 * syllable stress types
 */
typedef enum {
  /// not stressed 
  none, 
  /// word stress, ie. the most stressed syllable in a multisyllable word
  word, 
  /// main stress of the phrase, can be more then one
  sentence 
} ACCENT_TYPE;


/**
 * a syllable manages a list of phones.
 * It's needed because many rules can be expressed using syllables.
 * In fact it would be nice to have an even higher concept, 
 * like accent would designate all the syllables around a stressed one
 * containing an intonation group
 */
class syllable {

  /// the phones the syllable consists of  
  std::vector<phon> phonVec;
  /// number of phones
  uint phonNum;
  /// avr. val of all f0Vals
  uint meanF0; 
  /// type of stress
  ACCENT_TYPE accent; 
   
 public:

  /**
  * sets the strss type to accent
  * @param ACCENT_TYPE newAccent
  */
  void setAccent(ACCENT_TYPE newAccent) {accent = newAccent;}


  /**
  * returns the strss type
  * @return ACCENT_TYPE accent
  */
  ACCENT_TYPE Accent() {return accent;}
  
  /**
   *  appends new phon at end of phonVec,
   *  sideeffect: increments phonNum;
   *  @param phon newPhon
   */
  void addPhon(phon newPhon);

  /** 
   *  replaces phone at location loc
   *  @param phon newPhon  
   *  @param uint loc should be < phonNum
  */
  void replacePhon(phon newPhon, uint loc);

  /**
   *  erases phone at location loc
   *  sideeffect: changes phonNum
   *  @param uint loc
  */
  void erasePhon(uint loc);
  
  /**
   *  returns phone at location loc
   *  @param uint loc should be < phonNum
   *  @return phon
  */
  phon getPhon(uint loc);
  
  /** 
   * prints names of phons to outFile (debugging)
   * @param ostream &outFile
  */
  void printPhonVec(std::ostream &outFile);  

  /** 
   *  returns list of phones
   *  @return  vector<phon>
  */
  std::vector<phon>& PhonVec();

  /** 
   * returns average F0 of all F0-Vals from voiced phones in syllable (debugging)
   * @return uint meanF0
   */
  uint MeanF0();
  
  /** 
   * calculates the mean f0-value, should be done after intonation change
   */
  void calcMeanF0();
  
  /**    
   * returns num of phones
   * @return  uint number of phones
   */
  uint PhonNum();

  /**
   * clears list of phons
   * sideeffect: phonNum=0
   */
  void clearPhonVec();
  
  /// constructor
  syllable(){phonNum=0;}

  /**
   * change the f0-range with reference-value mean.
   * In fact all f0-values get expaned or compressed around reference value,
   * like in a contrast algorithm
   * @param uint rate gives the max amount of displacement 
   * (percent of distance between each val and reference)
   * @param uint mean
   */
  void  changeF0Range(uint rate, uint mean);

  /**
   * change the f0-range.
   * In fact all f0-values get expaned or compressed around syllable f0-mean,
   * like in a contrast algorithm
   * in fact all f0-values get expaned or compressed around the mean f0,
   * like in a contrast algorithm
   * \see phon::changeF0Range()
   * @param uint rate
   */
  void  changeF0Range(uint rate);

  /**
   * raise or lower f0-contour by rate in percent.
   * \see phrase::changeMeanF0()
   * \see phon::changeMeanF0()
   * @param uint rate
   */
  void  changeMeanF0(uint rate);

  /**
   * change the mean Intensity by dBVal.
   * affects only vowels
   * @param uint dBVal
   */
  void  changeAvrInt(int dBVal);
  

};

#endif /* _SYLLABLE_H */

