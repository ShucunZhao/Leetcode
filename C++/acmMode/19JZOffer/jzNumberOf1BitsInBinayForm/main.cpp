#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        // write code here
        /*
            10
            0000 0000 0000 0000 0000 0000 0000 1010
            &
            1

        */
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1) {
                ans += 1;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the n:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        int n = stoi(In);
        cout << "Res: " << S1.NumberOf1(n) << endl;
    }
}