/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int ans = 0;
    void preorder(TreeNode * root, int sum, int curSum){
        if(!root) return;
        curSum+=root->val;
        if(curSum==sum){
            ans++;
            //return;//You cannot return here because if the children node of current has situation -1 and 1 it will has anohter valid ans.
        }
        preorder(root->left, sum, curSum);
        preorder(root->right, sum, curSum);
        curSum-=root->val;
        return;
    }
    int FindPath(TreeNode* root, int sum) {//
        // write code here
        if(!root) return ans;
        preorder(root, sum, 0);
        FindPath(root->left, sum);
        FindPath(root->right, sum);
        return ans;
    }
};