#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int main() {
    ofstream outFile("input.in");  // Output file for the generated input
    random_device rd;                // Random number generator
    mt19937 gen(rd());
    
    // Define the ranges for the number of test cases and array elements
    const int MAX_TEST_CASES = 100; // 10^5
    const int MAX_ARRAY_LENGTH = 100; // 10^5
    const int MAX_SUM_LENGTH = 100000; // The sum of n over all test cases should not exceed 10^5

    uniform_int_distribution<int> testCaseDist(1, MAX_TEST_CASES);
    uniform_int_distribution<int> arrayLengthDist(1, MAX_ARRAY_LENGTH);
    uniform_int_distribution<int> elementDist(1, 1000000000); // 1 ≤ ai ≤ 10^9

    int t = testCaseDist(gen); // Random number of test cases
    outFile << t << endl;

    int totalLength = 0; // To keep track of the sum of lengths

    for (int i = 0; i < t; ++i) {
        int n = arrayLengthDist(gen); // Random array length
        if (totalLength + n > MAX_SUM_LENGTH) {
            n = MAX_SUM_LENGTH - totalLength; // Adjust to not exceed total length
        }
        totalLength += n;

        outFile << n << endl;

        for (int j = 0; j < n; ++j) {
            outFile << elementDist(gen) << (j < n - 1 ? " " : ""); // Generate random array elements
        }
        outFile << endl; // New line after the array
    }

    outFile.close();
    return 0;
}
