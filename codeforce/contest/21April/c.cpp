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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vi v(n+1);

        l(i,1,n+1) cin >> v[i];

        int maxi = mxv(v);
        l(i,1,n+1) 
            if(v[i] <= k) v[i] = -1;
            else v[i] = 1;

        vi pre = v;
        l(i,1,n+1) pre[i] += pre[i-1];
        vi suf = v;
        rl(i,0,n) suf[i] += suf[i+1];

        //  I need two medians which are <= k 
        // total 3 subrray (1,2,3)
        // 3 way I can get atleast 2 subarray having median <= k
        // (1,2)  or (1,3)  or (2,3) 

        bool flag = false;  // till now haven't got 2 subarrays
        if(k >= maxi) flag = true;

        int cnt = 0;
        // case 1 getting from (1,2) 
        if(!flag){
            int zero = 0;
            l(i,1,n+1){
                if(pre[i] < 0) cnt++;
                else if(pre[i] == 0) zero++;
            }
            if(zero >= 2 || cnt >= 2) flag = true;
            if(pre[1] > 0 && cnt+zero >= 2) flag = true;
        }

        // case 2 getting from (1,3)
        if(!flag){
            cnt = 0;
            l(i,1,n+1){
                if(pre[i] <= 0){
                    cnt = i;
                    break;
                }
            }
            if(cnt > 0){
                rl(i,1,n+1){
                    if(suf[i] <= 0 && i > cnt){
                        cnt = 2*n;
                        break;
                    }
                }
            }
            if(cnt == 2*n) flag = true;
        }

        // case 3 getting from 2,3
        if(!flag){
            cnt = 0;
            int zero = 0;
            rl(i,1,n+1){
                if(suf[i] < 0) cnt++;
                else if(suf[i] == 0) zero++;
            }
            if(zero >= 2 || cnt >= 2) flag = true;
            if(suf[n] > 0 && cnt+zero >= 2) flag = true;
        }

        if(flag) yes
        else no       
        
    }
    return 0;
}