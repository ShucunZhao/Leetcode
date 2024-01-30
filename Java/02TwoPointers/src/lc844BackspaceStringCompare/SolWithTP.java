package lc844BackspaceStringCompare;
import java.util.Scanner;

public class SolWithTP {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter String s: ");
            String s = scan.nextLine();
            System.out.println("Enter String t: ");
            String t = scan.nextLine();
            if(s.equals("exit")||t.equals("exit")){
                System.out.println("Quit.");
                break;
            }
            System.out.println("Res: "+S1.backspaceCompare(s,t));
        }

    }
    private static class Solution{
        public boolean backspaceCompare(String s, String t){
            /*
                O(N) time.
                Solution: convert the string to without # and compare if equals.
                O(1) space: we can use fast and slow pointer to modify original strings.
                     but in java need to use the StringBuilder or StringBuffer to generate
                     changeable string so the space is O(n)
                    sb: ab
                                  s
                                  f
                    Input: s = "ab#c", t = "ad#c"        Output: true
                    --------------------------------------------------
                                s
                    Input: s = "ab##", t = "c#d#"        Output: true
                                                f
                                 s
                           s = "a##c"   t = "#a#c"
                                 f
                           sb:
                                                 s
                           s = "y#fo##f"    t = "y#f#o##f"
                                                       f
             */
            return getStr(s).equals(getStr(t));
        }
        public String getStr(String In){
            StringBuilder sb = new StringBuilder();
            int s=0,f=0;
            for(;f<In.length();++f){
                if(In.charAt(f)=='#'&&s!=0){
                    s--;
                    sb.deleteCharAt(s);
                }
                else{
                    sb.append(In.charAt(f));
                    ++s;
                }
            }
            int i=0;
            while(i<sb.length()&&sb.charAt(i)=='#'){
                sb.deleteCharAt(i);
                ++i;
            }
            String res = sb.toString();
            System.out.println(In+"->"+res);
            return res;
        }
    }
}
