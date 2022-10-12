/*
 * You can simply this question into two for loop which time complexity is 2n^2
 * by divide it into two sum question and use the hash map to search the target.
 */
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
        int find;
        for(int k : nums3){
            for(int l : nums4){
                find = 0-k-l;
                if(ms.count(find)==1){
                    ans+=ms[find];
                }
            }
        }
        return ans;
    }
};