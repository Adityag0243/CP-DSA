#include<stdio.h>

int mean(int a,int b,int arr[]){
    int sum=0;
    for(int i=a;i<=b;i++){
        sum+=arr[i];
    }
    int m=sum/(b-a+1);
    return m;
}




int main(){
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        if(n==1){
            printf("YES\n");
            continue;
        }
        int m=mean(0,n-1,arr);
        int check=1,sum=0,msum=0;
        for(int k=0;k<n;k++){
            msum+=m;
            sum+=arr[k];
           // printf("%d %d\n",msum,sum);
            if(msum>sum){
                check=0;
                break;
            }
        }
        if(check==1 ) printf("YES\n");
        else printf("NO\n");
        
    }
    
    return 0;
}