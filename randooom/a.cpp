#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int sumOddDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i += 2) {  // Iterate only for odd divisors
        if (n % i == 0) {
            sum += i;  // Add divisor
            if (i != n / i && (n / i) % 2 == 1)  // Add paired divisor if odd
                sum += n / i;
        }
    }
    return sum;
}

int sumEvenDivisors(int n) {
    int sum = 0;
    for (int i = 2; i * i <= n; i += 2) {  // Iterate only for even divisors
        if (n % i == 0) {
            sum += i;  // Add divisor
            if (i != n / i && (n / i) % 2 == 0)  // Add paired divisor if even
                sum += n / i;
        }
    }
    return sum;
}

signed main() {
    int n;
    cin >> n;
    if (n % 2 == 1) 
        cout << sumOddDivisors(n) << endl;
    else 
        cout << sumEvenDivisors(n) << endl;
}
