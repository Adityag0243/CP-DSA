#include<stdio.h>
int max(int n,int arr[]){
    int ans=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>ans)
        ans=arr[i];
    }
    return ans;
}


int main(){
    int t;
    scanf("%d",&t);
    int ans[t];
    
    for(int l=0;l<t;l++){
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        if(a[n-1]>b[n-1]){
            for(int i=0;i<n-1;i++){
                if(b[i]>a[i]){
                    int p=a[i];
                    a[i]=b[i];
                    b[i]=p;
                }
            }
        }else{
            for(int i=0;i<n-1;i++){
                if(b[i]<a[i]){
                    int p=a[i];
                    a[i]=b[i];
                    b[i]=p;
                }
            }
            
        }
        
        if(a[n-1]==max(n,a) && b[n-1]==max(n,b)) ans[l]=1;
        else ans[l]=0;

    }
    
    for(int i=0;i<t;i++){
        if(ans[i]==1)
        printf("YES\n");
        else printf("NO\n");
    }
    
    
    return 0;
}