#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            sol with fix the current height then find the max width of current height:
            How to find? 
                             0  1 2 3 4 5 6
            Input: heights = 0 [2,1,5,6,2,3] 0
            Output: 10

            st: 0,1
            ans:  2*(1+1-1) = 2
        */
        int ans = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        for (int i = 1; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int curI = st.top();
                st.pop();
                int W = curI - st.top() + i - curI - 1;
                ans = max(ans, W * heights[curI]);
            }
            st.push(i);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the heights:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> heights;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while(getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                heights.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.largestRectangleArea(heights) << endl;
    }
}