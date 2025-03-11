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
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

pair<int,int> p;

void fn(vector<int>& v, vector<int> &sumv) {
    int n = v.size();
   
    
    int i = 0;
    while(i < n){
        
        int j = i+1;
        int sum = v[i];
        while( j < n  && ((v[j] > 0 && v[j-1] >0) || (v[j] < 0 && v[j-1] < 0)  ) ) {
            sum += v[j];
            j++; 
        }
        sumv.pb(sum);

        i = j;
    }

}


int fn2 (vector<int> &v, int st, int lst ){
    if(st >= v.size()) return 0;
    int val =0;
    l(i,st,lst){
        if(v[i] > 0) val += v[i];
        else{
            val +=  max( abs(v[i]) , fn2(v,st+1,lst));
            break;
        }
    }
    cout << val <<" ";
    return val;
}


signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        vi sumv;

        l(i,0,n){
            cin >> v[i];
        }

        fn(v,sumv); 
        for(auto it : sumv) cout << it <<" ";
        
        cout << fn2(sumv,0,sumv.size()) << endl;
        
        
        
        
    }
}