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
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */ 
    int traverse(TreeNode * root, int p, int q){
        if(!root){
            return -1;
        }
        if((p>=root->val&&q<=root->val)||(q>=root->val&&p<=root->val)){
            return root->val;
        }
        else if(p<=root->val&&q<=root->val){
            return traverse(root->left, p, q);
        }
        else if(p>=root->val&&q>=root->val){
            return traverse(root->right, p, q);
        }
        return -1;
    }
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        return traverse(root, p, q);
    }
};