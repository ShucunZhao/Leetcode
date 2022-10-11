class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        unordered_map<char, int> ms, mt;
        for(int i=0;i<s.length();i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }
        if(ms.size()!=mt.size()){
            return 0;
        }
        else{
            for(int k=0;k<s.length();k++){
                if(ms[s[k]]!=mt[s[k]]){
                    return 0;
                }
            }
        }
        return 1;
    }
};