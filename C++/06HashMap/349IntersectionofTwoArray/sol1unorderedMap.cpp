class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ms, mt;
        for(int i=0;i<nums2.size();i++){
            mt[nums2[i]]++;
        }
        for(int j=0;j<nums1.size();j++){
            if(mt[nums1[j]]>0){
                ms[nums1[j]];
            }
        }
        vector<int> ans;
        for(auto x : ms){
            ans.push_back(x.first);
        }
        return ans;
    }
};