package Amazon.Intern.oa202040303MaxmimumTimesWordRemoved;

import java.util.Scanner;

/**
 * Maximum Times Word Removed 🍅
 * 🤘 INTERN
 * Amazon Engineering maintains a large number of logs of operations across all products. A software engineer is debugging an issue in a product. An efficient way to analyze logs is to write automated scripts to check for patterns. The engineer wants to find the maximum number of times a target word can be obtained by rearranging a subset of characters in a log entry.
 * Given a log entry s and target word t, the target word can be obtained by selecting some subset of characters from s that can be rearranged to form string t and removing them from s. Determine the maximum number of times the target word can be removed from the given log entry.
 * Note: Both strings s and t consist only of lowercase English letters.
 * Function Description
 * Complete the function maximumTimesWordRemoved in the editor.
 * maximumTimesWordRemoved has the following parameters:
 * String s: a log entry
 * String t: a target word
 * Returns
 * int: the maximum number of times the target word can be removed
 * Example 1:
 * Input:  s = "abacbc", t = "bca"
 * Output: 2
 * Explanation:
 * All characters were removed from s.
 *
 * Example 2:
 * Input:  s = "abdadccacd", t = "edac"
 * Output: 0
 * Explanation:
 * It is not possible to form the target word t from the characters in s.
 */
public class SolWithCounting {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string s:");
            String S = scan.nextLine();
            if(S.equals("q")) break;
            S = S.substring(1, S.length()-1);
            System.out.println("Enter string t:");
            String T = scan.nextLine();
            if(T.equals("q")) break;
            T = T.substring(1, T.length()-1);
            System.out.println("Res: "+S1.maximumTimesWordRemoved(S,T));
        }
    }
    private static class Solution{
        public int maximumTimesWordRemoved(String s, String t) {
            /* Sol: 1.For log entry s and target word t, count the number of occurrences of each character.
                    2.For each character in the target word t, check the number of times it appears in the log entry s,
                      and calculate the maximum number of times t can be removed from s.
                    3.The maximum number of times a target word can be removed is the minimum ratio of the frequency of
                      each character in s to the frequency of the corresponding character in t.
             */
            //Step1: count all chars in s and t:
            int[] cntS = new int[26];
            int[] cntT = new int[26];
            for(int i=0;i<s.length();++i){
                cntS[s.charAt(i)-'a']++;
            }
            for(int i=0;i<t.length();++i){
                cntT[t.charAt(i)-'a']++;
            }
            //Step2: Determine the maximum number of times t can be removed from s
            int maxCnt = Integer.MAX_VALUE;
            for(int i=0;i<26;++i){
                if(cntT[i]==0) continue;
                maxCnt = Math.min(maxCnt, cntS[i]/cntT[i]);
            }
            //If the target word t cannot be formed, maxCnt is Integer.MAX_VALUE, then return 0.
            return maxCnt==Integer.MAX_VALUE?0:maxCnt;
        }
    }
}
