// Solution for Problem 876. Middle of the Linked List
// http://leetcode.com/problems/middle-of-the-linked-list

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (n--) {
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
    while(head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    ListNode* list = createList(n);
    printList(middleNode(list));
}