package vn.edu.ptit.duongvct.playground.icpc2025_java.contest1;

import java.math.BigInteger;
import java.util.Scanner;

public class Ex6 {
    public static final Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        int t = Integer.parseInt(scanner.nextLine());
        while (t-- > 0) {
            testCase();
        }


    }
    private static void testCase(){
        String inputA = scanner.nextLine();
        String inputB = scanner.nextLine();
//        System.out.println(inputA);
//        System.out.println(inputB);
        BigInteger a = new BigInteger(inputA);
        BigInteger b = new BigInteger(inputB);
        System.out.println(a.gcd(b));
    }
}
