#include <iostream>
#include <vector>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if (L && R) return root;
        if (L) {
            if (root == p || root == q) return root;
            return L;
        }
        if (R) {
            if (root == p || root == q) return root;
            return R;
        }
        if (root == p || root == q) return root;
        return nullptr;
    }
};

TreeNode* construct(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    vector<TreeNode*> tree;
    for (int i : nums) {
        if (i == -1) tree.push_back(nullptr);
        else tree.push_back(new TreeNode(i));
    }
    TreeNode* root = tree[0];
    int childI = 1;
    for (TreeNode* cur : tree) {
        if (cur && childI < tree.size()) cur->left = tree[childI++];
        if (cur && childI < tree.size()) cur->right = tree[childI++];
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int V) {
    if (!root) return nullptr;
    if (root->val == V) return root;
    TreeNode * L = findNode(root->left, V);
    TreeNode * R = findNode(root->right, V);
    if (L) return L;
    if (R) return R;
    return nullptr;
}

int main(int argc, char* argv[]) {
    //vector<int> root = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };
    //int p = 5, q = 1;
    vector<int> root = { 1,2 };
    int p = 1, q = 2;
    TreeNode* tRoot = construct(root);
    TreeNode* pN = findNode(tRoot, p);
    TreeNode* qN = findNode(tRoot, q);
    Solution S;
    cout << "Res: " << S.lowestCommonAncestor(tRoot, pN, qN)->val << endl;
}