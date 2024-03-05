package Amazon.Intern.oa20240301CountMaxGreyness;

import java.util.Scanner;

/**
 * Get Maximum Greyness 🌚
 * 🤘 INTERN
 * Several satellites provide observational black and white images which are stored in data centers at Amazon Web Services (AWS).
 * A black and white image is composed of pixels and is represented as an n x m grid of cells. Each cell has a value of 0 or 1, where 0 represents a white pixel and 1 represents a black pixel. The grayness of a cell (i, j) is affected by the pixel values in the ith row and the jth column. More formally, the grayness of the cell (i, j) is the difference between the number of black pixels in the ith row and the jth column and the number of white pixels in the ith row and the jth column.
 * Find the maximum grayness among all the cells of the grid.
 * Note: The value of cell (i, j) is counted both in the ith row and in the jth column.
 * Function Description
 * Complete the function getMaximumGreyness in the editor.
 * GetMaximumGreyness has the following parameter:
 * string pixels[n]: a grid of pixels, where the ithstring consists of m characters and represents the ithrow of pixels.
 * Returns
 * int: the max greyness of the grid of pixels.
 *
 * Example 1:
 * Input:  pixels = ["1010", "0101", "1010"]
 * Output: 1
 * Explanation:
 * The n x m = 3 x 4 grid of pixels looks like this:
 *
 *       1  0  1  0
 *
 *       0  1  0  1
 *
 *       1  0  1  0
 *
 * The grayness of each cell is:
 *
 *       1  -1  1  -1
 *
 *       1  -1  1  -1
 *
 *       1  -1  1  -1
 *
 * The maximum achievable grayness is 1.
 *
 * Example 2:
 * Input:  pixels = ["011", "101", "001"]
 * Output: 4
 * Explanation:
 * The 3 x 3 grid of pixels looks like this:
 *
 *       0  1  1
 *
 *       1  0  1
 *
 *       0  0  1
 *
 * The grayness of each cell is:
 *
 *       0  0  4
 *
 *       0  0  4
 *
 *      -2 -2  2
 *
 * The maximum achievable grayness is 4.
 */
public class SolWith2DPrefixSum {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter pixels with format [xx,xx,xx]:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] Ins = In.split(",");
            for(int i=0;i<Ins.length;++i){
                Ins[i] = Ins[i].replaceAll("\"", "");
                Ins[i] = Ins[i].trim();
            }
            System.out.println("Res: "+S1.getMaxGrayness(Ins));
        }
    }
    private static class Solution{
        public int getMaxGrayness(String[] pixels) {
            /*
                Sol with prefix sum in row and column to count the number of element '1'
                then we can use the length m and length n to minus the '1' number to get '0'.
             */
            int m = pixels.length;
            int n = pixels[0].length();
            int[] rowOnes = new int[m];
            int[] colOnes = new int[n];
            for(int i=0;i<pixels.length;++i){
                for(int j=0;j<pixels[i].length();++j){
                    rowOnes[i]+=pixels[i].charAt(j)-'0';
                    colOnes[j]+=pixels[i].charAt(j)-'0';
                }
            }
            int ans = 0;
            for(int i=0;i<pixels.length;++i){
                for(int j=0;j<pixels[i].length();++j){
                    int tmp = (rowOnes[i]+colOnes[j])-(m-rowOnes[i])-(n-colOnes[j]);
                    ans = Math.max(ans, tmp);
                }
            }
            return ans;
        }
    }
}
