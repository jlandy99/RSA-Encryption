/*
This class holds the encryption handling. It holds public keys
as well as various encryption functions.
*/

#include <string>
#include "Decrypt.h"

class Encrypt {
  // Public keys
  publicKey pub;
  // Holds message as a string
  std::string message;
  // Holds message as a number
  long numMessage;
  // Holds encrypted message
  long c;
public:
  // Function to set public keys given by Bob
  void setKeys(publicKey &p);
  // Function to set the message we would like to encrypt
  void setMessage(std::string &m);
  // Function to convert the string message to numeric
  void convertMessage();
  // Function to encrypt the message
  void encryptMessage();
  // Function to return the inital message
  long getNumericMessage();
};
