class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data,Node* next=nullptr,Node* prev=nullptr){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};

class dll{
public:
    Node* head;
    Node* tail;
    int cap=0;
    int size=0;
    map<int,pair<Node*,data>> mp;

    dll(int cap){
        head=tail=NULL;
        this->cap=cap;
        size=0;
    }
// will not change size in any deletion ,  why??  
    void del_head(){ 
        if(head==NULL) return;
        if(head==tail){
            tail=NULL;
            head=NULL;
            return;
        }
        Node* temp =head;
        head=head->next;
        temp=NULL;
    }
    
    void delete(int key){
        Node* temp= mp[key].first;
        if(key==head) return del_head();
        if(key==tail) return;
        temp->prev->next = temp->next;
        temp->next->prev

    }






    int find(int key){
        if(mp.find(key)==mp.end()) return -1;


    }








};


class LRUCache {
public:

    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */