#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,st,n) for(int i=st;i<n;i++) 
#define rloop(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


int searchpos(char a,vector<char> v){
    int ans=0;
    int low=0;
    int high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==a){
            ans=mid;
            break;
        }else if(v[mid]>a) high=mid-1;
        else low=mid+1;
    }
    return v.size()-ans-1;
    
}

int main(){
    string s;
    s+='A';
    s+='B';
    cout<<s;
	// int t;
	// cin>>t;
	// while(t--){
	//     int n;
	//     cin>>n;
	//     string s;
	//     cin>>s;
	//     set<char> st;
	//     for(int i=0;i<n;i++){
	//         st.insert(s[i]);
	//     }
	//     vector<char> vst;
	//     for(auto itr=st.begin();itr!=st.end();itr++){
	//         vst.push_back(*itr);
	//     }
	//     loop(i,0,n){
	//         int p=searchpos(s[i],vst);
	//         s[i]=vst[p];
	//     }
    //     cout<<s<<endl;
	    
	   

	// }
}