#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        /*
            Input: nums = [4,6,7,7]
            Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
        */
        vector<bool> used(nums.size(), false); //We use used array here like befor to remove the same path continuous duplicates
        backtracking(nums, used, 0);
        return ans;
    }
    void backtracking(vector<int> & nums, vector<bool> & used, int start) {
        if (start == nums.size()) {
            return;
        }
        // And we need to used hash set to remove the same for-level duplicates
        unordered_set<int> hset;
        for (int i = start; i < nums.size(); ++i) {
            if(hset.count(nums[i])>0) continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (path.empty()||path.back() <= nums[i]) {
                hset.insert(nums[i]);
                path.push_back(nums[i]);
                if (path.size() > 1) ans.push_back(path);
                used[i] = true;
                backtracking(nums, used, i+1);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter nums:" << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        string token;
        stringstream ss(In);
        vector<int> nums;
        while (getline(ss, token, ',')) {
            size_t l = token.find_first_not_of(" ");
            size_t r = token.find_last_not_of(" ");
            token = token.substr(l, r-l+1);
            nums.push_back(stoi(token));
        }
        vector<vector<int> > res = S1.findSubsequences(nums);
        cout << "Res: [";
        for (vector<int>& tmp : res) {
            cout << "[";
            for (int& i : tmp) {
                cout << i << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
}