/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        /*
            Use level traversal and designate index for each level, and if meet the un-end
            null node should treat it as a node and increse the index, then use the index of
            last node to subtract the first index to get width of each level and get the max ans.

            KeyPoint each children node index have a relationship with their father:
            leftChildIndex = 2*fatherIndex, rightChildIndex = 2*fatherIndex+1.
        */
        queue<pair<TreeNode*, long long> > Q;
        Q.push(make_pair(root, 0));
        int size;
        long long ans = 0;
        while(!Q.empty()){
            size = Q.size();
            long long head, tail;
            int first = size-1;
            while(size--){
                auto x = Q.front();
                Q.pop();
                TreeNode * cur = x.first;
                long long index = x.second;
                if(size==first){
                    head = index;
                }
                if(size==0){
                    tail = index;
                }
                if(cur->left){
                    Q.push(make_pair(cur->left, (index%INT_MAX)*2));
                }
                if(cur->right){
                    Q.push(make_pair(cur->right, (index%INT_MAX)*2+1));
                }
            }
            ans = max(ans, tail-head+1);
        }
        return ans;
    }
};