class Solution {
public:
    string path;
    vector<string> ans;
    string Map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//Map string: use for mapping the phone numbers
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        backtracking(digits,0);
        return ans;
    }
    void backtracking(string & digits, int start){
        if(start>digits.size()){
            return;
        }
        if(path.size()==digits.size()){
            ans.push_back(path);
            return;
        }
        int index = digits[start]-'0';
        string str = Map[index];
        for(int i=0;i<str.size();i++){
            path.push_back(str[i]);
            backtracking(digits, start+1);
            path.pop_back();
        }
        return;
    }
};