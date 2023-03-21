class Solution {
public:
    int count(vector<int> & nums, int target){
        int cnt = 0;
        for(int i : nums){
            if(i<=target) cnt++;
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        /*
            i:      0 1 2 3 4
            nums = [1,3,4,2,2]
            if the range[1,2] has no duplicates, the number of element which is smaller
            than 2 should be 2, if not which means the duplicates exist in this range.
        */
        int l=1, r = nums.size();
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;//(1+5)/2,(1+2)/2,(2+2)/2
            if(count(nums, m)>m){
                ans = m;//3,2
                r = m-1;//2,1
            }
            else{
                l = m+1;//2
            }
            //cout<<"ans:"<<ans<<endl;
        }
        return ans;
    }
};