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
    TreeNode(int inV) :val(inV), left(nullptr), right(nullptr) {}
    TreeNode(int inV, TreeNode * inL, TreeNode * inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left && !root->right) {
                root = nullptr;
            }
            else if (root->left && !root->right) {
                root = root->left;
            }
            else if (!root->left && root->right) {
                root = root->right;
            }
            else {
                TreeNode* right = root->right;
                TreeNode* cur = right;
                while (cur && cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                return right;
            }
        }
        return root;
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
    return;
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the tree nodes: " << endl;
        string T;
        getline(cin, T);
        if (T == "q") break;
        cout << "Enter the key: " << endl;
        string K;
        getline(cin, K);
        if (K == "q") break;
        T = T.substr(1, T.size() - 2);
        TreeNode* root = nullptr;
        if (!T.empty()) {
            stringstream ss(T);
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
        int key = stoi(K);
        TreeNode* res = S1.deleteNode(root, key);
        cout << "Res: [";
        printTree(res);
        cout << "]" << endl;
    }
}

