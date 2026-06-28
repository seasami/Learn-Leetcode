// Solution for Problem 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers

#include <bits/stdc++.h>
using namespace std;
    string addTwoNumbers(const string& num1, const string& num2) {
        string result = "";
        int i = 0, j = 0, carry = 0;

        while (i < num1.length() || j < num2.length() || carry != 0) {
            int n1 = (i < num1.length()) ? (num1[i] - '0') : 0;
            int n2 = (j < num2.length()) ? (num2[j] - '0') : 0;

            int sum = n1 + n2 + carry;
            carry = sum/10;
            int keep = sum % 10;
            result.push_back(keep + '0');
            i++; j++;
        }
        return result;
    }


int main() {
    // Nhập dãy 1
    string n; cin >> n;
    // Nhập dãy 2
    string m; cin >> m;

    cout << addTwoNumbers(n, m);
}