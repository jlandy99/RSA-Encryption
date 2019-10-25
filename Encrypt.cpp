#include "Encrypt.h"

#include <iostream>


// Function to set public keys given by Bob
void Encrypt::setKeys(publicKey &p) {
  pub = p;
}

// Function to set the message we would like to encrypt
void Encrypt::setMessage(std::string &m) {
  message = m;
}

// Function to convert the string message to numeric
void Encrypt::convertMessage() {
  long temp = 0;
  // Add each letter's number to the number
  for (int i = 0; i < message.length(); ++i) {
    temp += (int)(message[i] - 'a' + 1);
    if (i != message.size() - 1) temp *= 100;
  }
  numMessage = temp;
}

// Global function to raise long to power of long mod long
long power(long a, long e, long mod) {
  // Reduce a and e as much as possible before looping
  std::cout << "A: " << a << ", E: " << e << ", mod: " << mod << std::endl;
  a = a % mod;
  for (long i = 0; i < e; ++i) {
    a *= a;
    a = a % mod;
  }
  return a;
}

// Function to encrypt the message
void Encrypt::encryptMessage() {
  // Raise to power of e and then mod n
  c = power(numMessage, pub.e, pub.n);
  std::cout << "Encrypted = " << c << std::endl;
}

// Function to return the inital message
long Encrypt::getNumericMessage() {
  return numMessage;
}
