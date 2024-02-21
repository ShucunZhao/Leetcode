package lc1047RemoveAllAdjacentDuplicatesInString;
import java.util.Stack;
import java.util.Scanner;

public class SolWithStack {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s: ");
            String s = scan.nextLine();
            if(s.equals("q")) break;
            System.out.println("Res: "+S1.removeDuplicates(s));
        }
    }
    private static class Solution{
        public String removeDuplicates(String s) {
            Stack<Character> st = new Stack<>();
            st.push(s.charAt(0));
            for(int i=1;i<s.length();++i){
                if(st.empty()){
                    st.push(s.charAt(i));
                    continue;
                }
                char cur = s.charAt(i);
                if(st.peek()==cur){
                    st.pop();
                }
                else{
                    st.push(cur);
                }
            }
            char[] chars =  new char[st.size()];
            int i = 0;
            while(!st.empty()){
                chars[i++] = st.pop();
            }
            int l=0,r=chars.length-1;
            while(l<=r){
                char tmp = chars[l];
                chars[l] = chars[r];
                chars[r] = tmp;
                l++;
                r--;
            }
            return new String(chars);
        }
    }
}
