#include<stdio.h>
int main(){
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        arr[i][j]=0;
    }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    int row=5,col=5,count=1,i=0,j=0;
    //printf("%d %d   ",row,col);
     for(;row>0&&col>0;){
        //printf("%d %d   ",row,col);
        int jump=0;
        while(jump<col){
            arr[i][j]=count;
            jump++;
            count++;
            j++;
        }
        row--;
        i++;
        j--;
        //printf(" *%d %d\n ",i,j);
        jump=0;
        while(jump<row){
            arr[i][j]=count;
            jump++;
            count++;
            i++;
            //printf("jump: %d%d\n",jump,i);
        }
        col--;
        j--;
        i--;
        //break;
        //printf(" *%d %d %d %d\n ",row,col,i,j);
        jump=0;
        while(jump<col){
            arr[i][j]=count;
            count++;
            j--;
            jump++;
            //break;
        }
        row--;
        j++;
        i--;
             // printf(" *%d %d %d %d\n ",row,col,i,j);

        jump=0;
        while(jump<row){
            arr[i][j]=count;
            count++;
            i--;
            jump++;
        }
        col--;
        j++;
        i++;
        //break;
    }
    //printf("HELLO\n");

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        printf("%d      ",arr[i][j]);
        }
        printf("\n");
    }



}