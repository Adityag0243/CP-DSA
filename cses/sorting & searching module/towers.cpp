#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> v;

    v.push_back(a[0]);

    for( int i = 1; i < n; i++){
        if( v.back() <= a[i] ){
            v.push_back(a[i]);
        }else{
            int lo = 0,hi = v.size()-1;
            int ind = hi;
            while( lo <= hi ){
                int mid = (lo + hi)/2;

                if( v[mid] > a[i] ){
                    ind = mid;
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }
            v[ind] = a[i];
        }
    }
    cout << v.size() ;
    return 0;
}
