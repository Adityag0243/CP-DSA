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
    fastio;
    int t = 1;
    // cin >> t;
    while(t--){
        int m,s;
        cin >> m >> s;
        string ansn = "";
        string ansx = "";
  
        l(i,0,m){
            ansx += '0';
            ansn += '0';
        }

        
        if(( s == 0 && m > 1) || s > 9*m ){
            cout << -1 << " " << -1 ;
            return 0;
        } 

        int s1 = s;
        if( s1 != 0){
            ansn[0] = '1';
            s1--;
            
            rl(i,1,m){
                if(s1 <= 0 ) break;
             
                if( s1 > 9) ansn[i] = '9';
                else ansn[i] = ('0' +  s1);

                s1 -= 9;
            }
            // cout << ansn << " " << s1 << " ";
            if(s1 > 0){
                ansn[0] = ('1' + s1);
            }
        }


        l(i,0,m){
            if(s <= 0 ) break;
             
            if( s > 9) ansx[i] = '9';
            else ansx[i] = ('0' +  s);

            s -= 9;
        }

        cout << ansn << " " << ansx << endl;
    }
    return 0;
}