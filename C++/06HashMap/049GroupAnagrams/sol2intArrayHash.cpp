class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > ms;
        stringstream ss;
        int index;
        for(auto s : strs){
            int save[26];
            memset(save, 0, sizeof(save));
            for(auto c : s){
                index = c - 'a';
                // save[index]=save[index]<9?(save[index]+1):(save[index]-1);
                if(save[index]<9){//Prevent the int of index to be double digits.
                                 //Or will be wrong in case ["bdddddddddd","bbbbbbbbbbc"]
                                //Because both of their hash  int array is the same. 
                    save[index]++;
                }
                else{
                    save[index]--;
                }         
            }
            for(int i : save){
                ss<<i;
            }
            ms[ss.str()].push_back(s);
            ss.str("");
        }
        vector<vector<string> > ans;
        for(auto x:ms){
            ans.push_back(x.second);
        }
        return ans;
    }
};