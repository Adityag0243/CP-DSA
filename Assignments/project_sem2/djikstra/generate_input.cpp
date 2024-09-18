#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int t=300;
    ofstream outfile("large_input.txt");
    outfile << t << endl;
    srand(time(0));  // Seed for random number generation

    int k=t/2;         // first half having very less density then more then more like that.....
    t-=k;
     while(k--){
        int n = rand() % 3000;  // Number of nodes
        int m = rand() % 5*n + n;  // Number of edges
        
        
        outfile << n << " " << m << endl;

        for (int i = 0; i < m; ++i) {
            int u = rand() % n;
            int v = rand() % n;
            while (u == v) v = rand() % n;  // Ensure no self-loops
            int w = rand() % 100 + 1;  // Random weight between 1 and 100
            outfile << u << " " << v << " " << w << endl;
        }
        int source=rand()%n;
        outfile << source << endl;
    }



    while(t--){
    int n = rand() % 5000 + 100;  // Number of nodes
    int val = sqrt(n)*n;
    int m = rand() % val+ 10*n;  // Number of edges


    outfile << n << " " <<m<< endl;

    for (int i = 0; i < m; ++i) {
        int u = rand() % n;
        int v = rand() % n;
        while (u == v) v = rand() % n;  // Ensure no self-loops
        int w = rand() % 100 + 1;  // Random weight between 1 and 100
        outfile << u << " " << v << " " << w << endl;
    }
    int source=rand()%n;
    outfile << source << endl;
    }

    outfile.close();
    cout << "Large input generated and saved to 'large_input.txt'" << endl;

    return 0;
} 