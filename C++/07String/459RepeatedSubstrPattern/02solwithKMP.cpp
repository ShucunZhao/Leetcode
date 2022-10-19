/*
 * Method2: KMP with judging if the remain unrepeated elements can construct the whole original string.
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<2){
            return 0;
        }
        vector<int> next(s.size(), 0);
        next[0] = 0;
        int j;
        for(int i=1;i<s.size();i++){
            j = next[i-1];
            while(j>0&&s[j]!=s[i]){
                j = next[j-1];
            }
            next[i] = s[j]==s[i] ? j+1 : 0;
        }
        if(next[s.size()-1]!=0&&s.size() % (s.size()-next[s.size()-1])==0){
            return 1;
        }
        else{
            return 0;
        }
    }
};