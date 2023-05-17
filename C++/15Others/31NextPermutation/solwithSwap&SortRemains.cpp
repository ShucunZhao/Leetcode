class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            nums = [3,2,1]
            [1,5,1]
        */
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[j]>nums[i]){
                    // cout<<"j:"<<j<<"i:"<<i<<endl;
                    swap(nums[j], nums[i]);
                    sort(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};