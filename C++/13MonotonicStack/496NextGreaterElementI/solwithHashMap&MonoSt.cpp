class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> ms;
        stack<int> moSt;
        //ms:      [4:0, 1:1, 2:2]
        //nums1:   [4,1,2]
        //i:        0 1 2 3
        //nums2:   [1,3,4,2]
        //ans:     -1,3,-1
        //moSt:    [2
        //          4
        for(int i=0;i<nums1.size();i++){
            ms[nums1[i]] = i;
        }
        moSt.push(0);
        for(int j=1;j<nums2.size();j++){
            if(nums2[j]>nums2[moSt.top()]){
                while(!moSt.empty()&&nums2[j]>nums2[moSt.top()]){
                    if(ms.count(nums2[moSt.top()])!=0){
                        ans[ms[nums2[moSt.top()]]] = nums2[j];
                    }
                    moSt.pop();
                }
                moSt.push(j);
            }
            else{
                moSt.push(j);
            }
        }
        return ans;
    }
};