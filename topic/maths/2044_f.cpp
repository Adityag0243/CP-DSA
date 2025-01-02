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


const int val = 200005;

vector<bool> a_row(2*val,false);   // will store zero at 0 + val index -ve value before val +ve after val
vector<bool> b_col(2*val,false);

int suma = 0, sumb = 0;

bool fncheck(int fact1, int fact2){
    bool check = false;

    // if removing one row and one col as well
    if( (suma - fact1 + val < 0 || suma - fact1 + val >= 2*val)  || sumb - fact2 + val < 0 ||sumb - fact2 + val >= 2*val ) return false;
    if( a_row[suma - fact1 + val]  && b_col[sumb - fact2 + val] ){
        check = true;
    }

    return check;
}





signed main(){
    fastio
    
        int n , m , q;
        cin >> n >> m >>q;
        vi a(n);
        vi b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            suma += a[i];
            a_row[a[i]+val] = true;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            sumb += b[i];
            b_col[b[i]+val] = true;
        }
        

        // total = suma * sumb;
        
        while(q--){
            int x;
            cin >> x;

            int px = abs(x);

            bool check = false;

            for( int fact = 1; fact*fact <= px ; fact++ ){

                // check for these all possibilities whether present or not 
                if( x % fact != 0) continue;

                if( abs(fact) < 2*val  &&   abs(x/fact) < 2*val){
                    // 1. fact      *  (x/fact)
                    if( fncheck(fact , x/fact)){
                        check = true;
                        break;
                    }

                    // 2. (x/fact)  *  fact
                    if( fncheck(x/fact , fact)){
                        check = true;
                        break;
                    }

                    // 3. -fact     *  -(x/fact)
                    if( fncheck(-1*fact , -1*x/fact)){
                        check = true;
                        break;
                    }

                    // 4. -1*(x/fact) *  -fact
                    if( fncheck(-1*x/fact , -1*fact)){
                        check = true;
                        break;
                    }
                }
            }
            if(check) yes
            else no
        }
    
}