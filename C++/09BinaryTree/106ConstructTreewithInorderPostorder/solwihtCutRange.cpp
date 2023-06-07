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
        /*
                        l
                          r                                   r
             inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
        */
        if(inorder.size()==0||postorder.size()==0) return NULL;
        int rootVal = postorder.back();
        TreeNode * root = new TreeNode(rootVal);
        int rootIndex = -1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==rootVal){
                rootIndex = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin()+rootIndex);
        vector<int> rightInorder(inorder.begin()+rootIndex+1, inorder.end());
        vector<int> leftPost(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPost(postorder.begin()+leftPost.size(), postorder.end()-1);
        // for(int i : rightPost) cout<<i<<",";
        // cout<<endl;
        root->left = buildTree(leftInorder, leftPost);
        root->right = buildTree(rightInorder, rightPost);
        return root;
    }
};