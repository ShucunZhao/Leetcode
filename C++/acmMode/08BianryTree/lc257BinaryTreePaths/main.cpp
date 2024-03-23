#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode():val(0),left(nullptr),right(nullptr) {}
		TreeNode(int inVal) :val(inVal),left(nullptr),right(nullptr) {}
		TreeNode(int inVal, TreeNode* inL, TreeNode* inR) :val(inVal), left(inL), right(inR) {}
};

class Solution {
	public:
		string path;
		vector<string> ans;
		// Solution() :path(""), ans({}) {}
		vector<string> binaryTreePaths(TreeNode* root) {
			preorder(root, path, ans);
			return ans;
		}
		void preorder(TreeNode* root, string& path, vector<string>& ans) {
			if (root == nullptr) {
				return;
			}
			if (root->left==nullptr&&root->right==nullptr) {
				ans.push_back(path+to_string(root->val));
				return;
			} 
			string str = to_string(root->val);
			path += str;
			if (root->left) {
				path += "->";
				preorder(root->left, path, ans);
				path.erase(path.size()-2, 2);
			}
			if (root->right) {
				path +="->";
				preorder(root->right, path, ans);
				path.erase(path.size()-2, 2);
			}
			path.erase(path.size()-str.size(), str.size());
		}
};

TreeNode* construct(vector<int>& nums) {
	vector<TreeNode*> nodes;
	for (int i : nums) {
		if (i == -1) nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(i));
	} 
	TreeNode* root = nodes[0];
	int childI = 1;
	for (TreeNode * cur : nodes) {
		if (cur != nullptr && childI < nodes.size()) cur->left = nodes[childI++];
		if (cur != nullptr && childI < nodes.size()) cur->right = nodes[childI++];
	}
	return root;
}

int main(int argc, char* args[]) {
	while (true) {
		Solution S1;
		string In;
		cout << "Enter the tree nodes:" << endl;
		getline(cin, In);
		if (In == "q") break;
		In = In.substr(1, In.size() - 1);
		TreeNode* root = nullptr;
		if (!In.empty()) {
			vector<int> nums;
			stringstream ss(In);
			string token;
			while (getline(ss, token, ',')) {
				size_t first = token.find_first_not_of(" ");
				size_t last = token.find_last_not_of(" ");
				token = token.substr(first, last - first + 1);
				if (token == "null") nums.push_back(-1);
				else nums.push_back(stoi(token));
			}
			root = construct(nums);
		}
		vector<string> res = S1.binaryTreePaths(root);
		cout << "Res: [" << endl;
		for (string s : res) cout << s << "," << endl;
		cout << "]";
	}
}