class Solution {
public:
    string minWindow(string s, string t) {
        /*
            Ans: ADOBEC,DOBECODEBA,CODEBA,ODEBANC,BANC
                           r
                      l
            s = "ADOBECODEBANC", t = "ABC"
                                mt:  A:1
                                     B:1
                                     C:1
                             cntT:  3(types) 
            cnt: 3
            ms: A:1 == mt[A] so cnt++
                B:1 == mt[A] so cnt++
                C:1 == mt[A] so cnt++
                A:0 erase(A) so cnt--
                B:2 > mt[A] so cnt do nothing
                A:1 == mt[A] so cnt++
                B:1 == mt[A] so cnt do nothing
                C:0 erase(C) so cnt--
                C:1 == mt[A] so cnt++
        */
        unordered_map<char, int> ms, mt;
        for(char c : t){
            mt[c]++;
        }
        int cntT = mt.size();//3
        int cntM = 0;
        int ansI = 0, anslen = INT_MAX;
        for(int l=0,r=0;r<s.size();r++){
            if(mt.count(s[r])){//
                ms[s[r]]++;//A:1,A:1 B:1,A:1 B:1 C:1,
                if(ms[s[r]]==mt[s[r]]){//cntM:3
                    cntM++;
                }
            }
            while(cntM==cntT){
                if(r-l+1<anslen){
                    ansI = l;
                    anslen = r-l+1;
                }
                if(ms.count(s[l])){
                    ms[s[l]]--;
                    if(ms[s[l]]<mt[s[l]]){
                        cntM--;
                    }
                }
                l++;
            }
        }
        return anslen==INT_MAX?"":s.substr(ansI, anslen);
    }
};