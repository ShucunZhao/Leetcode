class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*
            ansI:
            ansV:6,9
            nextI: 4,3,5,6, 8
            nextV: 9,7,3,10,
             0 1 2 3 4 5 6 7 8 9  
            [5,4,3,7,5,6,6,9,9,10]

            [1,2,3,4,3,2,7,8]
        */
        unordered_set<int> mset;
        // vector<int> ans;
        int nextV, nextI;
        for(int i=0;i<nums.size();){
            // if(mset.count(nums[i])){
            //     i++;
            //     continue;
            // }
            nextI = nums[i]-1;//3,2
            nextV = nums[nextI];//7,2
            if(nextI==i){
                i++;
            }
            else if(nextV==nums[i]){
                // ans.push_back(nextV);
                mset.insert(nextV);
                i++;
            }
            else{
                swap(nums[i], nums[nextI]);
            }
        }
        // cout<<"nums:";
        // for(int i : nums) cout<<i<<",";
        // cout<<endl;
        // cout<<"mset:";
        // for(int i : mset) cout<<i<<",";
        // cout<<endl;       
        vector<int> ans(mset.begin(), mset.end()); 
        return ans;
    }
};