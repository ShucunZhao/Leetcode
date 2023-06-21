class Solution {
public:
    vector<string> path;
    vector<vector<string> > ans;
    bool isValid(string s, int l, int r){
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void backtracking(string s, int start){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isValid(s,start,i)){
                path.push_back(s.substr(start, i-start+1));
                backtracking(s, i+1);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        /*   
             l
            "aab"
        */
        backtracking(s, 0);
        return ans;
    }
};