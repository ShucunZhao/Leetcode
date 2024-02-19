package lc541ReverseStringIl;
import java.util.Scanner;

public class SolWithFormula {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s:");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            System.out.println("Enter k:");
            String K = scan.nextLine();
            if(K.equals("q")){
                break;
            }
            int k = Integer.parseInt(K);
            System.out.println("Res: "+S1.reverseStr(In,k));
        }
    }
    private static class Solution{
        public String reverseStr(String s, int k) {
            /*
                Input: s = "abcdefg x", k = 2 Output: "bacdfeg"
                                i
                Input: s = "abcdefgh", k = 3 Output: "cbadefhg"

             */
            char[] chars = s.toCharArray();
            int m = chars.length;
            int i=0;
            for(;i<m;i+=2*k){
                if(i+2*k>=m){
                    if (m - i > k) {
                        reverse(chars, i, i + k - 1, m);
                    } else {
                        reverse(chars, i, m - 1, m);
                    }
                }
                else{
                    reverse(chars, i, i+k-1, m);
                }
            }
            return new String(chars);
        }
        public void reverse(char[] chars, int l, int r, int m){
            for(;l<=r&&l<m&&r<m;l++,r--){
                char tmp = chars[l];
                chars[l] = chars[r];
                chars[r] = tmp;
            }
        }
    }
}
