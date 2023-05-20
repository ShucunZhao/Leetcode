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
        if(root->val==p) return p;
        if(root->val==q) return q;
        int L = traverse(root->left, p, q);
        int R = traverse(root->right, p, q);
        if(L!=-1&&R!=-1){
            return root->val;
        }
        else if(L!=-1&&R==-1){
            return L;
        }
        else if(L==-1&&R!=-1){
            return R;
        }
        return -1;
    }
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        return traverse(root, p, q);
    }
};