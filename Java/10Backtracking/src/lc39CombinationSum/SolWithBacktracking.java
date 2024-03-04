package lc39CombinationSum;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithBacktracking {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter the candidates: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            System.out.println("Enter the target: ");
            String T = scan.nextLine();
            if(T.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] Ins = In.split(",");
            int[] candidates = new int[Ins.length];
            for(int i=0;i<Ins.length;++i) candidates[i] = Integer.parseInt(Ins[i]);
            int target = Integer.parseInt(T);
            List<List<Integer> > res = S1.combinationSum(candidates,target);
            System.out.print("Res: [");
            for(int i=0;i<res.size();++i){
                System.out.print("[");
                for(int j=0;j<res.get(i).size();++j){
                    System.out.print(res.get(i).get(j)+",");
                }
                System.out.println("]");
            }
            System.out.println("]");
        }
    }

    private static class Solution{
        List<Integer> path = new ArrayList<>();
        List<List<Integer> > ans = new ArrayList<>();
        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            backtracing(candidates,target,0,0);
            return ans;
        }
        public void backtracing(int[] candidates, int target, int start, int sum){
            if(sum==target){
                ans.add(new ArrayList<Integer>(path));
                return;
            }
            for(int i=start;i<candidates.length;++i){
                if(sum>target){
                    break;
                }
                sum+=candidates[i];
                path.add(candidates[i]);
                backtracing(candidates, target, i, sum);
                sum-=candidates[i];
                path.remove(path.size()-1);
            }
        }
    }
}
