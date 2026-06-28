// Solution for Problem 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* pA = headA;
    ListNode* pB = headB;

    while (pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    return pA;
}

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while(n--) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(ListNode* head) {
    if (!head) return;
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m;

    cin >> n;
    ListNode* listA = createList(n);

    cin >> m;
    ListNode* listB = createList(m);

    printList(getIntersectionNode(listA, listB));
    return 0;
}