# 정렬 기준 방법

## java

### 1. Comparable

정렬 수행 시 **기본적으로 적용**되는 정렬 기준이 되는 **메서드를 정의**하는 인터페이스

```java
public class Main {

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

        Arrays.sort(time);
        for (times ts: time)  System.out.println(ts);
    }

}

//time 클래스를 새로 만든다.
class times implements Comparable<times> {
    int start;
    int end;

    public times(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public String toString() {
        return "times{" +
                "start=" + start +
                ", end=" + end +
                '}';
    }

    @Override
    public int compareTo(times arg0) {
        if (this.end == arg0.end) {
            return Integer.compare(arg0.start, this.start); // 내림차순
        } else {
            return Integer.compare(this.end, arg0.end); // 오름차순
        }
    }
}
```

배열의 경우, Array.sort(time)

Collection의 경우, Collection.sort()

### 2. Comparator

정렬 가능한 클래스(Comparable 인터페이스를 구현한 클래스)들의 **기본 정렬 기준과 다르게 정렬**하고 싶을 때 사용하는 인터페이스

주로 익명 클래스로 사용한다.

```java
Comparator<Point> myComparator = new Comparator<Point>() {
    @Override
    public int compare(Point p1, Point p2) { 
        if (p1.x > p2.x) return 1; // x에 대해서는 오름차순

        else if (p1.x == p2.x)
            if (p1.y < p2.y) return 1;// y에 대해서는 내림차순
	}
};

List<Point> pointList = new ArrayList<>();
Collections.sort(pointList, myComparator);
```



## 실험 중

### 내림차순 (객체가 아닌 일반변수형 int, double)

```java
int[] grades = new int[N];
grades = Arrays.stream(grades).boxed()
        .sorted(Collections.reverseOrder())
        .mapToInt(Integer::intValue)
        .toArray();
```

### 내림차순 (객체를 사용할 때)

```java
Time[] times = new Time[N];
Array.sort(times, Comparator.reverseOrder());
Integer[] grades = new Integer[N];
Collection.sort(grades, Comparator.reverseOrder());
```

