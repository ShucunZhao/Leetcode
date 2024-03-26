#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(nullptr),right(nullptr) {}
	TreeNode(int inVal):val(inVal),left(nullptr),right(nullptr) {}
	TreeNode(int inVal, TreeNode* inL, TreeNode* inR) :val(inVal), left(inL), right(inR) {}
};

TreeNode* construct(vector<int>& nums) {
	vector<TreeNode*> nodes;
	for (int& i : nums) {
		if (i == -1) nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(i));
	}
	TreeNode* root = nodes[0];
	int childI = 1;
	for (TreeNode * cur : nodes) {
		if (cur && childI < nodes.size()) cur->left = nodes[childI++];
		if (cur && childI < nodes.size()) cur->right = nodes[childI++];
	}
	return root;
}

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> Q;
		Q.push(root);
		int size;
		int ans = root->val;
		while (!Q.empty()) {
			size = Q.size();
			bool first = true;
			while (size--) {
				TreeNode* cur = Q.front();
				Q.pop();
				if (cur->left) {
					Q.push(cur->left);
					if (first) {
						ans = cur->left->val;
						first = false;
					}
				} 
				if (cur->right) {
					Q.push(cur->right);
					if (first) {
						ans = cur->right->val;
						first = false;
					}
				}
			}
		}
		return ans;
	}
	int findBottomLeftValue_sol2(TreeNode* root) {
		/*
			We need find the deepest node and which should be the left-most one.
		*/
		int curD = 1;
		int maxD = 0;
		int ans = -1;
		preorder(root, ans, curD, maxD);
		return ans;
	}
	void preorder(TreeNode* root, int& ans, int& curD,  int& maxD) {
		if (curD > maxD) {
			maxD = curD;
			ans = root->val;
		}
		if (root->left) {
			curD++;
			preorder(root->left, ans, curD, maxD);
			curD--;
		}
		if (root->right) {
			curD++;
			preorder(root->right, ans, curD, maxD);
			curD--;
		}
	}
};

int main(int argc, char* args[]) {
	while (true) {
		Solution S1;
		cout << "Enter tree nodes: " << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		In = In.substr(1, In.size() - 2);
		TreeNode* root = nullptr;
		if (!In.empty()) {
			stringstream ss(In);
			string token;
			vector<int> nums;
			while (getline(ss, token, ',')) {
				size_t first = token.find_first_not_of(" ");
				size_t last = token.find_last_not_of(" ");
				token = token.substr(first, last - first + 1);
				if (token == "null") nums.push_back(-1);
				else nums.push_back(stoi(token));
			}
			root = construct(nums);
		}
		cout << "Res1:" << S1.findBottomLeftValue(root) << endl;
		cout << "Res2:" << S1.findBottomLeftValue_sol2(root) << endl;
	}
}