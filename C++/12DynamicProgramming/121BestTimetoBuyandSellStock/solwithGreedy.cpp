class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int ans = 0;
        int minP = prices[0];
        for(int i=1;i<prices.size();i++){
            ans = max(ans, prices[i]-minP);
            minP = min(minP, prices[i]);
        }   
        return ans;
    }
};