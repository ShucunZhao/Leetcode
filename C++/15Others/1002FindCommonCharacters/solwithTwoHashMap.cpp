/*
 * Use hash map ms to record temporary characters frequency and hash map ans to store answer. 
 * Update ans when iterating the words set to compare with tmp.
 */
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        //words:         ["bella","label","roller"]
        //ans:            b:1 e:1  
        //                l:2 a:1
        //ms:            b:1 e:1   l:2 a:1  r:2 o:1
        //               l:2 a:1   b:1 e:1  l:2 e:1
        vector<string> rst;
        unordered_map<char, int> ms;
        unordered_map<char, int> ans;
        vector<char> del;
        for(char c : words[0]){
            ans[c]++;
        }
        for(int i=1;i<words.size();i++){
            for(char c : words[i]){
                if(ans.count(c)==1) ms[c]++;
            }
            for(auto x : ans){
                if(ms.count(x.first)==0){
                    del.push_back(x.first);
                }
                else{
                    ans[x.first] = min(ans[x.first], ms[x.first]);
                } 
            }
            for(char rem : del){
                ans.erase(rem);
            }
            del.clear();
            ms.clear();
        }
        for(auto x : ans){
            for(int i=0;i<x.second;i++){
                string s(1, x.first);
                rst.push_back(s);
            }
        }
        return rst;
    }
};