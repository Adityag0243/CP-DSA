// WRONG
// #include <bits/stdc++.h>
// using namespace std;
// #define all(arr)        arr.begin(), arr.end()
// #define vi              vector<int>
// #define vvi             vector<vi>
// #define int             int64_t
// #define yes             cout << "YES" << endl;
// #define no              cout << "NO" << endl;
// #define p(x)            cout << (x) << endl;
// #define sp(x)           cout << (x) << " ";
// #define endl            '\n'
// #define pb              push_back
// #define mxv(arr)        *max_element(arr.begin(), arr.end())
// #define mnv(arr)        *min_element(arr.begin(), arr.end())
// #define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
// #define srt(arr)        sort(arr.begin(), arr.end())
// #define rev(arr)        reverse(all(arr))
// #define MOD2            1000000007
// #define x               first
// #define y               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// int n , W;  
// vi v;
// vi w;
// int dp[101];

// int fn(int sum , int i){
//     cout << "i and sum is " << i << " " <<sum << endl;

//     if(i >= n){
//         cout << "returned i " << endl;
//         return 0;
//     }
//     if(sum + w[i] > W){
//         cout << "returned W " << endl;
//         return 0;
//     }

//     if(dp[i] != -1){
//         cout <<dp[i]<< "here broooo " << endl;
        
//         return dp[i];
//     }

//     int itself = v[i] + fn(sum+w[i] , i+1) ;
//     cout << "Not calling for i and sum "<<i <<" "<<sum << endl;
    
//     cout<<itself<<endl;
//     int next   = fn(sum , i+1);
//     dp[i] = max( itself , next );
//     cout << "returning from here" << endl;
//     return dp[i];
// }


// signed main(){
    
//     cin >> n >> W;
//     w.resize(n);
//     v.resize(n);
//     fill(dp, dp + 101, -1);
//     l(i,0,n){
//         cin >> w[i];
//         cin >> v[i];
//     }
//     cout << fn(0 , 0) ;

// }




#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
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
int n , W;  
vi w;
vi v;
int dp[101];

int fn(int sum , int i){
    if(i >= n){
        return 0;
    }
    if(sum + w[i] > W){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    dp[i] = max( v[i] + fn(sum+w[i] , i+1)  , fn(sum , i+1));

    return dp[i];
}


signed main(){
    
    cin >> n >> W;
    w.resize(n);
    v.resize(n);

    l(i,0,n){
        cin >> w[i];
        cin >> v[i];
    }

    fill(dp, dp + 101, -1);

    cout << fn(0 , 0) ;

}