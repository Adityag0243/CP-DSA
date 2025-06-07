#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;   cin >> s;
        set<int> alice, bob;
        
        for(int i= 0; i<n ; i++)
        {
            if(s[i] == 'A') alice.insert(i+1);
            else bob.insert(i+1);
        }

        bool a = false;

        if(alice.size() == 0)   a = false; 

        else if(bob.size() == 0)  a = true;
        else{
            if(  (alice.find(1) != alice.end()) && (alice.find(n) != alice.end())){
                a = true;
            }else if( ((alice.find(1) != alice.end()) || (alice.find(n) != alice.end()))  == false) {
                a = false; 
            }else{
                if(bob.size() == 1){
                    if( bob.find(n) != bob.end() ) a = true;
                    else if( n > 2) a = true;
                    else a = false; 
                }
                else if(bob.size() >= 2  && bob.find(n) != bob.end() ){
                    a = false; 
                }else{
                    if(alice.find(n-1) != alice.end()) a = true;
                    else{
                        a = false; 
                    }
                }
            
            }
        }

        if(a) cout << "Alice"<<endl;
        else cout << "Bob" << endl;
    }
    return 0;
}