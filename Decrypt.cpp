#include "Decrypt.h"

#include <iostream>

// Global function to raise long to power of long mod long
extern long power(long a, long e, long mod);

// Global function to find gcd of two numbers
int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

// Helper function to handle coprimality testing
bool Decrypt::areCoprime(long l1, long l2) {
  return gcd(l1, l2) == 1;
}

// Helper function to handle determining multiplicate iverses
bool Decrypt::isMultiplicativeInverse(long a, long b, long mod) {
  return (a * b) % mod == 1;
}

// Function that generates all keys
void Decrypt::generateKeys() {
  // For this example, we will pick reasonably sized primes
  p = 100003;
  q = 100213;
  // Calculate our n
  pub.n = p * q;
  // Find our phi
  long phi = (p - 1) * (q - 1);
  // Generate e based on phi(n)
  long encrypt = 2;
  while (!areCoprime(encrypt, phi)) ++encrypt;
  // We should have now arrived at a suitable e
  pub.e = encrypt;
  // We can use this e to calculate d
  for (long i = 1; i < phi; ++i) {
    // Otherwise, check if it's the mutliplicative inverse
    if (isMultiplicativeInverse(i, pub.e, phi)) {
      // If it is, set d to i and break
      d = i;
      break;
    }
  }
}

// Function that returns public keys
publicKey Decrypt::getPublicKeys() {
  return pub;
}

// Function to handle decryption of an encrypted message
long Decrypt::decrypt(long c) {
  long message = power(c, d, pub.n);
  std::cout << "Decrypted = " << message << std::endl;
  return message;
}
// Function to convert numeric message back into a string
std::string Decrypt::convert(long c) {
  std::string num = (std::string)c;
  std::string result = "";
  // If the string is of odd length, our first char is LT 10
  int i = 0;
  if (num.length() % 2 == 1) {
    result += 'a' + c[i++];
  }
  for (; i < num.length() - 1; i += 2) {
    int temp = stoi(c[i]) + stoi(c[i + 1]);
  }
}
