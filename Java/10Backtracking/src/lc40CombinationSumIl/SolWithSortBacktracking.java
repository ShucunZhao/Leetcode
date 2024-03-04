package lc40CombinationSumIl;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithSortBacktracking {
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
            List<List<Integer> > res = S1.combinationSum2(candidates,target);
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
        public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            Arrays.sort(candidates);
            boolean[] used = new boolean[candidates.length];
            backtracing(candidates, target, 0, 0, used);
            return ans;
        }
        public void backtracing(int[] candidates, int target, int start, int sum, boolean[] used){
            if(sum==target){
                ans.add(new ArrayList<Integer>(path));
                return;
            }
            for(int i=start;i<candidates.length;++i){
                if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]!=true){
                    continue;
                }
                if(sum>target){
                    break;
                }
                used[i] = true;
                sum+=candidates[i];
                path.add(candidates[i]);
                backtracing(candidates, target, i+1, sum, used);
                used[i] = false;
                sum-=candidates[i];
                path.remove(path.size()-1);
            }
        }
    }
}
