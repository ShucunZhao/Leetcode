class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int l = i, r = i;
            for(;l>=0;l--){
                if(heights[l]<heights[i]) break;
            }
            for(;r<heights.size();r++){
                if(heights[r]<heights[i]) break;
            }
            int w = r-l-1;
            ans = max(ans, w*heights[i]);
        }
        return ans;
    }
};