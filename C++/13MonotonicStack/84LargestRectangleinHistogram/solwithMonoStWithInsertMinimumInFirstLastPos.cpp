class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
                            heights = [2,1,5,6,2,3]
    insert first position and last positon the value '-1' for initial egde: 
                            heights = [-1,2,1,5,6,2,3,-1]
                                i:      0 1 2 3 4 5 6, 7

                AscendingSt: In:  7 | 6,5,2,0|base.
                cur = (2-0-1)*heights[i] = 1*2 =2;
                ans = max()
        --------------------------------------------------------------------
                            heights = [-1,2,4,-1]
                                i:      0 1 2  3 
                AscendingSt: In:   | 2,1,0|base.
                ans = 
        */
        heights.insert(heights.begin(), -1);
        heights.insert(heights.end(), -1);
        //cout<<heights[0]<<","<<heights[heights.size()-1];
        int ans = 0;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            // if(heights[i]==-1){
            //     continue;
            // }
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int mid = st.top();//1,4,3,6
                st.pop();
                int left=0;
                if(!st.empty()){
                    left = st.top();//3,2,5
                }
                int H = heights[mid];//5
                int W = i-left-1;//
                ans = max(ans, H*W);//2,6,10
            }
            st.push(i);
        }
        return ans;
    }
};