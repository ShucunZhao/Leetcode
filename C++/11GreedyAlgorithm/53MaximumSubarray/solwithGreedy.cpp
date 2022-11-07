class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, count = 0;
        for(int i : nums){
            count+=i;
            ans = ans>count?ans:count;
            if(count<0){
                count = 0;
            }
        }
        return ans;
    }
};