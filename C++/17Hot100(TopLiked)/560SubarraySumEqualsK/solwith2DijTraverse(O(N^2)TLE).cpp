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
        */   
        int preSumJ = 0;
        int cnt = 0;
        for(int j=0;j<nums.size();j++){
            preSumJ+=nums[j];
            // cout<<"preSumJ:"<<preSumJ<<endl;
            int preSumI = 0;
            for(int i=0;i<=j;   ++){
                if(i>0){
                    preSumI+=nums[i-1];
                }
                // cout<<"preSumI:"<<preSumI<<endl;
                if(preSumI==preSumJ-k) cnt++;
            }
        }
        return cnt;
    }
};