package Amazon.Intern.oa20240127RemoveAnagrams;


import java.util.*;

/**
 * @Description
 * Remove Anagram
 * 🤘 INTERN
 * A list of unique product IDs needs to be extracted from a database of products available on Amazon's website. In the database, multiple versions of the products IDs exist such that the order of the characters varies (e.g., code and ecode are the same product). To create the unique list, all anagrams must be removed. Two strings are anagrams if they are permutations of each other. In other words, both strings have the same size and the same characters. For example, "aaagmnrs" is an anagram of "anagrams". Given an list of strings, remove each string that is an anagram of an earlier string, then return the remaining list in sorted order.
 *
 * Write an algorithm that returns a list of strings after removing anagram string in sorted order.
 *
 * Function Description
 *
 * Complete the function removeAnagram in the editor below.
 *
 * removeAnagram has the following parameter:
 *
 * textList, a list of strings representing product IDs.
 * Returns
 *
 * String Array
 *
 * Note: Each string text[i] is made up of characters in the range ASCII[a-z].
 *
 * Example 1:
 * Input:  textList = ["code", "doce", "ecod", "framer", "frame"]
 * Output: ["code", "frame", "framer"]
 * Explanation:
 *
 * "code" and "doce" are anagrams. Remove "doce" from the list and keep the first occurrence "code" in the list.
 *
 * "code" and "ecod" are anagrams. Remove "ecod" from the list and keep the first occurrence "code" in the list.
 *
 * "code" and "framer" are not anagrams. Keep both strings in the list.
 *
 * "framer" and "frame" are not anagrams due to the extra 'r' in "framer". Keep both strings in the list.
 *
 * Order the remaining strings in ascending order: ["code","frame","framer"].
 *
 *
 * So the output is ["code","frame","framer"].
 * Constraints:
 * 0 <= num <= 1000
 * 0 <= m <= num; where m represents the size of output list
 * 1 <= length of text[i] <= 1000
 * 0 <= i < num
 */
public class SolWithHashSet {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter text list:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            for(int i=0;i<InSet.length;++i){
                InSet[i] = InSet[i].replaceAll("\"", "").trim();
            }
            String[] res = S1.removeAnagram(InSet);
            System.out.print("Res: [");
            for(String s : res) System.out.print(s+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public String[] removeAnagram(String[] textList) {
            HashSet<String> mset = new HashSet<>();
            List<String> ans = new ArrayList<>();
            for(String s : textList){
                char[] chars = s.toCharArray();
                Arrays.sort(chars);
                String sorted = new String(chars);
                if(!mset.contains(sorted)){
                    mset.add(sorted);
                    ans.add(s);
                }
            }
            Collections.sort(ans);
            String[] sAns = new String[ans.size()];
            for(int i=0;i<sAns.length;++i) sAns[i] = ans.get(i);
            return sAns;
        }
    }
}
