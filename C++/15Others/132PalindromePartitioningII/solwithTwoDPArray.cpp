class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > dp1(s.size(), vector<bool>(s.size(), 0));//This dp is used for checking if string s[i~j] is palindrome.(Same with 647.)
        //s:        "aab"
        //dp1:     a a b
        //     a   1
        //     a     1
        //     b       1
        for(int i=0;i<s.size();i++) dp1[i][i] = 1;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<2){
                        dp1[i][j] = 1;
                    }
                    else{
                        if(dp1[i+1][j-1]){
                            dp1[i][j] = 1;
                        }
                    }
                }
            }
        }
        /*
        // for(int i=0;i<s.size();i++){
        //     for(int j=0;j<s.size();j++){
        //         cout<<"dp1["<<i<<"]"<<"["<<j<<"]:"<<dp1[i][j]<<endl;
        //     }
        // }
        */
        vector<int> dp2(s.size(), INT_MAX);//dp2[i]: The minimum cuts from string s[0~i], the ans should return dp2[s.size()-1].
        dp2[0] = 0;
        for(int i=1;i<s.size();i++){
            if(dp1[0][i]){
                dp2[i] = 0;
                continue;
            }
            for(int j=0;j<i;j++){
                if(dp1[j+1][i]==1){
                    dp2[i] = min(dp2[i], dp2[j]+1);
                }
            }
        }
        return dp2[s.size()-1];
    }
};