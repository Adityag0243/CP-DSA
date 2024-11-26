#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
#define l(i,st,n)       for(int i=st;i<n;i++)
#define MOD             1000000007
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



int pow2(int base , int exp) {
    exp %= (MOD-1);
    int result = 1;
    base %= MOD;  

    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD; 
        exp /= 2;  
    }
    return result;
}



signed main(){
    // fastio

    // freopen("inp.txt" , "r" , stdin);
    // freopen("out.txt" , "w" , stdout);
    // cout<<"hmm ";

    int n;
    cin >> n;
    int x[n];
    int k[n];

    l(i,0,n){
        cin >> x[i] >> k[i];
    }

    int no_of_divisor = 1;

    l(i,0,n){
        no_of_divisor = (no_of_divisor * (k[i]+1))%MOD;
    }
    cout << no_of_divisor << " ";




    int sum_of_divisor = 1;
    l(i,0,n){
        // int sum_of_verticle = (pow2(x[i]%MOD , (k[i]+1)%MOD) - 1) / (x[i] -1);
        int sum_of_verticle = (pow2(x[i], k[i] + 1) - 1 + MOD) * pow2(x[i] - 1, MOD - 2) % MOD;

        sum_of_verticle %= MOD;
        sum_of_divisor = (sum_of_divisor * sum_of_verticle)%MOD;
    }
    cout<<sum_of_divisor<<" ";




    // by chat japata bhai
    
    vector<int> preprod(n), sufprod(n);
    for (int i = 0; i < n; i++) {
        preprod[i] = sufprod[i] = k[i] + 1;
        if (i > 0) preprod[i] = (preprod[i] * preprod[i - 1]) % (MOD - 1);   // mod-1 bcz aage prev*nxt me use hoga as an exponent
    }

    for (int i = n - 2; i >= 0; i--) {
        sufprod[i] = (sufprod[i] * sufprod[i + 1]) % (MOD - 1);
    }

    int prod_of_divisor = 1;
    for (int i = 0; i < n; i++) {
        int prod_of_verticle = pow2(x[i], (k[i] * (k[i] + 1) / 2) % (MOD - 1));
        int prev = (i > 0 ? preprod[i - 1] : 1);
        int next = (i < n - 1 ? sufprod[i + 1] : 1);
        int power = (prev * next) % (MOD - 1);
        prod_of_divisor = (prod_of_divisor * pow2(prod_of_verticle, power)) % MOD;
    }
    cout << prod_of_divisor << " ";
    // int preprod[n];
    // int sufprod[n];

    

    // for(int i = n-2 ; i>= 0 ; i--){
    //     sufprod[i] = (sufprod[i]% MOD * sufprod[i+1]% MOD)%MOD;
    // }

    // int prod_of_divisor = 1;

    // l(i,0,n){
    //     int prod_of_verticle = pow2(x[i], (k[i] * (k[i] + 1) / 2) % (MOD - 1));
    //     int prev = (i > 0 ? preprod[i - 1] : 1);
    //     int next = (i < n - 1 ? sufprod[i + 1] : 1);
    //     int power = (prev * next) % (MOD - 1);
    //     prod_of_divisor = (prod_of_divisor * pow2(prod_of_verticle, power)) % MOD;
    // }

    // cout << prod_of_divisor <<" ";

}