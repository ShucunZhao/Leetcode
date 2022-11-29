class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> ms, mt;
        for(char c : s1){
            mt[c]++;
        }
        int c1 = mt.size();
        int c2 = 0;
        int lenS = 0;
        for(int l=0,r=0;r<s2.size();r++){
            ms[s2[r]]++;
            lenS++;
            if(ms[s2[r]]==mt[s2[r]]){
                c2++;
            }
            if(c2==c1){
                return 1;
            }
            if(lenS==s1.length()){
                if(ms[s2[l]]==mt[s2[l]]){
                    c2--;
                }
                ms[s2[l]]--;
                lenS--;
                l++;
            }
        }
        return 0;
    }
};