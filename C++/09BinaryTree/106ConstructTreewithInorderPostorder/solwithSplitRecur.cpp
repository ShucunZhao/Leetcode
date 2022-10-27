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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return NULL;
        int rootVal = postorder[postorder.size()-1];
        TreeNode * root = new TreeNode(rootVal);
        if(postorder.size()==1) return root;
        int inIndex;
        for(inIndex=0;inIndex<inorder.size();inIndex++){
            if(inorder[inIndex]==rootVal){
                break;
            }
        }
        vector<int> leftIn(inorder.begin(), inorder.begin()+inIndex);
        vector<int> leftPo(postorder.begin(),postorder.begin()+leftIn.size());
        root->left = buildTree(leftIn, leftPo);
        vector<int> rightIn(inorder.begin()+inIndex+1, inorder.end());
        vector<int> rightPo(postorder.begin()+leftIn.size(), postorder.begin()+postorder.size()-1);
        root->right = buildTree(rightIn, rightPo);
        return root;
    }
};