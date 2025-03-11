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
    
    int n;
    cin >> n;
    vi v(n);
    l(i,0,n) cin >> v[i];
    int thres;
    cin >> thres;
    
    vector<int> nextSmaller(n,n);

    stack<int> st;
    st.push(n-1);
    rl(i,0,n-1){
        while(!st.empty() && v[st.top()] >= v[i])   st.pop();
        if(!st.empty()) nextSmaller[i] = st.top();
        st.push(i);
    }


    vector<int> prevSmaller(n,-1);

    stack<int> st2;
    st2.push(0);
    l(i,1,n){
        while( !st2.empty() && v[st2.top()] >= v[i])  st2.pop();
        if(!st2.empty()) prevSmaller[i] = st2.top();
        st2.push(i);
    }
   
    l(i,0,n){
        int k = nextSmaller[i] - prevSmaller[i] -1;
        if( thres/k < v[i]){
            cout << k;
            return 0;
        }
    }
    cout<< -1;



    
}