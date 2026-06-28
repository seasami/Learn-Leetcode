// Solution for Problem 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

import java.util.*;

public static int removeDuplicates(int[] nums) {
    // Nếu mảng rỗng thì dừng chương trình
    if (nums.length == 0) {
        return 0;
    }
    // Trường hợp còn lại
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
        if (nums[i] != nums[count]) {
            count++;
            nums[count] = nums[i];
        }
    }
    return count + 1;
}

public static void main(String[] agrs) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int[] n = new int[k];
    for (int i = 0; i < k; i++) {
        n[i] = sc.nextInt();
    }
    System.out.println(removeDuplicates(n));
    sc.close();
}
