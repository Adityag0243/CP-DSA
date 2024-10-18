#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
// #define int             int64_t
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


    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    
    int n , k;
    cin >> n >> k;

    vector<vector<int>>  barn(1002, vector<int> (1002,0));
    while(n--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2 ;
        x2--;
        y2--;
        // cout<<"putting positive value at index "<<x1<<"  "<<y1<<"\n";
        for(int i = x1; i <= x2 ; i++){
            barn[i][y1]++;
        }
        // cout<<"putting negative value at index "<<x1<<"  "<<y2+1<<"\n";

        for(int i = x1 ; i <= x2 ; i++){
            barn[i][y2+1]--;
        }
    }

    l(i,0,1001){
        l(j,1,1001){
            barn[i][j] += barn[i][j-1];
        }
    }


    // l(i,0,10){
    //     l(j,0,10){
    //         cout<<barn[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    

    int cnt=0;
    for(int i = 0; i<1001 ; i++){
        l(j,0,1001){
            if(barn[i][j] == k) cnt++;
        }
    }
        // cout << "helllo   " << endl;

    cout<<cnt;   
    
}