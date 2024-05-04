#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
                Input: numRows = 5
                Output: [[1],
                        [1,1],
                       [1,2,1],
                      [1,3,3,1],
                     [1,4,6,4,1]]
                dp[2][1] = dp[1][0]+dp[1][1]
                ...
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
                dp[3][2] = dp[2][1]+dp[2][2]
        */
        vector<vector<int> > ans;
        int cnt = 0;
        while (numRows--) {
            vector<int> tmp(cnt+1);
            tmp[0] = 1;
            tmp[tmp.size() - 1] = 1;
            for (int i = 1; i < tmp.size() - 1; ++i) tmp[i] = ans[cnt - 1][i - 1] + ans[cnt - 1][i];
            ans.push_back(tmp);
            cnt++;
        }
        return ans;
    }
};

int main(int argc, char* argv) {
    while (true) {
        Solution S1;
        cout << "Enter the numRows:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        int numRows = stoi(In);
        vector<vector<int> > res = S1.generate(numRows);
        cout << "Res: ";
        for (vector<int>& tmp : res) {
            cout << "[";
            for (int& i : tmp) {
                cout << i << ",";
            }
            cout << "]," << endl;
        }
    }
}