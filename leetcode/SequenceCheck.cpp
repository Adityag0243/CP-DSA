//check whether s1 is sequence of s or not sequence means beech ko koi miss kr skte hai element 
//par ordering same ho  hello me hlo sequence hai lho nhi llo hai oll nhi
//A me kae sare number hai 4 2 3 aise to 4th ko delete kro batao ki ab subsequence hai ya nhi 
//then 2nd element from s delete kro now check s1 is sub sequence or not aise krna hai....


 // abhi kaam nhi kr rha hai//....

#include <bits/stdc++.h>
using namespace std;

int sequence_check(string s,string s1){
    int a=0,check;
    for(int i=0;i<s1.size();i++){
        check=0;
        for(int j=a;j<s.size();j++){
            if(s1[i]==s[j]){
                a=j;
                check=1;
                break;                         //time complexity s.size() yani n hi hai n^2 nhi
            }                              
        }
        if(check==0) break;
    }
    return check;
}
int main(){
    string s="abacabadc";
    string s1="adb";
    string sc=s;
    int ans=0;
    //cout<<sc[3];
    int a[s.size()]={4,2,3,1,0,5,0,1,2};
    int low=0;
    int high=s.size()-1;
    cout<<ans<<'*';
    while(low<=high){
        cout<<ans<<'*';
        int mid=(low+high)/2;
        for(int j=0;j<=mid;j++){
            sc[a[j]]=1;
        }
        if(sequence_check(sc,s1)==1){
            low=mid+1;
        }else{
            ans=mid;
            high=mid;
        }
        sc=s;
    }
cout<<ans;

}