#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n; cin >> x >> n;

    set<int> pos;
    pos.insert(0);
    pos.insert(x);

    priority_queue< tuple<int,int,int> > pq;
    pq.push({ x, 0, x});

    while( n-- ){
        int a; cin >> a;
        auto itr = lower_bound(pos.begin(), pos.end(), a);
        int right = *itr;
        int left = *prev(itr);

        pq.push({right- a, a, right});
        pq.push({a - left, left, a});
        pos.insert(a);
        
        while(true){
            auto [len, left, right] = pq.top();
            auto it2 = pos.upper_bound(left);
            if(it2 != pos.end() && *it2 == right){
                cout << len << " ";
                break;
            }
            pq.pop(); 
        }

    }
    
}

