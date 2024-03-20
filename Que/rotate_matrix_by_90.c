#include<stdio.h>
int main(){
    
    int arr[5][5];
    printf("Enter n^2 i.e. 25 elements : ");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        scanf("%d",&arr[i][j]);
        }
    
    }
    
    int ans[5][5];
    for(int i=0;i<5;i++){
        int k=4-i;
        for(int j=0;j<5;j++){
            ans[j][k]=arr[i][j];
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        printf("%d  ",ans[i][j]);
        }
        printf("\n");
    }



}