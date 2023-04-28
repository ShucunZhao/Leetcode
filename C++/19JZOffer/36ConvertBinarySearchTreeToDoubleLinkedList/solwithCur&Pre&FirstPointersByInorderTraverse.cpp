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
	//TreeNode * cur = NULL;//The current node when traversing tree, use it as 
	//Preorder function's parameter here.
	TreeNode * first = NULL;//Record the first node in converted list.
	TreeNode * pre = NULL;//The previous node when traversing tree.
	void Inorder(TreeNode * cur){
		if(cur==NULL) return;
		Inorder(cur->left);
		if(pre==NULL){//That's means the current node is the first node
			first = cur;		
		}
		else{
			pre->right = cur;
			cur->left = pre;
		}
		pre = cur;
		Inorder(cur->right);
		return;
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
        /*
			Pointers:
				mid, left, right
			Traverse with inorder:
				left->mid->right.
		*/
		Inorder(pRootOfTree);
		return first;
    }
};
