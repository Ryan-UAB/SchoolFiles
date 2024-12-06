#ifndef _hamming_h
#define _hamming_h

#include <string>
#include <vector>
#include <iostream>

//! A Hamming Code (7,4) class that can both decode and encode.
/*!This class takes a filename in its constructor where the file is a list of Hamming Codes for every line to be either decoded or encoded. If the given Hamming Code has an error, then it will be corrected. The Hamming Code pattern followed is d1d2d3d4p1p2p3.
 */
class Hamming{
 private:
  std::vector<unsigned int> codes;
  std::vector<unsigned int> encoded;
  std::vector<unsigned int> decoded;
 public:
  Hamming();
  //! Constructor that sets the current filename
  /*!This constructor takes a std::string that will be used to open a file with that name that contains the Hamming Codes needed.
    @param filename a std::string to set the filename
   */
  Hamming(std::string filename);
  //! Encodes current 4-bit codes into 7-bit codes with parity bits
  /*!This function will encode given 4-bit codes into the 7-bit codes with the 3 additional parity bits being added at the end of the initial 4-bits.
   */
  void encode();
  //! Decodes current 7-bit codes into their 7-bit counterparts with no errors.
  /*!This function will check the current 7-bit codes in order to see if there are any errors. If any errors are detected, then the errors are fixed.
   */
  void decode();
  //! Returns the encoded version of intially encoded 4-bit codes.
  /*!This function will return a std::string containing all of the newly encoded codes created via the encode() function. If encode has not been ran then this will return an empty string.
   */
  std::string showEncoded();
  //! Returns the decoded version of intial 7-bit codes with errors fixed.
  /*!This function will return a std::string containing all of newly decoded 7-bit codes that have had any of their one bit errors fixed.
   */
  std::string showDecoded();
  //! Returns the initial version of the codes as they were put into the class.
  /*!This function will return a std::string containing all of the original codes as they were put into the class. Useful for comparing against the encoded or decoded versions.
   */
  std::string showOriginal();
  //! Clears the decoded and encoded vectors
  /*!This function will clear both the decoded and encoded vectors so that more codes can be decoded/encoded.
   */
  void clear();

  ~Hamming(){};
};

#endif
