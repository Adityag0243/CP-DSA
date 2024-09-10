#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    char side;
    int pos;
    int step;

    Node(char side,int pos,int step){
        this->side = side;
        this->pos = pos;
        this->step = step;
    }

};

int n,k;


string fn(string l , string r)
{
    if(l[0]=='X') return "NO";
    
    queue<Node> q;
    q.push(Node('l',0,0));

    while(!q.empty()){
        char sd = q.front().side;
        int ps  = q.front().pos;
        int st  = q.front().step;
        q.pop();
        if(ps >= n || ps+k >= n) return "YES";

        if(ps < st) continue;

        if(sd=='l' && ps+1<n &&  l[ps+1]!= 'X' ){
            q.push(Node('l',ps+1,st+1));
            l[ps+1] = 'X';
        }
        if(sd=='r' && ps+1<n &&  r[ps+1]!= 'X'){
            q.push(Node('r',ps+1,st+1));
            r[ps+1] = 'X';
        }

        if(ps != 0  && sd=='l' && l[ps-1] !='X' ){
            q.push(Node('l',ps-1,st+1));
            l[ps-1] = 'X';
        }
        if(ps != 0  && sd=='r' && r[ps-1] !='X'){
            q.push(Node('r',ps-1,st+1));
            r[ps-1]= 'X';
        }

        if( sd=='l' && r[ps+k] != 'X' ){
            q.push(Node('r',ps+k,st+1));
            r[ps+k]= 'X';
        }
        if( sd=='r' && l[ps+k] != 'X' ){
            q.push(Node('l',ps+k,st+1));
            l[ps+k]='X';
        }
        
    } 
    return "NO";
}
int main(){
    
    cin>>n>>k;
    string l,r;
    cin>>l>>r;

    cout<< fn(l,r);


}