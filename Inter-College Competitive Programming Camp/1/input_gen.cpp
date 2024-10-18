#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;

int main() {
    ofstream outfile("large_input.txt");
    srand(time(0));  // Seed for random number generation
    int n = rand() % 200001; 
    outfile << n << endl;

    while(n--){
        int a = rand() % 200001; 
        outfile << a << " ";
    }
    outfile<<endl;
    int q = rand() % 200001; 
    while(q--){
        int a =  rand() % 2 + 1; 
        int b =  rand() % n + 1; 
        int c =  rand() % 200001; 
        outfile << a << " " << b << " " << c << endl;
    }

    outfile.close();
    cout << "Large input generated and saved to 'large_input.txt'" << endl;

    return 0;
} 