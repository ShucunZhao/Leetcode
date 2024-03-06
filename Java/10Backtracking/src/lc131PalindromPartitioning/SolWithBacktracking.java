package lc131PalindromPartitioning;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithBacktracking {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(true){
            Solution S1 = new Solution();
            System.out.println("Enter s:");
            String S = scan.nextLine();
            if(S.equals("q")) break;
            S = S.substring(1, S.length()-1);
            List<List<String> > res = S1.partition(S);
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
        List<String> path = new ArrayList<>();
        List<List<String> > ans = new ArrayList<>();
        public List<List<String> > partition(String s) {
            /*       i
                s = "aab"
            */
            backtracking(s, 0);
            return ans;
        }
        public boolean isPalin(String s){
            int l = 0, r = s.length()-1;
            while(l<=r){
                if(s.charAt(l)!=s.charAt(r)) return false;
                l++;
                r--;
            }
            return true;
        }
        public void backtracking(String s, int start){
            if(start==s.length()){
                ans.add(new ArrayList<>(path));
                return;
            }
            for(int i=start;i<s.length();++i){
                if(isPalin(s.substring(start, i+1))){
                    path.add(s.substring(start, i+1));
                }
                else{
                    continue;
                }
                backtracking(s, i+1);
                path.remove(path.size()-1);
            }
        }
    }
}

