class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            i       0,1,2,3,4
            nums = [1,3,4,2,2]
            This method is similar to the circle list, use fast and slow pointer and 
            original pointer to find the entry of the circle which is also the duplicate:

        f,s     
        dum 0,1,2,3,4
            1-3-4-2-2
                |___|  ---> this is a circlr!
               x,s,f       
            1 3 2 
            2 4 2 4 2 4 
        */
        int slow=nums[0];//The slow pointer start from the first step.
        int fast=nums[slow];//The fast pointer start from the second step. 
        //cout<<"slow:"<<slow<<",fast:"<<fast<<endl;
        while(slow!=fast){
            slow = nums[slow];//The slow pointer goes 1 step each time.
            fast = nums[nums[fast]];//The fast pointer goes 2 step each time. 
            //cout<<"slow:"<<slow<<",fast:"<<fast<<endl;
        }
        
        int org = 0;
        while(org!=slow){//1!=4
            org = nums[org];//3,2,4,2
            slow = nums[slow];//2,4,2,4
        }
        
        return org;
        //return -1;
    }
};