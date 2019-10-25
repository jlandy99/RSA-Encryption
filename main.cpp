#include <iostream>
#include <string>

#include "Encrypt.h"

int main() {
  // Create Alice and Bob
  Decrypt bob;
  Encrypt alice;
  // Have Bob generate his keys from a table of known large primes
  bob.generateKeys();
  // Have Bob send keys to Alice
  publicKey p = bob.getPublicKeys();
  alice.setKeys(p);
  // Have user select message for Alice to encrypt and send to Bob
  std::string message;
  std::cout << "Pick an alpha-numeric message for Alice to Encrypt: ";
  std::cin >> message;
  // Have Alice convert her message from string to number via custom system
  alice.setMessage(message);
  alice.convertMessage();
  // Have Alice encrypt her message
  // Have Alice send her message to Bob and have Bob decrypt the message
  long original = alice.getNumericMessage();
  long decryption = bob.decrypt(original);
  std::cout << decryption << std::endl;
}
