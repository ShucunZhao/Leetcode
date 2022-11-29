class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> ms;
        int subL = INT_MIN;
        for(int l=0,r=0;r<s.size();r++){
            ms[s[r]]++;//abcb
            if(ms[s[r]]>1){//a:2 b:2 c:2
                // cout<<r-1-l+1<<endl;//3,3,3,
                subL = max(subL, r-1-l+1);// 
                while(ms[s[r]]>1){//
                    ms[s[l]]--;//a:1 b:1,c:1
                    l++;//l:3
                }
            }
            else{
                subL = max(subL, r-l+1);
            }
        }
        return subL==INT_MIN?0:subL;
    }
};