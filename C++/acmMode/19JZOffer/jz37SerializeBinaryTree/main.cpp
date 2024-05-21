#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int inV):val(inV), left(nullptr), right(nullptr) {}
	TreeNode(int inV, TreeNode * inL, TreeNode * inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
	char* Serialize(TreeNode* root) {
		queue<TreeNode*> Q;
		Q.push(root);
		string str;
		while (!Q.empty()) {
			int size = Q.size();
			while (size--) {
				TreeNode* cur = Q.front();
				Q.pop();
				if (!cur) {
					str += "#,";
					continue;
				}
				else {
					str += (to_string(cur->val) + ",");
				}
				Q.push(cur->left);
				Q.push(cur->right);
			}
		}
		str.pop_back();
		char* ans = new char[str.size()+1];
		strcpy_s(ans,str.size()+1, str.c_str());
		return ans;
	}
	TreeNode* Deserialize(char* str) {
		stringstream ss(str);
		string token;
		vector<TreeNode*> nodes;
		while (getline(ss, token, ',')) {
			if (token == "#") nodes.push_back(nullptr);
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
};

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter the tree:" << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		In = In.substr(1, In.size()-2);
		char* str = new char[In.size() + 1];
		strcpy_s(str, In.size()+1,In.c_str());
		TreeNode* root = S1.Deserialize(str);
		string s(S1.Serialize(root));
		cout << "Res: " << s << endl;
	}
}