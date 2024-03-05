package Amazon.Intern.oa202040303MaxmimumTimesWordRemoved;

import java.util.Scanner;

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
