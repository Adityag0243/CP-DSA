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
#define out+ a +endl     cout << a << endl
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



int fn(vector<int> &v, int n ,string &s){
    stack<int> st;
    l(i,0,n){
        if(s[i] == '(') st.push(i);
        else{
            if(!st.empty()){
                v[i] = 2;
                v[st.top()] = 2;
                st.pop();
            }
        }
    }
    int cnt = 1;
    l(i,1,n) if(v[i] != v[i-1]) cnt=2;
    return cnt;

}








signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cb = 0;
        l(i,0,n) if(s[i] == '(') cb++;

        if(n&1  || n/2 != cb){
            cout<<-1<<endl;
            continue;
        }

        
        vi v(n,1);
        int cnt = fn(v,n,s);

        if(cnt == 2){
            reverse(s.begin() , s.end());
            vi v1(n,1);
            if( cnt > fn(v1,n,s)){
                v = v1;
                cnt = 1;
            }
        }

        if(cnt ==1 && v[0] == 2){
            l(i,0,n) v[i] = 1;
        }
        cout<<cnt<<endl;









        l(i,0,n) cout<<v[i]<<" ";        
        cout<<endl;
        
    }
}