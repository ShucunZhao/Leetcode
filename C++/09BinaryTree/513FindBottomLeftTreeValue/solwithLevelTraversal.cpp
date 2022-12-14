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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qt;
        if(root==NULL){
            return 0;
        }
        qt.push(root);
        int size;
        vector<int> ans;
        while(!qt.empty()){
            size = qt.size();
            bool flag=1;
            while(size--){
                TreeNode * cur = qt.front();
                qt.pop();
                if(cur!=NULL){
                    if(flag){
                        ans.push_back(cur->val);
                        flag=0;
                    }
                    if(cur->left!=NULL) qt.push(cur->left);
                    if(cur->right!=NULL) qt.push(cur->right);
                }
            }
        }
        return ans[ans.size()-1];
    }
};