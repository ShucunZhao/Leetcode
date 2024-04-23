#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses_dp(string s) {
        /*                   i
            Input: s = "()(())"
                    dp: 0 00 i
                          dp[i-1] is the length of valid substring
                   if determin dp[i] we need to judge the char in pos i-dp[i-1]-1
                    if the s[i-dp[i-1]-1] is '(' then dp[i] = 2+[i-1]+dp[i-dp[i-1]-1-1].
            1.dp[i]: the longest valid substring length which ends with positon i.
            2.dp[i] = 2+dp[i-1]+dp[i-dp[i-1]-1-1]
            3.dp[x] = 0 
        */
        vector<int> dp(s.size());
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1]=='(') {
                    if ((i - dp[i - 1] - 1 - 1) < 0) dp[i] = 2 + dp[i - 1];
                    else dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 1 - 1];
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        /*
            1.We need to used invalid case as reference index, and we count the result when meet the right-paranthese(')')
              by refering the reference index, and we should push -1 as intial reference index to prevent
              the fisrt element is a invalid ')'.
                   01234
              s = "()(()"
                [-1,2,3,4
                ans: 1-(-1)=2
                     4-2 = 2                     
        */
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size();++i) {
            if (s[i] == ')') {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
            else {
                st.push(i);
            }
        }
        return ans;
    }
};

int main(int argc, char* argv) {
    while (true) {
        Solution S1;
        string s;
        cout << "Enter s:" << endl;
        getline(cin, s);
        if (s == "q") break;
        s = s.substr(1, s.size() - 2);
        cout << "Res: " << S1.longestValidParentheses(s) << endl;
        cout << "Res2: " << S1.longestValidParentheses_dp(s) << endl;
    }
}