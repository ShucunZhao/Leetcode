class Solution {
public:
    vector<string> path;
    vector<vector<string> > ans;
    void backtracking(string & s, int start){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            string tmp(s.begin()+start, s.begin()+i+1);//KeyPoint here!
            if(!isPalindrome(tmp)){
                continue;
            }
            path.push_back(tmp);
            backtracking(s, i+1);
            path.pop_back();
        }
        return;
    }
    bool isPalindrome(string & s){
        int l =0;
        int r = s.size()-1;
        for(l,r;l<=r;l++,r--){
            if(s[l]!=s[r]) return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};