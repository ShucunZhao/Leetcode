package lc48Rotatelmage;
import java.util.Scanner;

public class SolWithSM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter matrix with format [[x,x,x],[x,x,x],[x,x,x]]");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            In = In.substring(1, In.length()-1);
            String[] sSet = In.split("\\],\\[");
            int n = sSet.length;
            sSet[0] = sSet[0].substring(1);
            sSet[sSet.length-1] = sSet[sSet.length-1].substring(0, sSet[sSet.length-1].length()-1);
//            int m = sSet[0].length();
            int m = sSet[0].split(",").length;
            int[][] matrix = new int[n][m];
            for(int i=0;i<n;i++){
                String[] curSet = sSet[i].split(",");
                for(int j=0;j<m;j++){
                    matrix[i][j] = Integer.parseInt(curSet[j]);
                }
            }
            S1.rotate(matrix);
            System.out.println("Res: [");
            for(int i=0;i<n;i++){
                System.out.print("[");
                for(int j=0;j<m;j++){
                    System.out.print(matrix[i][j]+",");
                }
                System.out.println("],");
            }
            System.out.println("]");
        }
    }
    private static class Solution{
        public void rotate(int[][] matrix) {
            /*
                Input: matrix = [[1,4,7],
                                 [2,5,8],
                                 [3,6,9]]
                      matrix = [[7,4,1],
                                [8,5,2],
                                [9,6,3]]
                Output: [[7,4,1],
                         [8,5,2],
                         [9,6,3]]
              ------------------------------------------
              matrix = [[5,1,9,11],
                        [2,4,8,10],
                        [13,3,6,7],
                        [15,14,12,16]]
              matrix = [[5, 2,  13,15],
                        [1, 4,  3, 14],
                        [9, 8,  6, 12],
                        [11,10, 7,16]]
              matrix = [[15, 13, 2,5],
                        [14, 3,  4, 1],
                        [12, 6,  8, 9],
                        [16, 7,  10, 11]]
             */
            int n = matrix.length;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
//                    int[] tmp = swap(matrix[i][j], matrix[j][i]);
//                    matrix[i][j] = tmp[0];
//                    matrix[j][i] = tmp[1];
                }
            }
            int left = 0, right = n-1;
            while(left<=right){
                for(int i=0;i<n;i++){
//                    int[] tmp = swap(matrix[i][left], matrix[i][right]);
                    int tmp = matrix[i][left];
                    matrix[i][left] = matrix[i][right];
                    matrix[i][right] = tmp;
                }
                left++;
                right--;
            }
        }
//        static int[] swap(int a, int b){
//            return new int[]{b,a};
//        }
    }
}
