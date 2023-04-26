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
	void backtracking(TreeNode * root, int sum, int target, vector<int> & path, vector<vector<int> > & ans){
		if(!root->left&&!root->right){
			sum+=root->val;
			path.push_back(root->val);
			if(sum==target){
				ans.push_back(path);
			}
			path.pop_back();
			return;
		}
		sum+=root->val;//10,15,19
		path.push_back(root->val);//[10,5,4]
		if(root->left){
			backtracking(root->left, sum, target, path, ans);
		}
		if(root->right){
			backtracking(root->right, sum, target, path, ans);
		}
		sum-=root->val;
		path.pop_back();
		return;
	}
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
		if(!root) return {};
		vector<int> path;
		vector<vector<int> > ans;
		backtracking(root, 0, expectNumber, path, ans);
		return ans;
    }
};