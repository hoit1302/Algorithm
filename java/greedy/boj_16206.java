package greedy;

import java.io.*;
import java.util.*;

public class boj_16206 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 첫 번째 줄 입력받기
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        //두 번째 줄 입력받기
        st = new StringTokenizer(br.readLine());
        int tmp = 0, res = 0; // res는 return 값
        int noneTen = 0; //noneZero는 10의 배수 아닌 숫자 앞자리 합
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            tmp = Integer.parseInt(st.nextToken());
            if (tmp == 10) res++;
            else if (tmp % 10 == 0) list.add(tmp);
            else noneTen += (tmp / 10);
        }
        // 먼저 10의 배수들 처리하가
        Collections.sort(list);
        for (Integer num : list) {
            if (num == 20 && 1 <= M) {
                res += 2;
                M--;
            } else if (num / 10 - 1 <= M) {
                res += num / 10;
                M -= num / 10 - 1;
            } else {
                res += M;
                M = 0;
            } // M이 작은 경우
        }
        // 더 자를 수 있다면 noneTen 추가
        res += Math.min(M, noneTen);
        // 출력
        System.out.println(res);
    }
}

