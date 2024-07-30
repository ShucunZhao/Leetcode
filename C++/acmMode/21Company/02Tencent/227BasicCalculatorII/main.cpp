#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    bool checkDigit(string& s) {
        for (char& c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    int calculate(string s) {
        /*
            Input: s = "3/2*2"
            Output: 7
            {/
             3,4/
            ------------
            Input: s = " 3+5 / 2 "
            Output: 5

            s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
        */
        vector<string> save;
        stack<string> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int j = i;
                while (j < s.size() && isdigit(s[j])) j++;
                if (i == j) {
                    string str;
                    str.push_back(s[i]);
                    save.push_back(str);
                }
                else {
                    save.push_back(s.substr(i, j - i));
                    i = j - 1;
                }
            }
            else {
                string str;
                str.push_back(s[i]);
                if (s[i] == '+' || s[i] == '-') {
                    while (!st.empty()) {
                        save.push_back(st.top());
                        st.pop();
                    }
                    st.push(str);
                }
                else {
                    while (!st.empty() && (st.top() == "*" || st.top() == "/")) {
                        save.push_back(st.top());
                        st.pop();
                    }
                    st.push(str);
                }
            }
        }
        while (!st.empty()) {
            save.push_back(st.top());
            st.pop();
        }
        stack<int> ans;//2,-26
        for (string& s : save) {
            if (checkDigit(s)) {
                ans.push(stoi(s));
            }
            else {
                int second = ans.top();
                ans.pop();
                int first = ans.top();
                ans.pop();
                if (s == "+") {
                    ans.push(first + second);
                }
                else if (s == "-") {
                    ans.push(first - second);
                }
                else if (s == "*") {
                    ans.push(first * second);
                }
                else if (s == "/") {
                    ans.push(first / second);
                }
            }
        }
        return ans.top();
    }
};

int main(int argc, char* argv[]) {
    Solution S1;
    string s = "1*2-3/4+5*6-7*8+9/10";
    cout << "Res: " << S1.calculate(s) << endl;
}