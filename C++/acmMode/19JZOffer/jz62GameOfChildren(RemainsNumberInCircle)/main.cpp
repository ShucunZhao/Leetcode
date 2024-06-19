#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        // write code here
        /*
              m: 3
              0 1 2 3 4
              1 0 1 0 1
              cnt: 2
        */
        vector<bool> record(n, false);
        int cnt = 0;//Count the out amount
        int i = -1;//Traverse index
        int j = 0;
        while (cnt < n) {
            i++;
            if (i >= n) i = 0;
            if (record[i] == false) {
                j++;
            }
            if (j == m) {
;               record[i] = true;
                cnt++;
                j = 0;
            }
        }
        return i;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the n:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        cout << "Enter the m:" << endl;
        string M;
        getline(cin, M);
        if (M == "q") break;
        int n = stoi(N);
        int m = stoi(M);
        cout << "Res: " << S1.LastRemaining_Solution(n, m) << endl;
    }
}