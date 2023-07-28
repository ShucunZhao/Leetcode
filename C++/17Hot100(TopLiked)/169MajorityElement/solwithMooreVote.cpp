class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int tar;
        int vote = 0;
        for(int i=0;i<nums.size();i++){
            if(vote==0){
                tar = nums[i];
                vote++;
                continue;
            }
            if(nums[i]==tar) vote++;
            else vote--;
        }
        return tar;
    }
};