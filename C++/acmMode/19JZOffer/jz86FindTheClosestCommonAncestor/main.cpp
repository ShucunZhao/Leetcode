#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int inV):val(inV),left(nullptr), right(nullptr) {}
    TreeNode(int inV, TreeNode* inL, TreeNode* inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return postOrder(root, o1, o2);
    }

    int postOrder(TreeNode* root, int o1, int o2) {
        if (!root) return -1;
        int L = postOrder(root->left, o1, o2);
        int R = postOrder(root->right, o1, o2);
        if (L != -1 && R != -1) return root->val;
        if (L != -1) {
            if (root->val == o1 || root->val == o2) return root->val;
            else return L;
        }
        if (R != -1) {
            if (root->val == o1 || root->val == o2) return root->val;
            else return R;
        }
        if (root ->val == o1 || root->val == o2) return root->val;
        return -1;
    }
};

TreeNode* construct(string In) {
    if (In.empty()) return nullptr;
    stringstream ss(In);
    string token;
    vector<TreeNode*> nodes;
    while (getline(ss, token, ',')) {
        size_t l = token.find_first_not_of(" ");
        size_t r = token.find_last_not_of(" ");
        token = token.substr(l, r - l + 1);
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

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the tree:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter the o1:" << endl;
        string O1;
        getline(cin, O1);
        if (O1 == "q") break;
        cout << "Enter the o2:" << endl;
        string O2;
        getline(cin, O2);
        if (O2 == "q") break;
        In = In.substr(1, In.size() - 2);
        TreeNode* root = construct(In);
        int o1 = stoi(O1);
        int o2 = stoi(O2);
        cout << "Res: " << S1.lowestCommonAncestor(root, o1, o2) << endl;
    }
}