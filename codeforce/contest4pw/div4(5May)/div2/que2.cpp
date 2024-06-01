#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long suhru, a;
        cin >> suhru >> a;

        long long i = 1;
        long long end = 0;
        long long num = 0;

        
        while (suhru > 0) {
            //  current bit  1 hai 
            if (suhru % 2 == 1) {
                end += i; // toh ham final meh bit ko add kardenge
                num += i; // track all bits with any vaeiable 
            } else {
                // agar aisa nhi hai toh kam wala find karo 
                long long next_number= min(i - num, num + 1);
                // for  time inteval checking 
                if (next_number <= a) {
                    end += i; // fional meh add karo 
                }                                       
            }
            // agle bit peh jaoo
            i *= 2;
            suhru /= 2;
        }

        // baki ke bacche hau bit 
        while (i - num <= a) {
            end += i; // bacche hau bit add karo aage badho
            i *= 2; 
        }

        cout << end  << endl;
    }

    return 0;
}
                                                                         