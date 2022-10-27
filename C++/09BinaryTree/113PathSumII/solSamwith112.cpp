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
    vector<vector<int> > ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        path.push_back(root->val);
        traverse(root, path[0], targetSum);
        return ans;
    }
    void traverse(TreeNode * cur, int sum, int target){//Because you need to traverse all node in BT so this recuersive func has no return value.
        if(cur->left==NULL&&cur->right==NULL&&sum==target){ 
            ans.push_back(path);
            return;
        }
        if(cur->left==NULL&&cur->right==NULL) return;
        if(cur->left!=NULL){
            sum+=cur->left->val;
            path.push_back(cur->left->val);
            traverse(cur->left, sum, target);
            sum-=cur->left->val;
            path.pop_back();
        }
        if(cur->right!=NULL){
            sum+=cur->right->val;
            path.push_back(cur->right->val);
            traverse(cur->right, sum, target);
            sum-=cur->right->val;
            path.pop_back();
        }
        return;
    }
};