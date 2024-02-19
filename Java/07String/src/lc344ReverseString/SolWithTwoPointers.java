package lc344ReverseString;
import java.util.Scanner;

public class SolWithTwoPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter char[] s with format: [\"x\", \"x\"]:");
            String In = scan.nextLine();
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            char[] s = new char[InSet.length];
            for(int i=0;i<InSet.length;++i){
                s[i] = InSet[i].charAt(1);
            }
            S1.reverseString(s);
            System.out.print("Res: [");
            for(char c : s){
                System.out.print("\""+c+"\""+",");
            }
            System.out.println("]");
        }
    }
    private static class Solution{
        public void reverseString(char[] s) {
            for(int l=0,r=s.length-1;l<=r;l++,r--){
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
            }
        }
    }
}
