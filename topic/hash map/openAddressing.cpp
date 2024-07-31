#include<bits/stdc++.h>
using namespace std;


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
    
    int cap=7;
    int size=0;
    float load_factor=0;    
    public:
    vector<vector<int>> v;
    hash<int> hash_int;
    Hashmap(){
        
    }
    vector<vector<int>> v;
    void sizing(){
        for(int i=0;i<(cap-size);i++){
            vector<int> vin(3,-1);
            v.push_back(vin);
        }
    }
    

    int hashing(int key){
        return 5*key;
    }

    int probe(int x){
        return 5*x;   //p(x)=5x (we should put prime as a coeffiecient less collidable , why??)
    }

    void resize(){

        vector<vector<vector<int>>> vnew;
        cap=cap+2;
        for(int i=0;i<cap;i++){
            vector<vector<int>> vsample;
            vnew.push_back(vsample);
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                size_t hash1 = hash_int(v[i][j][0]);
                v[i][j][0]=hash1%cap;
                vnew[v[i][j][0]].push_back(v[i][j]);
                
            }
        }
        this->v = vnew;
    }





    void insert(int key , int val){
        this->sizing();
        
        Entry* e =new Entry(key , val);
        e->hash=probe(e->key)%cap;
        if(size==cap) this->resize();
        else{
            int x=0;
            while(true){
                if(v[(e->hash+x)%cap][0]==e->key){
                    v[(e->hash+x)%cap][1]=e->data;
                }
                else if(v[(e->hash+x)%cap][0]==-1){
                    size++;
                    v[(e->hash+x)%cap][0]=e->key;
                    v[(e->hash+x)%cap][1]=e->data;
                    v[(e->hash+x)%cap][2]=e->hash;
                    break;
                }
                x++;
            }
        }
    }


    void show_map(){
        // cout<<"hello";
        for(int i=0;i<v.size();i++){
            for(int k=0;k<3;k++){
                cout<<v[i][k]<<" ";
            }
        }
    }


    void get(int key){
        int hash1 =probe(key);
        hash1%=cap;
        if(v[hash1%cap][0]==key){
            cout<<"value at "<<key<<" key is: "<<v[hash1%cap][1];
        }

        //remaining
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