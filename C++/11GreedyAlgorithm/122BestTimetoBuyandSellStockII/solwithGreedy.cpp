class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int tmp;
        for(int i=1; i<prices.size(); i++){
            tmp = prices[i]-prices[i-1];
            if(tmp>0){
                ans+=tmp;
            }
        }
        return ans;
    }
};