#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        /*
        *              i
            push: [2,1,0]
            pop:  [1,2,0]
                     j
            st: 2,0
            ans: true
            ------------------------
                              i
            push:  [1,2,3,4,5]
            pop:   [4,3,5,1,2]
                      j
            st: 1,2,3,5
            ans: false
        */
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushV.size() && j < popV.size()) {
            if (pushV[i] != popV[j]) {
                if (!st.empty() && st.top() == popV[j]) {
                    st.pop();
                    j++;
                }
                else st.push(pushV[i++]);
            }
            else {
                i++;
                j++;
            }
        }
        while (j < popV.size()) {
            if (!st.empty() && popV[j] == st.top()) {
                j++;
                st.pop();
            }
            else {
                return false;
            }
        }
        return true;
    }
};

void construct(vector<int>& nums, string& In) {
    if (In.empty()) return;
    stringstream ss(In);
    string token;
    while (getline(ss, token, ',')) {
        size_t l = token.find_first_not_of(" ");
        size_t r = token.find_last_not_of(" ");
        nums.push_back(stoi(token.substr(l, r - l + 1)));
    }
    return;
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter pushV:" << endl;
        string Push;
        getline(cin, Push);
        if (Push == "q") break;
        cout << "Enter popV:" << endl;
        string Pop;
        getline(cin, Pop);
        if (Pop == "q") break;
        Push = Push.substr(1, Push.size() - 2);
        Pop = Pop.substr(1, Pop.size() - 2);
        vector<int> pushV;
        vector<int> popV;
        construct(pushV, Push);
        construct(popV, Pop);
        cout << "Res: " << S1.IsPopOrder(pushV, popV) << endl;
    }
}