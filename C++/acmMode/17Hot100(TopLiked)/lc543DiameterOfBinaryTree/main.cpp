#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int inV) :val(inV), left(nullptr), right(nullptr) {}
	TreeNode(int inV, TreeNode * inL, TreeNode *inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
	int ans = 0;
	int postorder(TreeNode* root) {
		if (!root) return 0;
		int L = postorder(root->left);
		int R = postorder(root->right);
		ans = max(L + R, ans);
		return max(L, R) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		postorder(root);
		return ans;
	}
};

TreeNode* construct(vector<string> & Tree) {
	vector<TreeNode*> nodes;
	for (string& s : Tree) {
		if (s == "null") nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(stoi(s)));
	}
	int childI = 1;
	TreeNode* root = nodes[0];
	for (TreeNode* cur : nodes) {
		if (cur && childI < nodes.size()) cur->left = nodes[childI++];
		if (cur && childI < nodes.size()) cur->right = nodes[childI++];
	}
	return root;
}

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter tree:" << endl;
		string In;
		getline(cin, In);
		In = In.substr(1, In.size() - 2);
		TreeNode* root = nullptr;
		if (!In.empty()) {
			stringstream ss(In);
			string token;
			vector<string> Tree;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				Tree.push_back(token.substr(l, r - l + 1));
			}
			root = construct(Tree);
		}
		cout << "Res: " << S1.diameterOfBinaryTree(root) << endl;
	}
}