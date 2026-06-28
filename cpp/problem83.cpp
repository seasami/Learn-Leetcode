// Solution for Problem 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode*head) {
    if (!head) return 0;
    
    ListNode* left = head;
    ListNode* right = head->next;

    while (right) {
        if (left->val != right->val) {
            left = right;
            right = right->next;
        } else {
            ListNode* temp = right;
            left->next = right->next;
            right = left->next;
            delete temp;
        }
    }
    return head;
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
    printList(deleteDuplicates(list));
}