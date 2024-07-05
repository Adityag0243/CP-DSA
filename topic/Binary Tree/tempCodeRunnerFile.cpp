class Node{
    public:
        char data;
        Node* l;
        Node* r;
        Node* p;
        Node(char data,Node* l=nullptr,Node* r=nullptr,Node* p=nullptr){
            this->data=data;
            this->l=l;
            this->r=r;
            this->p=p;
        }
};