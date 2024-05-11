#include <bits/stdc++.h>
using namespace std;



int main(){
    int c=4;
    vector<vector<int>> v[c];
	    
	    
	    cout<<"hello";
	    for(int k=0;k<c;k++){
    	    for(int i=1;i<=100;i++){
				vector<int> varr;
    	        for(int j=i+1;j<=100;j++){
					varr.push_back(1);
    	        }
				v[c].push_back(varr);  
    	    }
	    }
		for(int k=0;k<c;k++){
    	    for(int i=1;i<=100;i++){
				cout<<v[k][i-1].size()<<" "; 
    	    }
	    }


}
