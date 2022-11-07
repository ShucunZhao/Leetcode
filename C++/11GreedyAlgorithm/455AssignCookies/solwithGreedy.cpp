class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int index = s.size() - 1;
        for(int i = g.size()-1; i>=0; i--){
            if(index>=0&&s[index]>=g[i]){
                ans++;
                index--;
            }
            if(index<0){
                break;
            }
        }
        return ans;
    }
};