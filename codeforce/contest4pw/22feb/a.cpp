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

bool isPalindrome(string s){
    bool flag = true;
    l(i,0,s.size()/2) if( s[i] != s[s.size()-1-i]) flag = false;
    return flag;
}


signed main(){
    int t = 1;
    // cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s == "1"){
            cout << '0';
            continue;
        }

        string temp = s;

        if(isPalindrome(s)){

            if(s.size() % 2 == 1){

                if(s[s.size()/2] == '0'){
                    s[s.size()/2]++;
                }
                else{
                    s[s.size()/2]--;
                }

            }else{

                if(s[s.size()/2 + 1] == '0'){
                    s[s.size()/2]++;
                    s[s.size()/2 - 1]++;
                }else{
                    s[s.size()/2]--;
                    s[s.size()/2 - 1]--;
                }

            }


        }


        else{

            int n = s.size();

            int j = 0;
            rl(i,s.size()/2,s.size()){
                s[i] = s[j];
                j++;
            }
            if( n%2 == 0){
                // cout << "idhar ";
                if(temp[n/2 - 1] != temp[n/2]){
                    string t = "";
                    if(n  > 2){
                        t += temp[n/2 - 1];
                        t += temp[n/2 ];
                    }else t = temp;
                    string s3 = t;
                    string s4 = t;
                    // cout << s3 << " "<< s4 <<  endl;
                    while( !isPalindrome(s3) ){
                        long long num = stoll(s3);
                        num++;
                        s3 = to_string(num);
                    }
                    while( !isPalindrome(s4)){
                        long long num = stoll(s4);
                        num--;
                        s4 = to_string(num);
                    }

                    if(abs(stoll(t) - stoll(s3)) > abs(stoll(t) - stoll(s4)) ) s3 = s4;
                    if(n > 2){
                        s[n/2 - 1] = s3[0];
                        s[n/2 ] = s3[1];
                    }else s = s3;
                    
                }
            }
        }
        cout << s ;
        
    }
}