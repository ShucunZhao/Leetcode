class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        st.push(0);
        //i:         0   1   2   3   4   5   6   7
        //heights:  [0,  2,  1,  5,  6,  2,  3,  0]
        //st:       [0  2
        //           0
        for(int i=0;i<heights.size();i++){
            if(!st.empty()&&heights[i]<heights[st.top()]){
                while(!st.empty()&&heights[i]<heights[st.top()]){
                    int mid = st.top();
                    st.pop();
                    ans = max(ans, heights[mid]*(i-st.top()-1));
                }
                st.push(i);
            }
            else {
                st.push(i);
            }
        }
        return ans;
    }
};