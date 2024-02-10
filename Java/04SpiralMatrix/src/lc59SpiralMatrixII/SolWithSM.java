package lc59SpiralMatrixII;
import java.util.Scanner;

public class SolWithSM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Please enter number n:");
            String In = scan.nextLine();
            if(In.equals("q")){
                break;
            }
            int n = Integer.parseInt(In);
            int[][] ans = S1.generateMatrix(n);
            System.out.print("Res: [");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    System.out.print(ans[i][j]+",");
                }
                System.out.println("");
            }
        }
    }
    private static class Solution{
        public int[][] generateMatrix(int n) {
            /*
                n = 3
                SM:
                        1 2 3
                        8 9 4
                        7 6 5
             */
            int[][] ans = new int[n][n];
            int up = 0, down = n-1, left = 0, right = n-1;
            int cnt = 1;
            while(true){
                for(int i= left;i<=right;++i){
                    ans[up][i] = cnt;
                    cnt++;
                }
                up++;
                if(up>down){
                    break;
                }
                for(int j=up;j<=down;j++){
                    ans[j][right] = cnt;
                    cnt++;
                }
                right--;
                if(left>right) {
                    break;
                }
                for(int i=right;i>=left;--i){
                    ans[down][i] = cnt;
                    cnt++;
                }
                down--;
                if(up>down){
                    break;
                }
                for(int j=down;j>=up;--j){
                    ans[j][left] = cnt;
                    cnt++;
                }
                left++;
                if(left>right){
                    break;
                }
            }
            return ans;
        }
    }
}
