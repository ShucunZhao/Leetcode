class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode) return nullptr;
        if (pNode->right) {
            TreeLinkNode* cur = pNode->right;
            while (cur && cur->left) {
                cur = cur->left;
            }
            return cur;
        }
        if (pNode->next && pNode->next->left == pNode) {
            return pNode->next;
        }
        if (pNode->next && pNode->next->right == pNode) {
            while (pNode&&pNode->next) {
                TreeLinkNode* f1 = pNode->next;
                TreeLinkNode* f2 = pNode->next->next;
                if (f2&&f2->left == f1) {
                    return f2;
                }
                pNode = pNode->next;
            }
        }
        return nullptr;
    }
};