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
    fastio;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        

        vi bs;
        int n = s.size();
        int val = n;
        while(n > 0){
            bs.pb(val);
            n--;
            val += n;
        }

        int pos;
        cin >> pos;

        int lo = 0;
        int hi = bs.size()-1;
        int ind = -1;        // to get the length of current word
        int remainder = pos; // to get the position in the current length word....

        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(bs[mid] <= pos){
                lo = mid+1;
                ind = mid;
                remainder = pos - bs[mid];
            }else{
                hi = mid-1;
            }
        }




        vi v(s.size(),-1);
        int ct = 1;

        // putting value in vector v which indicate in which order character should be removed
        // logic is to remove any character if the very next character of current string is smaller then remove
        // and always start it from the beginning for each word
        // eg.   for word    dtttbaab
        // remove t again t again t as they are greater than next letter b 
        // now after 3 removal word is dbaab again start from zero for each word length 
        // remove d word become : baab
        // remove b word: aab
        // finally word will become sorted then simply remove from end one by one that is whole logic
        l(i,0,s.size()){
            if(i+1 < s.size()){
                if( s[i] > s[i+1]) v[i] = ct++;
                int ind = i-1;
                while(ind >= 0 && s[ind] > s[i+1]){
                    if(v[ind] != -1){
                        ind--;
                        continue;
                    }
                    v[ind] = ct++;
                    ind--;
                }
            }
        }

        rl(i,0,s.size()){
            if(v[i] == -1) v[i] = ct++;
        }


        char c = s[0];
        if(remainder == 0)
        {
            int len = s.size() - ind;

            l(i,0,s.size()){
                if( v[i] > ind) c = s[i];
            }
        }else{
            int cnt = 0;
            l(i,0,s.size()){
                if( v[i] > ind+1 ){
                    c = s[i];
                    cnt++;
                }
                if(cnt == remainder) break;
            }
        }

        cout << c;


    }
    return 0;
}