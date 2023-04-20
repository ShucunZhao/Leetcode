class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> ms;
        for(int i=0;i<nums2.size();i++){
            ms[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++){
            int index = ms[nums1[i]];
            while(++index<nums2.size()){
                // cout<<index<<endl;
                if(nums2[index]>nums1[i]){
                    ans[i] = nums2[index];
                    break;
                }
            }
        }
        return ans;
    }
};