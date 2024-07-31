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
    int head_key=-1;
    map<int,pair<Node*,int>> mp;

    dll(){
        head=tail=NULL;
        size=0;
    }

    void set_cap(int cap){
        this->cap=cap;
    }

    void del_mp(int key){
        mp.erase(key);
    }

    void insert_mp(int key,int val){
        mp[key]=make_pair(tail,val);
    }

    void del_head(){ 
        if(head==NULL) return;
        size--;
        if(head==tail){
            tail=head=NULL;
            head_key=-1;
            return;
        }
        Node* temp =head;
        head=head->next;
        if(head==NULL) head_key=-1;
        else head_key=head->data;
        delete temp;
    }
    
    void del(int key){
        Node* temp= mp[key].first;
        if(mp[key].first==head) return del_head();
        size--;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp=nullptr;
    }


    void insert(int key,int val){
        
        if(head==nullptr){
            Node* temp = new Node(val);
            head_key=key;
            head=temp;
            tail=temp;
            size++;
            insert_mp(key,val);

        }else if( mp.find(key) != mp.end() ){
            if(mp[key].first==tail){
                mp[key].second=val;
            }else{
                del(key);
                del_mp(key);
                insert(key,val);
            }

        }else if(size == cap){
            del_mp(head_key);
            del_head();
            insert(key,val);
        }else{
            Node* temp = new Node(val);
            tail->next = temp;
            temp->prev = tail;
            tail       = temp;
            insert_mp(key,val);
            size++;
        }

    }



    int find(int key){
        if(mp.find(key)==mp.end()) return -1;
        if(mp[key].first==tail) return mp[key].second;
        int val=mp[key].second;
        del(key);
        del_mp(key);
        insert(key,val);
        return val;
    }


};


class LRUCache {
public:
    dll a;

    LRUCache(int capacity) {
        a.set_cap(capacity);
    }
    
    int get(int key) {
        return a.find(key);
    }
    
    void put(int key, int value) {
        
        a.insert(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */