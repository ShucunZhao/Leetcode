package lc62UniquePaths;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWith2dDP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter m:");
            String M = scan.nextLine();
            if(M.equals("q")) break;
            int m = Integer.parseInt(M);
            System.out.println("Enter n:");
            String N = scan.nextLine();
            if(N.equals("q")) break;
            int n = Integer.parseInt(N);
            System.out.println("Res: "+S1.uniquePaths(m,n));
        }
    }

    private static class Solution{
        public int uniquePaths(int m, int n) {
            /*
                1.dp[i][j]: the number of paths in location row i and col j.
                2.dp[i][j] = dp[i-1][j]+dp[i][j-1]
                3.dp[0][x] = 1,dp[x][0]=1
            */
            int[][] dp = new int[m][n];
            for(int i=0;i<m;++i) dp[i][0] = 1;
            for(int j=0;j<n;++j) dp[0][j] = 1;
            for(int i=1;i<m;++i){
                for(int j=1;j<n;++j){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
    }
}
