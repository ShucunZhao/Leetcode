class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // nums = [5,2,3,1]
        //  o1:    1 2 3 5
        //  o2:    1 2 3 5 
        for(int i=0;i<nums.size()-1;i++){
            int minI = i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[minI]) minI = j;
            }
            if(i!=minI){
                int tmp = nums[i];
                nums[i] = nums[minI];
                nums[minI] = tmp;
            }
        }
        return nums;
    }
};