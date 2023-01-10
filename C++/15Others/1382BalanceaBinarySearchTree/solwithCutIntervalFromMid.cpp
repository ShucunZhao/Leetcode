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
    vector<int> Set;
    void traverse(TreeNode * root){
        if(root==NULL) return;
        traverse(root->left);
        Set.push_back(root->val);
        traverse(root->right);
    }
    TreeNode * construct(vector<int> & Set, int l, int r){
        if(l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode * root = new TreeNode(Set[mid]);
        root->left = construct(Set, l, mid-1);
        root->right = construct(Set, mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        // for(int i:Set){
        //     cout<<i<<endl;
        // }
        return construct(Set, 0, Set.size()-1);
    }
};