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



void reverseit(int i,int j, vvi &v, int status){
    int n = v.size();

    if(status == -1){
        for(int k =0; k<n ; k++){
            if(v[i][k] > 0 || k == j){
                v[i][k] = abs(v[i][k]) - 1 ;
            }else{
                v[i][k] = (abs(v[i][k]) - 1 ) *(-1);
            }
        }
    }else{
        for(int k = 0; k<n ; k++){
            if(v[k][j] > 0 || k == i){
                v[k][j] = abs(v[k][j]) - 1;
            }else{
                v[k][j] = (abs(v[k][j]) - 1) * (-1);
            }
        }
    }
}

void doitfor1(int i,int j, vvi &v){
    int n = v.size();
    for(int k = 0; k<n; k++){
        if(v[i][k] < 0 || k == j){
            v[i][k] = (abs(v[i][k]) + 1 ) * (-1);
        }else{
            v[i][k] = v[i][k] + 1;
        }
    }
}


// status 1--> row -1--> col  0-->check first

int fn( int i, int j, vvi &v, vi &a, vi &b, int status, int cost){
    int n = v.size();
    if(i >= n || j >= n) return cost;

    if(status == 1){  // row operation
        for(int k = 0; k<n; k++){
            if(v[i][k] < 0 || k == j){
                v[i][k] = (abs(v[i][k]) + 1 ) * (-1);
            }else{
                v[i][k] = v[i][k] + 1;
            }
        }
        return fn(i,0,v,a,b,0,cost+a[i]);   // cost of operation......
    }
    else if(status == -1){  // col operation
        for(int k = 0; k<n ; k++){
            if(v[k][j] < 0 || k == i){
                v[k][j] = (abs(v[k][j]) + 1 ) * (-1);
            }else{
                v[k][j] = v[k][j] + 1;
            }
        }
        return fn(0,j,v,a,b,0,cost+b[i]);  // cost of operation......
    }
    else if( (i < n-1  && abs(v[i][j]) != abs(v[i+1][j]) )  && (j < n-1   && abs(v[i][j]) != abs(v[i][j+1])) ){

        if(j < n-1) return fn(i, j+1, v, a, b, 0, cost);
        else return fn(i+1, 0, v, a, b, 0, cost);

    }else{

        // iska mtlb height kisi se to match ho gaya hai .......
        if( v[i][j] < 0 )  return -1;   // not possible scenerio second time hiring...
        
        int cost1 = fn(i,j,v,a,b,1,cost);
        reverseit(i,j,v,1);
        int cost2 = fn(i,j,v,a,b,-1,cost);
        // reverseit(i,j,v,-1);

        if(cost1 == -1 && cost2 == -1) return -1;
        else if(cost1 == -1){
            return cost + cost2;
        }
        else if(cost2 == -1){
            reverseit(i,j,v,-1);
            doitfor1(i,j,v);
            return cost + cost1;
        }
        else cost + min(cost1, cost2);
    }
}




signed main(){
    // fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vvi v(n, vi(n));
        l(i,0,n) l(j,0,n) cin >> v[i][j];

        vi a(n);
        l(i,0,n) cin >> a[i];
        vi b(n);
        l(i,0,n) cin >> b[i];

        cout << fn(0,0,v,a,b,0,0) << endl;
        l(i,0,n){ 
            l(j,0,n) cout << v[i][j] << " ";
            cout << endl;
        }


    }
    return 0;
}