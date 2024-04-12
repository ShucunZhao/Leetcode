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
	TreeNode(int inV, TreeNode * inL, TreeNode * inR) :val(inV), left(inL), right(nullptr) {}
};

TreeNode* construct(vector<int> nums) {
	vector<TreeNode*> nodes;
	for (int& i : nums) {
		if (i == -1) nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(i));
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
	TreeNode* trimBST2(TreeNode* root, int low, int high) {
		if (!root) return nullptr;
		if (root->val >= low && root->val <= high) {
			root->left = trimBST2(root->left, low, high);
			root->right = trimBST2(root->right, low, high);

		}
		else if (root->val > high) {
			root = trimBST2(root->left, low, high);
		}
		else {
			root = trimBST2(root->right, low, high);
		}
		return root;
	}
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) return nullptr;
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		if (root->val >= low && root->val <= high) return root;
		else {
			if (!root->left && !root->right) root = nullptr;
			else if (root->left && !root->right) root = root->left;
			else if (!root->left && root->right) root = root->right;
			else {
				TreeNode* right = root->right;
				TreeNode* cur = right;
				while (cur && cur->left) {
					cur = cur->left;
				}
				cur->left = root->left;
				return right;
			}
		}
		return root;
	}
};

void printTree(TreeNode* root) {
	if (!root) return;
	cout << root->val << ",";
	printTree(root->left);
	printTree(root->right);
	return;
}

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter tree nodes:" << endl;
		string N;
		getline(cin, N);
		if (N == "q") break;
		cout << "Enter low:" << endl;
		string L;
		getline(cin, L);
		if (L == "q") break;
		cout << "Enter high:" << endl;
		string H;
		getline(cin, H);
		if (H == "q") break;
		N = N.substr(1, N.size() - 2);
		TreeNode* root = nullptr;
		if (!N.empty()) {
			stringstream ss(N);
			string token;
			vector<int> nums;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				token = token.substr(l, r - l + 1);
				if (token == "null") nums.push_back(-1);
				else nums.push_back(stoi(token));
			}
			root = construct(nums);
		}
		int low = stoi(L);
		int high = stoi(H);
		TreeNode* res = S1.trimBST(root, low, high);
		cout << "Res: [";
		printTree(res);
		cout << "]" << endl;
	}
}