#include<bits/stdc++.h>
using namespace std;
// #define l(i,st,n) for(int i=st;i<n;i++) 


class Entry{
    public:
    int key;
    int data;
    int hash;
    Entry(int key,int data,int hash=0){
        this->data=data;
        this->key=key;
        this->hash=hash;
    }
};
class Hashmap{
    
    int cap=1;
    int size=0;
    float load_factor=0;    
    public:
    hash<int> hash_fn;
    Hashmap(){
        
    }
    vector<vector<vector<int>>> v;

    hash<int> hash_int;

    int probe(int x){
        return 7*x;   //p(x)=5x
    }

    // void resize(){

    //     vector<vector<vector<int>>> vnew;
    //     cap=cap+2;
    //     for(int i=0;i<cap;i++){
    //         vector<vector<int>> vsample;
    //         vnew.push_back(vsample);
    //     }
    //     for(int i=0;i<v.size();i++){
    //         for(int j=0;j<v[i].size();j++){
    //             size_t hash1 = hash_int(v[i][j][0]);
    //             v[i][j][0]=hash1%cap;
    //             vnew[v[i][j][0]].push_back(v[i][j]);
                
    //         }
    //     }
    //     v=vnew;
    // }





    void insert(int key , int val){
        // if(float(size)/cap>=0.6){
        //     this->resize();
        // }
        

        Entry* e =new Entry(key , val);
        size_t hash1 = hash_fn(key);
        e->hash=hash1%cap;

        if(e->hash==cap-1){
            vector<vector<int>> vsample;
            v.push_back(vsample);
            cap++;
        }
        bool check=false;
        for(int j=0;j<v[e->hash].size();j++){
            if(v[e->hash][j][0]==key){
                v[e->hash][j][1]=e->data;
                check=true;
                break;
            }
        }
        if(check) return;

        size++;        
        vector<int> entry;
        entry={e->key,e->data,e->hash};
        // v[e->hash].push_back(entry);

        int x=0;
        while(true){
            int ind=((int)e->hash+probe(x))%cap;
            if(v[ind].empty()){
                entry={e->key,e->data,ind};
                e->hash=ind;
                v[ind].push_back(entry);
                break;
            }else x++;
            cout<<"bhai bacha lo  ";
        }
    
    }


    void show_map(){
        // cout<<"hello";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                for(int k=0;k<3;k++){
                    cout<<v[i][j][k]<<" ";
                }
                if(j<v[i].size()-1) cout<<", ";
            }
            if(v[i].size()) cout<<endl;
        }
    }


    void get(int key){
        size_t hash1 = hash_fn(key);
        int hashval=hash1%cap;
        for(int i=0;i<v[hashval].size();i++){
            if(v[hashval][i][0]==key){
                cout<<"value for this key is: "<<v[hashval][i][1]<<"\n";
                return;
            }
        }
        cout<<"KEY "<<key<<" NOT FOUND \n";

    }


    void deletekey(int key){
        size_t hash1 = hash_fn(key);
        int hashval=hash1%cap;
        int pos=-1;
        for(int i=0;i<v[hashval].size();i++){
            if(v[hashval][i][0]==key){
                pos=i;
                size--;
                load_factor=float(size)/cap;
                break;
            }
        }
        if(pos==-1){
            cout<<"KEY "<<key<<" NOT FOUND \n";
            return;
        }
        v[hashval].erase(v[hashval].begin()+pos);
    }  
};

int main(){

    Hashmap* a= new Hashmap();
    a->insert(1,10);
    a->insert(3,20);
    a->insert(3,19);
    a->insert(1,12);
    a->insert(5,13);
    a->insert(1,23);
    a->deletekey(1);
    a->insert(8,20);
    a->insert(23,25);
    a->insert(15,5);
    a->show_map();
    a->get(3);
    a->get(8);
    a->get(1);
    a->get(4);
}