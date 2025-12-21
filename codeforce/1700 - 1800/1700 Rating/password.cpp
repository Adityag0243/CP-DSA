#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>

#define endl            '\n'
#define pb              push_back
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
    string str; cin >> str;
    int n = str.size();

    Hashing stringHash(str);  


    vvi alphaPos(26);
    int cnt = 0;
    for( char c : str) alphaPos[c-'a'].pb(cnt++);

    string ans = "Just a legend";

    for(int i = n-1; i>= 0 ; i--){
        
        vector<ll> v1 = stringHash.substringHash(0 , i);  // prefix 
        vector<ll> v2 = stringHash.substringHash(n-1-i , n-1); // suffix

        bool milGya = false;

        // SEARCH FOR MIDDLE ONE
        if( v1[0] == v2[0] && v1[1] == v2[1]){

            string st = str.substr(0, i+1);
            int len = st.size(); 
            if(len > n-2) continue; 
            
            for( int p1 : alphaPos[st[0] - 'a'] ){

                if(p1 == 0) continue;
                int ind = lower_bound( all(alphaPos[st[len-1] -'a' ]), p1+len-1 ) -  alphaPos[st[len-1] - 'a'].begin();

                if( ind < alphaPos[st[len-1] - 'a'].size()  && alphaPos[st[len-1] - 'a'][ind] < n-1){
                    // cout << ind << " ";
                    
                    vector<ll> v1 = stringHash.substringHash(0 , len-1);
                    vector<ll> v2 = stringHash.substringHash(p1 , p1+len-1);
                    if( v1[0] == v2[0] && v1[1] == v2[1]){
                        ans = st;
                        milGya = true;
                        break;
                    }
                } 
            }            
        
        }
        if(milGya) break;
        
    }

    cout << ans;
    
    

    return 0;
}