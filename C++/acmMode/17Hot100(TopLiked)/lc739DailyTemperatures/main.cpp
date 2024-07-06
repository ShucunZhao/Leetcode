#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        *                          0   1  2  3 4   5  6  7 
            Input: temperatures = [73,74,75,71,69,72,76,73]
                               st: 2 3 4  
                              ans: 1 1
                                   0 1 2 3 4 5 6 7
            Output: [1,1,4,2,1,1,0,0]
        */
        vector<int> ans(temperatures.size(),0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the temperatures:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> temperatures;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                temperatures.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        vector<int> res = S1.dailyTemperatures(temperatures);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}