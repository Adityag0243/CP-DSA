#include<iostream>
using namespace std;
#define val data
class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next=nullptr){
     this->data=data;
     this->next=next;
    }
};

class Linkedlist{
    int size=0;
    Node* head;
    Node* tail;
public:
    Linkedlist(){
        head=tail=NULL;
        size=0;
    }

    void insert_i(int index,int val){
        if(index>size || index<0) throw out_of_range("Index out of bound enter valid index");
        Node* temp=new Node(val);
        Node* itr=head;
        for(int i=1;i<index;i++){
            itr=itr->next;
        }
        temp->next=itr->next;
        itr->next=temp;
        size+=1;
    }
    Node* Head(){
        return head;
    }
    Node* Tail(){
        return tail;
    }
    void remove_i(int index){
        if(index>size || index<0) throw out_of_range("Index out of bound enter valid index");
        if(index==0){
            headremove();
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


    void insert(int val){
        Node* temp=new Node(val);
        if(this->size==0){
            head=tail=temp;
            size+=1;
        }
        else{
            tail->next=temp;
            tail=temp;
            size+=1;
        }
    }
    void headinsert(int val){
        Node* temp=new Node(val);
        if(this->size==0) {
            insert(val);
            size+=1;
        }
        else{
          temp->next=head;
          head=temp;  
          size+=1;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int len(){
        int s=0;
        Node* temp=head;
        while(temp!=NULL){
            s+=1;
            temp=temp->next;
        }
        return s;
    }

    bool is_empty(){
        if(len()==0){
            return true;
        }else false;
    }


    void headremove(){
        if(size<1) throw out_of_range("No element in linkedlist");
        Node* temp=head->next;
        head=NULL;
        head=temp;
        size-=1;
    }
    void pop(){
        if(size<1) throw out_of_range("No element in linkedlist");
        
        if(size==1) tail=NULL;
        else{
            Node* temp=head;
            for(int i=1;i<size-1;i++){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size-=1;
        }
    }

    Node* k_rotation(int k){
        // 1->2->3->4->5 become 3->4->5->1->2 by 2 right rotation
        if(k<0) throw out_of_range("Negative index");
        k=(k%len());
        if(k==0) return head;
        else{
            // Node* tail=head;
            // while(tail!=NULL){
            //     tail=tail->next;
            // }
            Node* itr=head;
            while(--k){
                itr=itr->next;
            }
            tail->next=head;
            tail=itr;
            head=itr->next;
            itr->next=NULL;
        }
        return head;
    }

    Node* reverse() {
        tail=head;
        if(head==NULL || head->next==NULL ){
            return head;
        }
        Node* itr2=head->next->next;
        head->next->next=head;
        head=head->next;
        head->next->next=NULL;
        while(itr2!=NULL){
            Node* itr1=head;
            head=itr2;
            itr2=itr2->next;
            head->next=itr1;
        }
        return head;
    }

    Node* mergeTwoList(Node *list2){     //will merge list2 head in list1 whichis used for calling this function
        tail->next=list2;
        return head;
    }







    Node* mergeTwoSortedLists(Node* list2) {          // function for sorted merged list
        Node* list1=head;
        
        if(list1==NULL && list2==NULL){
            head=list1;
            return head;
        } 
        if(list1==NULL && list2!=NULL){
            head=list2;
            return head;
        }
        if(list1!=NULL && list2==NULL){
            head=list1;
            return head;
        }
        
        Node* itr1=list1;
        Node* itr2=list2;
        Node* hed;
        if(list1->val <=list2->val){
            hed=list1;
            itr1=list1->next;
        }else{
            hed=list2;
            itr2=list2->next;
        }
        
        Node* itr=hed;

        while(1){
            if(itr1!=NULL && itr2!=NULL){
                if(itr1->val <= itr2->val){
                    itr->next=itr1;
                    itr1=itr1->next;
                }else{
                    itr->next=itr2;
                    itr2=itr2->next;
                }
            }else if(itr2!=NULL && itr1==NULL){
                itr->next=itr2;
                itr2=itr2->next;
            }else if(itr1!=NULL && itr2==NULL){
                itr->next=itr1;
                itr1=itr1->next;
            }else{
                break;
            }
            itr=itr->next;
        }
       head=hed;
       return head; 
        
    }
    Node* middle(){ // will return middle for odd , n/2+1 th node for even
        Node* itr=head;
        int n=len();
        if(n==0) return NULL;
        if(n==1) return head;
        n/=2;
        while(n--){
            itr=itr->next;
        }
        return itr;
    }






};

int main(){
    Linkedlist a;
    cout<<a.is_empty()<<"\n";
    a.insert(10);
    a.insert(50);
    a.insert_i(1,75);
    a.insert_i(3,95);
    a.headinsert(20);
    a.insert_i(a.len(),30);
    a.headremove();
    a.pop();
    a.remove_i(2);
    a.insert(45);
    a.insert(55);
    // a.remove_i(a.len()-1);
    // a.remove_i(0);

    // a.display();
    // cout<<a.is_empty()<<"\n";
    
    // // a.display();
    // cout<<a.Head()->data<<"\n";
    // a.k_rotation(9);
    a.display();    //10 75 95 45 55
    a.reverse();
    a.display();   //55 45 95 75 10
    Linkedlist b;
    b.insert(15);
    b.insert(20);
    b.display();      //15 20
    a.mergeTwoList(b.Head());    //b will be merged in a in sorted order if a and b is already sorted
    a.display();    //15 20 55 45 95 75 10
    cout<<a.middle()->val;
    
    return 0;
}


