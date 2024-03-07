package lc93RestoreIPAddresses;

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
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            List<String> res = S1.restoreIpAddresses(In);
            System.out.print("[");
            for(int i=0;i<res.size();++i){
                System.out.print(res.get(i)+",");
            }
            System.out.println("]");
        }
    }

    private static class Solution{
        List<String> ans = new ArrayList<>();
        int dot = 0;
        public List<String> restoreIpAddresses(String s) {
            /*
                Input: s = "25525511135"
                Output: ["255.255.11.135","255.255.111.35"]
            */
            StringBuilder sbd = new StringBuilder(s);
            backtracking(sbd, 0);
            return ans;
        }
        public boolean isValid(String s){
            if(s.length()<1) return false;
            if(s.length()==1) return true;
            if(s.charAt(0)=='0') return false;
            else if(s.length()>3||Integer.parseInt(s)>255) return false;
            return true;
        }
        public void backtracking(StringBuilder s, int start){
            if(dot==3){
                if(isValid(s.substring(start))){
                    ans.add(new String(s.toString()));
                }
                return;
            }
            for(int i=start;i<s.length();++i){
                if(isValid(s.substring(start, i))){
                    s.insert(i, '.');
                    i++;
                    dot++;
                    backtracking(s, i);
                    dot--;
                    s.deleteCharAt(i-1);
                    i--;
                }
            }
        }
    }
}
