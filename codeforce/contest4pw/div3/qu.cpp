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
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		vector<vector<int>> v1(26);
		vector<vector<int>> v2(26);

		vector<int> ans;
		l(i,0,n){
			v1[s1[i]-'a'].push_back(i+1);
			v2[s2[i]-'a'].push_back(i+1);
		}
		
		

		while(q--){
			int l,r;
			cin>>l>>r;
			int cnt=0;
			l(i,0,26){
				int cnt1=0,cnt2=0;
				int ind1=lower_bound(v1[i].begin(),v1[i].end(),l)-v1[i].begin();
				int ind2=upper_bound(v1[i].begin(),v1[i].end(),r)-v1[i].begin();
				cnt1=ind2-ind1;
				ind1=lower_bound(v2[i].begin(),v2[i].end(),l)-v2[i].begin();
				ind2=upper_bound(v2[i].begin(),v2[i].end(),r)-v2[i].begin();
				cnt2=ind2-ind1;


				
				cnt+=(abs(cnt1-cnt2));
			}
			cout<<cnt/2<<endl;
		}


		
		
		
	}
}