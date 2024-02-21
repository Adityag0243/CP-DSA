class Solution {
public:
    int mySqrt(int x) {
        
        long long int low=1;
        long long int high=x;
        long long int ans=0;
        if(x==0) return ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid<=x/mid){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        int ans1=(int)ans;
        return ans1;
        
    }
};