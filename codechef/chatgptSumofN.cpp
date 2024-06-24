#include <bits/stdc++.h>
using namespace std;

#define l(i,st,n) for(int i=st;i<n;i++) 

int main() {
    vector<int> v(1e6 + 1);
    l(i, 0, 1e6 + 1) v[i] = i;

    int i = 2;
    while (i < 1e6 + 1) {
        if (v[i] == i) {
            for (int j = i * i; j < 1e6 + 1; j += i) {
                if (v[j] == j) v[j] = i;
            }
        }
        i++;
    }

    l(i, 0, 25) cout << v[i] << "  ";
    cout << endl;

    return 0;
}
