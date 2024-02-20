package lc151ReverseWordsInAString;
import java.util.Scanner;

public class SolWithTwoPointers {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s:");
            String s = scan.nextLine();
            if(s.equals("q")){
                break;
            }
            System.out.println("Res: "+S1.reverseWords(s));
        }
    }
    private static class Solution{
        public String reverseWords(String s) {
            /*
                                 l
                Input: s = "the sky is blue"    Output: "blue is sky the"
                                     r
                      l
                trim: eulb   si yks eht
                          r
                res:  blue is sky the

                  the    sky   is blue
             */
            String trim = s.trim();
            StringBuilder sbd = new StringBuilder(trim);
            sbd.reverse();
            int l=0,r=0;
            while(r<sbd.length()){
                while(r<sbd.length()&&sbd.charAt(r)!=' '){
                    r++;
                }
                reverse(sbd,l,r-1);
                l = r+1;
                if(r+1<sbd.length()&&sbd.charAt(r+1)==' ') {
                    r++;
                    while (r < sbd.length() && sbd.charAt(r) == ' ') r++;
                    if(r<sbd.length()) {
                        sbd.delete(l, r);
                    }
                    r = l;
                }
                else{
                    r = r+1;
                }
            }
//            reverse(sbd,l,r-1);
            return sbd.toString();
        }
        public void reverse(StringBuilder sbd, int l, int r){
            while(l<=r){
                char c = sbd.charAt(l);
                sbd.setCharAt(l, sbd.charAt(r));
                sbd.setCharAt(r,c);
                l++;
                r--;
            }
        }
    }
}
