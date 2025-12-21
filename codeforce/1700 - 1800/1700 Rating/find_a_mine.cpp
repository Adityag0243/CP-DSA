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

int fn(int l ,int r)
{   
    cout<<'?'<<" "<<l<<" "<<r<<endl;
    int x;
    cin >> x;
    return x;
}


signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int d1 = fn(1,1);

        pair<int,int> corner1;
        if(n >=  d1 + 1) corner1 = {d1+1 , 1};
        else corner1 = {n , d1+2 - n};
       

        int d2 = fn(corner1.first , corner1.second);


        
        pair<int,int> corner2;
        if(m >= d1+1) corner2 = {1 , d1+1};
        else corner2 = {d1 + 2 - m, m};

        int d3 = fn(corner2.first , corner2.second);

        if(fn( corner1.first - d2/2,corner1.second + d2/2) == 0){
            cout<<"! "<< corner1.first - d2/2 <<" "<<corner1.second + d2/2<<endl;
        }else{
            cout<<"! "<< corner2.first + d3/2 <<" "<<corner2.second - d3/2<<endl;
        }


    }
}