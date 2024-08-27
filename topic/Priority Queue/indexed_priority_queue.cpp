#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)

const int maxn=100;


class IPQ{
    public:
    int sz=0;
   
    vector<int> value;
    vector<int> heap_ind;
    vector<int> key_ind;

    IPQ() : value(maxn, -1), heap_ind(maxn, -1), key_ind(maxn, -1) {}

    bool less(int i,int j){
        return (value[i] < value[j]);
    }

    void swap_ind(int i , int j){
        swap( heap_ind[key_ind[i]] , heap_ind[key_ind[j]] );
        int temp   = key_ind[i];
        key_ind[i] = key_ind[j];
        key_ind[j] = temp;
    }

    void sink(int key){
        
        while( 2*key+1 < sz ){
            int smaller = 2*key+1;
            if(2*key+2 < sz && less(2*key+2,key)) smaller = 2*key+2;
            if(less(key,smaller)) return;
            swap_ind(smaller,key);
            key=smaller;
        }

    }

    void swim_up(int key){
        for( ; key > 0 && less(key, (key-1)/2) ;){
            int parent=(key-1)/2;
            swap_ind(key,parent);
            key=parent;
        }
    }

    void update(int val,int key){
        value[key]=val;
        swim_up(heap_ind[key]);
        sink(heap_ind[key]);
    }

    void insert(int val,int key){
        if(value[key] != -1){           // already present
            update(val,key);
            return;
        }    
        value[key]=val;
        heap_ind[key]=sz;
        key_ind[sz]=key;
        swim_up(sz++);
    }

    void remove(int key){
        if(value[key] == -1){           // already not present
            return;
        } 
        int i=heap_ind[key];

        swap_ind(key,--sz);
        sink(i);
        swim_up(i);

        value[key]=-1;
        heap_ind[key]=-1;
        key_ind[sz]=-1;
    }

    int peek_min() {            // return key of minimum value
        if (sz == 0) return -1; // Queue is empty
        return key_ind[0];
    }

    bool contains(int key){           // check if key is present or not
        return value[key] != -1;
    }

    void display()  const{
        cout << "Indexed Priority Queue: ";
        for (int i = 0; i < sz; ++i) {
            cout<<"(" << key_ind[i]<<","<<value[key_ind[i]] << ")  ";
        }
        cout << endl;
    }





};



int main(){
    IPQ pq;
    pq.insert(5, 0);
    pq.insert(3, 1);
    pq.insert(7, 2);
    pq.insert(2, 3);

    pq.display();

    cout << "Minimum element: " << pq.peek_min() << endl;

    pq.display();

    pq.update(2, 1);

    pq.display();
   
}