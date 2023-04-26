class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        /*
                          o  
                            e
            i:      0 1 2 3 
            nums = [4,5,2,7]
        */
        int even = 0, odd = 1;
        for(even,odd;even<nums.size()&&odd<nums.size();){
            if(nums[even]%2==0){
                even+=2;
            }
            else if(nums[odd]%2==1){
                odd+=2;
            }
            else if(nums[even]%2==1&&nums[odd]%2==0){
                swap(nums[even], nums[odd]);
                even+=2;
                odd+=2;
            }
        }
        return nums;
    }
};