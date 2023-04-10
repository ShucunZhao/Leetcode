class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
            nums = [2,6,4,8,10,9,15]
            max: 15
            end: 5
                                             end
                   [2,  6,  4,  8,  10,  9,  15]
            -------------------------------------       
            min: 2
            begin: 1 
                       begin
                   [2,  6,  4,  8,  10,  9,  15]       
        */
        if(nums.size()<2) return 0;
        int min = INT_MAX, max = INT_MIN;
        int begin = -1, end = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=max){
                max = nums[i];
            }
            else{
                end = i;
            }
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]<=min){
                min = nums[j];
            }
            else{
                begin = j;
            }
        }
        return end==begin?0:end-begin+1;
    }
};