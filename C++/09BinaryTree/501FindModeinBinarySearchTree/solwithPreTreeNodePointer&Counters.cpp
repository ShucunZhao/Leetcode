class Solution {
public:
    int cntMax = 0;
    TreeNode * pre = NULL;
    int cnt = 0; // Declare cnt as a member variable, initialize cnt to 0 before each call to inorder.
    // vector<int> Arr;
    vector<int> Mode;
    void inorder(TreeNode * root){
        if(!root) return;
        inorder(root->left);
        // if(!Arr.empty()){
            // pre = Arr.back();
        if(pre&&pre->val==root->val){
            cnt++; // increment cnt correctly
        }
        else{
            cnt = 0;
        }
        // }
        if(cnt==cntMax){
            if(find(Mode.begin(), Mode.end(), root->val)==Mode.end()){
                Mode.push_back(root->val);//0
            }
        }
        else if(cnt>cntMax){
            cntMax = cnt;
            Mode.clear();
            Mode.push_back(root->val);
        }
        // Arr.push_back(root->val);
        pre = root;
        inorder(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return Mode;
    }
};
