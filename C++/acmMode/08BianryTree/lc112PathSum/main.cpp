#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int inV) :val(inV), left(nullptr), right(nullptr) {}
    TreeNode(int inV, TreeNode * inL, TreeNode * inR) :val(inV), left(inL), right(inR) {}
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

class Solution {
public:
    int path = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preorder(root, targetSum);
    }
    bool preorder(TreeNode* root, int& targetSum) {
        if (!root) {
            return false;
        }
        // path += root->val;
        if ((path+root->val) == targetSum && !root->left && !root->right) return true;
        bool L = false, R = false;
        if (root->left) {
            path += root->val;
            L = preorder(root->left, targetSum);
            if (L == true) return true;
            path -= root->val;
        }
        if (root->right) {
            path += root->val;
            R = preorder(root->right, targetSum);
            if (R == true) return true;
            path -= root->val;
        }
        return L || R;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        string targetSum;
        cout << "Enter tree nodes: " << endl;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter targetSum: " << endl;
        getline(cin, targetSum);
        if (targetSum == "q") break;
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
                if (token == "null") nums.push_back(-1);
                else nums.push_back(stoi(token));
            }
            root = construct(nums);
        }
        int tSum = stoi(targetSum);
        cout << "Res: " << S1.hasPathSum(root, tSum) << endl;
    }
}