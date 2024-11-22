#include <iostream>
using namespace std;

// Function to find GCD using Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to find the multiplicative inverse of 'a' modulo 'm'
int multiplicativeInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);
    if (gcd != 1) {
        cout << "Multiplicative inverse doesn't exist.\n";
        return -1;
    }
    return (x % m + m) % m; // Ensure the inverse is positive
}

int main() {
    int a, m;
    cout << "Enter a number (a): ";
    cin >> a;
    cout << "Enter modulus (m): ";
    cin >> m;

    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);
    cout << "GCD of " << a << " and " << m << " is: " << gcd << endl;

    int modInverse = multiplicativeInverse(a, m);
    if (modInverse != -1) {
        cout << "Multiplicative inverse of " << a << " modulo " << m << " is: " << modInverse << endl;
    }

    return 0;
}
