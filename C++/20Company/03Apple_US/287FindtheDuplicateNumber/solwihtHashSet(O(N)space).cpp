class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mset;
        for(int i : nums){
            if(mset.count(i)){
                return i;
            }
            mset.insert(i);
        }
        return -1;
    }
};