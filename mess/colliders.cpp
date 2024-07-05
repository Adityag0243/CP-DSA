#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i, st, n) for (int i = st; i < n; i++)
#define rl(i, st, n) for (int i = n - 1; i >= st; i--)
#define srt(v) sort(v.begin(), v.end())
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define vp(v) vector<pair<int, int>> v;

int main() {
    vector<int> n(1e5 + 2, 0);
    n[0] = n[1] = 0;
    l(i, 2, 1e5 + 2) n[i] = i;
    l(i, 2, 1e5 + 2) {
        if (n[i] == i) { // i is a prime number
            for (ll j = (ll)i * i; j < 1e5 + 2; j += i) {
                n[j] = 0; // Marking multiples of i as non-prime
            }
        }
    }
    vector<pair<int,int>> p;
    
    l(i,2,1e5+1){
        if(n[i]==i) p.push_back(make_pair(i,0));
    }
    
    int t,m;
    cin>>t>>m;
    int ps=(int)p.size();
    bool one=false;
    while(m--){
        string sign;
        cin>>sign;
        string input;
        cin>>input;
        
        // cout<<input<<"  ";
        if(sign=="-"){

            int num=stoi(input);
            if(num==1){
                if(one){
                    one=false;
                    cout<<"Success\n";
                }else cout<<"Already off\n";
                continue;
            }
            bool check=false;
            // cout<<"num is "<<num<<"  ";
            for(int i=0;i<ps && p[i].first<=num;i++){
                if(num%p[i].first==0   &&  p[i].second!=num){
                    cout<<"Already off\n";
                    check=true;
                    break;
                }
            }
            if(check) continue;
            for(int i=0;i<ps && p[i].first<=num;i++){
                if(p[i].second==num){
                    p[i].second=0;
                }
            }
            cout<<"Success\n";
            
        }
        else{
            int num=stoi(input);
            if(num==1){
                if(one==false){
                    one=true;
                    cout<<"Success\n";
                }else cout<<"Already on\n";
                continue;
            }
            bool check=false;
            for(int i=0;i<ps && p[i].first<=num;i++){
                if(p[i].second!=0 && (num%(p[i].first)==0))
                {
                    check=true;
                    if(p[i].second==num){
                        cout<<"Already on\n";
                        break;
                    }
                    cout<<"Conflict with "<<p[i].second<<endl;
                    break;
                }
            }
            if(check) continue;
            // cout<<"No come for "<<num<<"  ";
            for(int i=0;i<ps && p[i].first<=num;i++){
                if(p[i].second==0 && (num%(p[i].first)==0))
                {
                    p[i].second=num;
                }
            }
            cout<<"Success\n";

        }
    }
    

    return 0;
}
