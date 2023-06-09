class Solution {
public:
    int counter(vector<int>& nums, int tar){
        int cnt = 0;
        for(int i : nums){
            if(i<=tar){
                cnt++;
            }
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        /*

  
                     l   m   r
               i:    0 1 2 3 4      
             nums = [1,3,4,2,2]

        */
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(counter(nums, m)>m){
                ans = m;
                r = m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};