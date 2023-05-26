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
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        if(!root) return -1;
        int L = lowestCommonAncestor(root->left, o1, o2);
        int R = lowestCommonAncestor(root->right, o1, o2);
        if(L!=-1&&R!=-1){
            return root->val;
        }
        if(L!=-1||R!=-1){
            if(root->val==o1||root->val==o2){
                return root->val;
            }
            return L==-1?R:L;   
        }
        if(root->val==o1) return o1;
        if(root->val==o2) return o2;
        return -1;
    }
};