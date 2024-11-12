#include <iostream>
#include <vector>
#include <string>

// gpt code to check if it sahi ki nhi , itna bruteforce kaam kr rha hai kya 


using namespace std;

bool isSafe(const string &s, int n) {
    vector<pair<int, int>> ranges;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            int range = s[i] - '0';
            ranges.push_back({i - range, i + range});
        }
    }
    for (int i = 0; i < ranges.size(); ++i) {
        for (int j = i + 1; j < ranges.size(); ++j) {
            int start1 = ranges[i].first;
            int end1 = ranges[i].second;
            int start2 = ranges[j].first;
            int end2 = ranges[j].second;

            if (end1 >= start2 && end2 >= start1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;

        if (isSafe(s, s.size())) {
            cout << "safe" << endl;
        } else {
            cout << "unsafe" << endl;
        }
    }
}
