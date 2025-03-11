// Problem Statement :   An array of size n filled with 0 at all index i (1<= i <= n) you have to perform q operations. 
// For each operation you have given indices a and b where (1 <= a < b <= n ).
//         In one operation you have to increment all the elements from index a to b inclusive.
// And then finally you need to print the updated array.


#include <bits/stdc++.h>
using namespace std;


// it will take O(n) time complexity for each operation...
void bruteforceQueryResolveFunction(vector<int> &arr, int a, int b){   
    for(int i = a; i<= b; i++)
        arr[i]++;
}

// it will take O(1) CONSTANT time complexity for each operation...
void prefix2QueryResolveFunction(vector<int> &arr, int a, int b){   
    arr[a]++;                          
    if(b < arr.size() -1 ) arr[b+1]--;
}




int main(){
    cout << "Size of array: ";
    int n;
    cin >> n;
    vector<int> arrBruteforce(n,0);  // n sized array, filled with zero
    vector<int> arrPrefix2(n,0);     // n sized array, filled with zero

    cout <<"No of operation you want to do : ";
    int q;
    cin >> q;

    while(q--){
        cout << "Enter two indices a and b (1 based less and equal to n: " << n << " ): "; 
        int a,b;
        cin >> a >> b;
        // for making zero based indexing decrementing the value of a b (confused ??? skip this part)
        a--;
        b--;

        bruteforceQueryResolveFunction(arrBruteforce, a, b);
        prefix2QueryResolveFunction(arrPrefix2, a, b);

    }
    

    cout <<"Result with TC O( q * n) arrBruteforce >> ";
    for(int i=0; i<n ;i++) cout << arrBruteforce[i] << " ";


    // just one extra work of taking prefix sum for generating the final array....
    for(int i = 1; i<n ; i++) 
        arrPrefix2[i] += arrPrefix2[i-1];
    
    // and that's it your arrPrefix2 array is ready as same as arrBruteforce with time complexity q + n
    cout <<"\nResult with TC O(q + n)     arrPrefix2 >> ";
    for(int i=0; i<n ;i++) cout << arrPrefix2[i] << " ";

    cout << "\nGetting same results in both the array but there is huge difference of TC in both the method.";
        
    
}