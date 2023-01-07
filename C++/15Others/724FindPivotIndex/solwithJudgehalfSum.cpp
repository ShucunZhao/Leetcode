class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //nums:   [1,   7,   3,   6,   5,   6]
        //sum:    28
        //i:       0    1    2    3    4    5
        //lSum:    0    1    8    11
        //rSum:    27   20   17   11
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lS = 0, rS = 0;
        for(int i=0;i<nums.size();i++){
            if(i==0) lS = 0;
            else{
                lS+=nums[i-1];
            }
            rS = sum - lS - nums[i];
            if(lS==rS) return i;
        }
        return -1;
    }
};