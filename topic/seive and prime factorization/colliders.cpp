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

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];
    vector<int> p(n+1,0);

    // vector<int> prime;

    v[1].push_back(1);
    l(i,2,n+1){
        if(v[i].size()==0){
            p[i]=i;
            for(int j=i*2;j<=n;j+=i){
                v[j].push_back(i);
            }
        }
    }
    vector<int> pos(n+1,0);
    
    while(m--){
        char sign;
        cin>>sign;
        int num;
        cin>>num;

        if(sign=='-'){
            bool check=true;
            if(p[num]==num){
                if(pos[num]==num){
                    pos[num]=0;
                    cout<<"Success\n";
                }else cout<<"Already off\n";
                continue;
            }
            for(int i=0;i<v[num].size();i++){
                if(pos[v[num][i]] !=num){
                    check=false;
                    break;
                }
            }
            if(check){
                for(int i=0;i<v[num].size();i++){
                    pos[v[num][i]]=0;
                }
                cout<<"Success\n";
            }else cout<<"Already off\n";

        }else
        {   
            if(p[num]==num){
                if(pos[num]==num){
                    cout<<"Already on\n";
                }else if(pos[num]!=0){
                    cout<<"Conflict with "<<pos[num]<<endl;
                }else{
                    pos[num]=num;
                    cout<<"Success\n";
                }
                continue;
            }
            if(pos[v[num][0]]==num){
                cout<<"Already on\n";
                continue;
            }
            bool flag=false;

            for(int i=0;i<v[num].size();i++){
                if(pos[v[num][i]]!=0){
                    cout<<"Conflict with "<<pos[v[num][i]]<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag) continue;
            for(int i=0;i<v[num].size();i++){
                pos[v[num][i]]=num;                 
            }
            cout<<"Success\n";
        }
    }
}