class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> ms;
        for(int i=tmp.size()-1;i>=0;i--){//Use reverse order to store the index of element from small to large
                                        // can deal with the same elements situation.
            ms[tmp[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            tmp[i] = ms[nums[i]]; 
        }
        return tmp;
    }
};