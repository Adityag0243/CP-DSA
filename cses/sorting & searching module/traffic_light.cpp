#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n; cin >> x >> n;

    set<int> pos;
    pos.insert(0);
    pos.insert(x);

    multiset<int> ms;
    ms.insert(x);

    while( n-- ){
        int a; cin >> a;
        auto itr = lower_bound(pos.begin(), pos.end(), a);
        int right = *itr;
        int left = *prev(itr);


        ms.erase(ms.find(right - left));
        ms.insert(right- a);
        ms.insert(a - left);
        pos.insert(a);
        if( a - 1 == *pos.begin()) pos.erase(*pos.begin());
        if( a + 1 == *pos.rbegin()) pos.erase(*pos.rbegin());

        if(pos.find(a+1) != pos.end()  && pos.find(a-1) != pos.end()) pos.erase(a);

        cout << *ms.rbegin() << " ";
    }
    
}

