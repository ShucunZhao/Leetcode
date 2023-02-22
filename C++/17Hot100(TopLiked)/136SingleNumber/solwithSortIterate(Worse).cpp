class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            nums = [2,2,1]
            nums = [1,2,2]
            nums = [4,1,2,1,2]
                             
             nums = [1,1,2,2,4]
        */
        //Sol1:
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                i++;
            }
            else{
                return nums[i];
            }
        }   
        return nums[nums.size()-1];
    }
};