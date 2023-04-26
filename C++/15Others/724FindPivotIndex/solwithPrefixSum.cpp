class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //if(nums.size()==1) return 0;
        /*
            i:      0 1 2 3 4 5
            nums = [1,7,3,6,5,6]
            sum: 28
            find if the prefixSum*2 + current element is equal to totalSum,
                if yes, return the current index else return -1;
        */
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;
        for(int i=0;i<nums.size();i++){
            if(prefixSum*2+nums[i]==totalSum){
                return i;
            }
            prefixSum+=nums[i];
        }
        return -1;
    }
};