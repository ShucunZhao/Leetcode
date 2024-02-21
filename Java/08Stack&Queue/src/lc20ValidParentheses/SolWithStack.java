package lc20ValidParentheses;
import java.util.Stack;
import java.util.Scanner;

public class SolWithStack {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s:");
            String s = scan.nextLine();
            if(s.equals("q")) break;
            System.out.println("Res: "+S1.isValid(s));
        }
    }
    private static class Solution{
        public boolean isValid(String s) {
            /*
                Input: s = "()[]{}" Output: true
                {[
             */
            Stack<Character> st = new Stack<>();
            st.push(s.charAt(0));
            for(int i=1;i<s.length();++i){
                char cur = s.charAt(i);
                if(st.empty()){
                    st.push(cur);
                    continue;
                }
                char tmp = st.peek();
                if((tmp=='('&&cur==')')||(tmp=='['&&cur==']')||(tmp=='{'&&cur=='}')){
                    st.pop();
                }
                else{
                    st.push(cur);
                }
            }
            return st.empty();
        }
    }
}
