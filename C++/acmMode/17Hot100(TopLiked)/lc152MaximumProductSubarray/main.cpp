#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        *   ans = 0
            Input: nums = [2,3,-2,4]
                           2 6 -2 4         
            Output: 6
            Explanation: [2,3] has the largest product 6.
            We need to concern about the minumum and maximum at the same time 
            becuse the number maybe negative.
            1.dp_max[i]: the max product in position i of nums
              dp_min[i]: the min product in position i of nums
            2.for(int i=1;i<nums.size();++i){
                    we need to concern the three cases:
                        1.current nums[i] is negative:
                            max: dp_min[i-1]*nums[i]
                            min: dp_max[i-1]*nums[i]
                           
                        2.current nums[i] is positive:
                            max: dp_max[i-1]*nums[i]
                            min: dp_min[i-1]*nums[i]
                        3.Themself: nums[i]/dp_min[i]/dp_max[i]
              }
            3.dp_max[0] = nums[0]
              dp_min[0] = nums[0]
            ---------------------------
            nums =  [-2,3,-4]
        */
        vector<int> dp_max(nums.begin(), nums.end());
        vector<int> dp_min(nums.begin(), nums.end());
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp_max[i] = max(dp_max[i], max(dp_max[i-1] * nums[i], dp_min[i-1] * nums[i]));
            dp_min[i] = min(dp_min[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
            ans = max(dp_max[i], ans);
        }
        return ans;
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
        cout << "Res: " << S1.maxProduct(nums) << endl;
    }
}