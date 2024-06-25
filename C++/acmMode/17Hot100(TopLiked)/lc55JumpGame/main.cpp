#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
                           0 1 2 3 4
            Input: nums = [3,2,1,0,4]
            Output: true
            Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
            Sol with greedy, find the max jump step in each range.

            [1,2,0,1]

            [3,2,1,0,4]

            nums =
            [1,1,0,1]
            [1,1,1,0]

            [5,9,3,2,1,0,2,3,3,1,0,0]
        */
        if (nums.size() == 1) return true;
        int curMax = nums[0];
        for (int i = 0; i <= curMax; ++i) {
            curMax = max(curMax, nums[i] + i);
            if (curMax >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.canJump(nums) << endl;
    }
}