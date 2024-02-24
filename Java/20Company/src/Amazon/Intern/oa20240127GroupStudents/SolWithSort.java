package Amazon.Intern.oa20240127GroupStudents;

import java.util.Arrays;
import java.util.Scanner;

public class SolWithSort {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter levels:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            System.out.println("Enter maxSpread:");
            String S = scan.nextLine();
            if(S.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] levels = new int[InSet.length];
            for(int i=0;i<InSet.length;++i){
                levels[i] = Integer.parseInt(InSet[i].trim());
            }
            int maxSpread = Integer.parseInt(S.trim());
            System.out.println("Res: "+S1.groupStudents(levels,maxSpread));
        }
    }
    private static class Solution{
        public int groupStudents(int[] levels, int maxSpread) {
            /*
                 levels = [1, 4, 7, 3, 4], maxSpread = 2
                                 l
                 sort = [1,3,4,4,7]
                                  r
                cnt:2
            */
            if(levels.length==0) return 0;
            Arrays.sort(levels);
            int ans = 1;
            int l=0, r=0;
            while(r<levels.length){
                if(levels[r]-levels[l]>maxSpread){
                    ans++;
                    l=r;
                }
                else{
                    r++;
                }
            }
            return ans;
        }
    }
}
