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
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if(!head) return NULL;
        if(head->val==val) return head->next;
        ListNode * dum = new ListNode(0);
        dum->next = head;
        while(head->next){
            if(head->next->val==val){
                head->next = head->next->next;
            }
            head = head->next;
        }
        return dum->next;
    }
};