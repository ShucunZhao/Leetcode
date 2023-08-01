class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*  
             left     1   1   2   6    
             nums =  [1,  2,  3,  4]
             right    24  12  4   1
        */
        int size = nums.size();
        vector<int> left(size);
        left[0] = 1;
        vector<int> right(size);
        right[size-1] = 1;
        for(int i=1;i<nums.size();i++){
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=size-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = left[i]*right[i];
        }
        return nums;
    }
};