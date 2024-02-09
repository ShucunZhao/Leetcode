package lc3LongestSubstringWithoutRepeatingCharacters;
import java.util.HashSet;
import java.util.Scanner;

public class SolWithSW {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please enter the string:");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            System.out.println("Res: "+S1.lengthOfLongestSubstring(In));
        }
    }
    private static class Solution{
        public int lengthOfLongestSubstring(String s) {
            /*
                                 l
                    Input: s = "abcabcbb"       Output: 3   (abc)
                                   r
                    set: ,b,c      ans: 3

                    s = "aab"       Output: 2       (ab)
             */
            HashSet<Character> hSet = new HashSet<>();
            int l=0,r=0;
            int ans = Integer.MIN_VALUE;
            int tmpL = 0;
            while(r<s.length()){
                Character rL = s.charAt(r);
                while(hSet.contains(rL)){
                    tmpL = r-l;
                    ans = Math.max(ans, tmpL);
                    Character cL = s.charAt(l);
                    hSet.remove(cL);
                    l++;
                }
                hSet.add(rL);
                r++;
            }
            ans = Math.max(ans, r-l);
            return ans;
        }
    }
}
