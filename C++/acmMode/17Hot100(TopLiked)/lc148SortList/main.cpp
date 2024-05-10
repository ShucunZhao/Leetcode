#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int inV):val(inV), next(nullptr) {}
    ListNode(int inV, ListNode * inN) :val(inV), next(inN) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        /*
            Input: head = [4,2,1,3]
            Output: [1,2,3,4]
            sol1.Swap each two elements until cannot change(Like bubble, O^2)
            sol2.Divide and conquer: 
                4,2,1,3
                    |
             4,2       1,3
              |         |
            4   2     1   3
        */
        if (!head||!head->next) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* cut = nullptr;  
        while (fast && fast->next) {
            fast = fast->next->next;
            if (!fast|| !fast->next) cut = slow;
            slow = slow->next;
        }
        cut->next = nullptr;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(slow);
        ListNode* dum = new ListNode(0);//KeyPoint!!!
        ListNode* cur = dum;
        while (h1 || h2) {
            if (!h1) {
                cur->next = h2;
                h2 = h2->next;
            }
            else if (!h2) {
                cur->next = h1;
                h1 = h1->next;
            }
            else if (h1->val > h2->val) {
                cur->next = h2;
                h2 = h2->next;
            }
            else {
                cur->next = h1;
                h1 = h1->next;
            }
            cur = cur->next;
        }
        while (h1) {
            cur->next = h1;
            cur = cur->next;
            h1 = h1->next;
        }
        while (h2) {
            cur->next = h2;
            cur = cur->next;
            h2 = h2->next;
        }
        return dum->next;
    }
};

ListNode* construct(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter list:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        ListNode* head = nullptr;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            vector<int> nums;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
            head = construct(nums);
        }
        ListNode* res = S1.sortList(head);
        cout << "Res: ";
        while (res) {
            cout << res->val << ",";
            res = res->next;
        }
        cout << endl;
    }
}