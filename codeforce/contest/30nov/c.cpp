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


// spiral traversal from gpt bhai
// I will make '?' if it will lead to any exit box


void fn(vector<vector<char>>& matrix , int i , int j){
    bool check = true;
    if(i-1 >=0 &&  matrix[i-1][j] != 'y' )
    {
        check = false;
    }
    if( i+1 < matrix.size() &&  matrix[i+1][j] != 'y'){
        check = false;
    }
    if( j-1 >= 0 && matrix[i][j-1] != 'y'){
        check = false;
    }
    if( j+1 < matrix[0].size() && matrix[i][j+1] != 'y'){
        check = false;
    }
    
    if(check){
        matrix[i][j] = 'y';
    }

}







void spiralTraversal(vector<vector<char>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns

    int top = 0, bottom = n - 1;   // Row boundaries
    int left = 0, right = m - 1;   // Column boundaries

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) {
            fn(matrix,top,j);
        }
        top++; // Move top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            fn(matrix,i,right);
        }
        right--; // Move right boundary left

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int j = right; j >= left; --j) {
                fn(matrix,bottom,j);
            }
            bottom--; // Move bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; --i) {
                fn(matrix,i,left);
            }
            left++; // Move left boundary right
        }
    }
}







signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> v(n, vector<char>(m));
        queue<pair<int,int>> q;
        l(i,0,n){
            l(j,0,m){
                cin>>v[i][j];
                if(i==0  && (v[i][j] == 'U')){
                    v[i][j] = 'y';   // marking as yes
                    q.push(make_pair(i, j));
                }

                if(i==n-1 && (v[i][j] == 'D')){
                    v[i][j] = 'y';   // marking as yes
                    q.push(make_pair(i, j));
                }

                if(j==0 && v[i][j] == 'L'){
                    v[i][j] = 'y';  
                    q.push({i,j});
                }

                if(j==m-1 && v[i][j] == 'R'){
                    v[i][j] = 'y';  
                    q.push({i,j});
                }
            }
        }

        if(n==1 && m==1 && v[0][0]=='?'){
            cout<<0<<endl;
            continue;
        }

        if(q.size() == 0){
            cout<<n*m<<endl;
            continue;
        }
        

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if( i-1 >= 0  && (v[i-1][j] == 'D') ){
                v[i-1][j] = 'y';
                q.push({i-1,j});
            }

            if( i+1 < n && v[i+1][j] == 'U'){
                v[i+1][j] = 'y';
                q.push({i+1,j});
            }

            if( j-1 >= 0 && v[i][j-1] == 'R'){
                v[i][j-1] = 'y';
                q.push({i,j-1});
            }

            if( j+1 < m  && v[i][j+1] == 'L'){
                v[i][j+1] = 'y';
                q.push({i,j+1});
            }

        }

        int cnt = 0;

        l(i,0,n){
            l(j,0,m){
                if( v[i][j] != 'y' && v[i][j] != '?') cnt++;
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
        }

        

        // ab bache '?' 

        spiralTraversal(v);

        l(i,0,n){
            l(j,0,m){
                if(v[i][j] == '?'){
                    bool check = true;
                    if(i-1 >=0 &&  v[i-1][j] != 'y' )
                    {
                        check = false;
                    }
                    if( i+1 < v.size() &&  v[i+1][j] != 'y'){
                        check = false;
                    }
                    if( j-1 >= 0 && v[i][j-1] != 'y'){
                        check = false;
                    }
                    if( j+1 < v[0].size() && v[i][j+1] != 'y'){
                        check = false;
                    }

                    if(check == false) cnt++;
                }
            }
        }

        cout<<cnt<<endl;



        

        
    }
}