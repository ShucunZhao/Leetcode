#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int inV):val(inV),left(nullptr), right(nullptr) {}
	TreeNode(int inV, TreeNode * inL, TreeNode * inR):val(inV), left(inL), right(inR) {}
};

class Solution {
public:
	TreeNode* cur = nullptr;
	TreeNode* pre = nullptr;
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (!pRootOfTree) return pRootOfTree;
		inorder(pRootOfTree);
		TreeNode* first = cur;
		while (first->left) first = first->left;
		return first;
	}
	void inorder(TreeNode* pRootOfTree) {
		if (!pRootOfTree) return;
		inorder(pRootOfTree->left);
		cur = pRootOfTree;
		if (pre) {
			cur->left = pre;
			pre->right = cur;
		}
		pre = cur;
		inorder(pRootOfTree->right);
		return;
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

void printAscending(TreeNode* head) {
	if (!head) return;
	printAscending(head->right);
	cout << head->val<<",";
}

void printDescending(TreeNode* tail) {
	if (!tail) return;
	printDescending(tail->left);
	cout << tail->val << ",";
}

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter the tree:" << endl;
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
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				token = token.substr(l, r - l + 1);
				if (token == "#") nums.push_back(-1);
				else nums.push_back(stoi(token));
			}
			root = construct(nums);
		}
		TreeNode* res = S1.Convert(root);
		TreeNode* cur1 = res;
		TreeNode* cur2 = res;
		while (cur2->right) cur2 = cur2->right;
		cout << "Ascending: [";
		printAscending(cur1);
		cout << "]" << endl;
		cout << "Decending: [";
		printDescending(cur2);
		cout << "]" << endl;
	}
}