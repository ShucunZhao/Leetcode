class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // nums = [5,2,3,1]
        //  o1:    2 3 1 5
        //  o2:    2 1 3 5
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size()-i;j++){
                if(nums[j]<nums[j-1]){
                    int tmp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums;
    }
};