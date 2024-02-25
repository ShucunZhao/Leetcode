package Amazon.Intern.oa20230831FindMinimumInefficiency;

import java.util.Scanner;

/**
 * @Description
 * Find Minimum Inefficienty
 * 🤘 INTERN
 * Amazon Web Service has n servers, each of them either has high fault tolerance or high reliability. A system works better if all the servers have the same attributes. The inefficiency of a group of server is defined as the number of adjacent pairs of server that have different attributes.
 *
 * Consider, for example, a set of servers described as 1001001 where '0' means the server has high fault tolerance, '1' means the server has high reliabiity. The inefficiency of this group is 4 as described in the image below:
 * Given a string serverType of length n consisting of '0', '1', and '?', where '0' means the server has high fault tolerance, '1' means the server has high reliability, and '?' means you can install any type of server there, find the minimum inefficiency you can get after install a server at each '?'.
 * Function Description
 * Complete the function findMinimumInefficiency in the editor.
 * findMinimumInefficiency has the following parameter:
 * string serverType: the server types
 * Returns
 * int: the minimum possible inefficiency
 *
 * Example 1:
 * Input:  serverType = "??011??0"
 * Output: 2
 * Explanation:
 * In the above example, the number of servers n = 8. One optimal way to install servers is to
 * 1. Install a server having fault tolerance (0) at the first and the second positions.
 * 2. Install a server having high reliability (1) at the sixth and the seventh positions.
 * After making these changes, the server types are '00011110'. The number of adjacent pairs having different server types is 2. It can be shown that the answer cannot be reduced from 2. Return 2.
 * Note that another possible way to achieve a minimum number of different adjancet pairs as 2 would 00011100 and 00011000.
 *
 * Example 2:
 * Input:  serverType = "00?10??1?"
 * Output: 3
 * Explanation:
 * One optimal way to install server is to install high-reliability servers. The new
 * server types are "0011011111" with 3 adjacent dissimilar pairs.
 *
 * Constraints:
 * 1 <= n <= 105
 * serverType consists of '0', '1' and '?' only
 */
public class SolWithJump {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the serverType: ");
            String S = scan.nextLine();
            if(S.equals("q")) break;
            S = S.substring(1, S.length()-1);
            System.out.println("Res: "+S1.findMinimumInefficiency(S));
        }
    }
    private static class Solution{
        public int findMinimumInefficiency(String serverType) {
            /*
                serverType = "??011??0", Output: 2
                With analysis we can know, If the the '?' is in the middle of string 'serverType'.
                When left and right symbol are difference, no matter what symbol we place in the '?'
                to it, there at least has one pair of difference.
                At the same if the the '?' is in the head or tail of string, it can be placed the same
                symbol besides of it.
                In summary, we can ignore the ? directly and then find the total inefficiency.
            */
            StringBuilder sbd = new StringBuilder();
            for(int i=0;i<serverType.length();++i){
                if(serverType.charAt(i)!='?') sbd.append(serverType.charAt(i));
            }
            int ans = 0;
            for(int i=1;i<sbd.length();++i){
                if(sbd.charAt(i)!=sbd.charAt(i-1)) ans++;
            }
            return ans;
        }
    }
}
