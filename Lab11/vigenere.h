#include <string>
//! Class that uses a vigenere cipher to both encrypt and decrypt given messages using a set key
class Vigenere{
 private:
  std::string vigkey;
 public:
  //! Constructor that sets the current vigenere key
  /*!
  @param key a std::string that becomes the current key to be used by the cipher
  */
  Vigenere(std::string key);
  //! Returns a given message encrypted by a vigenere cipher using the current key
  /*!
  @param msg a std::string that will be encrypted using a vigenere cipher
  @return The encrypted version of the initial message using the set key
   */
  std::string encrypt(std::string msg);
  //!  Returns a given message decrypted by a vigenere cipher using the current key
  /*!
  @param msg a std::string that will be decrypted using a vigenere cipher
  @return The decrypted version of the initial message using the set key
   */
  std::string decrypt(std::string msg);
  //! Returns a bool that checks if a given encrypted message and decrypted message are the same message after encryption/decryption
  /*!
  @param encryptedMsg a message that has already been encrypted using a vigenere cipher by a key
  @param decryptedMessage a message that has already been decrypted using a vigenere cipher by a key/is the unencrypted message
  @return A bool that is either a 1 or 0 depending on if the two messages are a pair using the same key
   */
  bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);
  //! Changes the current key used by the vigenere encryption and decryption
  /*!
  @param key a new key to be replace the currently set key
   */
  void setKey(std::string key);
  ~Vigenere() {};
};
