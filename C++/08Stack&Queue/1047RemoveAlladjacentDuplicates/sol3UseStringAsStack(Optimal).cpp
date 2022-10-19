class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(char x : s){
            if(!ans.empty()&&x==ans.back()){
                ans.pop_back();
            }
            else{
                ans.push_back(x);
            }
        }
        return ans;
    }
};