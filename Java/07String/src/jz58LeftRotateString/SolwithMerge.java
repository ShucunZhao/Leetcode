package jz58LeftRotateString;
import java.util.Scanner;

public class SolwithMerge {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s: ");
            String s = scan.nextLine();
            if(s.equals("q")){
                break;
            }
            System.out.println("Enter n: ");
            String N = scan.nextLine();
            if(N.equals("q")){
                break;
            }
            int n = Integer.parseInt(N);
            System.out.println("Res: "+S1.LeftRotateString(s,n));
        }
    }
    private static class Solution{
        public String LeftRotateString (String str, int n) {
            /*
                "abcXYZdef",3
             */
            int m = str.length();
            if(m==0||n==0||n%m==0) return str;
            if(n>m){
                n%=m;
            }
            char[] chars = new char[m];
            int j = 0;
            for(int i=n;i<m;++i){
                chars[j++] = str.charAt(i);
            }
            int k = 0;
            while(n-->0){
                chars[j++] = str.charAt(k++);
            }
            return new String(chars);
        }
    }
}
