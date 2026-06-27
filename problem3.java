import java.util.*;

public static int lengthOfLongestSubstring(String s) {
    // Nếu chuỗi rỗng thì thoát
    if (s.isEmpty()) return 0;

    int max_length = 0, left = 0;
    // Tạo mảng để lưu trữ vị trí trong chuỗi s của một ký tự bất kỳ
    int[] lastSeen = new int[128];
    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }

    for (int right = 0; right < s.length(); right++) {
        char curr = s.charAt(right);
        if (lastSeen[curr] >= left) {
            left = lastSeen[curr] + 1;
        }
        lastSeen[curr] = right;
        max_length = Math.max(max_length, right - left + 1);
    }
    return max_length;
}

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    System.out.println(lengthOfLongestSubstring(s));
    sc.close();
}