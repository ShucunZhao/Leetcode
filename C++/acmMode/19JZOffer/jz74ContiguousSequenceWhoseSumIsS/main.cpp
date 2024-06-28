#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    int curSum = 0;
    vector<int> getArray(int l, int r) {
        vector<int> tmp;
        while (l <= r) tmp.push_back(l++);
        return tmp;
    }
    vector<vector<int> > FindContinuousSequence2(int sum) {
        /*
               l
            1, 2, 3, 4, 5, 6, 7, 8, 
                     r
            cur: 6
        */
        int l = 1, r = 1;
        while (r < sum) {
            curSum += r;
            while (curSum > sum) {
                curSum -= l;
                l++;
            }  
            if (curSum == sum) {
                ans.push_back(getArray(l, r));
            }
            r++;
        }
        return ans;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        // write code here
        if (sum == 0) return {};
        backtracking(1, sum);
        return ans;
    }
    void backtracking(int start, int sum) {
        if (curSum == sum) {
            if(path.size()>1){
                ans.push_back(path);
            }
            return;
        }
        for (int i = start; i <= sum; ++i) {
            if (curSum+i > sum) break;
            if (!path.empty() && path.back() + 1 != i) break;
            curSum += i;
            path.push_back(i);
            backtracking(i + 1, sum);
            curSum -= i;
            path.pop_back();
        }
        return;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the sum:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        int sum = stoi(In);
        vector<vector<int> > res = S1.FindContinuousSequence2(sum);
        cout << "Res: [";
        for (vector<int>& nums : res) {
            cout << "[";
            for (int& i : nums) {
                cout << i << ",";
            }
            cout << "],";
        }
        cout << "]" << endl;
    }
}