class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ms; 
        int hash[1000] = {0};
        for(int i : nums2){
            hash[i]++;
        }
        for(int j : nums1){
            if(hash[j]!=0){
                ms.insert(j);
            }
        }
        return vector<int>(ms.begin(), ms.end());
    }
};