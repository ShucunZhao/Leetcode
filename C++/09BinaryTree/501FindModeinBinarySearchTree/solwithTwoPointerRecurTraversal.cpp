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
class Solution {//This solution is only used in binary search tree(continuous distribution)
public:
    TreeNode * pre = NULL;
    int count = 0, countMax = 0;
    vector<int> ans;
    void traverse(TreeNode * cur){
        if(cur==NULL) return;
        traverse(cur->left);
        if(pre==NULL){
            count=1;
        }
        else if(pre->val==cur->val){
            count++;
        }
        else if(pre->val!=cur->val){
            count=1;
        }
        pre=cur;
        if(count==countMax){
            ans.push_back(cur->val);
        }
        else if(count>countMax){
            countMax = count;
            ans.clear();
            ans.push_back(cur->val);
        }
        traverse(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root==NULL) return {};
        traverse(root);
        return ans;
    }
};