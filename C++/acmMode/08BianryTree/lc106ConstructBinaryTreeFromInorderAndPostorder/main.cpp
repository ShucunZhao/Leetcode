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
    TreeNode(int inV, TreeNode* inL, TreeNode* inR) :val(inV), left(inL), right(inR) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
        *                                                          R 
            Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
            Output: [3,9,20,null,null,15,7]
        */
        return construct(inorder, postorder);
    }

    TreeNode* construct(vector<int> inorder, vector<int> postorder) {
        if (postorder.size() == 0) return nullptr;
        int rVal = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rVal);
        size_t rPos = 0;
        for (rPos; rPos < inorder.size(); ++rPos) {
            if (inorder[rPos] == rVal) {
                break;
            }
        }
        vector<int> leftIn(inorder.begin(), inorder.begin()+rPos);
        vector<int> rightIn(inorder.begin() + rPos + 1, inorder.end());
        int sizeL = leftIn.size();
        vector<int> leftPost(postorder.begin(), postorder.begin() + sizeL);
        vector<int> rightPost(postorder.begin() + sizeL, postorder.end() - 1);
        root->left = construct(leftIn, leftPost);
        root->right = construct(rightIn, rightPost);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << ",";
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char * argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter inorder:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter postorder: " << endl;
        string Post;
        getline(cin, Post);
        if (Post == "q") break;
        vector<int> inorder;
        vector<int> postorder;
        In = In.substr(1, In.size() - 2);
        Post = Post.substr(1, Post.size() - 2);
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                inorder.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        if (!Post.empty()) {
            stringstream ss(Post);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                postorder.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        TreeNode* res = S1.buildTree(inorder, postorder);
        printTree(res);
        cout << endl;
    }
}