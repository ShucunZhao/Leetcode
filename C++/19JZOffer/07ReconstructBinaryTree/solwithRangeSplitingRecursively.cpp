/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * construct(vector<int> & PreRange, vector<int> & InRange){
        if(PreRange.size()==0) return NULL;
        int rootVal = PreRange[0];
        TreeNode * root = new TreeNode(rootVal);
        int index;
        for(int i=0;i<InRange.size();i++){
            if(InRange[i]==rootVal){
                index = i;
                break;
            }
        }
        vector<int> leftIn(InRange.begin(), InRange.begin()+index);
        vector<int> rightIn(InRange.begin()+index+1, InRange.end());
        vector<int> leftPre(PreRange.begin()+1, PreRange.begin()+1+leftIn.size());
        vector<int> rightPre(PreRange.begin()+1+leftIn.size(), PreRange.end());
        root->left = construct(leftPre, leftIn);
        root->right = construct(rightPre, rightIn);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        /*
            First stack in root:
                root: 1
                               m (l & r)
                    preorder: {1,2,4,7,3,5,6,8}
                                l    m   r  
                    inorder:  {4,7,2,1,5,3,8,6}

                leftInRange: 4,7,2    ;   rightInRange: 5,3,8,6 
                (accoording to the size of leftInRange and rightInRange 
                to find the corresponding PreRanges:)
                leftPreRange: 2,4,7   ;   rightPreRange: 3,5,6,8
            Second stack in left:
                root:  2
                         m l r
                    pre: 2,4,7
                          l  m r
                    in:  4,7,2

                    leftIn:    4,7    rightIn: []
                    leftpre:   4,7    rightpre: []

            Second stack in right:
                root: 3
                         m l & r
                    pre: 3,5,6,8
                         l m  r
                    in:  5,3,8,6 
            ......
        */
        return construct(pre, vin);
    }
};