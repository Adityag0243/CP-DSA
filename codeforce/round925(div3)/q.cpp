#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
// int lower_b(vector<int> &v , int num);

int fn(string s){
   
    int score=0;
    bool al[5]={false};
    l(i,0,s.size()){
        if(s[i]=='n'){
            if(!al[0] && !al[1] && !al[2] && !al[3] && !al[4]) al[0]=true;
            else score--;
        }else if(s[i]=='a'){
            if(al[0]) al[1]=true;
            else score--;
        }
        else if(s[i]=='r'){
            if(al[0] && al[1]) al[2]=true;
            else score--;
        }else if(s[i]=='e'){
            if(al[0] && al[1] && al[2]) al[3]=true;
            else score--;           
        }else if(s[i]=='k'){
            if(al[0] && al[1] && al[2] && al[3]){
                score+=5;
                al[0]=al[1]=al[2]=al[3]=al[4]=false;
            }
            else score--;      
        }

    }
    return score;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int score=0;
        while(n--){
            string s;
            cin>>s;
            // score+=fn(s);
            cout<<fn(s)<<endl;
        }
        cout<<score<<endl;
        
        
    
    }
}