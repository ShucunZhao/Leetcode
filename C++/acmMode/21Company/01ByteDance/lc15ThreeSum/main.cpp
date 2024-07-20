#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            [ 1,-1,-1,0 ]
                      r 
            sort: -1,-1,0,1
                   i     l  
        */
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back({ nums[i], nums[l], nums[r] });
                    while (l + 1 < r && nums[l] == nums[l + 1]) l++;
                    while (l < r - 1 && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r]>0){
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution S;
    vector<int> nums = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
    vector<vector<int> > res = S.threeSum(nums);
    cout << "Res: [";
    for (vector<int>& tmp : res) {
        cout << "[";
        for (int& i : tmp) cout << i << ",";
        cout << "],";
    }
    cout << "]" << endl;
}