class Solution {
public:
    int numDecodings(string s) {
        /*
            i:   0 1 2 3 4 
            s: " 1 1 1 0 6 "
            dp:  0 0 0 0 0
            dp[i]: the total decode ways in the first i chars of string.
            Inference formula:
            There are two cases:
                case 1: the current pos s[i] is valid which means:
                        '1'=<s[i]<='9', so dp[i] = dp[i-1]
                case 2: the current pos and the previous one can construct a two bits valid which means:
                        '10'=<s[i-1]s[i]<='26', so dp[i] = dp[i-2]
            Initialization:
                dp[0]: 1
        */
        if(s[0]=='0') return 0;
        if(s.size()<2) return 1;
        vector<int> dp(s.size());
        dp[0] = 1;//From s[i]!=0 case we can know should initial dp[0] into 1.
        for(int i=1;i<s.size();i++){
            if(s[i]!='0'){
                dp[i] = dp[i-1];
            }
            if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6'){
                if(i-2>=0){
                    dp[i]+=dp[i-2];
                }
                else{
                    dp[i]++;//This situation is don't need to be infered by dp[i-2], it should only increase itself.
                }
            }
        }
        return dp[s.size()-1];
    }
};