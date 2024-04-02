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
    TreeNode(int inV) :val(inV), left(nullptr), right(nullptr) {}
    TreeNode(int inV, TreeNode* inL, TreeNode* inR) :val(inV), left(inL), right(inR) {}
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        else if (!root1&& root2) {
            root1 = new TreeNode(root2->val);
        }
        else if (root1 && !root2) {
            root2 = new TreeNode(root1->val);
        }
        else {
            root1->val += root2->val;
        }
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

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
        cout << "Enter root1:"<<endl;
        string R1;
        getline(cin, R1);
        if (R1 == "q") break;
        cout << "Enter root2:"<<endl;
        string R2;
        getline(cin, R2);
        if (R2 == "q") break;
        R1 = R1.substr(1, R1.size() - 2);
        R2 = R2.substr(1, R2.size() - 2);
        TreeNode* root1 = nullptr;
        TreeNode* root2 = nullptr;
        if (!R1.empty()) {
            stringstream ss(R1);
            string token;
            vector<int> nums;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                if (token == "null") nums.push_back(-1);
                else nums.push_back(stoi(token));
            }
            root1 = construct(nums);
        }
        if (!R2.empty()) {
            stringstream ss(R2);
            string token;
            vector<int> nums;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                nums.push_back(stoi(token));
            }
            root2 = construct(nums);
        }
        TreeNode* res = S1.mergeTrees(root1, root2);
        cout << "Res:" << endl;
        printTree(res);
        cout << endl;
    }
}