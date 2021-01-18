package math;

import java.util.Scanner;

public class boj_4796 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int L,P,V;
        int cnt = 1;
        while (true) {
            // 입력
            L = sc.nextInt();
            P = sc.nextInt();
            V = sc.nextInt();
            // testcase 끝
            if (L == 0) break;
            // 알고리즘
            System.out.println("Case " + cnt + ": "
                    + ((V / P) * L + Math.min(V % P, L)));
            cnt++;
        }
    }
}
