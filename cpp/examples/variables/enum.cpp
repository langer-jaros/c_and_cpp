#include<iostream>
#include<string>

using namespace std;

enum APPROACH {
    BF=1,       // Brute Force
    BAB=2,      // Branch and Bound
    DP=3,       // Dynamic Programming
    GH=4,       // Greedy Heuristic
    REDUX=5,    // REDUX
    FPTAS=6     // FPTAS
};

int main(int argc, char **argv)
{
    if (argc <= 1) {
        cout << "Required argument was not passed, operation failed." << endl;
        return 1;
    }
    
    APPROACH approach = (APPROACH)stoi(argv[1]);

    cout << "Approach: " << approach << endl;        

    return 0;
}