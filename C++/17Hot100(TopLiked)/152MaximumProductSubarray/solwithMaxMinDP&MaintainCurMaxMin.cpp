class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            dp[i]: the max product of subarray from index 0 to i.
            dp[i]: 

                           0   1   2   3  4  
            nums =nums = [ 2, -5  -2  -4  3]
            dp_max:        2  -5  20  8   24 
            dp_min:        2  -10 -2 -80 -320
            ans: 
        */
        vector<int> dpMin(nums.size()), dpMax(nums.size());
        dpMin[0] = nums[0];
        dpMax[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            //Operate max case:
            if(dpMax[i-1]*nums[i]<nums[i]){
                dpMax[i] = nums[i];
            }
            else{
                dpMax[i] = dpMax[i-1]*nums[i];
            }
            if(dpMin[i-1]*nums[i]>nums[i]){
                dpMin[i] = nums[i];
            }
            else{
                dpMin[i] = dpMin[i-1]*nums[i];
            }
            dpMax[i] = max(dpMax[i], dpMin[i-1]*nums[i]);
            dpMin[i] = min(dpMin[i], dpMax[i-1]*nums[i]);
            ans = max(ans, dpMax[i]);
        }
        /*
        cout<<"dpMax: ";
        for(int i=0;i<nums.size();i++){
            cout<<dpMax[i]<<",";
        }
        cout<<endl;
        cout<<"dpMin: ";
        for(int i=0;i<nums.size();i++){
            cout<<dpMin[i]<<",";
        }
        cout<<endl;        
        */
        return ans;
    }
};