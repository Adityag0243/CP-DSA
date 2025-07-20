#include<bits/stdc++.h>
//goel_aadhaar
using namespace std;
//goel_aadhaar
#define all(x) (x).begin(), (x).end()
typedef long long ll;

ll mod_mul(ll a, ll b, ll mod) {
    return (a % mod) * (b % mod) % mod;
}

ll mod_sub(ll a, ll b, ll mod) {
    return ((a - b + mod) % mod);
}

ll mminvprime(ll a, ll mod) {
    ll res = 1, p = mod - 2;
    while(p > 0) {
        if(p & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        p >>= 1;
    }
    return res;
}

struct Hashing {
    string s;
    int n;
    int primes;
    int base = 52;
    vector<ll> hashPrimes = {1000000007 , 1000000009};
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;

    Hashing(string str) {
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);

        s = str;
        n = s.length();
        for(int i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            hashValues[i].resize(n);

            for(int j = 1; j <= n; j ++) {
                powersOfBase[i][j] = mod_mul(powersOfBase[i][j - 1], base, hashPrimes[i]);
            }

            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);

            for(int j = n - 1; j >= 0; j--) {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }

            for(int j = 0; j < n; j ++) {
                if(s[j] >= 65 && s[j] <= 90) {
                    hashValues[i][j] = (s[j] - 'A' + 1 + 26) * powersOfBase[i][j] % hashPrimes[i];
                } else {
                    hashValues[i][j] = (s[j] - 'a' + 1) * powersOfBase[i][j] % hashPrimes[i];
                }
                if(j > 0) hashValues[i][j] = (hashValues[i][j] + hashValues[i][j - 1]) % hashPrimes[i];
            }
        }
    }

    vector<ll> substringHash(int l , int r) {
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++) {
            ll rightVal = hashValues[i][r];
            ll leftVal = (l > 0) ? hashValues[i][l - 1] : 0ll;
            hash[i] = mod_mul(mod_sub(rightVal, leftVal, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};

void solve(){
    string s;
    int m , p;
    cin >> s >> m >> p; 

    Hashing SH(s);

    int n = s.length(), chance = 1, mxOpr = 1e6, l = 0;

    vector<vector<ll>> precompute(n);
    precompute[0] = SH.substringHash(0 , n - 1);
    
    // cout << precompute[0][0] << '\n';
    vector<ll> currHash = precompute[0];
    for(int i = 1; i < n; i++) {

        precompute[i].resize(SH.primes);
        for(int j = 0; j < SH.primes; j++) {
            int add_ = 0;
            if(s[n - i] >= 65 && s[n - i] <= 90) {
                add_ = s[n-i] - 'A' + 1 + 26; 
                precompute[i][j] = mod_mul(52 , mod_sub(currHash[j]  , mod_mul(s[n - i] - 'A' + 1 + 26 , SH.powersOfBase[j][n - 1] , SH.hashPrimes[j]) , SH.hashPrimes[j]), SH.hashPrimes[j] );
            } else {
                add_ = s[n-i] - 'a' + 1; 
                precompute[i][j] = mod_mul(52, mod_sub(currHash[j] , mod_mul(s[n - i] - 'a' + 1 , SH.powersOfBase[j][n - 1] , SH.hashPrimes[j]) , SH.hashPrimes[j]), SH.hashPrimes[j]);
            }
            precompute[i][j]   = (precompute[i][j] + add_ ) % SH.hashPrimes[j];
            currHash[j] = precompute[i][j];
        }
        // cout << precompute[i][0] << '\n';
    }

    int pos = 0;
    for(int i = 1; i <= mxOpr; i++) {
        if(chance)
            pos = (pos + m) % n;
        else
            pos = (pos + p) % n;
        chance ^= 1;

        if(precompute[pos] == precompute[0]) {
            cout << i << '\n';
            // cout << pos << " " << precompute[pos][0] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
//goel_aadhaar
void display() {
      
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
}