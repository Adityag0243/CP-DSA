#include <bits/stdc++.h>
using namespace std;

//symmetric string nhi identify kr pa rha hu abcabc is symmetric ye kaam kr rha hai aabaab isme nhi kr rha hai 

int main(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        
        string a;
        cin>>a;
        int check2=1;
        
        set<char> s;
        for(int j=0;j<n;j++){
            s.insert(a[j]);
        }
        if(n%s.size()!=0) check2=0;
        else
        for(int j=0;j<s.size();j++){
            for(int k=1;k<a.size()/s.size();k++){
                //cout<<a[j]<<a[j+k*s.size()]<<" ";
                if(a[j]!=a[j+k*s.size()]){
                    check2=0;
                    break;
                }
            }
            if(check2==0) break;
            
        }

  
        int check=1;
        
        for(int j=1;j<n;j++){
            if(a[j]!=a[0]){
                check=0;
                break;
            }
        }
        

        if(check==1 && check2==0) cout<<1<<"\n";
        else if(check2==1) cout<<s.size()<<endl;
        else cout<<n<<endl;
    }
    

}