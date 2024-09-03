#include <iostream>
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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		/*
			intersectVal = 8, listA = [4,1,8,4,5],
						    listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
		*/
		ListNode* curA = headA, * curB = headB;
		int lenA = 0, lenB = 0;
		while (curA) {
			lenA++;
			curA = curA->next;
		}
		while (curB) {
			lenB++;
			curB = curB->next;
		}
		curA = headA;
		curB = headB;
		if (lenA > lenB) {
			int tmp = lenA - lenB;
			while (tmp--) {
				curA = curA->next;
			}
		}
		else {
			int tmp = lenB - lenA;
			while (tmp--) {
				curB = curB->next;
			}
		}
		while (curA && curB) {
			if (curA == curB) return curA;
			curA = curA->next;
			curB = curB->next;
		}
		return nullptr;
	}
};

ListNode* construct(vector<int> & nums) {
	if (nums.empty()) return nullptr;
	ListNode* head = new ListNode(nums[0]);
	ListNode* cur = head;
	for (int i = 1; i < nums.size(); ++i) {
		cur->next = new ListNode(nums[i]);
		cur = cur->next;
	}
	return head;
}

void printList(ListNode* list) {
	cout << "[";
	while (list) {
		cout << list->val << ",";
		list = list->next;
	}
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	int intersectVal = 8;
	vector<int> listA = { 4, 1, 8, 4, 5 };
	vector<int> listB = { 5, 6, 1, 8, 4, 5 };
	int skipA = 2, skipB = 3;
	ListNode* A = nullptr;
	ListNode* B = nullptr;
	if (skipA > skipB) {
		B = construct(listB);
		vector<int> newA(listA.begin(), listA.begin() + skipA);
		A = construct(newA);
		ListNode* curB = B;
		while (skipB--) curB = curB->next;
		ListNode* dumA = new ListNode(0);
		dumA->next = A;
		ListNode* curA = dumA;
		while (skipA--) {
			curA = curA->next;
		}
		curA->next = curB;
	}
	else {
		A = construct(listA);
		vector<int> newB(listB.begin(), listB.begin() + skipB);
		B = construct(newB);
		ListNode* curA = A;
		while (skipA--) curA = curA->next;
		ListNode* dumB = new ListNode(0);
		dumB->next = B;
		ListNode* curB = dumB;
		while (skipB--) {
			curB = curB->next;
		}
		curB->next = curA;
	}
	cout << "A: ";
	printList(A);
	cout << "B: ";
	printList(B);
	Solution S1;
	ListNode* res = S1.getIntersectionNode(A, B);
	cout << "Res: " << res->val << endl;
}