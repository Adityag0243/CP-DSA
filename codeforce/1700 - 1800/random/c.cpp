#include<bits/stdc++.h>
//goel_aadhaar
using namespace std;
//goel_aadhaar
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define int int64_t
#define mod 1000000007

double squareRoot(double n) {
    double low = 0, high = n, mid;
    if (n < 1) high = 1; 
    for (int i = 0; i < 100; i++) { 
        mid = (low + high) / 2.0;
        if (mid * mid < n)
            low = mid;
        else
            high = mid;
    }
    return (low + high) / 2.0;
}

void solve1(){
    double a , b , c , x;
    cin >> a >> b >> c >> x;
    double answer = 0;
    answer += squareRoot(c * c + (a * a / 4.0)) + squareRoot((a * a) / 4.0 + ((b + c) * (b + c)));
    answer += (x / 100.0) * squareRoot(a * a + b * b);

    double na = (100 * a - a * x) / 100;
    double nb = (100 * b - b * x) / 100;

    answer += squareRoot(c * c + (na * na / 4.0));
    answer += squareRoot(((na * na) / 4.0) + ((nb + c) * (nb + c)));
    cout << fixed << setprecision(10) << answer << '\n';
}


void solve2() {
    double a, b, c, x;
    cin >> a >> b >> c >> x;
    double ans = 0;
    ans += (sqrt(a*a + b*b) * x) / 100.0;

    ans += (sqrt((b+c)*(b+c) + (a * a)/4.0 ));
    ans += (sqrt((c*c) + (a * a)/4.0 ));
    
    ans += (sqrt((c*c) + ((a * a) * (100-x) *(100-x))/ 40000.0));
    ans += (sqrt(((b+c-((b*x)/100.0))*(b+c-((b*x)/100.0))) + ((a * a) * (100-x) *(100-x))/ 40000.0));

    cout << setprecision(10) << fixed << ans << "\n";
}
//goel_aadhaar
void display() {
      
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while( t-- ){
        solve1();
        solve2();
    }
}