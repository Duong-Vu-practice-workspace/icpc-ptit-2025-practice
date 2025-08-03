package vn.edu.ptit.duongvct.playground.icpc2025_java.contest2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Ex6 {
    public static class Bottle implements Comparable<Bottle>{
        private int index;
        private int current;
        private int total;

        public Bottle(int index, int total, int current) {
            this.total = total;
            this.current = current;
            this.index = index;
        }

        public Bottle() {
        }

        @Override
        public int compareTo(Bottle bottle) {
            return Integer.compare(bottle.total, this.total);
        }
    }
    private static final Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        int totalV = 0;
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
            totalV += a.get(i);
        }
        for (int i = 0; i < n; i++) {
            b.add(scanner.nextInt());
        }
        List<Bottle> bottles = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            bottles.add(new Bottle(i, b.get(i), a.get(i)));
        }
        Collections.sort(bottles);
        int k = 0;
        int sum = 0;
        for (Bottle x : bottles) {
            sum += x.total;
            k++;
            if (sum >= totalV) {
                break;
            }
        }
        int totalInK = 0;
        for (int i = 0; i < k; i++) {
            totalInK += bottles.get(i).current;
        }
        int t = totalV - totalInK;
        System.out.println(k + " " + t);

    }
}
