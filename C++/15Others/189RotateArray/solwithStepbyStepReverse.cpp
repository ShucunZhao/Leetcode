class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //nums: [1,2,3,4,5,6,7]
        //      [4,3,2,1,7,6,5]
        //      [5,6,7,1,2,3,4]    
        if(k>=nums.size()){
            k%=nums.size();
        }
        reverse(nums.begin(), nums.begin()+nums.size()-k);
        reverse(nums.begin()+nums.size()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};