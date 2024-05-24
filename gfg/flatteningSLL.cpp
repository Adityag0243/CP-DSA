Node *flatten(Node *root)
{
   // Your code here
   int n;
   cin>>n;
   Node* itr=root;
   vector<int> v;
   while(itr!=NULL){
       Node* trav=itr;
       while(trav!=NULL){
           v.push_back(trav->data);
           trav=trav->bottom;
       }
       itr=itr->next;
   }
   
   
   
   
   
   
   if(v.size()==0) return NULL;
   sort(v.begin(),v.end());
   
   
//   for(int i=0;i<v.size();i++){
//       cout<<v[i]<<" ";
//   }
   
   
   
   itr=root;
   Node* trav=itr->next;
   root=itr;
   itr->data=v[0];
   for(int i=1;i<v.size();i++){
    //   cout<<v[i]<<" ";
       trav->data=v[i];
       itr->next=trav;
       trav=trav->next;
       itr=itr->next;
   }
   return root;
   
   
}
