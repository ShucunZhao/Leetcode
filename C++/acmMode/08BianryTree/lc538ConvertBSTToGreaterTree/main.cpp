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
    TreeNode(int inV, TreeNode * inL,TreeNode * inR) :val(0), left(inL), right(inR) {}
};

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        root->right = convertBST(root->right);
        root->val += sum;
        sum = root->val;
        root->left = convertBST(root->left);
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
        string N;
        cout << "Enter nodes:" << endl;
        getline(cin, N);
        if (N == "q") break;
        N = N.substr(1, N.size() - 2);
        TreeNode* root = nullptr;
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
        TreeNode* res = S1.convertBST(root);
        cout << "Res: [";
        printTree(res);
        cout << "]"<<endl;
;    }
}