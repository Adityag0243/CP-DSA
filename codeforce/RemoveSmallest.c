#include<stdio.h>








int main(){


    int t;
    scanf("%d",&t);
    
    int ans[t];
    
    for(int i=0;i<t;i++){
        
        int n;
        scanf("%d",&n);
        int arr[n];
        ans[i]=1;

        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        int small=arr[0],max=arr[0];
        for(int j=0;j<n;j++){
            if(arr[j]<small) small=arr[j];
            if(arr[j]>max) max=arr[j];
            
        }
        
        for(int j=small; j<max;j++ ){
            int check=0;
            
            for(int a=0;a<n;a++){
                if(arr[a]-1==j){
                    check=1;
                }
                }
                if(check==0){
                    ans[i]=0;
                    break;
                }
            }
        }
        
    
     
    
    for(int i=0;i<t;i++){
       if (ans[i]==1) printf("YES\n");
       else printf("NO\n");
    }
    return 0;
    }
    
