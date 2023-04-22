/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if(!pHead) return NULL;
        ListNode * fast = pHead, * slow = pHead;
        while(fast&&k--){
            fast = fast->next;
        }
        if(!fast){
            if(k>0) return NULL;
            else return slow;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};