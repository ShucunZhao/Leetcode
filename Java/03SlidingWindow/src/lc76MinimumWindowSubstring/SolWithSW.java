package lc76MinimumWindowSubstring;
import java.util.HashMap;
import java.util.Scanner;

public class SolWithSW {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s: ");
            String s = scan.nextLine();
            System.out.println("Enter string t: ");
            String t = scan.nextLine();
            if(s.equals("exit")&&t.equals("exit")){
                System.out.println("Quit.");
                break;
            }
            System.out.println("Res: "+S1.minWindow(s,t));
        }
    }
    private static class Solution{
        public String minWindow(String s, String t) {
            /*
                               l
                   Input: s = "AADOBECODEBAANC",   Output: "BANC"
                                     r
                          sM:              curL:
                                l
                           t = "AABC"  tM: (A,2),(B,1),(C,1)  neededL: 3
             */
            int m = s.length(), n = t.length();
            if(n>m) return "";
            int l=0, r=0;
            HashMap<Character, Integer> sM = new HashMap<>();
            HashMap<Character, Integer> tM = new HashMap<>();
            int curL = 0, neededL = 0;
            int res = Integer.MAX_VALUE;
            String ans = "";
            for(int i=0;i<n;++i){
                char c = t.charAt(i);
                if(tM.containsKey(c)){
                    tM.put(c, tM.get(c)+1);
                }
                else{
                    tM.put(c, 1);
                }
            }
            neededL = tM.size();
            while(r<m){
                char rC = s.charAt(r);
                if(sM.containsKey(rC)){
                    sM.put(rC, sM.get(rC)+1);
                }
                else{
                    sM.put(rC, 1);
                }
                /**
                 * KeyPoint why error here!!!
                 * Because the "==" is compare the reference address of object
                 * You need to use equals() function to compare the value(content)
                 *                 if(sM.get(rC)==tM.get(rC)){
                 *                     curL++;
                 *                 }
                 */
                if(sM.get(rC).equals(tM.get(rC))){
                    curL++;
                }
                while(curL>=neededL){
                    if(res>r-l+1){
                        ans = s.substring(l, r+1);
                        res = r-l+1;
                    }
                    char lC = s.charAt(l);
                    sM.put(lC, sM.get(lC)-1);
                    l++;
                    if(tM.containsKey(lC)&&sM.get(lC)<tM.get(lC)) curL--;
                }
                r++;
            }
            return ans;
        }
    }
    private static class Solution2{ //Maybe faster than so1 because record the index rather than whole substring
        public String minWindow(String s, String t) {
            int m = s.length(), n = t.length();
            if (n > m) return "";
            int l = 0, r = 0;
            HashMap<Character, Integer> sM = new HashMap<>();
            HashMap<Character, Integer> tM = new HashMap<>();
            int curL = 0, neededL = 0;
            int ansLen = Integer.MAX_VALUE;
            int left = 0;

            for(int i=0;i<n;++i){
                char c = t.charAt(i);
                if(tM.containsKey(c)){
                    tM.put(c, tM.get(c)+1);
                }
                else{
                    tM.put(c, 1);
                }
            }

            neededL = tM.size();
            while (r < m) {
                char rC = s.charAt(r);
                if(sM.containsKey(rC)){
                    sM.put(rC, sM.get(rC)+1);
                }
                else{
                    sM.put(rC, 1);
                }

                if (sM.get(rC).equals(tM.get(rC))) {
                    curL++;
                }

                while (curL >= neededL) {
                    if (ansLen > r - l + 1) {
                        left = l;
                        ansLen = r - l + 1;
                    }

                    char lC = s.charAt(l);
                    sM.put(lC, sM.get(lC) - 1);
                    l++;

                    if (tM.containsKey(lC) && sM.get(lC) < tM.get(lC)) {
                        curL--;
                    }
                }
                r++;
            }
            return ansLen == Integer.MAX_VALUE ? "" : s.substring(left, left + ansLen);
        }
    }
}
