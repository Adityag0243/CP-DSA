#include <bits/stdc++.h>
using namespace std;

int checkAP(vector<int> &v){
    int check=0;
    if(2*v[1]==v[0]+v[2]) check=1;
    return check;
}


int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
        int a;
        cin>>a;
        int b=a;
        int izero=INT_MAX;
        int ifive=INT_MAX;
        int counter=0;

        while(b>0){
            counter++;
            b/=10;
        }
        int ans=counter;





        counter=0;
        b=a;
        while(b>0){
            counter++;
            if(b%10==0){
                izero=counter;
                b/=10;
                break;
            }
            if(b%10==5){
                ifive=counter;
                b/=10;
                break;
            }
            b/=10;            
        }
        cout<<izero<<
        
        if(izero<ifive){
            counter--;
            while(b==5 || b==0){
                counter++;
                b/=10;
            }
            ans=min(counter,ans);

        }else{
            counter--;
            int counter2=counter;
            int c;
            while(b>0){
                
                counter2++;
                int check=0;
                if(b%10==0 && check==0){
                    izero=counter2;
                    check=1;
                    b/=10;
                    c=b;
                }
                if(b%10==2 || b%10==7){
                    ans=min(counter,ans);
                    b/=10;
                    break;
                }
                b/=10;            
            }
            while(c==5 || c==0){
                counter2++;
                c/=10;
            }
            ans=min(counter2,ans);


        }
        cout<<ans<<endl;
        
        
        
    }
    

}