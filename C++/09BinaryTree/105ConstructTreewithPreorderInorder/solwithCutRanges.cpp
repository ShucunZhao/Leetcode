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
        /*
                         r                          r
             preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        */   
        if(preorder.size()==0||inorder.size()==0) return NULL;
        int rVal = preorder[0];
        TreeNode * root = new TreeNode(rVal);
        if(preorder.size()==1) return root;
        int rIndex = -1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==rVal){
                rIndex = i;
                break;
            }
        }
        vector<int> leftIn(inorder.begin(), inorder.begin()+rIndex);
        vector<int> rightIn(inorder.begin()+rIndex+1, inorder.end());
        vector<int> leftPre(preorder.begin()+1, preorder.begin()+1+leftIn.size());
        vector<int> rightPre(preorder.begin()+1+leftPre.size(), preorder.end());
        /*
        for(int i:rightPre) cout<<i<<",";
        cout<<endl;
        */
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};