class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*  
             left     1   1   2   6    
             nums =  [1,  2,  3,  4]
             right    24  12  4   1

-------------------------------------------------
             ans      1   1   2   6    
             nums =  [1,  2,  3,  4]

            tmp: 1       
        */
        int size = nums.size();
        vector<int> ans(size, 1);
        // vector<int> left(size);
        // left[0] = 1;
        // vector<int> right(size);
        // right[size-1] = 1;
        for(int i=1;i<ans.size();i++){
            // left[i] = left[i-1]*nums[i-1];
            ans[i] = ans[i-1]*nums[i-1];
        }
        int tmp = 1;
        // ans[size-1]*=tmp;
        for(int i=size-1;i>=0;i--){
            ans[i]*=tmp;
            tmp *= nums[i];
        }
        return ans;
    }
};