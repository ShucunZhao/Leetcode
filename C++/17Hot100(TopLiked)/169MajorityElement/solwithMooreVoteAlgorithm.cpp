class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            nums = [2,2,1,1,1,2,2]
            [3,2,3]
            candidate: 3
            votes:  2
        */
        int candidate = nums[0], votes = 0;
        for(int i : nums){
            if(i==candidate){
                votes++;
            }
            else{
                if(votes==0){
                    candidate = i;
                }
                else{
                    votes--;
                } 
            }
        }
        return candidate;
    }
};