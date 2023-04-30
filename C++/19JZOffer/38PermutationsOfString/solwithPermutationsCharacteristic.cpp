class Solution {
public:
    unordered_set<string> ans;
    void backtracking(string str, int index){
        if(index==str.size()-1){
            ans.insert(str);
            return;
        }
        for(int i=index;i<str.size();i++){
            swap(str[i], str[index]);
            backtracking(str, index+1);
            swap(str[i], str[index]);
        }
        return;
    }
    vector<string> Permutation(string str) {
        /*
                     x
            str:   aba

            path: ab
        */
        backtracking(str, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};