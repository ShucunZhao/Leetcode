/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(!pNode) return NULL;
        //Case1: Has right children.
        if(pNode->right){
            TreeLinkNode * cur = pNode->right;
            while(cur->left){
                cur = cur->left;
            }
            return cur;
        }
        else if(pNode->next&&pNode->next->left==pNode){//Cases2: Has no right children and is leftNode.
            return pNode->next;
        }
        else if(pNode->next&&pNode->next->right==pNode){//Cases3: Has no right children and is rightNode.
            TreeLinkNode * cur = pNode;
            while(cur->next){
                TreeLinkNode * father1 = cur->next;//6
                TreeLinkNode * father2 = cur->next->next;//8
                if(father2!=NULL&&father2->left==father1) return father2;
                cur = cur->next;
            }
        }
        return NULL;
    }
};
