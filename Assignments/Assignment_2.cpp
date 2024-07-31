//225 .Implement Stack using Queues
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        if(q.size()){
            int s=q.size();
            while(--s){
                q.push(q.front());
                q.pop();
            }
        }
        
    }
    
    int pop() {
        int a=q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return !(q.size());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */






/************** 232. Implement Queue using Stacks ************/

class MyQueue {
    stack<int> s1;
public:
    MyQueue() {
        
    }
    void push(int x) {
        s1.push(x);
        
    }  
    int pop() {
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }
    
    int peek() {
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;
    }
    
    bool empty() {
        return s1.empty();
          
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */









/********************   380. Insert Delete GetRandom O(1)     *********************/

// not done


/********************     381. Insert Delete GetRandom O(1) - Duplicates allowed      *********************/

// not done

/****************  707. Design Linked List     ******************/

class Node{
    public:
    int val;
    Node* next;
    Node(int val,Node* next=nullptr){
     this->val=val;
     this->next=next;
    }
};
class MyLinkedList {
    int size=0;
    Node* head;
    Node* tail;   
public:
    MyLinkedList() {
        head=tail=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node* itr=head;
        while(index--){
            itr=itr->next;
        }
        return itr->val;
    }
    
    void addAtHead(int val) {
        Node* temp=new Node(val);
        if(this->size==0) {
            head=tail=temp;
            size+=1;
        }
        else{
          temp->next=head;
          head=temp;  
          size+=1;
        }

    }
    
    void addAtTail(int val) {
        Node* temp=new Node(val);
        
        if(this->size==0){
            tail=temp;
            head=tail;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size+=1;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size || index<0) return;
        if(index==0){
            addAtHead(val);
        }
        else if(index==size){
            addAtTail(val);   
        }else{
            Node* temp=new Node(val);
            Node* itr=head;
            for(int i=1;i<index;i++){
                itr=itr->next;
            }
            temp->next=itr->next;
            itr->next=temp;
            size+=1;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index>=size || index<0) return;
        if(index==0){
            Node* temp=head;
            head=head->next;
            temp=NULL;
            size-=1;
            return;
        }
        if(index==size-1){
            Node* itr=head;
            for(int i=1;i<index;i++){
                itr=itr->next;
            }
            tail=NULL;
            tail=itr;
            size--;
            return;
        }
        Node* itr=head;
        for(int i=1;i<index;i++){
            itr=itr->next;
        }
        Node* itr2=(itr->next)->next;
        itr->next=NULL;
        itr->next=itr2;
        size-=1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */




/****************  901. Online Stock Span     ******************/
class StockSpanner {
public:
    int size=0;
    vector<int> v,ans;
    StockSpanner() {
        
    }
    stack<int>st;
    int next(int price) {
        v.push_back(price);
        ans.push_back(1);
        while(!st.empty() && v[st.top()]<=price){
            ans[size]+=ans[st.top()];
            st.pop();
        }
        st.push(size);

        size++;
        return ans[size-1];  
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */








/****************   1381. Design a Stack With Increment Operation   ******************/
class CustomStack {
    int maxl=0;
    int size=0;

public:
    CustomStack(int maxSize) {
        maxl=maxSize;     
    }
    vector<int> v;
    void push(int x) {
        if(size>=maxl) return;
        v.push_back(x);
        size++;
    }
    
    int pop() {
        if(size==0) return -1;
        int a=v[size-1];
        v.pop_back();
        size--; 
        return a;
    }
    
    void increment(int k, int val) {
        if(k>=size){
            for(int i=0;i<size;i++){
                v[i]+=val;
            }
        }
        else{
            for(int i=0;i<k;i++){
                v[i]+=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */



/****************  1472. Design Browser History  ******************/
class Node{
    public:
        string val;
        Node* next;
        Node* prev;
        Node(string val,Node* next=nullptr,Node* prev=nullptr){
            this->val=val;
            this->next=next;
            this->prev=prev;
        }
};

class BrowserHistory {
public:
    Node* homepage;
    Node* current;
    int current_pos=0;
    int size=0;

    BrowserHistory(string homepge) {
        Node* newpage= new Node(homepge);
        current=newpage;
        homepage=newpage;
        size=1;    
        current_pos=size;   
    }
    
    void visit(string url) {
        Node* newpage= new Node(url);
        size=current_pos;
        size++;

        Node* temp=homepage; 
        while(--current_pos){
            temp=temp->next;
        }

        temp->next=newpage;
        newpage->prev=temp;
        current=newpage;   
        current_pos=size;
    }
    
    string back(int steps) {
       if(steps>=(current_pos)){
        current = homepage;
        current_pos=1;
        return homepage->val;
       }
        for(int i=0;i<steps;i++){
            current_pos--;
            current=current->prev;
        }
        return current->val;
    }
    
    string forward(int steps) {
        if(steps>(size-current_pos)){
            current_pos=size;
            while(current->next!=NULL) current=current->next;
        }
        else{
            for(int i=0;i<steps;i++){
                current_pos++;
                current=current->next;
            }
        }
        return current->val; 
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
