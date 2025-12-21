#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vi spf(10000007);

void pre(){
    l(i,0,1e7+7) spf[i] = i;
    l(i,2,1e7+7){
        if( spf[i] == i){
            for(int j = 2*i; j<1e7+7; j+=i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}



signed main(){
    pre();

    
    int n,m; cin >> n >> m;
    vi a(n); l(i,0,n) cin >> a[i];
    vi b(m); l(i,0,m) cin >> b[i];

    map<int,int> mpa;
    l(i,0,n){
        int val = a[i];
        while( val > 1){
            mpa[spf[val]]++;
            val /= spf[val];
        }
    }

    // Important to take mpb before changing the actual b array
    map<int,int> mpb;
    l(i,0,m){
        int val = b[i];
        while( val > 1){
            mpb[spf[val]]++;
            val /= spf[val];
        }
    }



    mpa.erase(1);
    mpb.erase(1);

    //  Now we will chang the array b and reduce by the primes of the array a which is stored in mpa
    l(i,0,m){
        int val = b[i];
        set<int> factor;

        while( val > 1){
            factor.insert(spf[val]);
            val /= spf[val];
        }

        val = b[i];
        for(int j : factor){
            while(val > 1 && val % j == 0 &&  mpa.find(j) != mpa.end() && mpa[j] > 0 ){
                val /= j;
                mpa[j]--;
            }
        }

        b[i] = val;
    }


    // will reduce a by using mpb which holds the freq of all prime that we can get from b....
    l(i,0,a.size()){
        int val = a[i];
        set<int> factor;
        while( val > 1){
            factor.insert(spf[val]);
            val /= spf[val];
        }

        val = a[i];

        for(int j : factor){
            while(val > 1 && val % j == 0 &&  mpb.find(j) != mpb.end() && mpb[j] > 0 ){
                val /= j;
                mpb[j]--;
            }
        }
        a[i] = val;
    }


    cout << a.size() << " " << b.size() << endl;
    for(int x : a ) cout << x << " ";
    cout << endl;
    
    for(int x : b) cout << x << " ";
    cout << endl;


    


    
    

    




    return 0;
}