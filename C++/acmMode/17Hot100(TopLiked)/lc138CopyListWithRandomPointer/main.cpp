/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// void printList(Node * head){
//     Node * cur = head;
//     cout<<"list: ";
//     while(cur){
//         if(cur->random==nullptr) cout<<"null,";
//         else cout<<cur->random->val<<",";
//         cur = cur->next;
//     }
//     cout<<endl;
// }
class Solution {
public:
Node* copyRandomList(Node* head) {
if(!head) return nullptr;
        unordered_map<int, Node*> ms;
        Node * ans = new Node(head->val);
        Node * ans1 = ans;
        Node * cur1 = head;
int index = 0; 
ms[index++] = ans;
while(cur1->next){
ans1->next = new Node(cur1->next->val);
ms[index++] = ans1->next;
            ans1 = ans1->next;
            cur1 = cur1->next;
        }
        // printList(ans);
        Node * cur2 = head;
        Node * ans2 = ans;
while(cur2){
if(cur2->random){
                Node * tmp = head;
int cnt = 0;
while(tmp!=cur2->random){
                    cnt++;
                    tmp = tmp->next;
                }
ans2->random = ms[cnt];
            }
            cur2 = cur2->next;
            ans2 = ans2->next;
        }
return ans;
    }
};
