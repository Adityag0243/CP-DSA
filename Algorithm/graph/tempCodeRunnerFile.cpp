// https://youtu.be/KiCBXu4P-2Y?si=n-RB52sh8CtSTTf4
// S --> start assuming 0,0   E ->end (destination)  #->rocks .-> path
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


class Node{
    public:
    int row;
    int col;
    int time;
    Node(int row,int col,int time=0){
        this->row=row;
        this->col=col;
        this->time=time;
    }
};


int m,n;
vector<vector<bool>> is_visited;

bool is_valid(int row,int col){
    if(row<0 || col<0) return false;
    if(row>=m || col>=n) return false;
    return true;
}

int min_time(vector<vector<char>> &v){
    queue<Node> q;
    q.push(Node(0,0,0));
    is_visited[0][0] = true;


    while(!q.empty()){
        Node cr=q.front();
        if(v[cr.row][cr.col]=='E'){
            return cr.time;
        }
        int r[]={-1,1,0,0};
        int c[]={0,0,-1,1};
        Node* a;
        l(i,0,4){
            int rr=cr.row + r[i];
            int cc=cr.col + c[i];
            
            if(is_valid(rr,cc) && v[rr][cc]!='#' && !is_visited[rr][cc]){                
                q.push(Node(rr,cc,1+cr.time));
                is_visited[rr][cc]=true;
            }

        }
    }
    return -1;
}






int main(){
    cin>>m>>n;
    vector<vector<char>> v;
    l(i,0,m){
        vector<char> rv(n);
        vector<bool> bv(n,false);
        v.push_back(rv);
        is_visited.push_back(bv);
    }


    l(i,0,m){
        l(j,0,n) cin>>v[i][j];
    }


    cout<<min_time(v);
}