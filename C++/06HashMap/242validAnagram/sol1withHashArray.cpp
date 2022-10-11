class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        int save[26] = {0};
        for(int i=0;i<s.size();i++){
            save[s[i]-'a']++;
        }
        for(int j=0;j<t.size();j++){
            save[t[j]-'a']--;
        }      
        for(int k=0;k<26;k++){
            if(save[k]!=0){
                return 0;
            }
        }
        return 1;
    }
};