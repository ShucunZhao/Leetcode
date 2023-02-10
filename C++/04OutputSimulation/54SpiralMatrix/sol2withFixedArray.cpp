class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
            i+j: 0 1 2
            ans: 1 2 3

        */
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m*n);
        int up = 0, down = m-1, left = 0, right = n-1;
        int index = 0;
        while(1){
            for(int i=up,j=left;j<=right;j++){
                ans[index++] = matrix[i][j];
            }
            up++;
            if(up>down) break;
            for(int i=up,j=right;i<=down;i++){
                ans[index++] = matrix[i][j];
            }
            right--;
            if(left>right) break;
            for(int i=down,j=right;j>=left;j--){
                ans[index++] = matrix[i][j];
            }
            down--;
            if(up>down) break;
            for(int i=down,j=left;i>=up;i--){
                ans[index++] = matrix[i][j];
            }
            left++;
            if(left>right) break;
        }
        // for(int i : ans){
        //     cout<<i<<",";
        // }
        // cout<<endl;
        return ans;
    }
};