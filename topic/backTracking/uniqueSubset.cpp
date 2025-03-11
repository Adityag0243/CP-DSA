// #include <bits/stdc++.h>
// using namespace std;
// #define all(arr)        arr.begin(), arr.end()
// #define vi              vector<int>
// #define vvi             vector<vi>
// #define int             int64_t
// #define yes             cout << "YES" << endl;
// #define no              cout << "NO" << endl;
// #define p(x)            cout << (x) << endl;
// #define sp(x)           cout << (x) << " ";
// #define endl            '\n'
// #define pb              push_back
// #define mxv(arr)        *max_element(arr.begin(), arr.end())
// #define mnv(arr)        *min_element(arr.begin(), arr.end())
// #define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
// #define srt(arr)        sort(arr.begin(), arr.end())
// #define rev(arr)        reverse(all(arr))
// #define MOD2            1000000007
// #define x               first
// #define y               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



// void fn(int index, vector<int> &arr, vector<pair<int,int>> &vp)
// {
//     if(index == vp.size()){
//         for(int j= 0 ; j< arr.size() ; j++){
//             cout << arr[j] << " ";
//         }
//         cout << endl;
//         return;
//     }

//     for(int k = index+1; k < vp.size(); k++){

//         fn(index+1,arr,vp);

//         for(int i = 1; i<= vp[k].second ; i++){
//             arr.pb(vp[k].first);
//             fn(index+1,arr,vp);
//         }

//         for(int i= 0; i<vp[k].second; i++){
//             arr.pop_back();
//         }



//     }
//     return;
// }

// signed main(){
    
//         int n;
//         cin >> n;
//         vi v(n);
//         l(i,0,n) cin >> v[i];
//         srt(v);
//         map<int,int> mp;
//         l(i,0,n) mp[v[i]]++;

//         vector< pair<int,int> > vp;

//         for(auto it : mp){
//             vp.push_back({it.first,it.second});
//             cout << vp.back().first<<" "<<vp.back().second<<endl;
//         }
//         cout << "done\n";

//         vector<int> arr;
//         fn(-1,arr,vp); 
        
    
// }

