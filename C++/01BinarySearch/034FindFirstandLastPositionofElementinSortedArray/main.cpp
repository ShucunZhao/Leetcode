/*
* Binary searching
* left close and right close version
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1, -1};
        }
        else if(nums[0]>target||nums[nums.size()-1]<target){
            return {-1,-1};
        }
        else{
            return {findPos(nums, target, 1), findPos(nums, target, 0)};
        }
    }
    
    int findPos(vector<int>& nums, int target, bool first) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]>target){ 
                right = mid-1;                    
            }
            else if(nums[mid]<target){
                left = mid+1;
            }                
            else{
                if(first){
                    if(mid==0||nums[mid-1]<target){
                        return mid;
                    }
                    right = mid - 1;
                }
                else{
                    if(mid==nums.size()-1||nums[mid+1]>target){
                        return mid;
                    }
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};