/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead) return NULL;
        unordered_map<int, RandomListNode*> ms;
        RandomListNode * cur1 = pHead; 
        RandomListNode * cur2 = new RandomListNode(pHead->label);
        ms[cur2->label] = cur2;
        RandomListNode * dum = new RandomListNode(0);
        dum->next = cur2;
        while(cur1->next){
            cur2->next = new RandomListNode(cur1->next->label);
            ms[cur2->next->label] = cur2->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1 = pHead;
        cur2 = dum->next;
        while(cur2){
            if(cur1->random){
                cur2->random = ms[cur1->random->label];
            }
            cur2 = cur2->next;
            cur1 = cur1->next;
        }
        return dum->next;
    }
};