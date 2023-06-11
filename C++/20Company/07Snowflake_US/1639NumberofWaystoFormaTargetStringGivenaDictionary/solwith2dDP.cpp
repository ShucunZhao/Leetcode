class Solution {
public:
    int numWays(vector<string>& words, string target) {
        /*
            words = ["acca","bbbb","caca"], target = "aba"
            vec: vector<vector<char>> ?
                0: a:1,b:1,c:1
                1: c:1,b:1,a:1
                2: c:2,b:1
                3: a:2,b:1

            dp[k][i]: the number of ways that use the first i chars from words to construct 
                      the first k target chars.
            case1: do not use the No.i character of word:
                dp[k][i] = dp[k][i-1];
            case2: use the No.i character of word:
                dp[k][i] = dp[k-1][i-1] * (the number of cases in current pos)
            To sum up:
                dp[k][i] =  dp[k][i-1] + dp[k-1][i-1] * vec[i].

            Initialization:
                dp[0][x]: to construct a empty string from first x chars in words that means we don't need to choose any char which can be treated as only one case.
                So: dp[0][x] = 1;
                dp[1 to end][0]: means we need to construct a non-empty target by choose nothing from words, which is no any case.
                So: dp[1 t0 end][0] = 0;
        */
        long long mod = 1e9+7;
        vector<vector<long long> > vec(words[0].size(), vector<long long>(26, 0));
        for(int j=0;j<words[0].size();j++){
            for(int i=0;i<words.size();i++){
                vec[j][words[i][j]-'a']++;
            }
        }
        /*
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<26;j++){
                cout<<vec[i][j]<<",";
            }
            cout<<endl;
        }     
        */
        vector<vector<long long> > dp(target.size()+1, vector<long long>(words[0].size()+1));
        for(int k=1;k<=target.size();k++) dp[k][0] = 0;
        for(int i=0;i<=words[0].size();i++) dp[0][i] = 1;
        for(int k=1;k<=target.size();k++){
            for(int i=1;i<=words[0].size();i++){
                // dp[k][i] = (dp[k][i-1] + ((dp[k-1][i-1]*vec[i-1][target[k-1]-'a']) % mod)) % mod;
                dp[k][i] = dp[k][i-1]%mod + dp[k-1][i-1]*vec[i-1][target[k-1]-'a']%mod;
                // dp[k][i] = (dp[k][i-1] + dp[k-1][i-1]*vec[i-1][target[k-1]-'a'])%mod;
                //dp[1][1]: dp[1][0] + dp[0][0]*vec[1][1]
            }
        }
        
        /*
        for(int k=1;k<=target.size();k++){
            for(int i=1;i<=words[0].size();i++){
                // dp[k][i] = dp[k][i-1] + dp[k-1][i-1]*vec[i][target[k]-'a'];
                //dp[1][1]: dp[1][0] + dp[0][0]*vec[1][1]
                cout<<"dp["<<k<<"]["<<i<<"]:"<<dp[k][i]<<endl;
            }
        }    
        */
        
        return dp[target.size()][words[0].size()]%mod;
    }
};