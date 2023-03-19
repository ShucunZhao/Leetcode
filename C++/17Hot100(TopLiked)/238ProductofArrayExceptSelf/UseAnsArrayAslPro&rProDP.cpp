class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            nums =      [1,2,3,4]
            leftPro =   [1,1,1,1]
                        [1,1,2,6]
            rightPro =  [4,4,4,4]
                        [24,12,4,1]
            ans            1,1,2,6
        */
        //vector<int> lPro(nums.size()), rPro(nums.size());
        //lPro[0] = 1;
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i=1;i<nums.size();i++){
            ans[i]=nums[i-1]*ans[i-1];
        }
        /*
        for(int i=0;i<nums.size();i++){
            cout<<"ans["<<i<<"]:"<<ans[i]<<endl;
        }
        */
        int right = 1;
        for(int j=nums.size()-1;j>=0;j--){
            /*
            if(j==nums.size()-1){
                right = 1;
            }
            else{
                right*=nums[j+1];
            }
            */
            ans[j]*=right;
            right*=nums[j];
        }
        return ans;
    }
};