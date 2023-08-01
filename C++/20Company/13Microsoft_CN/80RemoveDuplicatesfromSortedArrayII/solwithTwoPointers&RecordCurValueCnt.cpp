class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            cur: 2
            cnt: 1
                                              r                             
            nums = [0,1,1,2,2,3,3,4,5,5,4,5,5]
                                        l  
        */
        if(nums.size()<3) return nums.size();
        int l = 2, r = 2;
        int cur = nums[1];
        int cnt = 1;
        if(nums[0]==nums[1]){
            cnt++;
        } 
        for(l,r;r<nums.size();){
            if(nums[r]==cur){
                if(cnt==2){
                    r++;
                }
                else{
                    nums[l] = nums[r];
                    cnt++;
                    r++;
                    l++;
                }
            }
            else{
                cur = nums[r];
                nums[l] = nums[r];
                cnt = 1;
                l++;
                r++;
            }
        }
        return l;
    }
};