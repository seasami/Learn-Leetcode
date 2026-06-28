// Solution for Problem 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer

import java.util.*;

public static int romanValue(char c) {
    switch(c) {
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

public static int romanToInt(String s) {
    int curr, max_value = 0, result = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        curr = romanValue(s.charAt(i));

        if (curr < max_value) {
            result -= curr;
        } else {
            result += curr;
            max_value = curr;
        }
    }
    return result;
}

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    System.out.println(romanToInt(s));
    sc.close();
}