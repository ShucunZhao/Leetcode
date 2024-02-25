package Amazon.Intern.oa20231219GetScoreDifference;

import java.util.Arrays;
import java.util.Scanner;

public class SolWithTraverse {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the n: ");
            String N = scan.nextLine();
            if(N.equals("q")) break;
            System.out.println("Enter the points with format [x,x,x]:");
            String P = scan.nextLine();
            if(P.equals("q")) break;
            int n = Integer.parseInt(N.trim());
            P = P.substring(1, P.length()-1);
            String[] Ps = P.split(",");
            int[] points = new int[Ps.length];
            for(int i=0;i<points.length;++i) points[i] = Integer.parseInt(Ps[i].trim());
            System.out.println("Res: "+S1.getScoreDifference(n, points));
        }
    }
    private static class Solution{
        public long getScoreDifference(int n, int[] points) {
            /*
                Input:  n = 4, points = [4, 1, 2, 3]

                                        [1,2,3,4]
                p1:
                p2:
            */
            long p1 = 0;
            long p2 = 0;
            Arrays.sort(points);
            boolean first = true;
            for(int i=points.length-1;i>=0;--i){
                if(first){
                    p1+=(long)points[i];
                    first = false;
                }
                else{
                    p2+=(long)points[i];
                    first = true;
                }
            }
            return p1>p2?p1-p2:p2-p1;
        }
    }
}
