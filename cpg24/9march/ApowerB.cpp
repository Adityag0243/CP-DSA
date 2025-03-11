#include <bits/stdc++.h>
using namespace std;

// % 999 is just for avoiding integer overflow.....
// cnt is just to calculate no of operation we are doing 

int cnt = 0;
int fn(int a, int b){
    cnt++;
    if(b == 1) return a;
    int midP = fn(a, b/2);

    if(b%2 == 0) return midP * midP % 999;
    else return midP * midP * a % 999;
}

int main(){
    cout <<fn(3,1000) <<  endl;
    cout <<"Bruteforce would have taken 100 operation but this fn take only : " << cnt ;
}