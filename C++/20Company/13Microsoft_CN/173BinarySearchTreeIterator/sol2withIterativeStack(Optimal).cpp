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
/**
 * Use the method of iterative traversal method to traverse the binary tree with stack.
*/ 
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushFromLeft(root);
    }
    
    void pushFromLeft(TreeNode * root){
        while(root!=nullptr){
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        if(st.empty()){
            return -1;
        }
        TreeNode * cur = st.top();
        st.pop();
        // int val = cur->val;
        pushFromLeft(cur->right);
        return cur->val;
        // if(cur->right){
        //     cur = cur->right;

        // }

    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */