#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        /*
            Sn = 1+2+3+...+n
            Sn = n+n-1+...+1
            Add above two together:
                2Sn = n*(n+1)
                 Sn = n*(n+1)/2
                    = (n^2+n)/2
            So we need to implement the divide 2 operation by >> 1
        */
        int tmp = pow(n, 2) + n;
        tmp >>= 1;
        return tmp;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the n:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        int n = stoi(N);
        cout << "Res: " << S1.Sum_Solution(n) << endl;
    }
}