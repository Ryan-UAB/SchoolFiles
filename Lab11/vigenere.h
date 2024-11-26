#include <string>
//! A vigenere cipher that both encrypts and decrypts using a set key
/*!This class takes a key in its constructor that it will use to encrypt and decrypt messages. It can also change its key later using the setKey command. It can also tell if a pair of messages are the same message after being encrypted/decrypted using a vigenere cipher with the current key.
 */
class Vigenere{
 private:
  std::string vigkey;
 public:
  //! Constructor that sets the current vigenere key
  /*! This constructor takes a std::string that will be used as the current key for both the encryption and decryption of messages using a vigenere cipher.
  @param key a std::string that becomes the current key to be used by the cipher
  */
  Vigenere(std::string key);
  //! Returns a given message encrypted by a vigenere cipher using the current key
  /*!This function will return an encrypted version of the initial message after being encrypted by the vigenere cipher using the currently set key.
  @param msg a std::string that will be encrypted using a vigenere cipher
  @return The encrypted version of the initial message using the set key
   */
  std::string encrypt(std::string msg);
  //!  Returns a given message decrypted by a vigenere cipher using the current key
  /*!This function will return a decrypted version of the initial message after being decrypted by the vigenere cipher using the currently set key.
  @param msg a std::string that will be decrypted using a vigenere cipher
  @return The decrypted version of the initial message using the set key
   */
  std::string decrypt(std::string msg);
  //! Returns a bool that checks if a given encrypted message and decrypted message are the same message after encryption/decryption
  /*!This function takes in two different std::string messages, one already encrypted and one already decrypted/unencrypted, to determine if the two messages are in fact the same message after being encrypted/decrypted by the vigenere cipher using the current key.
  @param encryptedMsg a message that has already been encrypted using a vigenere cipher by a key
  @param decryptedMessage a message that has already been decrypted using a vigenere cipher by a key/is the unencrypted message
  @return A bool that is either a 1 or 0 depending on if the two messages are a pair using the same key
   */
  bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);
  //! Changes the current key used by the vigenere encryption and decryption
  /*!This function takes a std::string that will replace the current key and be used for the encryption and decryption going forward.
  @param key a new key to be replace the currently set key
   */
  void setKey(std::string key);
  ~Vigenere() {};
};
