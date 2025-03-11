#include<stdio.h>
#include<string.h>

void reverse(int n ,char str[n]){
    printf("%c",str[n-1]);
    char b[n-1];
    for(int i=0;i<n-1;i++){
        b[i]=str[i];
    }
    reverse(n-1,b);
}


int main(){
    char a[100];
    for(int i=0;a[i]!='\n';i++){
        scanf("%c",&a[i]);
    }
    reverse(strlen(a) ,a);
    return 0;
}