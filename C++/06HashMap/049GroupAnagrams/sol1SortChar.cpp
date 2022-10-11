class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > ms;
        for(auto s : strs){
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            ms[tmp].push_back(s);
        }
        vector<vector<string> > ans;
        for(auto x:ms){
            ans.push_back(x.second);
        }
        return ans;
    }
};