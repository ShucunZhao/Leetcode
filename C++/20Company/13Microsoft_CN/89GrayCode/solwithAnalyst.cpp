class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        while(n--){
            for(int i=ans.size()-1;i>=0;i--){
                ans[i]<<=1;
                ans.push_back(ans[i]+1);
            }
        }
        return ans;
    }
};