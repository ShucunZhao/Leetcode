class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*
            Sol with prefix sum and same remainder theory:
            k: 5
              i         0 1 2  3  4 5 
            nums       [4,5,0,-2,-3,1]
            prefix      4 9 9  7  4 5   
            (x/k)mod    4 4 4  2  4 0
            ans = C4^2 : chooses 2 combination from 4 elements group.

            [-1,2, 9]     k:2
             -1 1 10
             -1 1  0

             [2,-2,2,-4]  k:6
              2  0 2 -2
              2  0 2  2

              [8,  9,  7,  8,  9] k:8
               8  17  24  32   41
               0  1   0   0    1 
               1+6
         */
        vector<int> prefix(nums.size());//Prefix sum and we use this same array to store the mod.
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
            //KeyPoint here! Convert the negative mod into positive:
            prefix[i-1] = (prefix[i-1]%k+k)%k;
            //prefix[i-1]%=k;
        }
        prefix[nums.size()-1] = (prefix[nums.size()-1]%k+k)%k;
        /*
        for(int i : prefix) cout<<i<<",";
        cout<<endl;
        */
        int ans = 0;
        unordered_map<int, int> ms;
        for(int i : prefix){
            if(i==0) ans+=1;
            ms[i]++;
        }
        // for(auto x : ms) cout<<x.first<<":"<<x.second<<endl;
        for(auto x : ms){
            if(x.second>1){
                int n = x.second;
                ans+=(n*(n-1))/2;
            }
        }
        return ans;
    }
};