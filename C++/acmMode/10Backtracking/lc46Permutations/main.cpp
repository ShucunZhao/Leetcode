#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return ans;
    }
    void backtracking(vector<int> & nums, vector<bool> & used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        cout << "Enter nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        stringstream ss(In);
        string token;
        vector<int> nums;
        while (getline(ss,token, ',')) {
            size_t l = token.find_first_not_of(" ");
            size_t r = token.find_first_not_of(" ");
            nums.push_back(stoi(token.substr(l, r-l+1)));
        }
        vector<vector<int> > res = S1.permute(nums);
        cout << "Res: [";
        for (vector<int>& tmp : res) {
            cout << "[";
            for (int& i : tmp) {
                cout << i << ",";
            }
            cout << "]," << endl;
        }
        cout<<"]"<< endl;
    }
}