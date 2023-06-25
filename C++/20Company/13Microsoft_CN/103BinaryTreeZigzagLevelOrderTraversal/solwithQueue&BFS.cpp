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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> Q; 
        Q.push(root);
        int size;
        bool even = true;
        vector<vector<int> > ans;
        while(!Q.empty()){
            size = Q.size();
            vector<int> path;
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                path.push_back(cur->val);
            }
            if(!even){
                reverse(path.begin(), path.end());
            }
            ans.push_back(path);
            even = !even;
        }
        return ans;
    }
};