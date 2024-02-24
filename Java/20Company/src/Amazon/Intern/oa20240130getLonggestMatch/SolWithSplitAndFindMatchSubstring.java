package Amazon.Intern.oa20240130getLonggestMatch;
import java.util.Scanner;

/**
 * @Description
 * You are given two strings, a text string text, and a regex expression regex. The string regex contains exactly one wildcard character().
 * A wildcard character () matches any sequence of zero or more lowercase English characters.
 * A regex matches some string if it is possible to replace the wildcard character with some sequence of characters such that the regex expression becomes
 * equal to the string. No other character can be changed. For example, regex "abc*bcd" match "abcbcd", "abcefgbcd" and "abccbcd" whereas it does not match the strings"abcbd""abzbcd""abcd"
 * Return the length of the longest substring of text that matches the expression regex. Return -1 if there is no such substring
 * Note: A substring is a contiguous sequence of characters within a string
 */
public class SolWithSplitAndFindMatchSubstring {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter string text:");
            String text = scan.nextLine();
            if(text.equals("q")) break;
            System.out.println("Enter string regex:");
            String regex = scan.nextLine();
            if(regex.equals("q")) break;
            System.out.println("Res: "+S1.getLonggestMatch(text, regex));
        }
    }
    public static class Solution{
        public int getLonggestMatch(String text, String regex){
            /*          1
                        l
                text ="hackerarank", regex = "ack*ra"
                              r
                              7
                ans: 8 (ackerra) r-l+len(suffix) = 7-1+2 = 8
            */
            String[] sSet = regex.split("\\*");
            String prefix = sSet[0], suffix = sSet[1];
            int l = text.indexOf(prefix);
            int r = text.lastIndexOf(suffix);
            if(l==-1||r==-1||l>r) return -1;
            return r-l+suffix.length();
        }
    }
}
