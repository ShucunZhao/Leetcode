/*
* The sliding window method is the upgraded version of two poiners.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i  = 0;
        int sum = 0;
        int subL = 0;
        int result = nums.size();
        bool check = 0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                check = 1;
                subL = j-i+1;
                //result=min(result, subL);
                result = subL < result ? subL : result;
                sum-=nums[i];
                i++;
            }
        }
        
        if(check){
            return result;
        }
        else{
            return 0;
        }
        
       // return result = check ? result : 0;
    }
};