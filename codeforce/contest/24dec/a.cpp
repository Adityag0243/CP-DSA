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


pair<int, int> fn(const vector<int>& arr, int a, int b) {
    int maxStreak1 = 0;      // Maximum streak of 1's
    int maxStreakMinus1 = 0; // Maximum streak of -1's

    int currentStreak1 = 0; // Current streak of 1's
    int currentStreakMinus1 = 0; // Current streak of -1's

    for (int i = a; i < b; i++) {
        if (arr[i] == 1) {
            currentStreak1++;
            currentStreakMinus1 = 0; // Reset the -1 streak
        } else if (arr[i] == -1) {
            currentStreakMinus1++;
            currentStreak1 = 0; // Reset the 1 streak
        }

        // Update maximum streaks
        maxStreak1 = max(maxStreak1, currentStreak1);
        maxStreakMinus1 = max(maxStreakMinus1, currentStreakMinus1);
    }

    // if(maxStreak1 == 0) maxStreak1 = -1;
    // if(maxStreakMinus1 == 0) maxStreakMinus1 = 1;

    return {maxStreak1, maxStreakMinus1};
}


signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> ans;
        vi v(n);
        int px = n;


        l(i,0,n){
            cin >> v[i];
            ans.insert(v[i]);
            if( v[i] != 1 && v[i] != -1) px = i;
        }
        int l1 = -1, n1 = 1 , l2 = -1 ,n2 = 1;

        // cout<<px<<" px : ";
        l1 = fn(v,0,px).first;   // streak of positive 1
        n1 = fn(v,0,px).second;  // streak of negative 1

        l2 = fn(v,px+1,n).first;
        n2 = fn(v,px+1,n).second;

        // cout<<l1<<" "<<n1<<" "<<l2<<" "<<n2<<endl;

        int one  = 0;
        l(i,0,px){
            if(v[i] == 1) one++;
        }
        int net_val = px - one; //total no of -1
        l1 = max(l1, one - net_val);
        n1 = min(n1,net_val);




        for(int i = -1*n1 ; i <= l1 ; i++) ans.insert(i);

        // cout << ans.size() << endl;
        // for(auto it : ans) cout<<it<<" ";
        // cout<<endl;

        one  = 0;
        l(i,px+1,n){
            if(v[i] == 1) one++;
        }
        net_val = n - px - one ;

        l2 = max(l2,one - net_val);
        n2 = min(n2,net_val);

        for(int i = -1*n2 ; i <= l2 ; i++) ans.insert(i);


        // cout << ans.size() << endl;
        // for(auto it : ans) cout<<it<<" ";
        // cout<<endl;


        vector<int> v1;
        int sum = 0;
        if(px < n)rl(i,0,px){
            sum += v[i];
            v1.pb(sum);
            ans.insert(sum+v[px]);
        }

        vector<int> v2;
        sum = 0;
        if(px<n)l(i,px+1,n){
            sum += v[i];
            v2.pb(sum);
            ans.insert(sum+v[px]);
        }


        if(px <n && v1.size() != 0 && v2.size() != 0){
            int mini = mnv(v1) + mnv(v2);
            int maxi = mxv(v1) + mxv(v2);
            l(i,mini,maxi+1){
                // ans.insert(i);
                ans.insert(i+v[px]);
            }
        }
        

        cout << ans.size() << endl;
        for(auto it : ans) cout<<it<<" ";
        cout<<endl;
        


        // cout <<endl;
    }
}



// 100 25
93915 74925 17023 68803 60904 6802 45943 12954 32023 68258 78505 48972 36571 41291 81024 30161 22461 3020 42880 46067 33975 19612 13599 51024 30682 79810 34500 47068 57992 31834 84079 44476 22842 37366 8017 3307 1595 98587 72367 95961 43018 52960 97699 45799 79453 67890 63003 72780 96601 82131 54808 36083 20026 79894 11345 19835 46674 50629 48525 50709 38754 88988 61612 56810 83618 35979 3871 92755 85279 20407 99052 9951 61047 729 72363 41392 75039 28701 55915 28414 83102 2693 45870 89426 42447 3428 39272 75500 42051 79396 63332 2111 50556 1440 91199 86511 92212 24042 45547 77882



//918528 1192320 1360128 850080 1153152 1064448 680064 1161216 1360128 709632 971520 1344000 680064 1360128 967680 680064 741888 844800 1013760 850080 1033344 739200 803712 870912 1419264 1216512 864000 1386000 1025024 946176 1360128 739200 1032192 1330560 680064 680064 1036288 1360128 680064 1483776 1419264 946176 1275120 1360128 1813504 1769472 741888 921600 680064 927360 1729728 680064 1596672 1419264 777216 777216 838656 1360128 953856 741888 838656 739200 1478400 1368576 709632 1483776 1020096 1165824 1360128 680064 739200 1483776 1217160 525504 741888 1197504 741888 865536 1554432 709632 1419264 680064 1179648 1419264 741888 739200 768768 1056000 1483776 1108800 1478400 680064 1075200 559104 680064 741888 739200 774144 1360128 887040 