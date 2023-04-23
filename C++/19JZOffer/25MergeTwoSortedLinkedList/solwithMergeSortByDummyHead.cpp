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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        /*
			src: {1,2,3},{3,3,3}
			                    2
				      1       
                    c
		dum  {1, 2, 3, 3, 3}
		*/
		if(!pHead1) return pHead2;
		else if(!pHead2) return pHead1;
		ListNode * dum = new ListNode(0);
		ListNode * cur;
		if(pHead1->val<pHead2->val){
			cur = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			cur = pHead2;
			pHead2 = pHead2->next;
		}
		dum->next = cur;
		while(pHead1&&pHead2){
			if(pHead1->val<pHead2->val){
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else{
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		if(pHead1){
			cur->next = pHead1;
		}
		if(pHead2){
			cur->next = pHead2;
		}
		return dum->next;
    }
};
