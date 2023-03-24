class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            solution: prefix sum
                               j
            Input: nums = [1,2,3], k = 3
                         i" 
            preSumJ = 6;
            preSumI = 0;

            for:     0=<i<=j<n
            if exist sum(nums[i,j])==k:
                sum(nums[0,j])-sum(nums[0,i-1])=k
                sum(nums[0,j])-k = sum(nums[0,i-1])
            so we need to find how many sum(nums[i,j]) is equal to
            k is find how many sum(nums[0,i-1]) is equal to sum(nums[0,j])-k;
            The key point here!:
                when pointer point to j the i-1 must be passed, so we can use a unordered_map
                to count the sum(nums[0,i-1]) occur times, then use another counter
                to record the ans when that is equal to sum(nums[0,j])-k;
                [Pay attention: you need to add map[0,1] at first because there would be a target
                nums[j] which is equal to k directly.]
        */   
        /*
            nums =  [1,2,3],    k = 3
            preSum:  1,3,6
            ms:[0,1],[1,1],[3,1],[]
            cnt: 1
        */
        unordered_map<int, int> ms;
        ms[0]++;
        int preSum = 0;
        int cnt = 0;
        for(int i : nums){
            preSum+=i;
            if(ms.count(preSum-k)){
                cnt+=ms[preSum-k];
            }
            ms[preSum]++;
        }
        return cnt;
    }
};