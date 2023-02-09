class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        /*
                 l    
                                    r
            s = "aaaaaaaaaaaabbbbbcdd"
            t = "abcdd"
            mt:  [a:1,b:1,c:1,d:2] mtLen: 4
            cnt: 4
            ms: [a:11,b:5,c:1,d:2]   ans: aaaaaaaaaaaabbbbbcdd
        */
        unordered_map<char, int> ms, mt;
        for(char c : t){
            mt[c]++;
        }
        int mtLen = mt.size();
        int cnt = 0;
        // string ans;//KeyPoint: Cannot use ans to store ans directly, because will cause out of memory error below. 
        int ansLen = INT_MAX;
        int l,r;
        int left;
        for(l=0,r=0;r<s.size();r++){
            ms[s[r]]++;
            if(ms[s[r]]==mt[s[r]]){
                cnt++;
            }
            while(cnt==mtLen){
                // cout<<"l:"<<l<<","<<"r:"<<r<<endl;
                if(r-l+1<ansLen){
                    ansLen = r-l+1;
                    left = l;
                    //ans = s.substr(l, ansLen);////KeyPoint: Cannot store ans answer string every update time, 
                    //should use record the index and length instead. 
                }
                ms[s[l]]--;
                if(mt[s[l]]>0&&ms[s[l]]<mt[s[l]]){
                    cnt--;
                }
                l++;
            }
        }
        return ansLen==INT_MAX?"":s.substr(left, ansLen);
    }
};