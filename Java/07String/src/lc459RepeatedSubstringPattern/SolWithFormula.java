package lc459RepeatedSubstringPattern;
import java.util.Scanner;

public class SolWithFormula {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s: ");
            String s = scan.nextLine();
            if(s.equals("q")) break;
            System.out.println("Res: "+S1.repeatedSubstringPattern(s));
        }
    }
    private static class Solution{
        public boolean repeatedSubstringPattern(String s) {
            /*
                    "abab"
             */
            StringBuilder sbd = new StringBuilder(s+s);
            sbd.deleteCharAt(0);
            sbd.deleteCharAt(sbd.length()-1);
            String newS = sbd.toString();
            return newS.contains(s);
        }
    }
}
