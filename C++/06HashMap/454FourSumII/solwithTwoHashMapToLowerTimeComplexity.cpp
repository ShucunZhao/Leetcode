class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> ms;
        for(int i : nums1){
            for(int j : nums2){
                ms[i+j]++;
            }
        }
        int ans = 0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                if(ms.count(-nums3[i]-nums4[j])){
                    ans+=ms[-nums3[i]-nums4[j]];
                }
            }
        }
        return ans;
    }
};