#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        char c;
        if(n<29){
            c=n+94;
            printf("aa%c\n",c);
        }else if(n<54){
            c=n+69;
            printf("a%cz\n",c);
        }else{
            c=n+44;
            printf("%czz\n",c);
        }
        
    }
    
    return 0;
}