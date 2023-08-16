class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            Use monotonic stack to find the first smaller height of rectangle from left and right 
            to get the width, then use the current rect's height to calculate
                0  1 2 3  4
                -1 2 1 2  -1

             st:  0  1     
                 -1  2 
            
            2
            1
            ans: 2, 2 , 2  
        */
        stack<int> st;//stack for storing index of rectangle.
        heights.insert(heights.begin(), -1);
        heights.push_back(-1);
        int ans = 0;
        st.push(0);
        // for(int i : heights) cout<<i<<",";
        // cout<<endl;
        for(int i=1;i<heights.size();i++){
            while(heights[i]<heights[st.top()]){
                int H = heights[st.top()];//4
                st.pop();
                int W = i-st.top()-1;//1,
                ans = max(ans, H*W);
            }
            st.push(i);
        }
        return ans;
    }
};