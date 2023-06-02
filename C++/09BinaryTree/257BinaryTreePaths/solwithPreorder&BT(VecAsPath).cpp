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
    vector<int> path;
    vector<string> ans;
    void preorder(TreeNode * root){
        if(!root) return;
        if(!root->left&&!root->right){
            string tmp;
            path.push_back(root->val);
            for(int i=0;i<path.size()-1;i++){
                tmp+=to_string(path[i]);
                tmp+="->";
            }
            tmp+=to_string(path.back());
            ans.push_back(tmp);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        path.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return {};
        }
        preorder(root);
        return ans;
    }
};