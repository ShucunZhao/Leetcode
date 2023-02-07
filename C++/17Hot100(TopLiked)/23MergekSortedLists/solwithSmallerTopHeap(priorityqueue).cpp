/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class cmp {
        public:
            bool operator () (const ListNode * A, const ListNode * B) const {
                return A->val>B->val;
            }
    };
    /*
    //This globle compare function definition method only can use in sort function,
    //if you want to define a priority queue cmpare function you need to use class
    //or struct and define the overload operator () to do the compare inside!
    static bool cmp(const ListNode * A, const ListNode * B){
        return A->val<B->val;
    }
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            lists = [[1,4,5],[1,3,4],[2,6]]
    priority queue: 6,5,4,4,3,2,1,1
            ans:    1,1,2,3,4,4,5,6
        */
        if(lists.size()<1) return NULL;
        priority_queue <ListNode*,vector<ListNode*>, cmp > q;
        for(int i=0;i<lists.size();i++){
            //Step1: Store all node into priority queue(it's a smaller heap here.)
            ListNode * cur = lists[i];
            while(cur){
                q.push(cur);
                cur = cur->next;
            }            
        }
        //Step2: Use dummy head to save each nodes from small to large by poping from priority queue.
        ListNode * dum = new ListNode();
        ListNode * cur = dum;
        while(!q.empty()){
            // cout<<(q.top())->val<<endl;
            cur->next = q.top();
            q.pop();
            cur = cur->next;
        }
        cur->next = NULL;//KeyPoint here: you must let the last node be NULL to keep a valid list!
        return dum->next;
        // return NULL;
    }
};