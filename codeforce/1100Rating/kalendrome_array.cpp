#include <bits/stdc++.h>
using namespace std;


int palendrome(vector<int> &v){
    int k=v.size()-1;
    int j=0;
    int ans=1;
    
    for( ; k>0 && j<k ; k--){
        if(v[j]!=v[k]){
            ans=0;
        }
        j++;
    }
    return ans;
}




int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        
        vector<int> v(n);
        set<int> s;
        for(int j=0;j<n;j++){
            cin>>v[j];
            s.insert(v[j]);
        }
        if(palendrome(v)==1){
            cout<<"YES"<<endl;
            continue;
        }
        string ans="NO";
        
        // cout<<s.size()<<"     ";
        
        
        
        
        for(auto itr=s.begin();itr!=s.end();itr++){
            cout<<*(itr)<<"   ";
            vector<int> vcopy;
            for(int j=0;j<n && (v[j]!=*(itr));j++){
                cout<<"AAAYA"
                cout<<v[j]<<" ";
                vcopy.push_back(v[j]);
            }
            for(int j=0;j<vcopy.size();j++) cout<<vcopy[j]<<" ";
            cout<<endl;
            
            
            if(palendrome(vcopy)==1){
                ans="YES";
                break;
            }
        }

            
        cout<<ans<<endl;
        
        
        // fail for 4 8 1 2 2 1 8 4 8
        
        
        

    }
}