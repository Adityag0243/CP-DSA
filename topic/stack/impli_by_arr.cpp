#include<bits/stdc++.h>
using namespace std;

int maxstk=5;
int arr[5];
int Top=-1;

void push(int val){
    if(Top==maxstk-1){
        cout<<"Overflow\n";
        return;
    }
    Top++;
    arr[Top]=val;
}

int top(){
    if(Top==-1){
        cout<<"Underflow\n";
        return -1;
    }
    return arr[Top];
}

bool isempty(){
    return Top==-1;
}

int pop(){
    if(Top==-1){
        cout<<"Underflow\n";
        return -1;        
    }
    Top--;
    return arr[1+Top];
}




int main(){
    cout<<top()<<endl;
    pop();
    push(10);
    cout<<top()<<endl;
    push(5);
    push(6);
    cout<<top()<<endl;
    pop();
    cout<<top()<<endl;  
    push(6);
    push(7);
    push(9);
    push(10);

}
