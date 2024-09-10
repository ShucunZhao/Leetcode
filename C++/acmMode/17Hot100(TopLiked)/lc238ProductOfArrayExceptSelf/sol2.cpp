#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            Input: nums =   [1,2,3,4]
                     left:   1 1 2 6 
                    right:  24 12 4 1 
            Output: [24,12,8,6]
        */
        vector<int> left = vector<int>(nums.size(), 1);
        vector<int> right = vector<int>(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            left[i] *= right[i];
        }
        return left;
    }
};

int main(int argc, char* argv[]) {
    vector<int>  nums = { -1,1,0,-3,3 };
    Solution S;
    vector<int> res = S.productExceptSelf(nums);
    cout << "Res: [";
    for (int& i : res) cout << i << ",";
    cout << "]" << endl;
}