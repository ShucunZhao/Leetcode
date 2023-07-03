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
class BSTIterator {
public:
    vector<int> arr;
    //int pre;
    int cur;
    void convert2Arr(TreeNode * root){
        if(!root) return;
        convert2Arr(root->left);
        arr.push_back(root->val);
        convert2Arr(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {
        convert2Arr(root);
        cur = 0;
    }
    
    int next() {
        // if(cur>=arr.size()){

        // }
        int rst = arr[cur];
        cur++;
        return rst;
    }
    
    bool hasNext() {
        return cur<arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */