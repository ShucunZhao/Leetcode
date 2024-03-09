package lc78Subsets;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithBacktracking {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter nums:");
            String M = scan.nextLine();
            if(M.equals("q")) break;
            M = M.substring(1, M.length()-1);
            String[] Ms = M.split(",");
            int[] nums = new int[Ms.length];
            for(int i=0;i<nums.length;++i){
                nums[i] = Integer.parseInt(Ms[i].trim());
            }
            List<List<Integer> > res = S1.subsets(nums);
            System.out.print("Res: [");
            for(int i=0;i<res.size();++i){
                System.out.print("[");
                for(int j=0;j<res.get(i).size();++j){
                    System.out.print(res.get(i).get(j)+",");
                }
                System.out.print("],");
            }
            System.out.println("]");
        }
    }

    private static class Solution{
        List<Integer> path = new ArrayList<>();
        List<List<Integer> > ans = new ArrayList<>();
        public List<List<Integer>> subsets(int[] nums) {
            ans.add(new ArrayList<>());
            backtracking(nums, 0);
            return ans;
        }
        public void backtracking(int[] nums, int start){
            if(start==nums.length){
                return;
            }
            for(int i=start;i<nums.length;++i){
                path.add(nums[i]);
                ans.add(new ArrayList<>(path));
                backtracking(nums, i+1);
                path.remove(path.size()-1);
            }
            return;
        }
    }
}
