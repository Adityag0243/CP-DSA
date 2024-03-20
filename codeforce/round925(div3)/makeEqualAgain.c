#include<stdio.h>
int max(int a,int b);

int max(int a,int b){
    if(a>=b) return a;
    else return b;
}

// int counter(int size , int arr[] , int a){

// }




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
        
        int count1=1;
        int count2=1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[0]) break;
            count1++;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]!=arr[n-1]) break;
            count2++;
        }
        if(arr[0]==arr[n-1]){
            if(count1==n) printf("%d\n",0);
            else
            printf("%d\n",n-count1-count2);
            
        }
        else printf("%d\n",n-max(count1,count2));
       
        
    }
    
    return 0;
}