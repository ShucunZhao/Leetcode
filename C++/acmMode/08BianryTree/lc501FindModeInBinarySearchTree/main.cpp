#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int inV) :val(inV), left(nullptr), right(nullptr) {}
    TreeNode(int inV, TreeNode * inL, TreeNode *inR) :val(inV), left(inL), right(inR) {}
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
    TreeNode* pre = nullptr;
    int curCnt = 0;
    int maxCnt = 0;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        /*
            We need to use the feature of binary search tree which is a sorted array if traverse with inorder,
            so the duplicates must show at the same time, so we can do it with two pointers.
        */
        inOrder(root);
        return ans;
    }
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        if (pre && pre->val == root->val) {
            curCnt++;
        }
        else {
            curCnt = 1;
        }
        if (curCnt > maxCnt) {
            maxCnt = curCnt;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (curCnt == maxCnt && find(ans.begin(), ans.end(), root->val) == ans.end()) {
            ans.push_back(root->val);
        }
        pre = root;
        inOrder(root->right);
        return;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        string In;
        Solution S1;
        cout << "Enter the tree nodes:" << endl;
        getline(cin, In);
        if (In == "q") break;
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
        vector<int> res = S1.findMode(root);
        cout << "Res: [";
        for (int& i : res) cout << i << ",";
        cout << "]" << endl;
    }
}