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
    TreeNode(int inV, TreeNode * inL, TreeNode * inR) :val(0), left(inL), right(inR) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        size_t index = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[index]);
        vector<int> L(nums.begin(), nums.begin() + index);
        vector<int> R(nums.begin() + index + 1, nums.end());
        root->left = sortedArrayToBST(L);
        root->right = sortedArrayToBST(R);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null,";
        return;
    }
    cout << root->val << ",";
    printTree(root->left);
    printTree(root->right);
    return;
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string N;
        cout << "Enter the tree nodes:" << endl;
        getline(cin, N);
        if (N == "q") break;
        N = N.substr(1, N.size() - 2);
        vector<int> nums;
        if (!N.empty()) {
            stringstream ss(N);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        TreeNode* res = S1.sortedArrayToBST(nums);
        cout << "Res: [";
        printTree(res);
        cout << "]" << endl;
    }
}
