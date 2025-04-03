// #include <bits/stdc++.h>
// using namespace std;


//  wrong ,,...   
// https://unstop.com/courses/unstop-practice-interview-pep/hcl/hcl-coding-assessment-29645/question-29710

// int predictTarget(int target, int start, int n){
//     int lo = 1;
//     int hi = n;
//     int ans = 0;
//     int mid = start;

//     while(lo <= hi){
        
//         if(mid == target) return ans;
//         else if( mid < target) lo = mid + 1;
//         else hi = mid - 1;

//         ans += mid;
//         mid = (lo + hi) / 2;
//     }
//     // cout << "returning "
//     return ans;
// }

// int predictionReward(int n) {
//     int ans = INT_MAX;

//     for(int i = 1; i<= n ; i++){
//         int inner_ans = INT_MIN;

//         if(i - 1 >  0) inner_ans = max(inner_ans , predictTarget(i-1, i, n));
//         if(i + 1 <= n) inner_ans = max(inner_ans , predictTarget(i+1, i, n));
//         inner_ans = max(inner_ans , predictTarget(1, i, n));
//         inner_ans = max(inner_ans , predictTarget(n, i, n));
//         // cout << "Inner ans: "<< inner_ans << "  ";
//         ans = min(ans, inner_ans);
//     }

//     return ans;
// }

// int main() {
//     int n;
//     std::cin >> n;
//     int result = predictionReward(n);
//     std::cout << result << std::endl;
//     return 0;
// }