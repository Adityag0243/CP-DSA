#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >>t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    vector<int> v(n);
	    for(int i = 0; i <n ;i ++) cin >> v[i];
	    vector<int> inc(n,1);
	    
	    for(int i= 1;i<n ;i++){
	        if(v[i] >= v[i-1]) inc[i] = inc[i-1]+1;
	    }
	    vector<int> dec(n,1);
	    for(int i = n-2; i>=0 ;i--){
	        if(v[i] <= v[i+1]) dec[i] = dec[i+1]+1;
	    }
	    
	    int ans = max(1,inc[n-1]);
	    
	    for(int i=0; i < n; i++){
	        int left = (i > 0 ? inc[i - 1] : 0);
            int right = (i < n - 1 ? dec[i + 1] : 0);
            int curr = 1; 
            if (i > 0 && v[i] * k >= v[i - 1]) 
                curr += left;
            if (i < n - 1 && v[i] * k <= v[i + 1]) 
                curr += right;

            ans = max(ans, curr);
	    }
	    cout << ans <<endl;
	   
	}

}
