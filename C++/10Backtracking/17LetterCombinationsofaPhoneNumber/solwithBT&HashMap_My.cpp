class Solution {
public:
    string path;
    vector<string> ans;
    void backtracking(string & digits, unordered_map<char, string> & ms, int start){
        if(path.size()==digits.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<digits.size();i++){
            for(char c : ms[digits[i]]){
                path.push_back(c);
                backtracking(digits, ms, i+1);
                path.pop_back();
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char, string> ms;
        ms['2'] = "abc";
        ms['3'] = "def";
        ms['4'] = "ghi";
        ms['5'] = "jkl";
        ms['6'] = "mno";
        ms['7'] = "pqrs";
        ms['8'] = "tuv";
        ms['9'] = "wxyz";
        backtracking(digits, ms, 0);
        return ans;
    }
};