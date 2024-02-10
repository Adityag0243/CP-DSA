#include<stdio.h>

int smallersearch(int pos,int size ,int arr[]){
    int ans=pos;
    int s=arr[pos];
    for(int i=pos+1;i<size;i++){
        if(arr[i]<s){
            s=arr[i];
            ans=i;
        }
    }

    return ans;
}

int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    int m=0;
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int p[size],q[size];
    for(int i=0;i<size;i++){
        p[i]=0;
        q[i]=0;
    }
    int count=0;
    ////////////////////////////////////////////////////////
    for(int i=0;i<size-1;i++){
        
            
            
            
            int pos=smallersearch(i,size,arr);
            if(i!=pos && arr[i]!=arr[pos]){
            //printf("%d\n",m);
            count++;
            p[m]=i;
            q[m]=pos;
            m++;
            
            int a=arr[i];
            arr[i]=arr[pos];
            arr[pos]=a;
            //printf("\n**%d %d %d\n",i,pos,m);
            }
        
    }
    
    printf("%d\n",count);
    // for(int i=0;i<size;i++){
    //     printf("%d ",arr[i]);
    // }
    for(int i=0;i<count;i++){
        printf("%d %d\n",p[i],q[i]);
    }
    


    return 0;
}