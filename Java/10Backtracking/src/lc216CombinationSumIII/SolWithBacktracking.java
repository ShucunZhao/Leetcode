package lc216CombinationSumIII;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SolWithBacktracking {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while (true) {
            Solution S1 = new Solution();
            System.out.println("Enter n:");
            String N = scan.nextLine();
            if (N.equals("q")) break;
            System.out.println("Enter k:");
            String K = scan.nextLine();
            if (K.equals("q")) break;
            int n = Integer.parseInt(N.trim());
            int k = Integer.parseInt(K.trim());
            List<List<Integer>> res = S1.combinationSum3(n, k);
            System.out.print("Res: [");
            for (int i = 0; i < res.size(); ++i) {
                System.out.print("[");
                for (int j = 0; j < res.get(i).size(); ++j) {
                    System.out.print(res.get(i).get(j) + ",");
                }
                System.out.println("],");
            }
            System.out.println("]");
        }
    }
    private static class Solution {
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer> > ans = new ArrayList<>();
        public List<List<Integer>> combinationSum3(int k, int n) {
            backtracking(1,k,n,0);
            return ans;
        }
        public void backtracking(int start, int k, int n, int sum){
            if(tmp.size()==k){
                if(sum==n){
                    ans.add(new ArrayList<>(tmp));
                }
                return;
            }
            for(int i=start;i<=9;++i){
                sum+=i;
                tmp.add(i);
                backtracking(i+1, k, n, sum);
                sum-=i;
                tmp.remove(tmp.size()-1);
            }
        }
    }
}
