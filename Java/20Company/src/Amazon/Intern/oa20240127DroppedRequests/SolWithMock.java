package Amazon.Intern.oa20240127DroppedRequests;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Description
 * Dropped Requests
 * 🤘 INTERN
 * On Amazon Prime Day, non-critical requests for a transaction system are routed through a throttling gateway to ensure that the network is not choked by non-essential requests. The gateway has the following limits:
 *
 * The number of transactions in any given second cannot exceed 3.
 * The number of transactions in any given 10 second period cannot exceed 20. A ten-second period includes all requests arriving from time T to T-9 (inclusive of both) for any valid time T.
 * The number of transactions in any given minute cannot exceed 60. Similar to above, 1 minute is from max(T, T-59) to T.
 * Any request that exceeds any of the above limits will be dropped by the gateway. Given the times at which different requests arrive sorted ascending, find how many requests will be dropped.
 *
 * Note: Even if a request is dropped it is still considered for future calculations. Although, if a request is to be dropped due to multiple violations, it is still counted only once.
 *
 * Function Description
 *
 * Complete the function droppedRequests in the editor.
 *
 * droppedRequests has the following parameter(s):
 *
 * List requestTime: an ordered list of integers that represent the times of various requests
 * Returns
 *
 * int: the total number of dropped requests
 *
 * Example 1:
 * n = 27
 * requestTime = [1, 1, 1, 1, 2, 2, 2, 3, 3, 3,
 *                4, 4, 4, 5, 5, 5, 6, 6, 6, 7,
 *                7, 7, 7, 11, 11, 11, 11]
 *
 * requestTime[3] : Dropped. Violate 3 second limit.
 * requestTime[21]: Dropped. Violate 10 second limit.
 * requestTime[22]: Dropped. Violate 10 second limit.
 * requestTime[23]: Dropped. Violate 3 second and 10 second limit.
 * requestTime[25]: Dropped. Violate 10 second limit.
 * requestTime[26]: Dropped. Violate 10 second limit.
 * requestTime[27]: Dropped. Violate 3 second and 10 second limit.
 *
 * Total dropped: 7
 */
public class SolWithMock {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter requestTime:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            List<Integer> requestTime = new ArrayList<>();
            for(String s : InSet){
                requestTime.add(Integer.parseInt(s.trim()));
            }
            System.out.println("Res: "+S1.droppedRequests(requestTime));
        }
    }
    private static class Solution{
        public int droppedRequests(List<Integer> requestTime) {
            /*

                    1s: 3 --- <=3
                    10s: 30 ---- <=20
                    60s: 180 ---- <=60
                n = 27  ans: 7
                requestTime = [1, 1, 1, 1,  2,  2,  2, 3, 3, 3,
                               4, 4, 4, 5,  5,  5,  6, 6, 6, 7,
                               7, 7, 7, 11, 11, 11, 11]
                                                            i
               requestTime = [1, 1, 1, 1,  2,  2,  2, 3, 3, 3,
                              4, 4, 4, 5,  5,  5,  6, 6, 6, 7,
                              7, 7, 7, 11, 11, 11, 11]
                cnt: 1,
             */
            int ans = 0;
            for(int i=0;i<requestTime.size();++i){
                if(i>=3&&(requestTime.get(i)==requestTime.get(i-3))){
                    ans++;
                }
                else if(i>=20&&(requestTime.get(i)-requestTime.get(i-20)<10)){
                    ans++;
                }
                else if(i>=60&&(requestTime.get(i)-requestTime.get(i-60)<60)){
                    ans++;
                }
            }
            return ans;
        }
    }
}
