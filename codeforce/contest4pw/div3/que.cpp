#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,st,n) for(int i=st;i<n;i++) 
#define rloop(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define vp(v) vector<pair<int,int>> v;


int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
        string s;
        cin>>s;
        vector<int> vc(4);
        loop(i,0,4){
            vc[i]=0;
        }
        loop(i,0,n){
            if(s[i]=='N') vc[0]++;
            else if(s[i]=='S') vc[1]++;
            else if(s[i]=='E') vc[2]++;
            if(s[i]=='W') vc[3]++;
        }
        if((vc[0]==1 && vc[1]==1)^ (vc[2]==1 && vc[3]==1)){
            cout<<"NO"<<endl;
            continue;
        }

        // loop(i,0,4){
        //     cout<<vc[i]<<" ";
        // }
        if(((vc[0]+vc[1])%2) || ((vc[2]+vc[3])%2)){
            cout<<"NO"<<endl;
            continue;
        }
        vector<int> vcr(4),vca(4);
        loop(i,0,4){
            vcr[i]=vc[i]/2;
        }
        loop(i,0,4){
            vca[i]=vc[i]-vcr[i];
        }
        loop(i,0,4){
            cout<<vc[i]<<" ";
        }
        cout<<'\n';
        loop(i,0,4){
            cout<<vcr[i]<<" ";
        }
        cout<<'\n';
        loop(i,0,4){
            cout<<vca[i]<<" ";
        }
        cout<<"\n";







        // string ans=s;
        // loop(i,0,n){
        //     if(s[i]=='N' && vcr[0]>0){
        //         ans[i]='R';
        //         vcr[0]--;
        //     }
        //     else if(s[i]=='S' && vcr[1]>0){
        //         ans[i]='R';
        //         vcr[1]--;
        //     }
        //     else if(s[i]=='E' && vcr[2]>0){
        //         ans[i]='R';
        //         vcr[2]--;
        //     }
        //     else if(s[i]=='W' && vcr[3]>0){
        //         ans[i]='R';
        //         vcr[3]--;
        //     }
        // }


        // loop(i,0,n){
        //     if(s[i]=='N' && vca[0]>0){
        //         ans[i]='H';
        //         vca[0]--;
        //     }
        //     if(s[i]=='S' && vca[1]>0){
        //         ans[i]='H';
        //         vca[1]--;
        //     }
        //     if(s[i]=='E' && vca[2]>0){
        //         ans[i]='H';
        //         vca[2]--;
        //     }
        //     if(s[i]=='W' && vca[3]>0){
        //         ans[i]='H';
        //         vca[3]--;
        //     }
        // }
        // cout<<ans<<endl;


	    

        
       

        
	   

	}
}