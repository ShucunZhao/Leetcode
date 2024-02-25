package Amazon.Intern.oa20231223LocationOfDataAfterTransfers;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

/**
 * @Description
 * Location Of Data After Transfers
 * 🤘 INTERN
 * X stores its data on different servers at different locations. From time to time, due to several factors, X needs to move its data from one location to another. This challenge involved keeping track of the locations of X's data and report them at the end of the year.
 * At the start of the year, X's data was located at n different locations. Over the course of the year, X's data was moved from one server to another m times. Precisely, in the ith operation, the data was moved from movedFrom[i] to movedTo[i]. Find the locations of the data after all m moving operations. Return the locations in ascending order.
 *
 * Note:
 * It is guaranteed that for any movement of data :
 * There is data at movedFrom[i].
 * There is no data at movedTo[i].
 * Returns
 * int[]: the locations storing data after all moves are made, in ascending order.
 *
 * Example 1:Input:  locations = [1, 7, 6, 8], movedFrom = [1, 7, 2], movedTo = [2, 9, 5]
 * Output: [5, 6, 8, 9]
 * Explanation:
 * Data begins at locations listed in locations. Over the course of the year, the data was moved three times.
 * Data was first moved from movedFrom[0] to movedTo[0], from 1 to 2. Next, it is moved from 7 to 9, and finally from location 2 to 5.
 * In the end, the locations where data is present are [5,6,8,9] in ascending order.
 *
 * Example 2:
 * Input:  locations = [1, 5, 2, 6], movedFrom = [1, 4, 5, 7] , movedTo = [4, 7, 1, 3]
 * Output: [1, 2, 3, 6]
 *
 */
public class SolWithHashSet {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the locations with format [x,x,x]: ");
            String L = scan.nextLine();
            if(L.equals("q")) break;
            System.out.println("Enter the movedFrom with format [x,x,x]:");
            String F = scan.nextLine();
            if(F.equals("q")) break;
            System.out.println("Enter the movedTo with format [x,x,x]:");
            String T = scan.nextLine();
            if(T.equals("q")) break;
            L = L.substring(1, L.length()-1);
            F = F.substring(1, F.length()-1);
            T = T.substring(1, T.length()-1);
            String[] Ls = L.split(",");
            String[] Fs = F.split(",");
            String[] Ts = T.split(",");
            int[] locations = new int[Ls.length];
            int[] movedFrom = new int[Fs.length];
            int[] movedTo = new int[Ts.length];
            for(int i=0;i<locations.length;++i) locations[i] = Integer.parseInt(Ls[i].trim());
            for(int i=0;i<movedFrom.length;++i){
                movedFrom[i] = Integer.parseInt(Fs[i].trim());
                movedTo[i] = Integer.parseInt(Ts[i].trim());
            }
            int[] res = S1.locationOfDataAfterTransfers(locations, movedFrom, movedTo);
            System.out.print("Res: [");
            for(int i : res) System.out.print(i+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public int[] locationOfDataAfterTransfers(int[] locations, int[]movedFrom, int[]movedTo) {
            /*
                Sol with hash set to store result, and update its elements when traversal.
                Input:  locations = [1, 7, 6, 8], movedFrom = [1, 7, 2], movedTo = [2, 9, 5]
                Output: [5, 6, 8, 9]
            */
            HashSet<Integer> mset = new HashSet<>();
            for(int i : locations) mset.add(i);
            for(int i=0;i<movedFrom.length;++i){
                mset.remove(movedFrom[i]);
                mset.add(movedTo[i]);
            }
            int[] ans = new int[mset.size()];
            int i = 0;
            for(Integer I : mset) ans[i++] = I;
            Arrays.sort(ans);
            return ans;
        }
    }
}
