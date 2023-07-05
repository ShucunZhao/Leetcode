class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
                   
            nums = [7,8,9,11,12]
            i:      0 1 2  3  4

                              
            nums = [1,1]
            i:      0 1 2 3

            4 - 3
            1 - 0
        */   
        for(int i=0;i<nums.size();){
            if(nums[i]<=0){
                i++;
            }
            else{
                if(nums[i]-1==i){
                    i++;
                }
                else if(nums[i]-1<nums.size()){
                    if(nums[i]!=nums[nums[i]-1]){
                        swap(nums[i], nums[nums[i]-1]);
                    }
                    else{
                        i++;
                    }
                }
                else{
                    i++;
                }
            }
        }
        /*
        cout<<"nums:";
        for(int i : nums){
            cout<<i<<",";
        }
        cout<<endl;
        */
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0||nums[i]-1!=i){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};