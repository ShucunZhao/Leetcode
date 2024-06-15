#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        /*
            Input: x = 1, y = 4
            Output: 2
            Explanation:
            1   (0 0 0 1)
            4   (0 1 0 0)
                   ¡ü  ¡ü
            xor: 0 1 0 1
        */
        int xorVal = x ^ y;
        int cnt = 0;
        while (xorVal) {
            if (xorVal & 1) cnt++;
            xorVal >>= 1;
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the x: " << endl;
        string X;
        getline(cin, X);
        if (X == "q") break;
        cout << "Enter the y: " << endl;
        string Y;
        getline(cin, Y);
        if (Y == "q") break;
        int x = stoi(X);
        int y = stoi(Y);
        cout << "Res: " << S1.hammingDistance(x, y) << endl;
    }
}