#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;

bool binary(vector<int> &v,int num);
bool binary1(vector<int> &v,int num);


bool binary(vector<int> &v,int num){
	int l=0;
	int h=v.size()-1;
	int ans;
	while(l<=h){
		int mid=(l+h)/2;
		if(v[mid]==num){
			v.erase(v.begin()+mid);
			return true;
		}
		else if(v[mid]>num) h=mid-1;
		else l=mid+1;
	}
	return false;
}

// 5
// 1 2 3 3 4
// 5 5 5 3 4
// 6
// 1 3 7 5 5 4





bool binary1(vector<int> &v,int num){
	int l=0;
	int h=v.size()-1;
	while(l<=h){
		int mid=(l+h)/2;
		if(v[mid]==num){
			return true;
		}
		else if(v[mid]>num) h=mid-1;
		else l=mid+1;
	}
	return false;
}








int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		l(i,0,n) cin>>a[i];
		l(i,0,n) cin>>b[i];
		int m;
		cin>>m;
		vector<int> d(m);
		l(i,0,m) cin>>d[i];

		bool check2=true;
		vector<int> dc(m);
		dc=d;
		srt(dc);

		l(i,0,n){
			if(a[i]!=b[i]){
				if(binary(dc,b[i])==false){
				check2=false;
				break;
				}
			}
		}	

		if(check2==false){
			no;
			continue;
		}
		
		bool check1=false;
		vector<int> checker;
		srt(b);
		int lastp=m;
		int count=0;
		rl(i,0,m){
			if(binary1(b,d[i])==false){
				lastp=i;
				break;
			}
		}

		if(lastp==m) check1=true;
		l(i,lastp,m){
			if(binary1(b,d[i])) check1=true;
		}
		
		if(check1) yes;
		else no;
		
		
		}
	

	
}