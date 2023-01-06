class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int size = heights.size();
        vector<int> lH(size);//dp: The first left smaller element's index from current
        vector<int> rH(size);//dp: The first right smaller element's index from current
        lH[0] = -1;
        rH[size-1] = size;
        //i:             1   2   3   4   5
        //L:         0   1   2
        //heights:  [2,  1,  5,  6,  2,  3]
        //lH:       -1  -1   
        for(int i=1;i<size;i++){
            int L = i-1;
            while(L>=0&&heights[L]>=heights[i]){
                L = lH[L];
            }
            lH[i] = L;
        }
        for(int i=size-2;i>=0;i--){
            int R = i+1;
            while(R<size&&heights[R]>=heights[i]){
                R = rH[R];
            }
            rH[i] = R;
        }
        for(int i=0;i<size;i++){
            ans = max(ans, heights[i]*(rH[i]-lH[i]-1));
        }
        return ans;
    }
};