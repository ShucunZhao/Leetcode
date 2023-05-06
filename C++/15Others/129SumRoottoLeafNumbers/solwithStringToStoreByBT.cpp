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
    string path;
    int sum = 0;
    void traverse(TreeNode * root){
        if(!root) return;
        char c = root->val+'0';
        //cout<<c<<endl;
        path.push_back(c);
        //cout<<path<<endl;
        if(!root->left&&!root->right){
            sum+=stoi(path);
            return;
        }
        if(root->left){
            traverse(root->left);
            path.pop_back();
        }
        if(root->right){
            traverse(root->right);
            path.pop_back();
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        traverse(root);
        return sum;
    }
};