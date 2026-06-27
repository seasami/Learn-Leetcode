#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    // Nếu mảng rỗng thì dừng
    if (nums.empty()) return -1;
    // Trường hợp còn lại
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[count]) {
            count++;
            nums[count] = nums[i]; 
        }
    }
    return count + 1;
}

int main() {
    int k; cin >> k;
    vector<int> n(k);
    for (int i = 0; i < k; i++) cin >> n[i];

    cout << removeDuplicates(n);
}
