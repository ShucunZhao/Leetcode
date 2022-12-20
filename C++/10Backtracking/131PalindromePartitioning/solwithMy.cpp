class Solution {
public:
    vector<string> path;
    vector<vector<string> > ans;
    bool isPalindrome(string & s, int l, int r){
        // cout<<"l:"<<l<<"r:"<<r<<endl;
        for(int i=l,j=r;i<=j;i++,j--){
            // cout<<"s["<<i<<"]:"<<s[i]<<endl;
            // cout<<"s["<<j<<"]:"<<s[j]<<endl;
            if(s[i]!=s[j]) return 0;
        }
        return 1;
    }
    void backtracking(string & s, int start){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s, start, i)){
                // cout<<"tar:"<<s.substr(start,i-start+1)<<endl;
                path.push_back(s.substr(start,i-start+1));
            }
            else{
                continue;
            }
            backtracking(s,i+1);
            // if(flag){
            path.pop_back();
            //     flag = 0;
            // }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};