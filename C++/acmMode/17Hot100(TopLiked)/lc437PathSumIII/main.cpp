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
	TreeNode(int inV, TreeNode* inL, TreeNode* inR) :val(inV), left(inL), right(inR) {}
};

TreeNode* construct(string In) {
	In = In.substr(1, In.size() - 2);
	if (In.empty()) return nullptr;
	stringstream ss(In);
	string token;
	vector<TreeNode*> nodes;
	while (getline(ss, token, ',')) {
		size_t l = token.find_first_not_of(" ");
		size_t r = token.find_last_not_of(" ");
		token = token.substr(l, r - l + 1);
		if (token == "null") nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(stoi(token)));
	}
	TreeNode* root = nodes[0];
	int childI = 1;
	for (TreeNode* cur : nodes) {
		if (cur && childI < nodes.size()) cur->left = nodes[childI++];
		if (cur && childI < nodes.size()) cur->right = nodes[childI++];
	}
	return root;
}

class Solution {
public:
	long long ans = 0;
	long long curSum = 0;
	int pathSum(TreeNode* root, int targetSum) {
		if (!root) return 0;
		curSum = 0;
		preOrder(root, targetSum);
		curSum = 0;
		pathSum(root->left, targetSum);
		curSum = 0;
		pathSum(root->right, targetSum);
		return ans;
	}

	void preOrder(TreeNode* root, int targetSum) {
		if (!root) return;
		curSum += root->val;
		if (curSum == targetSum) ans++;
		preOrder(root->left, targetSum);
		preOrder(root->right, targetSum);
		curSum -= root->val;
		return;
	}
};

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter tree:" << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		cout << "Enter sum:" << endl;
		string K;
		getline(cin, K);
		if (K == "q") break;
		TreeNode* root = construct(In);
		int k = stoi(K);
		cout << "Res: " << S1.pathSum(root, k) << endl;
	}
}