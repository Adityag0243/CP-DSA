#include<bits/stdc++.h>
using namespace std;


int main(){
  
  long long n;
  cin >> n;
  if(n & 1){
    cout << 0 ;
    return 0;
  }
  long long ans = 0;
  for(long long i = 5; n / i; i *= 5){
    ans += ((n/i)/2);
  }
  cout << ans;
  return 0;
}