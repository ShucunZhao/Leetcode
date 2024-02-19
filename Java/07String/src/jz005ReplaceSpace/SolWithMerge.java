package jz005ReplaceSpace;
//import java.util.ArrayList;
//import java.util.List;
import java.util.Scanner;

public class SolWithMerge {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s: ");
            String s = scan.nextLine();
            System.out.println("Res: "+S1.replaceSpace(s));
        }
    }
    private static class Solution{
        public String replaceSpace (String s) {
            // write code here
//            List<Character> list = new ArrayList<>();
            //Use StringBuider to store new string instead of char array list!
            StringBuilder sbd = new StringBuilder();
            for(int i=0;i<s.length();++i){
                char c = s.charAt(i);
                if(c==' '){
                    sbd.append("%20");
                }
                else{
                    sbd.append(c);
                }
            }
            return sbd.toString();
        }
    }
}
