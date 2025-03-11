#include <bits/stdc++.h>
using namespace std;

// % 999 is just for avoiding long longeger overflow.....
// cnt is just to calculate no of operation we are doing 

long long cnt = 0;
long long fn(long long a, long long b){
    cnt++;
    if(b == 1) return a;
    long long midP = fn(a, b/2);

    // it is important to first store the multiplication in an variable 
    // to force the mutliplication process come up in the integer range 
    midP = (midP * midP) % 999;

    // multiplication process knows that it is going to store in a variable
    // that mean at the end it will be in specified range 
    // so it will keep continue the multiplication process even if it overflows somewhere in between the process
    // on the other hand if we directly return (midP * midP ) % 999 if midP*midP overflow the range it will throw error
    // it will not proceed further and not able to know that overflow value is going to modulo by 999 

    if(b%2 == 0) return midP;
    else return (midP * a) % 999;
}

int main(){
    cout <<fn(3,1000) <<  endl;
    cout <<"Bruteforce would have taken 100 operation but this fn take only : " << cnt ;
}