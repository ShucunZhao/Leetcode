class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
            nums1 = [4,1,2], nums2 = [1,3,4,2]
            ms:
                key is value of nums1, and value is index of nums1:
                4: 0
                1: 1
                2: 2
            we need to use monotonic stack to traverse nums2 and find each elements' 
            next larger value, if this element is exist in nums1 we add it into ans.

            In: |,3|base
            ans: -1   3  -1 
                  0   1   2
        */
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> ms;
        for(int i=0;i<nums1.size();i++){
            ms[nums1[i]] = i;
        }
        stack<int> st;
        for(int j=0;j<nums2.size();j++){
            while(!st.empty()&&nums2[j]>st.top()){
                if(ms.count(st.top())){
                    ans[ms[st.top()]] = nums2[j];
                }
                st.pop();
            }
            st.push(nums2[j]);
        }
        return ans;
    }
};