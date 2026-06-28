// Solution for Problem 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head) return 0;

    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    if (!head) return;

    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    ListNode* list = createList(n);
    printList(reverseList(list));
    return 0;
}