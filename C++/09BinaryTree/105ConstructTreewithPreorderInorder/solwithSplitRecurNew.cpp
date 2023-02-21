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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            /*
                preorder = [3|,9,20,15,7],
                            m  lr
                inorder  = [9,|3,|15,20,7]
                            l  m   r
            */                  
            if(preorder.size()==0) return NULL;
            int rVal = preorder[0];
            TreeNode * root = new TreeNode(rVal);
            if(preorder.size()==1) return root;
            int rI;
            for(int i=0;i<inorder.size();i++){
                if(inorder[i]==rVal){
                    rI = i;
                    break;
                }
            }
            vector<int> lIn(inorder.begin(), inorder.begin()+rI);
            vector<int> lPre(preorder.begin()+1, preorder.begin()+1+lIn.size());
            vector<int> rIn(inorder.begin()+rI+1, inorder.end());
            vector<int> rPre(preorder.begin()+1+lIn.size(), preorder.end());
            /*
            cout<<"lIn:";
            for(int i : lIn){
                cout<<i<<",";
            }
            cout<<endl;
            cout<<"lPre:";
            for(int i : lPre){
                cout<<i<<",";
            }
            cout<<endl;       
            cout<<"rIn:";
            for(int i : rIn){
                cout<<i<<",";
            }
            cout<<endl;   
            cout<<"rPre:";
            for(int i : rPre){
                cout<<i<<",";
            }
            cout<<endl;  
            */                           
            root->left = buildTree(lPre, lIn);
            root->right = buildTree(rPre, rIn);
            return root;
    }
};