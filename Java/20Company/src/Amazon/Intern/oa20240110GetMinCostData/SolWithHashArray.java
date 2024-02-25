package Amazon.Intern.oa20240110GetMinCostData;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @Description
 * Minimal Cost Data Interpolation
 * 🤘 INTERN
 * The machine learning enthusiasts at Amazon are working on a data interpolation model to increase the size of the data set for better learning.
 *
 * In one such model, there are 26 different classifications possible and the ith data point is annotated to belong to the data[i] class where data is a string of lowercase English letters. However, for some data points, data[i] is equal to '?' representing that the corresponding data point classification is missing and needs to be replaced with some lowercase English letter.
 *
 * The cost of any index i of the string data is defined as the number of indices before it that also have the same classification result. For example,
 *
 * For the string "hello" the costs are [0, 0, 0, 1, 0] corresponding to each index.
 * For the string "abc" the costs are [0, 0, 0] corresponding to each index.
 * For the string "aaccbbc" the costs are [0, 1, 0, 1, 0, 1, 2] corresponding to each index because before the last c character, there are 2 more c characters.
 * The task is to replace all the characters '?' so that the sum of the indices' cost is minimum.
 *
 * Given the string data, interpolate the data such that the total cost of all the indices is minimized. If there are multiple ways to get minimum cost, print the lexicographically smallest possible string that satisfies the goal.
 *
 * Function Description
 * Complete the function getMinCostData in the editor below.
 * getMinCostData has the following parameter:
 * data: a string
 * Returns
 * string: the lexicographically minimum string with the minimum cost
 *
 * Note:
 * A string p is lexicographically smaller than string q, if p is a prefix of q, is not equal to q, or there exists i, such that pi < qi and for all j < i it is satisfied that pj = qj. Note that while comparing pj and qj we consider their ASCII values, i.e. '[' and ']' are greater than any uppercase English letters. For example, "ABC" is lexicographically smaller than "BCD" and "ABCD" but larger than "AAC" and "AACDE".
 *
 * Example 1:
 * Input:  data = "aaaa?aaaa"
 * Output: "aaaaabaaaa"
 * Explanation:Putting 'b' does not contribute to the total cost and is lexicographically minimum.
 *
 * Example 2:
 * Input:  data = "??????"
 * Output: "abcdef"
 * Explanation:This is the lexicographically smallest string that keeps the cost least. The cost will be 0 as there will be no duplicate character present in it.
 *
 * Example 3:
 * Input:  data = "abcd?"
 * Output: "abcde"
 * Explanation:The strings "abcda", "abcdb", "abcdc", and "abcdd" cost 1 because the last element has a duplicate character. We can see that the minimum cost possible is 0. Since there can be multiple possible strings with 0 cost, we choose the lexicographically smaller one i.e. abcde.
 *
 * Example 4:
 * Input:  data = "abcdefghijklmnopqrstuvwxyz?"
 * Output: "abcdefghijklmnopqrstuvwxyza"
 * Explanation: This is the lexicographically smallest string that keeps the cost least. The cost will be 1 as there will all a-z character present once before it so the lexicographically smallest char is a.
 */
public class SolWithHashArray {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true) {
            System.out.println("Enter data:");
            String In = scan.nextLine();
            if (In.equals("q")) break;
            In = In.substring(1, In.length() - 1);
            System.out.println("Res: " + S1.getMinCostData(In));
        }
    }
    private static class Solution{
        public String getMinCostData(String data) {
            /*
                Sol: When meet the '?' char, we need to find the minChar and minCnt by:
                    Step1: Do the steps below from a to z because the optimal result will be around a-z:
                        if the cnt of current char c is smaller than minCnt: update the minChar into c and update the minCnt to count(c)
                           else if the cnt of the current char c is equal to minCnt,
                                    determine if the lexico-order of c is smaller than minChar:
                                            if yes: update the minChar to c and update the minCnt to count(c)
                    Step2: Replace the minChar to original data and add one to the HashMap counter.
                      i
                data: a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,?
            */
            HashMap<Character, Integer> ms = new HashMap<>();
            char[] chars = data.toCharArray();
            for(int i=0;i<chars.length;++i){
                if(chars[i]=='?'){
                    char minChar = 'a';
                    int minCnt = ms.getOrDefault(minChar, 0);
                    for(char c='a';c<='z';++c){
                        if(ms.getOrDefault(c,0)<minCnt||(ms.getOrDefault(c,0)==minCnt&&c<minChar)){
                            minChar = c;
                            minCnt = ms.getOrDefault(minChar, 0);
                        }
                    }
                    chars[i] = minChar;
                    ms.put(chars[i], ms.getOrDefault(chars[i], 0)+1);
                }
                else{
                    ms.put(chars[i], ms.getOrDefault(chars[i],0)+1);
                }
            }
            return new String(chars);
        }
    }
}
