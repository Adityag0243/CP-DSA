#include <stdio.h>

int funct(int x,int y){
	if(x==0) return y+1;
	// else if(x>0 && y==0) return funct(x-1,y);
	// else if(x>0 && y>0){
	// 	int a=funct(x,y-1);
	// 	return funct(x-1,a);
	// }
	else{
		if(y==0) return funct(x-1,y);
		else return funct(x-1,funct(x,y-1));
	}
	// else return 0;
}


int main(){
	int x,y;
	scanf("%d%d", &x,&y);              	                  // Reading input from STDIN
	int ans=funct(x,y);       // Writing output to STDOUT
	printf("%d",ans%1000);
}
