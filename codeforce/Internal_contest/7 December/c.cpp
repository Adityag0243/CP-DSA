#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
//nCr from gpt....
long long factorial(long long n, vector<long long>& fact) {
    if (fact[n] != -1) return fact[n];
    if (n == 0 || n == 1) return fact[n] = 1;
    return fact[n] = (n * factorial(n - 1, fact)) % MOD;
}

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse using Fermat's Little Theorem
long long modInverse(long long n, long long mod) {
    return modPow(n, mod - 2, mod);
}

// Function to calculate nCr modulo MOD
long long nCr(long long n, long long r, vector<long long>& fact) {
    if (r > n) return 0;
    long long numerator = factorial(n, fact);
    long long denominator = (factorial(r, fact) * factorial(n - r, fact)) % MOD;
    return (numerator * modInverse(denominator, MOD)) % MOD;
}











int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> fact(n + 1, -1);

    
    int ans = 0;

    int div = 1;
    int digits = 1;

    while(div <= n && digits <= k ){
        int possibility = n/div;
        ans = ans+(possibility* nCr(k-1,digits-1,fact))%MOD;


        cout << digits<<" "<<possibility << " "<<ans<<endl;
        digits++;
        div *= 2;
    }

    cout << ans<< endl;
    return 0;
}
