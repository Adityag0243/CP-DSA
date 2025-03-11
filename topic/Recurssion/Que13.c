#include<stdio.h>
// int occurance(int size,int n,int arr[size]){


// }

int main(){
    int size;
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    int n;
    scanf("%d",&n);
    int ans=occurance(size,n,arr);

    return 0;
}