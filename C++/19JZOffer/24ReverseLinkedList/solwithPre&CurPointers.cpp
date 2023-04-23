/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		/*
			pre   cur
		    NULL { 1,  2,  3}
		*/
		if(!pHead) return pHead;
		ListNode * pre = NULL, * cur = pHead;
		while(cur){
			ListNode * tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
    }
};
