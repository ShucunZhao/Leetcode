class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            nums =      [1,2,3,4]
            leftPro =   [1,1,1,1]
                        [1,1,2,6]
            rightPro =  [4,4,4,4]
                        [24,12,4,1]
        */
        vector<int> lPro(nums.size()), rPro(nums.size());
        lPro[0] = 1;
        for(int i=1;i<nums.size();i++){
            lPro[i] = nums[i-1]*lPro[i-1];
        }
        rPro[nums.size()-1] = 1;
        for(int j=nums.size()-2;j>=0;j--){
            rPro[j] = nums[j+1]*rPro[j+1];
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            // cout<<"l:"<<lPro[i]<<",";
            // cout<<"r:"<<rPro[i]<<"."<<endl;
            ans[i]=lPro[i]*rPro[i];
        }
        return ans;
    }
};