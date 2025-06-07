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
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        while(q--){
            char a, b;
            cin >> a >> b;
            if(a == '-'){
                int r, c;
                cin >> r >> c;
                int ans = 0;
                int div = (1LL << n);
        
                while(r - 2 > 0 || c - 2 > 0) { 
                    div /= 2;
                    // div += 1;
                    int add = div * div;
                    // cout << "div and add  "<<div  << " " << add  << "    ";
                    div += 1;
                    if( r/div  + c/div  == 0 ){
                        // nothing to do...
                    }else if( r/div  + c/div  == 2 ){
                        ans += add;
                        r -= (div-1);
                        c -= (div-1);
                    }else if( r/div == 1){
                        ans += 2*(add);
                        r -= (div-1);
                    }else{
                        ans += 3*(add);
                        c -= (div-1);
                    }  
                    div--;
                    // cout << ans <<" " << r  << " " << c  << " r and c\n";
                }
                if( r + c == 2) ans += 1;
                else if( r + c == 4) ans += 2;
                else if( r == 2) ans += 3;
                else ans += 4;

                cout << ans << endl;
            }
            else{
                int num;
                cin >> num;
                int r = 0;
                int c = 0;
                int div = (1LL << n);
                
                // cout <<"here   ";
                while( num > 4){
                    div /= 2;
                    int add = div * div;
                    // cout << "div and add  "<<div  << " " << add  << "    ";
                    if(num > 3* add){
                        c += div;
                        num -= (3*add);
                    }else if( num > 2*add){
                        r += div;
                        num -= (2*add);
                    }else if( num > add){
                        r += div;
                        c += div;
                        num -= (add);
                    }
                }

                // cout << num << " numm...  ";
                
                r+=1; c+=1;
                if( num == 4)c += 1;
                else if(num == 3) r += 1;
                else if( num == 2){
                    r += 1;
                    c += 1;
                }
                cout << r << " " <<c <<endl;
            }
        }
    }
    return 0;
}