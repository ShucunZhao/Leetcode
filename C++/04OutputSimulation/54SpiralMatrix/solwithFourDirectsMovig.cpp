class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
            matrix = [[1,2,3],
                      [4,5,6],
                      [7,8,9]]
        int up = 0, down = m-1, left = 0, right = n-1;
        */
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int up = 0, down = m-1, left = 0, right = n-1;
        while(up<=down&&left<=right){
            for(int j=left;j<=right;j++){
                ans.push_back(matrix[up][j]);
            }
            up++;
            if(up>down) break;
            for(int i=up;i<=down;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(right<left) break;
            for(int j=right;j>=left;j--){
                ans.push_back(matrix[down][j]);
            }
            down--;
            if(down<up) break;
            for(int i=down;i>=up;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left>right) break;
        }    
        return ans;
    }
};