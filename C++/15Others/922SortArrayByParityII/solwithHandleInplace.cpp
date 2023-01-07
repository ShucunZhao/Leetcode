class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int even = 0, odd = 1;
        for(even;even<nums.size();even+=2){
            if(nums[even]%2==1){
                while(nums[odd]%2==1) odd+=2;
                swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};