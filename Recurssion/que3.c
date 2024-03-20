#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(char *a){
    

}





int main(){
    char *a=(char *)malloc(100*sizeof(char));
    int b;
    for(int i=0;i<100;i++){
        scanf("%c",a+i);
        b=i;
        if(*(a+i)==32||*(a+i)=='\0') break;
        printf("%d",b);
    }
    //printf("%d",b);
    a=(char *)realloc(a,(b)*sizeof(char));
    //printf("%d",b);
    // for(int i=0;i<b;i++){
    //     printf("%d",i);
    //     printf("%c",*(a+i));
    // }
    reverse(a);

    


    return 0;
}