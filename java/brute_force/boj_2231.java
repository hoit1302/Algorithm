package brute_force;

import java.util.Scanner;

public class boj_2231 {
    public static int len(int a){
        return Integer.toString(a).length();
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int lenN = len(N);
        for (int i = N - (9 * lenN); i < N; i++) {
            int temp = i;
            for (int j = 0; j < len(i); j++)
                temp += i / Math.pow(10,j) % 10;
            if (temp == N) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(0);
    }
}