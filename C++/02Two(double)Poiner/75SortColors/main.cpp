class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if(size<2){
            return;
        }
        int i=0,j=0,k=size-1;
        while(j<=k){
            if(nums[j]==2){
                swap(nums[j],nums[k--]);//The key is the j pointer and k pointer only need to move one of them:
                                        //After analyzing we should move the k.
            }
            else if(nums[j]==0){
                swap(nums[j++],nums[i++]);
            }
            else{
                j++;
            }
        }
    }
};