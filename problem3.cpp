#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    // Nếu chuỗi rỗng thì thoát
    if (s.empty()) return -1;
    // Tạo mảng để lưu trữ vị trí gần nhất lặp lại trong chuỗi của một ký tự bất kỳ
    int last_seen[128];
    for (int i = 0; i < 128; i ++) last_seen[i] = -1;

    int left = 0, max_length = 0;
    for (int right = 0; s[right] != '\0'; right++) {
        char curr = s[right];
        if (last_seen[curr] >= left) {
            left = last_seen[curr] + 1;
        }
        last_seen[curr] = right;
        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}

int main() {
    string s; cin >> s;
    cout << lengthOfLongestSubstring(s);
}