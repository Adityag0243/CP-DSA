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


vector<int> pow2;


void fn(deque<int> &dq ,int p, int n , int k ){

    if( p == n ){
        dq.push_back(p);
    }
    else{
        int prev_power = pow2[n-p-1];
        if(k > prev_power || k==0){
            fn(dq,p+1,n,k%prev_power);
            dq.push_back(p);
        }else{
            fn(dq,p+1,n,k);
            dq.push_front(p);
        }
    }

}



signed main(){
    fastio
    int t;
    cin >> t;
    

    pow2.pb(1);
    for(int i = 1 ; i < 45 && pow2[i-1] < 2*(1e12) ; i++){
        pow2.pb(pow2[i-1]*2);
    }




    while(t--){
        int n,k;
        cin >> n >> k;



        int ind =  lower_bound(all(pow2),k)-pow2.begin();
        if( ind  >= n ){
            cout<<-1<<endl;
            continue;
        }

        // first max s(p) come with sorted 1 to n

        //     *
        //    * 
        //   *   
        //  *



        // other max come with mountain array 

        //     *
        //    * *
        //   *   *
        //  *


        // last one is reverse sorted

        // *
        //  *
        //   *
        //    * 

        // but why this will work ??
        // let say u have          3 2 1(mountain)   and 2 1 3( valley or we can say beech me dip kr rha hai)     
        // we can't able able to make    pair(2,3)    in *valley* which will give minima as 2
        // instead we will get           pair(1,3)    in valley   which will give minima as 1 this make S(p) != maximum S(p)
        

        deque<int> dq;
        int jana_kis_ind_pe_hai = n - (lower_bound(all(pow2) , k)-pow2.begin()) ;
        int p = jana_kis_ind_pe_hai;
        fn(dq,p,n, k);

        for(int i = jana_kis_ind_pe_hai-1 ; i>0 ; i--) dq.push_front(i);

        for (int elem : dq) {
            cout << elem << " ";
        }

        cout<<endl;       
        
    }
}