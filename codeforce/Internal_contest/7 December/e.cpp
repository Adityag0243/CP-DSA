#include<bits/stdc++.h>
using namespace std;
int diff(string str1, string str2) {
    int count = abs((int)str1.length() - (int)str2.length());
    // cout<<"there 1: "<<count<<"\n";
    for (int i = 0; i < min((int)str1.size(), (int)str2.size()) ; i++) {
        if(str1[i] != str2[i]) count++;
    }
    // cout<<"there : "<<count<<"\n";
    return count;
}
void solve(){
    int l , r;
    cin >> l >> r;
    
    int sum;
    if(r - l < 20){
        int cnt = 0;
        for(int i = l; i < r; i++){
            string s1 = to_string(i);
            string s2 = to_string(i + 1);
            cnt += diff(s1 , s2);
            // cout <<"here: " <<cnt << endl;
        }
        cout << cnt << endl;
        return;
    } else {
        int a = (l + 9) / 10 + 1;

        sum = ((r - r % 10) - (a))  + ((r - r % 10) - (a))  / 9;
        int cnt = 0;
        for(int i = r - r % 10; i < r; i++){
            string s1 = to_string(i);
            string s2 = to_string(i + 1);
            cnt += diff(s1 , s2);
        }
        sum += cnt;
        for(int i = l; i <= a; i++){
            // cout << l << endl;
            string s1 = to_string(i);
            string s2 = to_string(i + 1);
            cnt += diff(s1 , s2);
        }
        sum += cnt;
    }
    cout << sum << endl;

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
}
