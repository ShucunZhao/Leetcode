class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms, mt;
        for(int i=0;i<s.size();i++){
            if(ms.count(s[i])==0){
                ms[s[i]] = t[i];
            }
            if(mt.count(t[i])==0){
                mt[t[i]] = s[i];
            }
            if(ms[s[i]]!=t[i]||mt[t[i]]!=s[i]) return 0;
        }
        return 1;
    }
};