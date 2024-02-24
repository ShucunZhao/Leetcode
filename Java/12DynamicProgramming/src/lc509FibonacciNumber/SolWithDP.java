package lc509FibonacciNumber;

import java.util.Arrays;
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
            System.out.println("Result: "+S1.fib(n));
        }
    }
    private static class Solution{
        public int fib(int n) {
            /*
                Step1: dp[i]: the current result, index i: the current number
                Step2: formula: dp[i] = dp[i-1]+dp[i-2]
                Step3: initialize: dp[0] = 0, dp[1] = 1
                Step4: traverse: From front to back
             */
            if(n<2) return n;
            int[] dp = new int[n+1];
            dp[0]=0;
            dp[1]=1;
            for(int i=2;i<=n;++i){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
    }
}
