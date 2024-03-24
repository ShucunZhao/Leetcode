#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*
            1.dp[i][j]: the number of ways to get pos (i,j), i is row, j is col
            2.if(obstacleGrid[i][j]==0): dp[i][j] = dp[i-1][j]+dp[i][j-1] else: dp[i][j]=0
            3.for(i=0;i<rows;++i) if(once dp[i][0]==1) dp[i][0]=0 else: dp[i][0]=1
              for(j=0;j<cols;++j) if(once dp[0][j]==1) dp[0][j]=0 else: dp[0][j]=1
        */
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while (i < m && obstacleGrid[i][0]==0) {
            dp[i][0] = 1;
            i++;
        }
        while (j < n && obstacleGrid[0][j]==0) {
            dp[0][j] = 1;
            j++;
        }
        for (int i = 1; i<m; ++i) {
            for (int j = 1; j < n;++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter obstacleGrid:" << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<vector<int> > obstacleGrid;
        size_t pos=0;
        while ((pos=In.find("],["))!=string::npos) {
            string row = In.substr(1, pos - 1);
            stringstream ss(row);
            string token;
            vector<int> tmp;
            while (getline(ss, token, ',')) {
                size_t first = token.find_first_not_of(" ");
                size_t last = token.find_last_not_of(" ");
                token = token.substr(first, last - first + 1);
                tmp.push_back(stoi(token));
            }
            In = In.substr(pos+2);
            obstacleGrid.push_back(tmp);
        }
        In = In.substr(1, In.size() - 2);
        stringstream ss(In);
        string token;
        vector<int> tmp;
        while (getline(ss, token, ',')) {
            size_t first = token.find_first_not_of(" ");
            size_t last = token.find_last_not_of(" ");
            token = token.substr(first, last - first + 1);
            tmp.push_back(stoi(token));
        }
        obstacleGrid.push_back(tmp);
        cout << "Res: " << S1.uniquePathsWithObstacles(obstacleGrid)<<endl;
    }
	
}