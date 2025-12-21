#include<stdio.h>
#include<string.h>

int main(){
    while(1){
        printf("Before fflush(std)...\n");
        fflush(stdout);

        char temp[100];
        fgets(temp, 100, stdin);
    }
    return 0;
}