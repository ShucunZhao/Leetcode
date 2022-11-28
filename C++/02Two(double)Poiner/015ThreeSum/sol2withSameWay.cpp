/*
 * This kind of problem can reduce the dimension into find two sum question:
 * We can iterate all elements and find another two non-duplicate elements whose sum is target(is 0 here).
 * 1.Sort the given array using the two pointers method(point at head and tail) at first
 * 2.Eliminate the repeated elements every time when iterating and pointer move on.
 */
/*
 * Never use the hash map in this question because it's hard to eliminate the repeated 
 * elements with hash map!
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        int size = nums.size();
        int target;
        for(int i=0;i<size-1;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            target = 0-nums[i];
            int l=i+1,r=size-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1]){
                        l++;
                    }
                    while(l<r&&nums[r]==nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};