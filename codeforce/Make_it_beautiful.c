#include<stdio.h>
#include<stdlib.h>

int check(int size,int arr[]){
    int c=1;
    for(int i=0;i<size;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum+=arr[j];
        }
        if(sum==arr[i]){
            c=0;
            break;
        }
    }
    
    return c;
}

void printArr(int n,int arr[]){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}






int main(){
    int t;
    scanf("%d",&t);
    for(int a=0;a<t;a++){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    int ans=check(n,arr);
    if(ans==1){
        printf("YES\n");
        printArr(n,arr);
    }
    else{
        int max=arr[0],min=arr[0],maxi=0,mini=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
                maxi=i;
            }
            if(arr[i]<min){
                min=arr[i];
                mini=i;
            }
        }
        int p=arr[0];
        arr[0]=max;
        arr[maxi]=p;
        if(arr[0]==arr[1]){
           int q=arr[1];
        arr[1]=min;
        arr[mini]=q; 
        }
        if(arr[0]==arr[1]){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            printArr(n,arr);
        }
    
    }
    }
    
    
    
    return 0;
}