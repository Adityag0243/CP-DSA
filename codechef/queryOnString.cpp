#include <bits/stdc++.h>
using namespace std;

vector<multiset<int>> depth;


class Trie{
public:
    map<char, Trie*> mp;
    int cw;

    Trie(){
        cw = 0;
    }
    
    void insert(string s){
        Trie* temp = this;
        int lvl = 0;
        
        for(char c : s){
            
            temp->cw++;
            if(depth[lvl].find(temp->cw - 1) != depth[lvl].end() ) 
                depth[lvl].erase( depth[lvl].find(temp->cw - 1) );
            depth[lvl++].insert(temp->cw);
            
            
            if(temp->mp.find(c) == temp->mp.end()){
                temp->mp[c] = new Trie();
            }
            temp = temp->mp[c];
        }
        
        temp->cw++;
        if(depth[lvl].find(temp->cw - 1) != depth[lvl].end() ) 
            depth[lvl].erase( depth[lvl].find(temp->cw - 1) );
            
        depth[lvl++].insert(temp->cw);
    }

    void remove(string s){
        Trie* temp = this;
        int lvl = 0;
        
        for(char c : s){
            temp->cw--;
            if(depth[lvl].find(temp->cw + 1) != depth[lvl].end() ) 
                depth[lvl].erase( depth[lvl].find(temp->cw +1) );
            depth[lvl++].insert(temp->cw);
        
            
            if(temp->mp.find(c) == temp->mp.end()) return;
            temp = temp->mp[c];
        }
        temp->cw--;
        if(depth[lvl].find(temp->cw + 1) != depth[lvl].end() ) 
            depth[lvl].erase( depth[lvl].find(temp->cw +1) );
        depth[lvl++].insert(temp->cw);
    }
    
};

int main(){
    int q; cin >> q;
    Trie* root = new Trie();
    map<int, string> m;
    depth.resize(1e5+1);
    

    for(int opr = 1; opr <= q; opr++){
        int type; cin >> type;
        
        if(type == 1){
            string s; cin >> s;
            reverse(s.begin(), s.end());
            m[opr] = s;
            root->insert(s);
        } else if(type == 3){
            int x; cin >> x;
            root->remove(m[x]);
            m[x] = "";
        } else {
            int k, l; cin >> k >> l;
            int cnt = 0;
            if( depth[l].size() > 0)
            {
                cnt = *depth[l].rbegin();
            }
            

            if(cnt >= k) cout << "YES\n";
            else cout << "NO\n";
        }
        
    }
    
    
}
