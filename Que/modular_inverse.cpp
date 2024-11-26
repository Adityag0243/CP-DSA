#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function for modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If the current power is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

int main() {
    int a = 2;
    long long inverse = modExp(a, MOD - 2, MOD);
    cout << "Modular inverse of " << a << " under mod " << MOD << " is: " << inverse << endl;
    return 0;
}
