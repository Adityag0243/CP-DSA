#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for( int i = 2; i <= n; i++){

        if(is_prime[i] == true){  // if i is prime then go to other 
            // starting from i*i why it will give any error won't it skip few multiple 
            // no it won't skip any non prime but why ????? think about it ......
            for(int j = i*i ; j <=n; j += i ){
                is_prime[j] = false;
            }
        }
    }

    cout <<"All prime till "<<n<<" : ";
    for(int i = 1; i<= n ;i++){
        if(is_prime[i]) cout << i <<" ";
    }
}