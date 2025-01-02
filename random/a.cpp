#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    cout<<"How's the Weather right now :\n";
    cout<<"Press 1 for Sunny :\nPress 2 for Overcast: \nPress 3 for Rainy: \nEnter your response: ";
    int val;
    cin >> val;
    if(val == 2) cout<<"you can go for playing";
    else if( val == 1 ){
        cout<<"If Temperature is high press 1 or press 2: ";
        int key;
        cin>>key;
        if(key == 1) cout<<"Temp is High you can't go for playing\n";
        else cout<<"You can Play\n";
    }else if(val == 3){
        int key;
        cin>>key;
        if(key == 1) cout<<"Wind is strong you cann't play\n";
        else cout<<"You can play\n";
    }
}