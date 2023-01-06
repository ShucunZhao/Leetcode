class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        vector<int> lH(size, 0);
        vector<int> rH(size, 0);
        lH[0] = height[0];
        rH[size-1] = height[size-1];
        for(int i=1;i<size;i++){
            lH[i] = max(height[i], lH[i-1]);
        }
        for(int i=size-2;i>=0;i--){
            rH[i] = max(height[i], rH[i+1]);
        }
        for(int i=0;i<size;i++){
            if(i==0||i==size-1) continue;
            int h = min(lH[i-1], rH[i+1]) - height[i];
            if(h>0) ans+=h;
        }
        return ans;
    }
};