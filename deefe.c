#include <stdio.h>

// Function to calculate modular exponentiation
long long int power(int base, int exp, int mod) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If the exponent is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, g, x, y;  // Shared values and private keys
    long long int A, B, key1, key2;

    // Input the common values n and g
    printf("Enter the value of n (prime number): ");
    scanf("%d", &n);
    printf("Enter the value of g (primitive root of n): ");
    scanf("%d", &g);

    // Input private key of the first person
    printf("Enter the private key for the first person (x): ");
    scanf("%d", &x);

    // Input private key of the second person
    printf("Enter the private key for the second person (y): ");
    scanf("%d", &y);

    // Calculate public keys
    A = power(g, x, n);  // First person's public key
    B = power(g, y, n);  // Second person's public key

    // Calculate shared secret keys
    key1 = power(B, x, n);  // First person's secret key
    key2 = power(A, y, n);  // Second person's secret key

    // Display results
    printf("Public key for the first person (A): %lld\n", A);
    printf("Public key for the second person (B): %lld\n", B);
    printf("Shared secret key for the first person: %lld\n", key1);
    printf("Shared secret key for the second person: %lld\n", key2);

    return 0;
}
