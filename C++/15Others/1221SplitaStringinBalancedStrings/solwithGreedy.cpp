class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int R=0,L=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R') R++;
            if(s[i]=='L') L++;
            if(R==L){
                ans++;
                R=0;
                L=0;
            }
        }
        return ans;
    }
};