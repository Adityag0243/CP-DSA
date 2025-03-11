#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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
#define mod            998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



// int power2( int exp) {

//     int result = 1;
//     int base = 2; 
//     while (exp > 0) {
//         if (exp % 2 == 1) { 
//             result = (1LL * result * base) % mod;  
//         }
//         base = (1LL * base * base) % mod; 
//         exp /= 2;
//     }
//     return result;
// }



// vector<int> vp; // Stores all 2^k % mod


// void precomputePowers() {
//     vp.resize(2e5 + 1);
//     vp[0] = 1; 
//     for (int i = 1; i <= 2e5; i++) {
//         vp[i] = (vp[i - 1] * 2) % mod;  
//     }
// }



int fn(int i,bool prev,bool prev1, vector<int> &v){
    if( i == v.size()-1 ){
        if(v[i] == 3) return 1;
        else return 0;
    }

    int cnt = 0;
    cout << i << "    ";
    
    if(v[i] == 3){

        if(prev) cnt = cnt + (1 + fn(i+1,prev,prev1,v)); 
        else cnt = cnt + fn(i+1, prev, prev1,v);

    }else if(v[i] == 2 ){

        if(prev1){
            cnt += fn(i+1,prev,prev1,v);
            if(!prev){
                prev = true;
                cnt += fn(i+1,prev,prev1,v);
            }
        }else cnt += fn(i+1,prev,prev1,v);
        
    }else if(v[i] == 1){

        if(prev) cnt += fn(i+1, prev,prev1, v);
        else if(!prev1 && !prev){
            prev1 = true;
            cnt = cnt +  fn(i+1, prev, prev1, v);
        }

    }

    return cnt;
}


signed main(){
    int t;
    cin >> t;
    // precomputePowers();
    
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        l(i,0,n) cin >> v[i];

        cout <<  fn(0,false,false,v) << endl;

        // vi pref(n,0);

        // set<int> s;
        // vi v3;
        // vi pref3(n,0);

        // l(i,0,n){
        //     if(v[i] == 2) pref[i]=1;
        //     else if(v[i] == 1) s.insert(i);
        //     else{
        //         v3.push_back(i);
        //         pref3[i] = 1;
        //     }
        // }

        // l(i,1,n){
        //     pref[i] += pref[i-1];
        //     pref3[i] += pref3[i-1];
        // }

        // int ans = 0;
        
        
        // for(auto it : s){ // pos of all 1's
        //     int till_now2 = pref[it]; 
        //     int prev_times = pref3[it];

        //     for(int i = till_now2  ; i <= pref[n-1]; i++){
        //         int ind = upper_bound( all(pref), i) - pref.begin();
        //         int times = pref3[ind-1] - prev_times;
                
        //         ans = (ans + ((times)  * max(1ll*0,(vp[i - till_now2] - 1)))%mod )% mod; 
        //         prev_times = pref3[ind-1];

                
        //     }
        // }

        // cout << ans << endl;



        
    }
}