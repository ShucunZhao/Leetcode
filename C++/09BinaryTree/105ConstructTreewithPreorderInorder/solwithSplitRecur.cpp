/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        int rootVal = preorder[0];
        TreeNode * root = new TreeNode(rootVal);
        if(preorder.size()==1) return root;
        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index]==rootVal){
                break;
            }
        }
        vector<int> leftIn(inorder.begin(),inorder.begin()+index);
        vector<int> leftPre(preorder.begin()+1, preorder.begin()+1+leftIn.size());
        vector<int> rightIn(inorder.begin()+index+1, inorder.end());
        vector<int> rightPre(preorder.begin()+1+leftIn.size(),preorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};