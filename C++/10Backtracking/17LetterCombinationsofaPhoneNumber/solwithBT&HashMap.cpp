class Solution {
public:
    string path;
    vector<string> ans;
    unordered_map<char, string> ms;
    void backtracking(string digits, int start){
        if(path.size()==digits.size()){
            ans.push_back(path);
        }
        string str = ms[digits[start]];
        for(int i=0;i<str.size();i++){
            path.push_back(str[i]);
            backtracking(digits, start+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        for(char c : digits){
            if(c=='2'){
                ms[c] = "abc";
            }
            else if(c=='3'){
                ms[c] = "def";
            }
            else if(c=='4'){
                ms[c] = "ghi";
            }
            else if(c=='5'){
                ms[c] = "jkl";
            }
            else if(c=='6'){
                ms[c] = "mno";
            }
            else if(c=='7'){
                ms[c] = "pqrs";
            }
            else if(c=='8'){
                ms[c] = "tuv";
            }
            else{
                ms[c] = "wxyz";
            }
        }
        backtracking(digits, 0);
        return ans;
    }
};