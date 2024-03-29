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
    TreeNode(int inVal) :val(inVal), left(nullptr), right(nullptr) {}
    TreeNode(int inVal, TreeNode* inL, TreeNode* inR) :val(inVal), left(inL), right(inR){}
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
    vector<int> path;
    vector<vector<int> > ans;
    int curSum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root, targetSum, curSum, path, ans);
        return ans;
    }
    void preorder(TreeNode* root, int& targetSum, int& curSum, vector<int>& path, vector<vector<int> >& ans) {
        if (!root) {
            return;
        }
        curSum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (curSum == targetSum) {
                ans.push_back(path);
            }
        }
        if (root->left) {
            preorder(root->left, targetSum, curSum, path, ans);
        }
        if (root->right) {
            preorder(root->right, targetSum, curSum, path, ans);
        }
        curSum -= root->val;
        path.pop_back();
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter tree nodes:" << endl;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter targetSum: " << endl;
        string target;
        getline(cin, target);
        if (target == "q") break;
        TreeNode * root = nullptr;
        In = In.substr(1, In.size() - 2);
        if (!In.empty()) {
            string token;
            stringstream ss(In);
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
        int targetSum = stoi(target);
        vector<vector<int> > res = S1.pathSum(root, targetSum);
        cout << "Res: [";
        for (vector<int>& tmp : res) {
            cout << "[";
            for (int& i : tmp) {
                cout << i << ",";
            }
            cout << "]," << endl;
        }
        cout << "]" << endl;
    }
}