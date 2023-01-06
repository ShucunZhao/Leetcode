class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int i=0;i<height.size();i++){
            if(i==0||i==height.size()-1) continue;
            int lH = height[i];
            int rH = height[i];
            for(int l=i-1;l>=0;l--){
                lH = max(lH, height[l]);
            }
            for(int r=i+1;r<height.size();r++){
                rH = max(rH, height[r]);
            }     
            int h = min(lH, rH) - height[i];
            if(h>0){
                ans+=h;
            }
        }
        return ans;
    }
};