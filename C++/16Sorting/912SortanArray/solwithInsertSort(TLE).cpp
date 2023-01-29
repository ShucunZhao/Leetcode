class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // nums = [5,2,3,1]
        //  o1:    1 2 3 5
        //  o2:    1 2 3 5 
        //3.Insert sort:
        for(int i=0;i<nums.size();i++){
            int preI = i-1;
            int cur = nums[i];
            while(preI>=0&&nums[preI]>cur){
                nums[preI+1] = nums[preI];
                preI--;
            }
            nums[preI+1] = cur;
        }
        /*
        //2.Select sort:
        for(int i=0;i<nums.size()-1;i++){
            int minI = i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[minI]) minI = j;
            }
            if(i!=minI){
                int tmp = nums[i];
                nums[i] = nums[minI];
                nums[minI] = tmp;
            }
        }
        */
        /*
        //1.Bubble sort:
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size()-i;j++){
                if(nums[j]<nums[j-1]){
                    int tmp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        */
        return nums;
    }
};