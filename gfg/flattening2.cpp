 Node* mergeTwoLists(Node* list1, Node* list2) {
        
        
        if(list1==NULL && list2==NULL) return list1;
        if(list1==NULL && list2!=NULL) return list2;
        if(list1!=NULL && list2==NULL) return list1;
        
        Node* itr1=list1;
        Node* itr2=list2;
        Node* head;
        if(list1->data <=list2->data){
            head=list1;
            itr1=list1->bottom;
        }else{
            head=list2;
            itr2=list2->bottom;
        }
        
        Node* itr=head;

        while(1){
            if(itr1!=NULL && itr2!=NULL){
                if(itr1->data <= itr2->data){
                    itr->bottom=itr1;
                    itr1=itr1->bottom;
                }else{
                    itr->bottom=itr2;
                    itr2=itr2->bottom;
                }
            }else if(itr2!=NULL && itr1==NULL){
                itr->bottom=itr2;
                itr2=itr2->bottom;
            }else if(itr1!=NULL && itr2==NULL){
                itr->bottom=itr1;
                itr1=itr1->bottom;
            }else{
                break;
            }
            itr=itr->bottom;
        }
       return head; 
        
    }




Node *flatten(Node *root)
{
  // Your code here
  int n;
  cin>>n;
  Node* itr=root->next;
  vector<int> v;
  while(itr!=NULL){
    //   Node* trav=itr;
    //   while(trav!=NULL){
    //       v.push_back(trav->data);
    //       trav=trav->bottom;
    //   }
    root=mergeTwoLists(root,itr);
      itr=itr->next;
    
  }
   
   
   
   
   
   
//   if(v.size()==0) return NULL;
//   sort(v.begin(),v.end());
   
   
// //   for(int i=0;i<v.size();i++){
// //       cout<<v[i]<<" ";
// //   }
   
   
   
//   itr=root;
//   Node* trav=itr->next;
//   root=itr;
//   itr->data=v[0];
//   for(int i=1;i<v.size();i++){
//     //   cout<<v[i]<<" ";
//       trav->data=v[i];
//       itr->next=trav;
//       trav=trav->next;
//       itr=itr->next;
//   }
  return root;
   
   
}
