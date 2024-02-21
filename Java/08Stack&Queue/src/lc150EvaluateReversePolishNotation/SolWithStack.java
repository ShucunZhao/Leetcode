package lc150EvaluateReversePolishNotation;
import java.util.Stack;
import java.util.Scanner;

public class SolWithStack {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter tokens with format [\"xx\",\"xx\",\"xx\"]:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            for(int i=0;i<InSet.length;++i){
                InSet[i] = InSet[i].substring(1, InSet[i].length()-1);
            }
            System.out.println("Res: "+S1.evalRPN(InSet));
        }
    }
    private static class Solution{
        public int evalRPN(String[] tokens) {
            /*
                    Input: tokens = ["2","1","+","3","*"]   Output: 9
                    Explanation: ((2 + 1) * 3) = 9
             */
            int ans = 0;
            int left, right;
            Stack<Integer> st = new Stack<>();
            for(String str : tokens){
                if(str.equals("+")){
                    right = st.pop();
                    left = st.pop();
                    st.push(left+right);
                }
                else if(str.equals("-")){
                    right = st.pop();
                    left = st.pop();
                    st.push(left-right);
                }
                else if(str.equals("*")){
                    right = st.pop();
                    left = st.pop();
                    st.push(left*right);
                }
                else if(str.equals("/")){
                    right = st.pop();
                    left = st.pop();
                    st.push(left/right);
                }
                else{
                    st.push(Integer.parseInt(str));
                }
            }
            return st.pop();
        }
    }
}
