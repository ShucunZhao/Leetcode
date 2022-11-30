class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int left=0,right=n-1,up=0,down=m-1;
        while(1){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[up][i]);
            }
            if(++up>down) break;
            for(int j=up;j<=down;j++){
                ans.push_back(matrix[j][right]);
            }
            if(--right<left) break;
            for(int k=right;k>=left;k--){
                ans.push_back(matrix[down][k]);
            }
            if(--down<up) break;
            for(int l=down;l>=up;l--){
                ans.push_back(matrix[l][left]);
            }
            if(++left>right) break;
        }
        return ans;
    }
};