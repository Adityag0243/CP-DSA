#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i, st, n) for (int i = st; i < n; i++)
#define rl(i, st, n) for (int i = n - 1; i >= st; i--)
#define srt(v) sort(v.begin(), v.end())
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define vp(v) vector<pair<int, int>> v;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    l(i,0,n) cin>>a[i];
    l(i,0,n) cin>>b[i];

    vector<int> c(n);
    l(i,0,n) c[i]=a[i]-b[i];
    srt(c);
    ll cnt=0;
    for(int i=0;i<n-1;i++){
        if(c[i]<=0){
            auto it =lower_bound(c.begin(),c.end(),abs(c[i])+1);
            cnt+=(n-(it-c.begin()));
        }else{
            cnt+=(n-i-1);
        }
    }
    cout<<cnt;



    
    return 0;
}
