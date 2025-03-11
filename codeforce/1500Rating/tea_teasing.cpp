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

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        l(i,0,n) cin >> a[i];

        vi bActual(n);
        l(i,0,n) cin >> bActual[i];
        vi b = bActual;



        // prefix Sum of b
        l(i,1,n) b[i] += b[i-1];


        // till what index any a can be served from its own index to upto[i] index
        vi upto(n,-1);

        // it may happen it can't fullfill expectation for the index upto[i] 
        //but can provide something lesser than expectation that is extra after serving till upto[i]
        vi extra(n,0);


        // simple binary search so get at what extend one a[i] can serve
        int prev = 0;
        l(i,0,n){
            int ind = lower_bound(all(b), prev+a[i]) - b.begin();
            if(ind == n){
                upto[i]= n-1;
                extra[i] = 0;
                prev = b[i];
                continue;
            }
            else if( b[ind] >  prev+a[i]) ind--;
            upto[i] = ind;

            if(ind == -1){
                extra[i] = a[i];
            } else{
                extra[i] = prev + a[i] - b[i == -1 ? 0 : upto[i]];
            }
            
            prev = b[i];
        }


        // now upto[i] = 5 for i = 2 it means a[2] can serve till index 5
        // putting 1 at index 2 and -1 at upto[i]+1 
        // for prefix Summation of that range
        vi preSum(n+1,0);
        l(i,0,n)
        {
            if(upto[i] == -1) continue;
            preSum[i]++;
            preSum[ upto[i] + 1]--;
        }

        // prefix Summation how many people serve b[i] fully
        l(i,1,n){
            preSum[i] += preSum[i-1];
        }

        // how many ---> how much 
        l(i,0,n){
            preSum[i] *= bActual[i];
        }

        // if not fullfulling full expectation then what lesser value someone is providing
        l(i,0,n){
            preSum[ upto[i] + 1] += extra[i];
        }

        // and that's all about this question

        l(i,0,n) cout << preSum[i]<<" ";
        cout << endl;


    }
}