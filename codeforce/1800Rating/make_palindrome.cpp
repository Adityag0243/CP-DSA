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
    string s;
    cin >> s;
    vector<int> v(26);
    l(i,0,s.size()){
        v[s[i]-'a']++;
    }

    // l(i,0,v.size()) cout<<v[i]<<" ";
    // cout << endl;

    int i = 0;
    int j = v.size()-1;

    // cout<<"Yes";
    while(true){
        while((v[i]&1)==0) i++;
        while((v[j]&1)==0) j--;
        if(i>=j) break;
        v[i]++;
        v[j]--;
    }

    l(i,0,v.size()){
        l(j,0,v[i]/2) cout<<(char)(i+'a');
    }
    if(s.size() & 1){     // aabbcccdd
        int odd_one = 0;
        l(i,0,v.size()){
            if(v[i]&1){
                cout<< (char)(i+'a');
                break;
            }
        }

    }
    
    rl(i,0,v.size()){
        l(j,0,v[i]/2) cout<<(char)(i+'a');
    }

}