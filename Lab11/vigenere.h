#include <string>

class Vigenere{
 private:
  std::string vigkey;
 public:
  Vigenere(std::string key);
  std::string encrypt(std::string msg);
  std::string decrypt(std::string msg);
  bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);
  void setKey(std::string key);
  //~Vigenere();
};
