package lc70ClimbingStairs;

import java.util.Scanner;

public class SolWithDP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please input n: ");
            String numsIn = scan.nextLine();
            if(numsIn.equals("q")){
                System.out.println("Quit.");
                break;
            }
            int n = Integer.parseInt(numsIn.trim());
            System.out.println("Result: "+S1.climbStairs(n));
        }
    }
    private static class Solution{
        public int climbStairs(int n) {
            /*
                 1. Meaning: dp[i]: the number of ways to get stair i; index i: the stair
                 2. Formula: dp[i] = dp[i-1] + dp[i-2]
                 3. Initial: dp[0] = 0; dp[1] = 1; dp[2] = 2;
                 4. Traverse: From front to back
             */
            if(n<2) return n;
            int dp[]  = new int[n+1];
            dp[1] = 1;
            dp[2] = 2;
            for(int i=3;i<dp.length;++i){
                dp[i] = dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
    }
}