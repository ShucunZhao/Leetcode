class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
                     j
                     i
            nums  = [1,1,1]
            preSum:  1 2 3
            sum[num[i],num[j]] = k
            sum[0, j] - sum[0, i-1] = k
            sum[0, j] - k = sum[0,i-1]: ans++
        */
        // vector<int> prefixSum(nums.size());
        // prefixSum[0] = nums[0];
        int ans = 0;
        unordered_map<int, int> ms;
        int prefixSum = 0;
        // if(prefixSum[0]==k) ans++;
        // ms[nums[0]]++;// 1: 1
        ms[0]++;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];//1,3,6
            if(ms.count(prefixSum-k)){//-2,
                ans+=ms[prefixSum-k];//1
            }
            ms[prefixSum]++;//1:1,3:1,
        }
        /*
        for(int i : prefixSum) cout<<i<<",";
        cout<<endl;
        */
        return ans;
    }
};