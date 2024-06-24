class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
    
        if(*max_element(nums.begin(), nums.end())>=k) return 1;


        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        deque<int> q;
        vector<int> sz;
        int i=0;
        while(i<nums.size()){
            q.push_back(i);
            if(nums[q.back()]<=0){
                while(!q.empty()){
                    q.pop_back();
                }
            }
            while(!q.empty() && q.size()!=1 && (q.front()==0 ? nums[q.back()] : nums[q.back()]-nums[q.front()-1])>=k){
                sz.push_back(q.back()-q.front()+1);
                int a=q.back();
                stack<int> st;
                while(!q.empty() && nums[a]-nums[q.back()]<k){
                    cout<<q.back()<<" yaha aaya hu  ";
                    st.push(q.back());
                    q.pop_back();
                }
                cout<<"yaha aaya ";
                if(st.size()) sz.push_back(st.size());
                while(!q.empty()){
                    q.pop_back();
                }
                while(!st.empty()){
                    q.push_back(st.top());
                    st.pop();
                }
                
            } 
            i++;
        }
        if(sz.size()==0) return -1;
        else {
            sort(sz.begin(),sz.end());
            return sz[0];
        }
       
        
        
    }
};