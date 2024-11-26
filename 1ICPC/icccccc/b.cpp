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
    int t;
    cin >> t;
    while(t--){
        int n, d, l;
        cin >> n >> d >> l;

        // condition for -1;

    
        // if(n==2 && l== 1){
        //     cout << -1 << "\n";
        //     continue;
        // }
        if(n==2 && d==1 && l==2){
            cout<<1<<" "<<2<<endl;
            continue;
        }
        
        // if(n==l || n-(d+1) != l-2 || d==1){
        //     cout<<-1<<endl;
        //     continue;
        // }

        int minii = (d-2)/2;
        int remaiin = n - (d+1+l-2);
        if(remaiin < 0){
            cout<<-1<<endl;
            continue;
        }
        int c  = 1;
        if(l-2 > 0){
            int cnt = remaiin/(l-2) + (remaiin%(l-2))/max(c,(remaiin%(l-2)));
            if(cnt > minii){
                cout<<-1<<endl;
                continue;
            }
        } 

        






        // connecting to root 
        for(int i =2 ; i <= l+1 ; i++){
            cout<< 1<<" "<<i <<endl;
        }


        // connecting to 2 and l+1 

        int remain = d-2;    // remaining after root and leaf
        int node = l+2;

        int prev2=2,prevl=l+1;
        while(remain > 0){
            cout<<prev2<<" "<<node<<endl;
            prev2=node;
            node++; 
            remain--;
            if(remain == 0) break;
            cout<<prevl<<" "<<node<<endl;
            prevl=node;
            node++;
            remain--;
        }
        
        // node done  1 + leafs + (d-2)
        remain = n - l - d + 1;
        vi v(n+1);
        l(i,0,n+1) v[i]=i;
        while(remain > 0){
            l(i,3,l+1){
                if(remain > 0){
                    cout << v[i] <<" "<< node << endl;
                    v[i] = node;
                    remain--;
                    node++;
                }else break;
            }
        }


        
    }
}