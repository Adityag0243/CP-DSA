#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int t=1000;
    ofstream outfile("large_input.txt");
    outfile << t << endl;
    srand(time(0));  // Seed for random number generation
    int k=t/10;         // first half having very less density
    t-=k;
    while(k--){
        int n = rand() % 1000;  // Number of nodes
        int m = rand() % 2*n + n;  // Number of edges
        
        
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
    k=t/10;
    t-=k;
    

    while(k--){
        int n = rand() % 10000;  // Number of nodes
        int m = rand() % 10*n + n;  // Number of edges
        
        
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

    k = t/10;
    t -= k;

    while(k--){
        int n = rand() % 30000;  // Number of nodes
        int m = rand() % 30*n + n;  // Number of edges
        
        
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
    int n = rand() % 50000 + 100;  // Number of nodes
    int m = rand() % 60*n + 10*n;  // Number of edges


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





    outfile.close();
    cout << "Large input generated and saved to 'large_input.txt'" << endl;

    return 0;
}
