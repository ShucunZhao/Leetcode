class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
                    0   1   2   3
            nums = [1,  3, 3,  1]
            len: 2
        */
        for(int i=0;i<nums.size();i++){
            while(nums[i]<=nums.size()&&(nums[i]-1)!=i&&nums[i]>0&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            // cout<<"nums["<<i<<"]:"<<nums[i]<<endl;
            if(nums[i]<=0||(nums[i]-1)!=i){
                return i+1;
            }
        }
        // for(int i : nums){
        //     cout<<i<<",";
        // }
        // cout<<endl;
        return nums.size()+1;
    }
};