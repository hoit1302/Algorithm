package math;

import java.util.Scanner;

public class boj_2839 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();

        if ( N%5 == 0){ // 5로 나눠짐
            System.out.println(N/5);
            return;
        }
        for (int i = N/5; i >= 0; i--){
            if ((N-i*5)%3 == 0){
                System.out.println(i+(N-i*5)/3);
                return;
            }
        }
        System.out.println(-1); // 그 어떤 해도 없음
    }
}
