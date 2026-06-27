import java.util.*;

public static String addTwoNumbers(String num1, String num2) {
    StringBuilder result = new StringBuilder();
    int i = 0, j = 0, carry = 0;

    while (i < num1.length() || j < num2.length() || carry != 0) {
        int n1 = (i < num1.length()) ? (num1.charAt(i) - '0') : 0;
        int n2 = (j < num2.length()) ? (num2. charAt(j) - '0') : 0;

        int sum = n1 + n2 + carry;
        carry = sum / 10;
        int keep = sum % 10;

        i++; j++;

        result.append(keep);
    }
    return result.toString();
}

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String n = sc.nextLine();
    String m = sc.nextLine();

    System.out.println(addTwoNumbers(n, m));
    sc.close();
}