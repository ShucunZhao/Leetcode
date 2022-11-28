class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<3){
            return fruits.size();
        }
        unordered_map<int, int> ms;
        int ans = INT_MIN;
        for(int l=0,r=0;r<fruits.size();r++){
            ms[fruits[r]]++;
            while(ms.size()>2){
                ms[fruits[l]]--;
                if(ms[fruits[l]]==0){
                    ms.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};