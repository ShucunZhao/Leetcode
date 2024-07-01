#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int inV) :val(inV), next(nullptr) {}
    ListNode(int inV, ListNode* inN) :val(inV), next(inN) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        /*
            Input: head = [3,2,0,-4], pos = 1
                 s   
                 f
            [3,2,0,-4]
               |____|
            Output: true
        */
        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* s = dum, * f = dum;
        while (s &&f&& f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) return true;
        }
        return false;
    }
};

ListNode* construct(string & In, int pos) {
    if (In.empty()) return nullptr;
    stringstream ss(In);
    string token;
    vector<int> tmp;
    while (getline(ss, token, ',')) {
        size_t l = token.find_first_not_of(" ");
        size_t r = token.find_last_not_of(" ");
        tmp.push_back(stoi(token.substr(l, r - l + 1)));
    }
    ListNode* head = new ListNode(tmp[0]);
    ListNode* cur = head;
    for (int i = 1; i < tmp.size(); ++i) {
        cur->next = new ListNode(tmp[i]);
        cur = cur->next;
    }
    if (pos != -1) {
        ListNode* entry = head;
        while (pos--) entry = entry->next;
        cur->next = entry;
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
        cout << "Enter pos:" << endl;
        string P;
        getline(cin, P);
        if (P == "q") break;
        In = In.substr(1, In.size() - 2);
        int pos = stoi(P);
        ListNode* head = construct(In, pos);
        cout << "Res: " << S1.hasCycle(head) << endl;
    }
}