package lc71SimplifyPath;
import java.util.Stack;
import java.util.Scanner;

public class SolWithStack {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string path: ");
            String path = scan.nextLine();
            if(path.equals("q")) break;
            System.out.println("Res: "+S1.simplifyPath(path));
        }
    }
    private static class Solution{
        public String simplifyPath(String path) {
            /*
                    /a/./b/..//../c/d//
                    {c,d
             */
            String[] pSet = path.split("/");
            Stack<String> st = new Stack<>();
            for(String s : pSet){
                if(s.equals("")||s.equals(".")){
                    continue;
                }
                else if(s.equals("..")){
                    if(!st.empty()) st.pop();
                }
                else{
                    st.add(s);
                }
            }
            String ans = "";
            // "/c/d"
            while(!st.empty()){
                ans = "/"+st.pop()+ans;
            }
            return ans==""?"/":ans;
        }
    }
}
