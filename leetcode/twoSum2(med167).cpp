#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans={0,0};
        bool check=false;

        for(int i=0;i<numbers.size();i++){
            int low=0;
            int high=numbers.size()-1;
        // if(target>=2*numbers[i]){
        //     low=i+1;
        // }else high=i-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(numbers[mid]+numbers[i]==target){
                if(mid!=i){
                ans[0]=i+1;
                ans[1]=mid+1;
                check=true;
                break;
                }else{
                    low=mid+1;
                }
            }else if(numbers[mid]+numbers[i]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        if(check==true) break;
        }

    return ans;  
    }
};