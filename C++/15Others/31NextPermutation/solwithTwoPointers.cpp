/*
 * The key point is find the first(shortest distance pairs) nums[j] > nums[i] in nums 
 * array that i is from nums.size()-1 to 1 and j is from j to i and meet j from 
 * nums.size()-1 to 0 at the same time.
 * Rather than just find the first pairs from the last position like nums[i] > nums[j] that i
 * is from nums.size()-1 to 0 and j is from i-1 to 0.
 * then swap this two elements nums[j], nums[i], and sort the elements from i+1 to end. (This step
 * can use reverse the remains element after i because it must obey the descending order.)
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //i:      0 1 2 3 4 5 6
        //nums = [4,2,0,2,3,2,0]
        //       j
        //        i
        //       132
        //       312
        //       
        //Not this traversal way!
        // // cout<<"My:"<<endl;
        // for(int i=nums.size()-1;i>=0;i--){
        //     for(int j=i-1;j>=0;j--){
        //         cout<<"i:"<<i<<"j:"<<j<<endl;
        //         // if(nums[i]>nums[j]){
        //         //     swap(nums[i], nums[j]);
        //         //     reverse(nums.begin()+j+1, nums.end());
        //         //     return;
        //         // }
        //     }
        // }
        // cout<<"New:"<<endl;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                // cout<<"j:"<<j<<"i:"<<i<<endl;
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    reverse(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};