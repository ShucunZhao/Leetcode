/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		if(!root) return {};
		queue<TreeNode*> Q;
		vector<int> ans;
		Q.push(root);
		int size;
		while(!Q.empty()){
			size = Q.size();
			while(size--){
				TreeNode * cur = Q.front();
				Q.pop();
				ans.push_back(cur->val);
				if(cur->left){
					Q.push(cur->left);
				}
				if(cur->right){
					Q.push(cur->right);
				}
			}
		}
		return ans;
    }
};
