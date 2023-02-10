/*
    sol:
       We know use binary search can divide an interval into left and right parts. First determine which part is the 
       ascending part and use binary search to check if the target is in this part, if the target out of this part we
       need to do binary search in another part.(If find the target in first BS just return the answer.)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
                       0 1 2 3 4 5 6 7  
                       l
            nums    = [4,5,6,7,8,0,1,2]
                               l m   r
            target  = 8
            ------------------------------
                       0 1 2 3 4  
                       l
            nums    = [5,1,2,3,4]
                       m r
            target  = 1        
            ------------------------------
                       0 1 2   
                       l
            nums    = [2,3,1]
                         m r
            target  = 1  
            -------------------------------
                       0 1 2 3 4   
                             l
            nums    = [2,3,4,5,1]
                             m r
            target  = 1 
        */
        if(nums.size()<2){
            return nums[0]==target?0:-1;
        }
        if(nums.size()<3){
            if(nums[0]==target) return 0;
            else if(nums[1]==target) return 1;
            else return -1;
        }
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return m;
            if(nums[l]<=nums[m]){
                if(nums[l]<=target&&nums[m]>target){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(nums[m]<target&&nums[r]>=target){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }
        return -1;
    }
};