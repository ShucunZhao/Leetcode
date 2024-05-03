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
    TreeNode(int inV):val(inV), left(nullptr), right(nullptr) {}
    TreeNode(int inV, TreeNode* inL, TreeNode* inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* tmpL = nullptr;
        TreeNode* tmpR = nullptr;
        if (root->left) {
            tmpL = root->left;
            root->left = nullptr;
            tmpR = root->right;
            root->right = tmpL;
            TreeNode* cur = tmpL;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = tmpR;
        }
        if (root->right) {
            flatten(root->right);
        }
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

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << ",";
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char* argv) {
    while (true) {
        Solution S1;
        cout << "Enter tree:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        vector<int> nums;
        In = In.substr(1, In.size() - 2);
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
        S1.flatten(root);
        cout << "Res: [";
        printTree(root);
        cout << "]" << endl;
    }
}