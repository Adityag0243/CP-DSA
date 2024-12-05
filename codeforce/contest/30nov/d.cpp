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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        l(i,0,n) cin >> v[i];
        priority_queue<int> st0,st1,st2;   // max will be on top
        l(i,0,n){
            if(v[i] == 0) st0.push(i);
            else if(v[i] == 1) st1.push(i);
            else st2.push(i);
        }


        int cnt = 0;
        vector<pair<int,int> > ans;


        int x = st0.size();
        int y = st1.size();
        y+=x;

        l(i,0,n){
            if( i < x && v[i] != 0){
                cnt++;
                if(v[i] == 1){
                    int zero_p = st0.top();
                    st0.pop();
                    st1.push(zero_p);   // new pos of 1
                    swap(v[i] , v[zero_p]);
                    ans.pb({i,zero_p});
                }else{
                    int one_p = st1.top();
                    st1.pop();
                    swap(v[i] , v[one_p]);
                    st2.push(one_p);
                    ans.pb({i,one_p});
                    i--;
                }
            }

            else if( i < y && v[i]==2){
                cnt++;
                int one_p = st1.top();
                st1.pop();
                swap(v[i],one_p);
                st2.push(one_p);
                ans.pb({i,one_p});
            }
        }

        cout<<cnt<<endl;
        l(i,0,ans.size()){
            cout<<ans[i].first +1 <<" "<<ans[i].second +1 <<endl;
        }



    }
}