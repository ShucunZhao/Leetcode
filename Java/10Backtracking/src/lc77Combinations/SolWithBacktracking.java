package lc77Combinations;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SolWithBacktracking {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter n:");
            String N = scan.nextLine();
            if(N.equals("q")) break;
            System.out.println("Enter k:");
            String K = scan.nextLine();
            if(K.equals("q")) break;
            int n = Integer.parseInt(N.trim());
            int k = Integer.parseInt(K.trim());
            List<List<Integer> > res = S1.combine(n,k);
            System.out.print("Res: [");
            for(int i=0;i<res.size();++i){
                System.out.print("[");
                for(int j=0;j<res.get(i).size();++j){
                    System.out.print(res.get(i).get(j)+",");
                }
                System.out.println("],");
            }
            System.out.println("]");
        }
    }

    private static class Solution{
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer> > ans = new ArrayList<>();
        public List<List<Integer>> combine(int n, int k) {
            backtracking(1, n, k);
            return ans;
        }

        public void backtracking(int start, int n, int k){
            if(tmp.size()==k){
                ans.add(new ArrayList<>(tmp));//KeyPoint here! If we only ans.add(tmp) its a shadow copy, we need to deep copy here.
                return;
            }
            for(int i=start;i<=n;++i){
                tmp.add(i);
                backtracking(i+1, n, k);
                tmp.remove(tmp.size()-1);
            }
        }
    }
}
