package Amazon.Intern.oa20231227GetMinLagDistance_CN;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @Description
 * Get Min Distance
 * 🤘 INTERN
 * An AWS client has brought servers and databases from data centers in different parts of the world for their application. For simplicity, let's assume all the servers and data centers are located on a 1-dimensional line.
 * You have been given the task of optimizing the network connection. Each data center must be connected to a server. The positions of n data ceenters and n servers are given in the form of arrays. Any particular data center, center[i], can deliver to any particular server destination, destination[i]. The lag is defined distance between a data center at locationx and a server destination at locationy is |x - y|, i.e., the absolute difference between x and y. Determine the minimum lag to establish the entire work.
 * Function Description
 * Complete the function getMinDistance in the editor.
 * getMinDistance has the following parameter(s):
 * int center[n]: the positions of data centers
 * int destination[n]: the positions of server destinations
 * Returns
 * long int: the minimum lag
 *
 * Example:
 * There are n = 3 connections, the positions of data centers, center = [1, 2, 2] and the positions of the server destinations, destination = [5, 2, 4]
 * The most efficient deliveries are
 * The center at location 1 makes the first connection to the server at location 2.
 * The center at location 2 makes the second connection to the server at location 4.
 * The center at location 2 makes the third connection to the server at location 5.
 * The minimum total lag is = abs(1 - 2) + abs(2 - 4) + abs(2 - 5) = 1 + 2 + 3 = 6.
 *
 * Constraints:
 * 1 <= n <= 105
 * 1 <= center[i], destination[i] <= 109
 */
public class CenterAndDestination01 {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the center with format [x,x,x]: ");
            String C = scan.nextLine();
            if(C.equals("q")) break;
            C = C.substring(1, C.length()-1);
            String[] cSet = C.split(",");
            System.out.println("Enter the dest with format [x,x,x]:");
            String D = scan.nextLine();
            if(D.equals("q")) break;
            D = D.substring(1, D.length()-1);
            String[] dSet = D.split(",");
            int[] center = new int[cSet.length];
            int[] dest = new int[dSet.length];
            for(int i=0;i<center.length;++i){
                center[i] = Integer.parseInt(cSet[i]);
                dest[i] = Integer.parseInt(dSet[i]);
            }
            int ans = S1.getMinDistance(center, dest);
            System.out.println("Res: "+ans);
        }
    }
    public static class Solution{
        public int getMinDistance(int[] center, int[] dest){
            Arrays.sort(center);
            Arrays.sort(dest);
            int n = center.length;
            int ans = 0;
            for(int i=0;i<n;++i){
                ans+=Math.abs(center[i]-dest[i]);
            }
            return ans;
        }
    }
}
