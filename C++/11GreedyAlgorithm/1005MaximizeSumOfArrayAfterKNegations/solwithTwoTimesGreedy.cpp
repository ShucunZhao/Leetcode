class Solution {
public:
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i] *= -1;
                k--;
            }
            if(k==0){
                return accumulate(nums.begin(), nums.end(), 0);
            }
        }
        while(k>0){
            nums[nums.size()-1] *= -1;
            k--;
        }
        // for(int i : nums){
        //     cout<<i<<endl;
        // }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};