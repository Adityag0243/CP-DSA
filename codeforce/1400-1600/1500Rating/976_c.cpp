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
    vector< pair<pair<int,int>,int> > vp;
    l(i,0,n){
        int a,b;
        cin >> a >> b;
        vp.pb({{a,-b},i});
    }

    srt(vp);

    l(i,0,n){
        vp[i].x.y *= (-1);
    }

    int ind = -1;
    int maxy = vp[0].x.y;
    l(i,1,n){
        if(vp[i].x.y <= maxy){
            ind = i;
            break;
        }
        maxy = max(maxy, vp[i].x.y);
    }
    if(ind == -1) cout << -1 << " "<< -1 ;
    else{
        l(i,0,ind){
            if( vp[i].x.y == maxy){
                cout << vp[ind].y + 1 << " "<< vp[i].y + 1;
                break;
            }
        }

    }
    


    return 0;
}