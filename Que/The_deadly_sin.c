#include <stdio.h>

int chocho(int x,int y){
    int m=1,n=1;
    if(x==y) return x+y;
    if(x>y){
        if((x-y)>y && y!=0) n=(x-y)/y;
        
        x-=(n*y);
        chocho(x,y);
        
    
    }
    else{
        if((y-x>x) && x!=0) m=(y-x)/x;
        
        y-=(m*x);
        chocho(x,y);
        
    }
}

int main(void) {
	int t;
	scanf("%d",&t);
    int ans[t];
    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ans[i]=chocho(x,y);
        
    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
    // int ans=chocho(5,3);
    // printf("%d",ans);
    

}

