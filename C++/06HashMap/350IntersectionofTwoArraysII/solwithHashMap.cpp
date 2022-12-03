class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ms, mt;
        for(int i : nums2){
            mt[i]++;
        }
        for(int j : nums1){
            if(mt[j]>0){
                mt[j]>ms[j]?(ms[j]++):(ms[j]=mt[j]);//Key Point: U must take the lesser one in this two hash map which
                                                    //represent the intersection.
            }
        }
        vector<int> ans;
        for(auto x : ms){
            for(int k=0;k<x.second;k++){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};