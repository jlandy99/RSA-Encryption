/*
This class holds the decrypt handling. It holds all keys
(both public and private), as well as various decryption
functions.
*/

#include <string>
#include <math.h>
#include <algorithm>

struct publicKey {
  long long n;
  long e;
};

class Decrypt {
  // Public key building blocks
  long p;
  long q;
  // Public keys
  publicKey pub;
  // Private keys
  long d;
  // Helper function to handle coprimality testing
  bool areCoprime(long l1, long l2);
  // Helper function to handle determining multiplicate iverses
  bool isMultiplicativeInverse(long a, long b, long mod);
public:
  // Function that generates all keys
  void generateKeys();
  // Function that returns public keys
  publicKey getPublicKeys();
  // Function to handle decryption of an encrypted message
  long decrypt(long c);
  // Function to convert numeric message back into a string
  std::string convert(long c);
};
