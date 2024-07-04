#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> ms;
    int numTrees(int n) {
    /*
                    if the n is 5
            we need to count how many trees can be constructed from 1-5
            we can fix the root node then divide the question into how 
            many trees can be constructed from 1 to root-1, and from root+1 to n.
            so the final answer is: dp[root] = dp[root-1]*dp[root+1]
            1.dp[i]: the number of trees can be constrcuted when the n is i
            2. if calculate n:
                for(int i=0;i<n;i++){
                    if(i==0||i==1) dp[i] = 1;
                    else if(i==2) dp[i] = 2;
                    else{
                        for(int j=0;j<i;++j){
                            dp[i]+=(dp[j]*dp[i-j-1]);
                        }
                    }
                }
            3.dp[0] = 1, dp[1] = 1, dp[2] = 2
    */
        if (n <=2) return n;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += (dp[j] * dp[i - j - 1]);
            }
        }
        return dp[n];
    }
    int numTrees2(int n) {
        /*
            sol with memorize dfs
        */
        ms[0] = 1;
        ms[1] = 1;
        ms[2] = 2;
        return dfs(n);
    }
    int dfs(int n) {
        if (ms.count(n)) return ms[n];
        int res = 0;
        /*
                n: 3     --->  res: 3,
        */
        for (int i = 0; i < n; ++i) {
            res += dfs(i) * dfs(n - i - 1);
        }
        ms[n] = res;
        return ms[n];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter n:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        int n = stoi(N);
        cout << "Res: " << S1.numTrees(n) << endl;
    }
}