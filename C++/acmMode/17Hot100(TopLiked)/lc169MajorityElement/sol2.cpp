#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];//1
        int cnt = 1;//1
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                cur = nums[i];
                cnt=1;
                continue;
            }
            if (nums[i] != cur) {
                cnt--;
            }
            else {
                cnt++;
            }
        }
        return cur;
    }
};

int main(int argc, char* argv[]) {
    vector<int>  nums = { 2, 2, 1, 1, 1, 2, 2 };
    Solution S;
    cout << "Res: " << S.majorityElement(nums) << endl;
}