class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         int hash[1001] = {0};
        for(int i : nums1){
            hash[i]++;
        }
        vector<int> ans;
        for(int j : nums2){
            if(hash[j]>0){
                ans.push_back(j);
                hash[j]--;
            }
        }
        return ans;
    }
};