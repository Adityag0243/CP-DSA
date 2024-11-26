#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n)       for(int i=st;i<n;i++)

void solve(){
    int n , k;
    cin >> n >> k;
    k = min(n , k);
    unordered_map<int , int> mp;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    
    priority_queue<int> pq;  
    
    for(auto it = mp.begin(); it != mp.end(); ++it){
        pq.push(it -> second);
    }

    while(!pq.empty() && k > 0){
        int x = pq.top();
        if(x == 1) break;
        x--;  
        k--;
        pq.pop();
        pq.push(x);
    }

    vector<int> v;
    int num = 1;
    while(!pq.empty()){
        int freq = pq.top();
        pq.pop();
        l(i,0,freq) v.push_back(num);
        num++;
    }
    long long ans = 0;
    for(int i =0; i< n; i++){
        if(v.size() < n) v.push_back(num++);
        // cout<<v[i]<<" ";
        int ub = upper_bound(v.begin() , v.end() , v[i]) - v.begin();
        ans += (n - ub);
    }
    cout<<ans<<endl;

    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
}