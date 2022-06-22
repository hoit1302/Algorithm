package back_tracking;

import java.io.*;
import java.util.*;

public class boj_15650 {
    static int N, M;
    static Stack<Integer> arr;
    public static void func(int order, int num){
        if (order == M+1) { // 초과 시 출력
            arr.forEach((n) -> System.out.print(n + " "));
            System.out.println();
            return;
        }
        for (int i = num; i <= N; i++){
            arr.push(i);
            func(order+1, i+1);
            arr.pop(); // 어려웠음.
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt();
        arr = new Stack<>();
        func(1,1);
    }
}
