#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// Function to compute the greatest common divisor (GCD)
long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to perform modular exponentiation for encryption
long encrypt(char ch, long n, long e) {
    long result = 1;
    for (long i = 0; i < e; i++) {
        result = (result * ch) % n;
    }
    return result;
}

// Function to perform modular exponentiation for decryption
char decrypt(long encryptedChar, long n, long d) {
    long result = 1;
    for (long i = 0; i < d; i++) {
        result = (result * encryptedChar) % n;
    }
    return static_cast<char>(result);
}

int main() {
    long p, q, n, phi, e, d;
    char text[100];
    long encryptedText[100];

    // Input the message to be encrypted
    cout << "Enter text to be encrypted: ";
    cin.getline(text, sizeof(text));
    int len = strlen(text);

    // Input two prime numbers
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Generate public key 'e'
    do {
        e = rand() % phi;
    } while (gcd(phi, e) != 1);

    // Generate private key 'd'
    do {
        d = rand() % phi;
    } while ((d * e) % phi != 1);

    cout << "\nPublic Key (n, e): (" << n << ", " << e << ")";
    cout << "\nPrivate Key (n, d): (" << n << ", " << d << ")\n";

    // Encrypt the message
    for (int i = 0; i < len; i++) {
        encryptedText[i] = encrypt(text[i], n, e);
    }

    // Display the encrypted message
    cout << "Encrypted Message: ";
    for (int i = 0; i < len; i++) {
        cout << encryptedText[i] << " ";
    }
    cout << endl;

    // Decrypt the message
    for (int i = 0; i < len; i++) {
        text[i] = decrypt(encryptedText[i], n, d);
    }

    // Display the decrypted message
    cout << "Decrypted Message: " << text << endl;

    return 0;
}
