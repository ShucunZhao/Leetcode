#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(vector<int>& num, int size) {
        // write code here
        /*
              0 1 2 3 4 5 6 7               
             [2,3,4,2,6,2,5,1],3
                            r
             ans: 4,4,6,6,6,5
             Q: 6,7
             cur: 5 
        */
        if (size > num.size()||size==0) return {};
        vector<int> ans;
        deque<int> Q;//Save index
        int curMax = 0;
        for (int i = 0; i < num.size(); ++i) {
            while (!Q.empty() && num[Q.front()] < num[i]) {
                Q.pop_front();
            }
            Q.push_front(i);
            if (i - Q.back() >= size) Q.pop_back();
            curMax = num[Q.back()];
            if (i + 1 >= size) {
                ans.push_back(curMax);
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the num:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter the size:" << endl;
        string S;
        getline(cin, S);
        if (S == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> num;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                num.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        int size = stoi(S);
        vector<int> res = S1.maxInWindows(num, size);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}