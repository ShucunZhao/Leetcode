class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
              real:      1  2  3  4 5 6  7  8 
                i:       0  1  2  3 4 5  6  7 
                nums = [-4,-3,-2,-7,8,2,-3,-1]
                nums = [4,3,2,7,8,2,3,1]
        */
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i]);//
            //if(index<=nums.size()){
                if(nums[index-1]>=0){
                    nums[index-1]*=-1;
                } 
            //}  
        }
        vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]>0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};