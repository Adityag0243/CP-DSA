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





signed main(){
    fastio
    
    // chicken McNugget theorem ax+by = c if a and b are coprime then
    // all the number greater than (a*b) - a   b will be linear combination of a and b i.e can be written 
    // in form of ax + by 
    // ofcourse x , y are non negative integer


    // here 11 and 111 are coprime so 11*111 - 111 - 11 ==> 1099
    // 1099 (greatest no which can't be written in form of 11x + 111y)
    //  so we need to worry only about number >= 1099 
    
    // for that we will bruteforce and store everything

    set<int> s11;
    int cur = 1;
    while( 11 * cur <= 1099){
        s11.insert(11 * cur);
        cur++;
    }
    set<int> s111;

    cur = 1;
    while( 111 * cur <= 1099){
        s111.insert(111 * cur);
        cur++;
    }

    set<int> combi;
    for( auto x : s11){
        for( auto y : s111){
            if(x + y > 1099) break;
            combi.insert(x + y);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n > 1099) yes
        else{
            if( s11.find(n) != s11.end() ) yes
            else if( s111.find(n) != s111.end()) yes
            else if( combi.find(n) != combi.end()) yes
            else no
        }
    }
    return 0;
}