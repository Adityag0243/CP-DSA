#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("Enter length of array: ");
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    int a;
    printf("Enter what u want to enter: ");
    scanf("%d",&a);
    int pos;
    for(int i=0;i<n;i++){
        if(a<arr[i]){
            pos=i;
            break;
        }
    }
   
    
    
    int ans[n+1];
    for(int i=pos+1;i<n+1;i++){
        ans[i]=arr[i-1];
    }
    for(int i=0;i<pos;i++){
        ans[i]=arr[i];
    }
    ans[pos]=a;
    
    for(int i=0;i<=n;i++){
        printf("%d ",ans[i]);
    }


return 0;

}