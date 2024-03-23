#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        /*
            Input: nums = [1,2,2]
            Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
        */
        vector<bool> used(nums.size(), false);
        ans.push_back({});
        sort(nums.begin(), nums.end());
        backtracking(nums, path, ans, used, 0);
        return ans;
    }
    void backtracking(vector<int> & nums, vector<int> & path, vector<vector<int> > & ans, vector<bool> & used, int start) {
        if (start == nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i-1] == false) {
                continue;
            }
            path.push_back(nums[i]);//1,2
            ans.push_back(path);
            used[i] = true;
            backtracking(nums, path, ans, used, i+1);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
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
        vector<vector<int> > res = S1.subsetsWithDup(nums);
        cout << "Res: [";
        for (vector<int> p : res) {
            cout << "[";
            for (int i : p) {
                cout << i << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
}