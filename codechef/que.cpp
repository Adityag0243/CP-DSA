#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,c;
	    cin>>n>>c;
	    vector<ll> v(n);
	    for(int i=0;i<n;i++) {
	        cin>>v[i];
	        v[i]+=(i+1);
	    }
	    sort(v.begin(),v.end());
	    bool check=false;
	    
	    for(int i=0;i<n;i++){
	        
	        if(i!=0)
	        v[i]+=v[i-1];
	        if(v[i]>c){
	            cout<<i<<endl;
	            check=true;
	            break;
	        }
	    }
	    if(check==false) cout<<n<<endl;

	}
}