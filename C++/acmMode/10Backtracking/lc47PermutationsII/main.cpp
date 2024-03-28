#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used1(nums.size(), false);
        vector<bool> used2(nums.size(), false);
        backtracking(nums, used1, used2);
        return ans;
    }
    void backtracking(vector<int> & nums, vector<bool> & used1, vector<bool> & used2) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used1[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && used2[i - 1] == false) {
                    continue;
                }
                used1[i] = true;
                used2[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used1, used2);
                path.pop_back();
                used1[i] = false;
                used2[i] = false;
            }
        }
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size()-2);
        vector<int> nums;
        if (!In.empty()) {
            string token;
            stringstream ss(In);
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                nums.push_back(stoi(token));
            }
        }
        vector<vector<int> > res = S1.permuteUnique(nums);
        cout << "Res: [";
        for (vector<int>& tmp : res) {
            cout << "[";
            for (int& i : tmp) {
                cout << i << ",";
            }
            cout << "]," << endl;
        }
        cout << "]" << endl;
    }
}
