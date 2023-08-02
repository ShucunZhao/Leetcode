class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            range: [1, n]: [1,5]
             1 2 3 4 4   
             0 1 2 3 4
            [1,2,3,4,2]
                 i 
        Use the feature of given range, because the range of each elments is from 1 to n,
        so when traversing the whole array we just sawp each element with the element nums[nums[i]-1]
        to make the elements in their own position whose index is nums[i]-1 like sort(smaller one in further ahead) 
        and find if they are duplicate at the same time to get the answer at the same time. 
        */
        for(int i=0;i<nums.size();){
            if(nums[i]-1!=i){
                int nextI = nums[i]-1;//1
                int nextV = nums[nextI];//3
                if(nextV==nums[i]) return nums[i];
                if(i<nextI&&nums[i]>nextV){
                    swap(nums[i], nums[nextI]);
                }
                else if(i>nextI&&nums[i]<nextV){
                    swap(nums[i], nums[nextI]);
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
        // for(int i : nums) cout<<i<<",";
        // cout<<endl;
        return -1;
    }
};