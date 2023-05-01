class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
            s: "badc"   "t =  "baba"
            msStoT: b:b 
                    a:a
                    d:b

            msTtoS: b:b
                    a:a
                    

        */
        unordered_map<char, char> msStoT;
        unordered_map<char, char> msTtoS;
        for(int i=0;i<s.size();i++){
            if(msStoT.count(s[i])){
                if(t[i]!=msStoT[s[i]]) return false;
                else{
                    continue;
                }
            }
            msStoT[s[i]] = t[i];
            if(msTtoS.count(t[i])){
                if(s[i]!=msTtoS[t[i]]) return false;
                else{
                    continue;
                }
            }
            msTtoS[t[i]] = s[i];
        }
        return true;
    }
};