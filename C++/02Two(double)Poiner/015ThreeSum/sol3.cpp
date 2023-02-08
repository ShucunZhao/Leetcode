/*
    sol with Two pointers.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            nums     = [-1,0,1,2,-1,-4]
            index:          i
            sorted   = [0,0,0,0]
                            l        
                            r
            ans:  
        */  
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int l;
        int r;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i-1]==nums[i]) continue;
            l = i+1;//
            r = nums.size()-1;
            // cout<<"i:"<<i<<","<<"l:"<<l<<","<<"r:"<<r<<endl;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]<0){
                    while(l<r&&nums[l]==nums[l+1]){
                        l++;
                    }
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    while(l<r&&nums[r]==nums[r-1]){
                        r--;
                    }
                    r--;
                }
                else{
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
            }
        }
        return ans;
    }
};