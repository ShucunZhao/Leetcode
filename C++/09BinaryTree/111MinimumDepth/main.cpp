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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> qt;
        if(root!=NULL){
            qt.push(root);
        }
        else{
            return 0;
        }
        int size;
        int ans = 1;
        while(!qt.empty()){
            size = qt.size();
            while(size--){
                TreeNode * cur = qt.front();
                qt.pop();
                if(cur!=NULL){
                    if(cur->left!=NULL){
                        qt.push(cur->left);
                    }
                    if(cur->right!=NULL){
                        qt.push(cur->right);
                    }
                    if((cur->left==NULL)&&(cur->right==NULL)){//When the node is leaf, it's the shortest path destination.
                        return ans;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};