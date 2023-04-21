class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        /*
                    0   1   2
            nums = [1,  2,  1]
            ans:    1   2  -1
            In: |2|base.
        */
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop(); 
            }
            st.push(i);
        }
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop(); 
            }
        }
        return ans;
    }
};