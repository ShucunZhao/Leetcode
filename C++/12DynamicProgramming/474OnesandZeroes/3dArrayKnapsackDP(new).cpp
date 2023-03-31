class Solution {
public:
    int countZero(string & str){
        int cnt = 0;
        for(char c : str){
            if(c=='0'){
                cnt++;
            }
        }
        return cnt;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*
            dp[i][j][k]: choose the first i strings(objs) to fill the 0 knapsack whose size is j and 
                         1 knapsack whose size is k. And the size j should <=m while size k <=n.

            dp[i][j][k] =  if sum(0)<=j&&sum(1)<=k:
                            dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-sum(0)][k-sum(1)]+1);
            Need to initial dp[0][j][k]......
             strs = ["10","0001","111001","1","0"], m = 5, n = 3

            objs:                 0 1 2 3 4 5 
                                0 0 1 1 1 1 1
                                1
                                2
                                3
                "10"    :  
                0:1, 1:1      
                "0001"  :
                "111001":
                "1"     :
                "0"     :
        */
        vector<vector<vector<int> > > dp(strs.size(), vector<vector<int> >(m+1, vector<int>(n+1, 0)));
        int firstZero = countZero(strs[0]);//1
        int firstOne = strs[0].size() - firstZero;//1
        cout<<"firstZero:"<<firstZero<<",firstOne:"<<firstOne<<endl;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i>=firstZero&&j>=firstOne){//11
                    dp[0][i][j] = 1;
                }
            }
        }
        for(int i=1;i<strs.size();i++){
            int zero = countZero(strs[i]);
            int one = strs[i].size()-zero;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(zero<=j&&one<=k){
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero][k-one]+1);
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()-1][m][n];
    }
};