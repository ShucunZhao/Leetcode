#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode() :val(0), next(nullptr) {}
        ListNode(int inV) :val(inV), next(nullptr) {}
        ListNode(int inV, ListNode * inN) :val(inV), next(inN) {}
    };
    static ListNode* construct(vector<int>& nums) {
        ListNode* head = new ListNode(nums[0]);
        ListNode* cur = head;
        for (int i = 1; i < nums.size(); ++i) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        return head;
    }
    bool isPalindrome(ListNode* head) {
        /*
             s
            N [1,2,5,2,1]
                         f
        */
        ListNode* dum = new ListNode(0);
        dum->next = head;
        ListNode* f = dum, * s = dum;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* head2 = s->next;
        s->next = nullptr;
        head2 = reverseL(head2);
        ListNode* c1 = head;
        ListNode* c2 = head2;
        while (c1 && c2) {
            if (c1->val != c2->val) return false;
            c1 = c1->next;
            c2 = c2->next;
        }
        if (c1 && c1->next != nullptr) return false;
        return true;
    }
    ListNode* reverseL(ListNode* head) {
        /*
        *           p c t
            [1,1,2,1]
        */
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the list:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        Solution::ListNode* head = nullptr;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            vector<int> nums;
            while (getline(ss,token,',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
            head = Solution::construct(nums);
        }
        cout << "Res: " << S1.isPalindrome(head) << endl;
    }
}