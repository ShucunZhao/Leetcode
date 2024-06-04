#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBit(int n) {
        int cnt = 0;
        /*
            1, 10, 11, 100, 101
            1  2   3   4     5
        */
        while (n) {
            if(n&1) cnt++;
            n = (n >> 1);
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            ans.push_back(countBit(i));
        }
        return ans;
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
        vector<int> res = S1.countBits(n);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}