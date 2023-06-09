class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*

  
                     l   m   r
               i:    0 1 2 3 4      
             nums = [1,3,4,2,2]

            Ues each value as next index from first element in nums that must be a circle exist:
                           s
                        f
             0  1 - 3 - 2 - 4 
                        |___|                    

            So we need to use the circle detect method in linklist to find the entry of circle,
            which is the final answer.
        */
        int slow = nums[0];//1
        int fast = nums[0];//
        while(1){
            slow = nums[slow];//3
            fast = nums[nums[fast]];//2
            if(slow==fast) break;
        }
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        // cout<<fast<<endl;
        return fast;
    }
};