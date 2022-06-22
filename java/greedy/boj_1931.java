package greedy;

import java.io.*;
import java.util.*;

public class boj_1931 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        times[] time = new times[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            time[i] = new times(b, c);
        }

        Arrays.sort(time, new Comparator<times>() {
            @Override
            public int compare(times o1, times o2) {
                if (o1.end != o2.end) return o1.end - o2.end; // end 오름차순
                else return o1.start - o2.start; // start 오름차순
            }
        });

        // for (times ts: time) System.out.println(ts);
        int count = 0;
        int end = -1;

        for (int i = 0; i < n; i++) {
            if (end <= time[i].start) {
                end = time[i].end;
                count++;
            }
        }
        System.out.println(count);
    }

}

//time 클래스를 새로 만든다.
class times {
    int start;
    int end;

    public times(int start, int end) {
        this.start = start;
        this.end = end;
    }
}