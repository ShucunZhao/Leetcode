package Amazon.Intern.oa20240127GroupStudents;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Description
 *Group Students 👩‍🎓🧑‍🎓
 * 🤘 INTERN
 * Amazon Technical Academy (ATA) provides in-demand, technical training to current Amazon employees looking to broaden their skill sets. ATA has admitted a group of n prospective trainees with varying skill levels. To better accommodate the trainees, ATA has decided to create classes tailored to the skill levels. A placement examination will return a skill level that will be used to group the trainees into classes, where levels[i] represents the skill level of trainee i. All trainees within a class must have a skill level within maxSpread, a specified range of one another. Determine the minimum number of classes that must be formed.
 *
 * Function Description
 *
 * Complete the function groupStudents in the editor.
 *
 * groupStudents has the following parameter(s):
 *
 * int levels[n]: the skill level for each student
 * int maxSpread: the maximum allowed skill level difference between any two members of a class
 * Returns
 *
 * int: the minimum number of classes that can be formed
 *
 * Example 1:
 * Input:  levels = [1, 4, 7, 3, 4], maxSpread = 2
 * Output: 3
 * Explanation:
 *
 * The trainees in any class must be within maxSpread = 2 levels of each other. In this case, one optimal grouping is (1, 3), (4, 4), and (7). Another possible grouping is (1), (3, 4, 4), (7). There is no way to form fewer than 3 classes.
 *
 * Constraints:
 * TO-DO
 */
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
