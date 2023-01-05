class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //i:         0  1  2  3  4  5  6  7  8  9 
        //nums:     [1, 2, 3, 4, 3]
        //ans:       2, 3, 4, -1, 4
        //moSt:     [3  3      
        //           4  4  
        //size: 5, 2*size = 10
        // i%size:  0 1   2  3  4   0  1  2  3  4
        //                
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<2*nums.size();i++){//Use 2*nums.size() to do the circle iteration
            while(!st.empty()&&nums[i%nums.size()]>nums[st.top()]){//Use i%nums.size() as index to do the circle iterative.
                ans[st.top()] = nums[i%nums.size()];
                st.pop();
            }
            st.push(i%nums.size());
        }
        return ans;
    }
};