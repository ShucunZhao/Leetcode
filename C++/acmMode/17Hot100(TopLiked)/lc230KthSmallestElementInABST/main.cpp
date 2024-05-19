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
    TreeNode(int inV, TreeNode * inL, TreeNode* inR) :val(inV), left(inL), right(inR) {}
};

class Solution{
public:
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        /*
            Each valid node is the middle node, so we can use the inorder traversal 
            to count the number of valid node, which will be a ascending order,
            then we can find what we need.
        */
        if (!root) return -1;
        int L = kthSmallest(root->left, k);
        cnt++;
        if (cnt == k) {
            return root->val;
        }
        int R = kthSmallest(root->right, k);
        if (L != -1) return L;
        if (R != -1) return R;
        return -1;
    }
};

TreeNode * construct(vector<int>& nums) {
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

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the tree:" << endl;
        string T;
        getline(cin, T);
        if (T == "q") break;
        cout << "Enter the k:" << endl;
        string K;
        getline(cin, K);
        if (K == "q") break;
        TreeNode* root = nullptr;
        T = T.substr(1, T.size() - 2);
        if (!T.empty()) {
            vector<int> nums;
            stringstream ss(T);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                if (token == "null") nums.push_back(-1);
                else nums.push_back(stoi(token));
            }
            root = construct(nums);
        }
        int k = stoi(K);
        cout << S1.kthSmallest(root, k) << endl;
    }
}