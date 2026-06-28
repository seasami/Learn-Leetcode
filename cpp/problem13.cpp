// Solution for Problem 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer

#include <bits/stdc++.h>
using namespace std;

int romanValue (char r) {
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int total = 0, max_seen = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int curr = romanValue(s[i]);

        if (curr < max_seen) total -= curr;
        else {
            total += curr;
            max_seen = curr;
        }
    }
    return total;
}

int main() {
    string s; cin >> s;
    cout << romanToInt(s);
}