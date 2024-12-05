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

/////////////////////////////////////////wronggggggggggggggggggg


// int fn(vector<int> &freq,int n,int k,bool last){
//     int sz = freq.size();

//     int lo = 2;
//     int hi=2;
//     if(sz&1) hi = (sz+1)/2;
//     else if(last) hi = sz/2+1;
//     else hi = sz/2;

//     int ans = -1;

//     while( lo<= hi ){
//         int mid = lo + (hi - lo)/2;
//         int score = 0;
//         int midi = mid; 
//         if(last){
//             mid--;
//             score += (mid)*(freq[sz-1]);
//             sz--;
            
//         }
//         for(int i = sz-1; i >= 0 ; i-=2){
//             if(score >= k) break;
//             mid--;
//             score += (mid*(freq[i-1]-freq[i])); // freq 1 - freq 0
//         }
//         if(score >= k){
//             ans = midi;
//             hi = midi-1;
//         }else{
//             lo = midi+1;
//         }
//     }
//     return ans;


// }


signed main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        vi freq;
        int n,k;
        cin >> n >> k;
        string s;
        cin>>s;
        int i = 0;
        while(i<s.size()){
            char c = s[i];
            int cnt = 0;
            while(s[i] == c){
                cnt++;
                i++;
            }
            freq.pb(cnt);
        }
        // cout<<"hii ";
        // suffix sum of freq;
        vi sfreq = freq;
        // cout<<"hmm ";
        int ssz = sfreq.size();
        for(int j = ssz-3 ; j >= 0 ; j--){
            // cout<<"what  ";
            sfreq[j] += sfreq[j+2];
        }
 
        int max_diff = 0;
        i = sfreq.size();    // want to land on 1's freq
        int index = -1;
        i-=2;

        if( s[s.size()-1] == '1'){
            index = freq.size()-1;
            max_diff = freq[freq.size()-1];
            i--; 
        }
        
        for( ; i>= 0 ; i-=2){
            if( sfreq[i] - sfreq[i+1]  > max_diff){
                max_diff = sfreq[i] - sfreq[i+1];
                index = i;
            }
        }

        int some_val = -1;
        int two = 2;
        if(max_diff > 0) some_val = max(two,(k+max_diff-1)/max_diff + 1);      
        cout<<some_val<<endl;     

    }
}