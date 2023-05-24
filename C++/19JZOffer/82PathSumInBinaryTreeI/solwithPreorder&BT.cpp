/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    int curSum = 0;
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(!root) return false;//tar: 22
        curSum+=root->val;//5,9
        if(curSum==sum&&root->left==NULL&&root->right==NULL) return true;
        bool L = hasPathSum(root->left, sum);
        bool R = hasPathSum(root->right, sum);
        curSum-=root->val;
        return L||R;
    }
};