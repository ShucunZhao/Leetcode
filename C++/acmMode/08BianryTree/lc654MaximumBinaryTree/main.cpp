#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << ",";
    printTree(root->left);
    printTree(root->right);
}

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        auto maxPos = max_element(nums.begin(), nums.end());
        int maxV = *maxPos;
        TreeNode* root = new TreeNode(maxV);
        vector<int> leftNums(nums.begin(), maxPos);
        vector<int> rightNums(++maxPos, nums.end());
        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r-l+1)));
            }
        }
        cout << "Res:" << endl;
        printTree(S1.constructMaximumBinaryTree(nums));
        cout << endl;
    }
} 