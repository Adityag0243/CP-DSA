#include<stdio.h>
// #include<string.h>

int funct(int x){
    if(x%10==x) return x;
    else {
        int a=0;
        while(x>0){
            a+=x%10;
            x/=10;
        }
        return funct(a);
    }
}


int main(){
    char a;
    int sum=0,k;
    for(int i=0; i!=-1 ;i++){
        scanf("%c",&a);
        //printf("%c\t",a);
        
        if(a=='\0') break;
        if(a==32) break;
        sum+=(int)a-48;
        //printf("%d\t",sum);
        sum=funct(sum);
        //printf("%d\t",sum);
        
    }
    //printf("%d\t",sum);
    scanf("%d",&k);
    sum*=k;
    //printf("%d\t",sum);
    int ans=funct(sum);
    
    //ans=funct(800);
    printf("%d",ans);

    
    return 0;
}
