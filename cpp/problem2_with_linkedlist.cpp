// Solution for Problem 2. Add Two Numbers
// using singly linked list
// https://leetcode.com/problems/add-two-numbers

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* tail = result;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;

        int sum = n1 + n2 + carry;
        carry = sum / 10;
        int keep = sum % 10;

        tail->next = new ListNode(keep);
        tail = tail->next;

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return result->next;
}


ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (n--) {
        int x;
        cin >> x;

        ListNode* node = new ListNode(x);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void PrintList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;
    cin >> n1;
    ListNode* l1 = createList(n1);

    cin >> n2;
    ListNode* l2 = createList(n2);

    PrintList(addTwoNumbers(l1, l2));
}