#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class  TreeNode {
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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot2) return false;
		if (!pRoot1) return false;
		if (check(pRoot1, pRoot2)) {
			return true;
		}
		bool L = HasSubtree(pRoot1->left, pRoot2);
		bool R = HasSubtree(pRoot1->right, pRoot2);
		return L || R;
	}
	bool check(TreeNode* p1, TreeNode* p2) {
		if (!p2) return true;
		if (!p1) return false;
		bool L = false;
		bool R = false;
		if (p1->val != p2->val) {
			return false;
		}
		L = check(p1->left, p2->left);
		R = check(p1->right, p2->right);
		return L && R;
	}
};

TreeNode* construct(vector<int>& nums) {
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

TreeNode* getTree(string & In) {
	if (In.empty()) return nullptr;
	stringstream ss(In);
	string token;
	vector<int> nums;
	while (getline(ss, token, ',')) {
		size_t l = token.find_first_not_of(" ");
		size_t r = token.find_last_not_of(" ");
		if (token == "#") nums.push_back(-1);
		else nums.push_back(stoi(token.substr(l, r - l + 1)));
	}
	return construct(nums);
}

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter the tree1: " << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		In = In.substr(1, In.size() - 2);
		TreeNode* p1 = getTree(In);
		cout << "Enter the tree2: " << endl;
		string In2;
		getline(cin, In2);
		if (In2 == "q") break;
		In2 = In2.substr(1, In2.size() - 2);
		TreeNode* p2 = getTree(In2);
		cout << "Res: " << S1.HasSubtree(p1, p2) << endl;
	}
}