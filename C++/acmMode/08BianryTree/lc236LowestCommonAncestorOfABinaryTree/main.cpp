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
    TreeNode(int inV, TreeNode * inL,TreeNode * inR) :val(inV), left(inL), right(inR) {}
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

TreeNode* getNode(int i, TreeNode* root) {
    if (!root) return nullptr;
    if (root->val == i) return root;
    TreeNode * l = getNode(i, root->left);
    TreeNode * r = getNode(i, root->right);
    if (l) return l;
    return r;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if (L && R) return root;
        else if (L && !R) return L;
        else if (!L && R) return R;
        return nullptr;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string N;
        cout << "Enter tree nodes:" << endl;
        getline(cin, N);
        if (N == "q") break;
        string P;
        cout << "Enter p:" << endl;
        getline(cin, P);
        if (P == "q") break;
        string Q;
        cout << "Enter q:" << endl;
        getline(cin, Q);
        if (Q == "q") break;
        TreeNode* root = nullptr;
        N = N.substr(1, N.size() - 2);
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
        TreeNode * p = getNode(stoi(P), root);
        TreeNode* q = getNode(stoi(Q), root);
        cout << "Res: " << S1.lowestCommonAncestor(root, p, q)->val << endl;
    }
}