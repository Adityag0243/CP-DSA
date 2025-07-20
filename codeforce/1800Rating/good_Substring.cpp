#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>

#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

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
    int base = 31;
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
                hashValues[i][j] = (s[j] - 'a' + 1) * powersOfBase[i][j] % hashPrimes[i];
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
 
struct VectorHash {
    size_t operator()(const vector<ll>& v) const {
        size_t hash = 0;
        for(ll i : v) {
            hash ^= hash * 31 + i;
        }
        return hash;
    }
};


signed main(){
    string str;
    cin >> str;
    string bn; cin >> bn;
    int k; cin >> k;

    Hashing stringHash(str);  


    int n = str.size();
    vi pref(n);
    for(int i = 0; i<n ; i++){
        if( bn[str[i]-'a'] == '0' ) pref[i] = 1;
    }

    for(int i = 1; i<n ; i++){
        pref[i] += pref[i-1];
    }

    unordered_set< vector<ll>, VectorHash > seenHashes;
    
    int cnt = 0;
    for(int i = 0; i<n; i++){
        string si = "";
        for(int j = i; j<n ; j++){
            si += str[j];
            int cnt = pref[j];
            if( i > 0) cnt -= pref[i-1];

            if(cnt <= k){
                vector<ll> v = stringHash.substringHash(i , j);
                if (seenHashes.find(v) != seenHashes.end() ) continue;
                seenHashes.insert(v);
            }
            else break;
        }
    }


    cout << seenHashes.size();
    return 0;
}