#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

class DSU{
    public:
    vector<int> p;
    vector<int> siz;
    vector<int> minima;
    vector<int> maxima;

    DSU(int sz){

        p.resize(sz+1);
        siz.resize(sz+1,1);
        minima.resize(sz+1);
        maxima.resize(sz+1);

        for(int i=0 ; i < sz+1 ; i++){
            p[i]=i;
            minima[i] = i;
            maxima[i] = i;
        }

    }
    int parent(int i){
        if( p[i] == i ) return i;
        return p[i] = parent(p[i]);
    }
    void unite(int i , int j){
        i = parent(i);
        j = parent(j);
        if(i == j) return;
        if(siz[i] >= siz[j]){
            siz[i] += siz[j];
            p[j] = i;
            minima[i] = min( minima[i] , minima[j]);
            maxima[i] = max( maxima[i] , maxima[j]);
        }else{
            p[i] = j;
            siz[j] += siz[i];
            minima[j] = min( minima[i] , minima[j]);
            maxima[j] = max( maxima[i] , maxima[j]);
        }
    }
 
    void get(int i){   // just because yaha pe return type int likh dia tha 3 bar TLE mara hu codeforces pe
        cout << minima[parent(i)] <<" "<< maxima[parent(i)] <<" "<< siz[parent(i)] << endl;
    }

    

};

int main(){
    ios::sync_with_stdio(false); // Fast I/O
    cin.tie(0); // Untie cin from cout

    int n,m;
    cin >> n >> m;
    DSU d(n);
    l(i,0,m){
        string s;
        cin>>s;
        
        if( s == "union"){
            int a,b;
            cin>>a>>b;
            d.unite(a,b);
        }
        else{
            int a;
            cin >> a;
            d.get(a);
        }

    }
}
