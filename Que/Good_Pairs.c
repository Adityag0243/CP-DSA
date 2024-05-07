#include<stdio.h>








int main(){


    int t;
    scanf("%d",&t);
    
    int ans1[t],ans2[t];
    
    for(int i=0;i<t;i++){
        
        int n;
        scanf("%d",&n);
        int arr[n];
        

        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        int small=arr[0],max=arr[0];
        int smalli,maxi;
        
        for(int j=0;j<n;j++){
            if(arr[j]<=small) {
                small=arr[j];
                smalli=j;
            }
            if(arr[j]>=max){
                max=arr[j];
                maxi=j;
            } 
        }
        
        ans1[i]=smalli+1;
        ans2[i]=maxi+1;
        }
        
    
     
    
    for(int i=0;i<t;i++){
      printf("%d %d\n",ans1[i],ans2[i]);
    }
    return 0;
    }
    
