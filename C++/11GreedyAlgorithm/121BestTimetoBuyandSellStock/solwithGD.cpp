class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int high = 0;
        for(int i=1;i<prices.size();i++){
            low = min(low, prices[i-1]);
            high = max(high, prices[i]-low);
        }
        return high;
    }
};