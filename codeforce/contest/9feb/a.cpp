#include <bits/stdc++.h>
using namespace std;

vector<int> lsmallArr(vector<int>& arr) {
    int n = arr.size();
    vector<int> s(2 * n);
    
    for (int i = 0; i < n; i++) {
        s[i] = s[i + n] = arr[i];  
    }

    int start = 0; 
    int k = 0;    
    for (int i = 1; i < n; i++) {
        k = 0;
        while (k < n && s[start + k] == s[i + k]) k++;
        if (k < n && s[start + k] > s[i + k]) {
            start = i; 
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(s[start + i]);
    }
    
    return result;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    vector<int> a(n);
	    vector<int> b(m);
	    
	    for(int i = 0; i<n ; i++) cin >> a[i];
	    for(int i = 0; i<m ; i++) cin >> b[i];
	    
	    int mini = *min_element(b.begin(),b.end());

	    
	    for(int i= 0; i< n-m ;i++){
	
	        if(a[i] > mini) a[i] = mini;
	        cout << a[i] <<" ";
	        
	    }
	    
	    vector<int> sml = lsmallArr(b);

	    
	    int j = 0;
	    while(j < sml.size() && a[n-m+j] == sml[j]){
	        cout << sml[j] << " ";
	        j++;
	    }
	    if(j < sml.size() && a[n-m + j] > sml[j]){
	        while(j < sml.size()){
	            cout << sml[j] << " ";
	            j++;
	        }
	    }else if(j < sml.size()){
	        while(j < sml.size()){
	            cout << a[n-m+j] << " ";
	            j++;
	        }
	    }
	    
	    
	    
	    cout << endl;
	    
	    
	}
	

}
