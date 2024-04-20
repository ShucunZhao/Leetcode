#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string path;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0);
        return ans;
    }
    void backtracking(int n, int numL, int numR) {
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }
        if (numL < n) {
            path.push_back('(');
            numL++;
            backtracking(n, numL,numR);
            path.pop_back();
            numL--;
        }
        if (numR < numL) {
            path.push_back(')');
            numR++;
            backtracking(n, numL, numR);
            path.pop_back();
            numR--;
        }
    }
};

int main(int argc, char* argv) {
    while (true) {
        Solution S1;
        cout << "Enter n:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        int n = stoi(N);
        vector<string> res = S1.generateParenthesis(n);
        cout << "Res: [";
        for (string& s : res) {
            cout << s << ",";
        }
        cout << "]"<<endl;
    }
}