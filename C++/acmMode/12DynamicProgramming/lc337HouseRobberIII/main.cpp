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
    TreeNode(int inV, TreeNode*inL,TreeNode*inR) :val(inV), left(inL), right(inR) {}
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
    int rob(TreeNode* root) {
        /*Tree DP: need to use postOrder traverse to handle in middle node at last
            1.dp[0]: the maximum can get if rob in node i
              dp[1]: the maximum can get if do not rob in node i
            2.dp[0] = (leftDP[1]+rightDP[1]+root->val),
              dp[1] = max(leftDP[0], leftDP[1]) + max(rightDP[0], rightDP[1])
            3.Non-initial
        */
        vector<int> dp = postOrder(root);
        return max(dp[0], dp[1]);
    }
    vector<int> postOrder(TreeNode* root) {
        vector<int> tmp(2);
        if (!root) {
            return { 0, 0 };
        }
        vector<int> leftDP = postOrder(root->left);
        vector<int> rightDP = postOrder(root->right);
        int Rob = leftDP[1] + rightDP[1] + root->val;
        int notRob = max(leftDP[0], leftDP[1]) + max(rightDP[0], rightDP[1]);
        return { Rob, notRob };
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "enter tree nodes:" << endl;
        string N;
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
        cout << "Res: " << S1.rob(root) << endl;
    }
}