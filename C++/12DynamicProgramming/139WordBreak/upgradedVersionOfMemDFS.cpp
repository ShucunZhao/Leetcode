class Solution {
public:
    map<string, bool> ms;
    bool dfs(string s, unordered_set<string>& wordSet){
        if(ms.count(s)){
            return ms[s];
        }
        if(s==""){
            return true;
        }
        bool rst = false;
        for(int i=0;i<s.size();i++){
            if(wordSet.count(s.substr(0, i+1))!=0){
                //string str = s.substr(i, s.size()-i+1);
                //cout<<s.substr(0, i)<<endl;
                //return 1&&dfs(s.substr(i+1), wordSet);Cannot use && here because the for loop may traverse the whole string to find a case that is true
                rst = rst||dfs(s.substr(i+1), wordSet);//So we need to use || instead.
                if(rst){
                    ms[s] = 1;
                    break;
                }
                else{
                    ms[s] = 0;
                } 
            }
        }
        return rst;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(string str : wordDict){
            wordSet.insert(str);
        }
        return dfs(s, wordSet);
    }
};