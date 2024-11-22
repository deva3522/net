#include <iostream>
using namespace std;

int main() {
    int n1, n2, gcd;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    // Ensure n1 >= n2 by swapping if needed
    if (n2 > n1) {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    // Find GCD using a loop
    for (int i = 1; i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }

    cout << "GCD = " << gcd;
    return 0;
}
