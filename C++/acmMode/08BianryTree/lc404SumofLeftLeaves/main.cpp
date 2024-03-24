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
    TreeNode(int inVal) :val(inVal), left(nullptr), right(nullptr) {}
    TreeNode(int inVal, TreeNode * inL, TreeNode * inR) :val(inVal), left(inL), right(inR) {}
};

TreeNode* construct(vector<int>& nums) {
    vector<TreeNode*> nodes;
    for (int i : nums) {
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

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        preorder(root);
        return ans;
    }
    void preorder(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) return;
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                ans += root->left->val;
            }
        }
        preorder(root->left);
        preorder(root->right);
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        cout << "Enter tree nodes:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size()-2);
        TreeNode* root = nullptr;
        if (!In.empty()) {
            stringstream ss(In);
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
        cout << "Res: " << S1.sumOfLeftLeaves(root) << endl;
        deleteTree(root);
    }
}