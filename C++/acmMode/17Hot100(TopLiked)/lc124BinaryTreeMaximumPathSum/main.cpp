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
	TreeNode(int inV, TreeNode * inL, TreeNode * inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
	int ans = INT_MIN;
	int maxPathSum(TreeNode* root) {
		postOrder(root);
		return ans;
	}
	int postOrder(TreeNode* root) {
		if (!root) return 0;
		int L = max(postOrder(root->left), 0);
		int R = max(postOrder(root->right), 0);
		int total = L + R + root->val;
		ans = max(ans, total);
		return root->val + max(L, R);
	}
};

TreeNode* construct(vector<int> & nums) {
	vector<TreeNode*> nodes;
	for (int& i : nums) {
		if (i == -1) nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(i));
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
		cout << "Enter the root:" << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		In = In.substr(1, In.size() - 2);
		vector<int> nums;
		if (!In.empty()) {
			stringstream ss(In);
			string token;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				token = token.substr(l, r - l + 1);
				if (token == "null") nums.push_back(-1);
				else nums.push_back(stoi(token));
			}
		}
		TreeNode* root = construct(nums);
		cout << "Res: " << S1.maxPathSum(root) << endl;
	}
}