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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        /*
				        l
				1-2-3-6-7
				        r
				4-5-6-7
		*/
		ListNode * t1 = pHead1, * t2 = pHead2;
		while(t1&&t2){
			t1=t1->next;
			t2=t2->next;
		}
		ListNode * c1 = pHead1, * c2 = pHead2;
		if(!t1&&t2){
			while(t2){
				c2=c2->next;
				t2=t2->next;
			}
		}
		else if(t1&&!t2){
			while(t1){
				c1 = c1->next;
				t1 = t1->next;
			}
		}
		while(c1&&c2){
			if(c1==c2){
				return c1;
			}
			c1 = c1->next;
			c2 = c2->next;
		}
		return NULL;
    }
};
