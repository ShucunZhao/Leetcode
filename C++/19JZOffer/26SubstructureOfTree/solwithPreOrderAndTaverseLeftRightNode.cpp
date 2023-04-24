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
	bool isSame(TreeNode* pRoot1, TreeNode* pRoot2){
		if(pRoot2==NULL){
			return true;
		}
		if(pRoot1==NULL){
			return pRoot2==NULL;
		}
		if(pRoot1->val==pRoot2->val){
			bool L = isSame(pRoot1->left, pRoot2->left);
			bool R = isSame(pRoot1->right, pRoot2->right);
			if(L&&R){
				return true;
			}
		}
		return false;
	}
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if(pRoot1==NULL||pRoot2==NULL){
			return false;
		}
		if(isSame(pRoot1, pRoot2)) return true;
		return HasSubtree(pRoot1->left, pRoot2)||HasSubtree(pRoot1->right, pRoot2);

    }
};
