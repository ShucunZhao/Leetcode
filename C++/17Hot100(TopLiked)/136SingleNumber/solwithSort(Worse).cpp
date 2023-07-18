class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
                [4,1,2,1,2]
                         
                 1,1,2,2,4
                 0,1,2,3,4
                       
        */
        sort(nums.begin(), nums.end());
        int i=0;
        for(i;i<nums.size()-1;){
            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
            i+=2;
        }
        if(i==nums.size()-1) return nums[nums.size()-1];
        return -1;
    }
};