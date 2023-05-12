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
	//int depth = 0;
    int TreeDepth(TreeNode* pRoot) {
		if(!pRoot){
			return 0;
		}
		int L = TreeDepth(pRoot->left);
		int R = TreeDepth(pRoot->right);
		return max(L,R)+1;
    }
};
