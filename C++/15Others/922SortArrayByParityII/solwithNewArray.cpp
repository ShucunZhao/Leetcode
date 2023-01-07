class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int even = 0, odd = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                ans[odd] = nums[i];
                odd+=2;
            }
            else{
                ans[even] = nums[i];
                even+=2;
            }
        }
        return ans;
    }
};