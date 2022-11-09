class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a'] = i; 
        }
        int start=0, end=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            end = max(end, hash[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};