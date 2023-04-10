class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<2) return 0;
        vector<int> org(nums);
        sort(nums.begin(), nums.end());
        int begin = 0, end = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=org[i]){
                begin = i;
                break;
            }
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]!=org[j]){
                end = j;
                break;
            }
        }
        return begin==end?0:end-begin+1;
    }
};