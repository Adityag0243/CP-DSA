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


int mss(const vector<int>& v) {
    int ms = v[0];
    int crt = v[0];
    l(i,1,v.size()){
        crt = max(v[i], crt + v[i]);
        ms = max(ms,crt);
    }
    return ms;
}



signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vi v(n);
        l(i,0,n){
            cin >> v[i];
            if(s[i] == '0') v[i] = -1e15;
        }
        if(mss(v) > k){
            no
        }else if(mss(v) == k){
            yes
            l(i,0,n) cout << v[i] << " ";
            cout << endl;
        }
        else{

            
            map<int, pair<int,int>> mp;
            l(i,0,n){
                if(s[i] == '0'){
                    // prev positive.....
                    if( i-1 >= 0 && s[i-1] == '0') mp[i].first = 0;
                    else{
                        int ind = i-1;
                        int maxi = 0; 
                        int sum = 0;
                        while( ind >= 0 && s[ind] != '0'){
                            sum += v[ind];
                            ind--;
                            maxi = max( maxi, sum);
                        }
                        mp[i].first = maxi;
                    }

                    if( i+1 < n && s[i+1] == '0') mp[i].second = 0;
                    else{
                        int ind = i+1;
                        int maxi = 0; 
                        int sum = 0;
                        // while( ind <= n-1 && s[ind] == '0') ind++;
                        while( ind <= n-1 && s[ind] != '0'){    
                            sum += v[ind];
                            ind++;
                            maxi = max(maxi, sum);
                        }
                        // cout << "I am here:  "<< maxi <<" maxi\n";
                        mp[i].second = maxi;
                    }

                }
            }


            l(i,0,n){
                if(s[i] == '0') v[i] = -1e18;
            }

            bool flag = false;

            l(i,0,n){
                if( s[i] == '0'){
                    int l = mp[i].x;
                    int r = mp[i].y;

                    if(l+r <= k){
                        v[i] = k - (l+r);
                        flag = true;
                    }

                    if( l == k || r == k){
                        flag = true;
                    }

                    if( l +  r > k){
                        flag = true;
                        v[i] = k - (l+r);
                    }
                }
                if(flag) break;
            }

            if(flag){
                yes
                l(i,0,n) cout << v[i] << " ";
                cout << endl;
            }else no

        }


    }
    return 0;
}