package lc54SpiralMatrix;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class SolWithSM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the matrix with format [[x,x,x],[x,x,x]]");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            In = In.substring(1, In.length()-1);
            System.out.println("In: "+In);
            String[] nSet = In.split("\\],\\[");//We cannot just split "," here because it would be split into 9 elements,
                                                //we need to split by "],[" this symbol.
            int n = nSet.length;
            nSet[0] = nSet[0].substring(1, nSet[0].length());
            nSet[nSet.length-1] = nSet[nSet.length-1].substring(0, nSet[nSet.length-1].length()-1);
            int m = nSet[0].split(",").length;
            int[][] matrix = new int[n][m];
            for(int i=0;i<n;i++){
                String[] curSet = nSet[i].split(",");
                for(int j=0;j<m;j++){
                    matrix[i][j] = Integer.parseInt(curSet[j]);
                }
            }
            List<Integer> res = S1.spiralOrder(matrix);
            System.out.print("Res: [");
            for(int i=0;i<res.size();i++){
                System.out.print(res.get(i)+",");
            }
            System.out.println("]");
        }
    }
    private static class Solution {
        public List<Integer> spiralOrder(int[][] matrix) {
            List<Integer> ans = new ArrayList<>();
            int n = matrix.length;
            int m = matrix[0].length;
            int up = 0, down = n - 1, left = 0, right = m - 1;
            while (true) {
                for (int j = left; j <= right; j++) {
                    ans.add(matrix[up][j]);
                }
                up++;
                if (up > down) {
                    break;
                }
                for (int i = up; i <= down; i++) {
                    ans.add(matrix[i][right]);
                }
                right--;
                if (left > right) {
                    break;
                }
                for (int j = right; j >= left; j--) {
                    ans.add(matrix[down][j]);
                }
                down--;
                if (up > down) {
                    break;
                }
                for (int i = down; i >= up; i--) {
                    ans.add(matrix[i][left]);
                }
                left++;
                if (left > right) {
                    break;
                }
            }
            return ans;
        }
    }
}
