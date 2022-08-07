## 03월 04일 - 정렬

1. header 추가하기

```c++
#include <algorithm>
```

2. 내림차순으로 정렬하기

```c++
sort(v.begin(), v.end(), greater<>())
```

3. 비교함수 구현하기

```c++
bool cmpStr(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    if (sumNum(a) != sumNum(b)) {
        return sumNum(a) < sumNum(b);
    }
    return a < b;
}
```

4. pair<int, int> 정렬
첫번째 값 먼저 오름차순, 동일하면 두번째 값 오름차순

   
## 03월 08일 - 맵과 셋

1. character가 숫자인가?

```c++
isdigit(input[0])
```

2. string을 숫자로

```c++
stoi(input);
```

3. character를 숫자로

```c++
input[0] - '0';
```

char to string

```c++
string (size_t n, char c);
s.append(1, c); // s 문자열에 c 문자를 string으로 변환하여 덧붙임.
```

4. 트리 셋, 트리 맵

c++의 set, map은 이진 트리로 구현된 컨테이너이기 때문에 기본적으로 정렬됨.

입력되는 수가 1e6 이상으로 삽입과 탐색이 많이 일어날 때는 O(log N)의 set이 아니라 

O(1)인 해시 셋 `unordered_set`, 해시 맵 `unordered_map` 을 사용해서 풀이해보자.

5. 부분 문자열 구하는 방법

- input.substr(시작 index, 문자열의 길이) -> O(N)
  - `#include <iostream>`에는 `#include <string>`이 내장되어 있으므로 보통 따로 추가하지 않는다.
- substr(시작 index) -> 시작 index ~ 마지막까지의 부분 문자열
- += 로 직접 더함 -> O(1)

6. 반복자로 출력하기

```c++
for (auto iter = set.begin(); iter != set.end(); iter++) {
    cout << *iter << ' ';
}

for (auto iter = set.rbegin(); iter != set.rend(); iter++) { // 반대로
    cout << *iter << ' ';
}

for (auto & iter : map) {
    cout << iter.first << ' ' << iter.second << '\n';
}
```

7. 참조자(reference) 란?

C++에서는 특정 변수의 실제 이름 대신 사용할 수 있는 & (참조자) 라는 기능이 있다. C의 포인터와도 유사한 개념이다.

- 참조자의 선언
```c++ 
int 변수이름;               // 변수의 선언

int& 참조자이름 = 변수이름; // 참조자 선언
```

이렇게 선언된 참조자는 대상 변수와 같은 메모리 위치를 참조하게 된다. 

예를 들어, int&는 int형 변수에 대한 참조를 의미한다.

- 참조자 활용

```c++
int x = 10; // 변수의 선언

int& y = x; // 참조자 선언

cout << "x : " << x << ", y : " << y << endl;  // x : 10, y : 10

y++;        // 참조자를 이용한 증가 연산

cout << "x : " << x << ", y : " << y << endl; // x : 11, y : 11

cout << "x의 주소값 : " << &x << ", y의 주소값 : " << &y; //x의 주소값 : 0x7ffe6c0a1234, y의 주소값 : 0x7ffe6c0a1234
```

참조자를 이용해 증가 연산을 수행하면, 참조 변수뿐만 아니라 대상 변수도 같이 변경되는 것을 확인할 수 있다.

따라서 C++에서 참조자는 주로 함수에 인수를 전달할 때 사용된다.

함수가 참조자를 인수로 전달받으면, 참조자가 참조하고 있는 실제 변수의 값을 함수 내에서 조작할 수 있게 되기 때문,

사실 위와 같은 참조에 의한 전달(call by reference)은 참조자뿐만 아니라 포인터를 사용해도 똑같은 결과를 얻을 수 있음. 

포인터를 사용하는 방법과 참조자를 사용하는 방법 모두 결과는 같으며, 구문 형태상의 차이점만이 존재!

포인터 대신 `&` 를 사용하면 함수 내에서 참조 연산자(*)를 사용하지 않으므로, **함수 내부의 코드가 깔끔하고 직관적이 되는 장점이 있음**

8. set 자료형 insert 함수의 반환값

link: [#](https://yonmy.com/archives/9)
insert 했을 경우, 즉 중복된 값이 없어서 넣은 경우, second 에서 true 값 반환
insert 하지 못했을 경우, 즉 중복된 값이 이미 있어서 못넣은 경우, second 에서 false 값 반환

s.find(value) 는 찾지 못했을 때 `s.end()` 반복자를 반환합니다.

9. map, set 자료형과 다른 다른 컨테이너를 vector container로 초기화하기

- map과 set 자료형에서는 정렬을 할 수 없으니, 정렬이 필요한 경우 이렇게 구현할 수 있음.

```c++
map<string, int> words;
... // 삽입
vector<pair<string, int>> vec(words.begin(), words.end());
```

10. map의 [] 연산자

[] 연산자는 map에 없는 key를 참조하면 자동으로 선언된 값의 default 생성자를 호출해서 원소를 추가해준다.

<img width=300 src="https://user-images.githubusercontent.com/68107000/182313521-5a5d9dd4-12fb-4bfe-b1d8-5cc53201ca30.png">

```c++
map<int, char> cmd;

if (cmd[t]) -> t라는 key가 있을 때: null이 아닌 다른 값이면 true
t라는 key가 존재하지 않을 때: 에러를 던지지 않고 key를 삽입시키고 value는 null로 할당돼 false를 리턴
```

11. map의 유효한 key 개수 세기

```c++
map<int, int> m;
... // 삽입됨
int kind = 0;
for (auto &p : m) { // p는 pair<int, int> 구조임.
    if (p.second) {
        kind++;
    }
}
c++17부터 아래와 같이 작성할 수 있다.
for (auto &[key, value] : m) { // p는 pair<int, int> 구조임.
    if (value) {
        kind++;
    }
}

```

## 03월 11일 - 스택, 큐, 덱

1. 공백 포함 입력받기
```c++
getline(cin, <변수명>)

string str;
getline(cin, str);
```
2. queue가 지원하는 메소드

```c++
기본적으로 
- push(x): 뒤에 삽입하기
- front(), pop(): 맨 앞 원소 찾고 빼내기

그런데! 특이하게 지원하는 것이 있다.
- back()
back_pop 이런 건 없지만 맨 뒤 원소에 접근할 수 있다!
```


## 03월 15일 - 정수론

1. 소수 구하기, 에라토스테네스의 체

```c++
void eratosthenes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= SIZE; i++) {
        if (!is_prime[i]) continue; // 소수 아니면
        for (int j = i * i; j < SIZE; j += i) {
            is_prime[j] = false;
        }
    }
}
```

1.2 소인수분해를 위해 idx 값이 가지는 가장 작은 소인수 저장하기
```c++
vector<int> primes(SIZE); // -1, -1, 2, 3, 2, 5, 2, 7, ...

void calEratos() {
    primes[0] = primes[1] = -1;
    for (int i = 2; i < SIZE; i++) {
        primes[i] = i;
    }

    for (int i = 2; i * i <= SIZE; i++) { // sqrt(SIZE) 까지
        if (primes[i] != i) continue; // 소수가 아님
        for (int j = i * i; j < SIZE; j += i) { // 소수인 수에 대해서
            if (primes[j] == j) // 아직 갱신되지 않은 경우에만
                primes[j] = i; // 갱신
        }
    }
}
```

2. 최대공약수 구하기, 유클리드 호제법

```c++
int calGcd(int a, int b) { // a < b
    if (a == 0)
        return b;
    return calGcd(b % a, a);
}
```
## 03월 18일 - 브루트 포스

1. string to int, int to string 정수 문자열 형변환

```c++
#include <string> 에 포함되어 있지만 c++14, 17  -> 표준에 이미 포함되어 있음.
int int_value = 10;
string str_int_value = to_string(int_value);
int_value = stoi(str_int_value);
```

2. 2차원 배열에서 규칙적인 패턴이 있을 때 인덱스 접근 아이디어

```c++
BWBW
WBWB
BWBW
WBWB
-> (i, j)로 표현할 때, i + j가 짝수이면 B, 홀수이면 W로 접근할 수 있다.

n X n matrix에서 
오른쪽/왼쪽 상향 줄 개수는 2 * n - 1이다.
오른쪽 상향은 i+j 값으로 0 ~ 2(n-1)로 판단할 수 있고
왼쪽 상향은 i-j 값으로 -(n-1) ~ (n-1)로 판단할 수 있다. (feat. nqueen)
```

3. 제일 중요한 건 숫자가 작다 싶으면 브루트포스가 가능한지 시간 복잡도를 계산해보는 것이다!

4. 조합 (nCr)

#include <algorithm>에 next_permutation, prev_permutation 포함되어 있음.

```c++
// 5C2일 때, {1, 1, 0, 0, 0}으로 설정하고 prev_permutation 돌리면 됨.
vector<bool> com(n, false);
for (int i = 0; i < c; i++) {
    com[i] = true;
}

do {
    for (int i = 0; i < c; i++) {
        if (com[i]) {
            cout << element[i];
        }
    } cout << '\n';
    // 한 가지의 조합을 구했음. 원하는 로직 수행하기
} while (prev_permutation(com.begin(), com.end()));
```

5. 순열 (nPr)

```c++
// 5P2일 때 , {1, 1, 0, 0, 0}으로 설정하고 prev_permutation 돌리면 됨.
vector<bool> com(n, false);
for (int i = 0; i < c; i++) {
    com[i] = true;
}

do {
    for (int i = 0; i < c; i++) {
        if (com[i]) {
            cout << element[i];
        }
    } cout << '\n';
    // 한 가지의 조합을 구했음. 원하는 로직 수행하기
} while (prev_permutation(com.begin(), com.end()));
```


## 03월 22일 - 구현, 코너케이스

1. c++의 switch-case 문에서 string은 사용이 불가하다.

2. bool 형을 출력하면 true는 1로, false는 0으로 출력된다.

3. 이전의 값과 비교할 때는 가장 첫 값의 초기화를 주의하자.

4. 맞왜틀! 마지막으로 확인해야 할 것은 자료형! long이라던가, double이라던가!!!

5. 맞왜틀! 스택, 큐, 덱은 참조 전 비었는가를 꼭 확인하자

6. string 클래스에서 `back()`, `pop_back()`과 같은 연산이 가능하다는 사실..!

7. reverse 함수는 algorithm 헤더에

```c++
reverse(v.begin() + 시작원소_인덱스, v.begin() + (마지막원소_인덱스 + 1) );
```

8. 시간초과가 난다. 입출력을 더 빠르게 해주자.

```c++
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
```

9. vector가 지원하는 메소드, 리스트(list)처럼 활용하기

```c++
auto element = v.front());
v.erase(v.begin()); // erase는 위치를 지정하여 삭제
v.erase(v.begin(), v.begin() + 2); // 0 <= 삭제 < 2로 마지막은 포함 X

v.push_back(x);
auto element = v.back();
v.pop_back();
v.erase(--v.end());
```

## 03월 25일 - 백트래킹
1. deque은 index 접근이 가능하다!!

2. 컨테이너 내 원소의 개수를 세어주는 함수
```c++
count(belt.begin(), belt.end(), 0)
0의 개수를 반환함.
```

3. 전역 변수 사용

재귀함수 사용시 함수를 계속 호출하므로 전역변수로 관리하는 것이 더 효율적이다.

4. prev_permutation으로 조합 구현하기

```c++
vector<bool> combination(n + 1, false); //1 ~ n까지의 수에 대한 조합정보 (true/false)

for (int i = 1; i <= m; i++) { // m개의 원소 true로 셋팅
    combination[i] = true;
}

do {
    for (int i = 1; i <= n; i++) {
        if (combination[i]) { //true라면 사용이므로 출력
            cout << i << ' ';
        }
    }
    cout << '\n';
  } while (prev_permutation(combination.begin() + 1, combination.end())); //인덱스 1부터 사용
```

5. 가지치기 잘 해주기

전형적인 유형을 적어보자면
- 최솟값, 최댓값을 구하는 경우, 기존 정답보다 더 크면/작으면 중단하기

```c++
최솟값: // 탐색 중인데 이미 정답보다 큼. 더 이상 탐색하지 않아도 됨.
if (ans <= tmp) {
    return;
}

최댓값: // 남은 비용들이 모두 최댓값이어도 ans보다 작음. 더 이상 탐색하지 않아도 됨.
if (tmp + (n-depth) * MAX <= ans) {
    return;
}
```

6. 재귀함수에서 리턴값 활용하기

```c++
bool fillSudoku(int fill) {
    // 기저조건
    if (fill == 81) {
        return true;
    }
    
    // 재귀함수 호출하는 경우의 수 2가지
    // 1. 값을 채우지 않아도 될 때, 바로 호출하기
    if (sudoku[r][c] != 0) {
        return fillSudoku(fill + 1);
    }
    // 값을 채워야할 때 필요한 판단, 로직을 작성하여 덧붙여주기
    for (int i = 1; i <= 9; i++) {
            ...
            if (fillSudoku(fill + 1)) {
                return true;
            }
            ...
        }
    }
    return false; // true를 리턴시키지 못했다면 false를 리턴시켜줘야함.
}
```

외판원 순회 2 [10971](https://www.acmicpc.net/problem/10971)

*대박이다... 샘플 코드는 샘플 코드인 이유가 있다...*

시작 도시가 무엇인가에 따라서 답이 달라지기 때문에 시작 도시를 지정해 for loop를 사용하여 구현한다.

하지만 시작 도시를 하나로 지정해도 답은 얻을 수 있다. 

다시 잘~ 생각해보면 0 1 2 3 0 은 결국 1 2 3 0 1, 2 3 0 1 2, 3 0 1 2 3과 같은 비용이 든다.

0으로 시작한 한 가지 경우가 1로 시작한 1가지 경우, 2로 시작한 1가지 경우, 3으로 시작한 1가지 경우와 동일하다.

backtracking 알고리즘을 통해 0으로 시작하는 모든 경우를 탐색하기 때문에 시작점을 하나로 지정해주어도 풀이가 된다.

그래서 실제로 제출해보면 최대 n 값인 10배 정도 차이가 난다.

## 03월 29일 - dp

**memoization**: 이전에 구해둔 값을 저장해서 중복 계산을 방지, 시간과 공간 모든 면에서 효율적

**구현 종류**
- Top-down (n부터)
  - 구하려 하는 문제를 작은 문제로 호출하여 탐색
- Bottom-up (0부터)
  - 이미 알고 있는 작은 문제부터 원하는 문제까지 탐색
  - 속도가 더 빠름

bottom-up
```c++
dp[1][1] = tri[1][1];
for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
    }
}
```

top-down
```c++

int f(int r, int c) {
    if (r == 1)
        return tri[1][1];
    if (r == 0 || c == 0)
        return 0;
    if (0 <= dp[r][c]) // 값이 이미 존재한다면
        return dp[row][c];
    return dp[r][c] = max(f(r-1, c-1). f(r-1, c)) + tri[r][c]
}
```

점화식을 미리 세우고 풀면 좋다. 이전 값들을 통해 DP (현재)를 정의하자.

**동적 계획법을 푸는 대표적인 문제와 방식**

- LIS (가장 긴 증가하는 부분 수열)
```c++
/**
  * i번 idx로 끝나는 증가하는 부분 수열 길이의 최댓값 계산하기
  * 따라서 dp의 마지막 원소가 정답이 아님. 최댓값을 갱신해주어야 함.
  * 시간 복잡도 O(n^2)
 */
int lis(int n, vector<int> &arr) {
    int ans = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

/**
 * 2.
 * dp[i] : 증가하는 부분 수열의 길이가 i인 수 중에 가장 작은 수
 * idx : 가장 긴 증가하는 부분 수열의 길이
 *
 * 시간 복잡도 O(nk) (k는 idx의 크기)
 *
 * -> k가 n이 될 수 있으므로 이론상 시간복잡도는 O(n^2)으로 동일하지만,
 *    증가하는 관계일 때 break를 해줌으로써 실제 연산횟수는 더 적어서 1번 함수보다 빠른 풀이
 */
int lisAdv(int n, vector<int> &arr) {
    vector<int> dp(n + 1, 0); //dp[1]을 갱신하기 위해 dp[0] = 0으로 설정
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = idx; j >= 0; j--) {
            if (arr[i] > dp[j]) { //증가하는 관계라면
                dp[j + 1] = arr[i];
                if (j == idx) { //최장 길이 갱신
                    idx++;
                }
                break;
            }
        }
    }
    return idx;
}

/**
 * 3.
 * lisAdv에서 이분탐색을 활용해 구현
 * 시간 복잡도 O(nlogk) (k는 dp의 크기)
 */
int lisFinal(int n, vector<int> &arr) {
    vector<int> dp;
    
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //arr[i] 이상의 값이 처음 나오는 위치
        if (pos == dp.size()) { //arr[i]가 가장 크다면 pos 값이 dp.size()와 같음 -> 최장 길이 갱신
            dp.push_back(arr[i]);
        }
        dp[pos] = arr[i]; //dp[pos]의 값이 arr[i]이상이므로 더 작은 arr[i]로 덮어 씌우기
    }
    return dp.size();
}
  ```

- knapsack
```c++
3번 물품을 사용할 때, 1~2번 물품한 사용한 정보에서 갱신되어야함.
순차적으로 갱신할 때 같은 물품을 중복해서 사용할 수 있음.
이를 방지하기 위해 최대 용량을 감소시키면서 계산하기 

int ans = 1;
for (int i = 1; i <= n; i++) { // n: 물건 개수
    for (int j = k; j >= 1; j--) { // k: 최대 용량
        if (w[i] <= j) { // i번째 물품을 넣을 수 있다면?
            // i번째 물건을 넣지 않았을 때와 넣었을 때 중 더 큰 값으로 초기화
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
}

```
  
- LCS (최장 공통 부분 수열)
```c++
int lcs(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 왼쪽과 위 중 큰 값 취하기
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1; // 왼쪽 상향의 값 취하기
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}
```

## 04월 01일 - 우선순위 큐

1. 기본적인 선언
```c++
priority_queue<ci> max_heap; // 기본적으로
priority_queue<ci, vector<ci>, greater<>> min_heap;
```

2. 정렬 조건 만들기

```c++
struct em {
    int d, h, line;
    bool isDeka;
};

bool operator <(em a, em b) {
    if (a.d != b.d)
        return a.d < b.d; // 높은 게 먼저
    if (a.h != b.h)
        return a.h < b.h; // 높은 게 먼저
    return a.line > b.line; // 낮은 게 먼저
}

int main() {
    priority_queue<em, vector<em> > pq;
}
```

```c++
struct people {
    int day;
    int hard;
    int no;
};

struct cmp {
    bool operator()(const people & x1, const people & x2) {
        if (x2.day != x1.day)
            return x2.day < x1.day;
        if (x2.hard != x1.hard)
            return x2.hard < x1.hard;
            return x2.no > x1.no;
    }
};

priority_queue<people, vector<people>, cmp> pq;
```

3. 알고리즘 아이디어, 유효성 검사 배열

is_valid, visited, is_used 와 같은 배열을 잘 활용하자

대표적 예시: 7662번, bfs&dfs, N-Queen

## 04월 08일 - 이분 탐색

1. binary_search()
binary_search() -> 이분탐색으로 원소가 있는지를 확인하고, 결과를 리턴하는 함수
`algorithm.h`에 정의되어 있다.

2. lower_bound()

c++에서는 이진 탐색으로 원소를 탐색하는 lower_bound, upper_bound 함수를 제공한다.

vector가 정렬되어 있어야 한다.

#include <algorithm> 헤더를 필요로 한다.
``` c++
int arr[6] = { 1,2,3,4,5,6 };
cout << "lower_bound(6) : " << lower_bound(arr, arr + 6, 6) - arr;
lower_bound(6) : 5
```

3. 맵과 셋을 활용

맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있다.
```c++
map.lower_bound(x)
```

## 04월 12일 - 투 포인터

배열의 탐색 효율을 높이기 위해 사용함.

효율성 테스트 문제로 아주 많이 출제됨.

일반적으로 시간 복잡도 O(n^2)의 문제를 시간 복잡도 O(n)으로 풀 수 있음.

유형

1. 두 개의 포인터 사이의 거리가 고정된다면 **슬라이딩 윈도우**
  - 같은 방향으로 이동하며 탐색
2. 포인터가 가까워짐
  - left < right
  - 보통 중복이 없고 정렬된 배열에서만 사용 가능하며 두 개의 포인터가 가리키는 값만 고려함
3. 포인터가 멀어짐
   - left <= right
   - 두 개의 포인터가 가리키는 값 사이의 모든 값을 고려함.


도둑 [#](https://www.acmicpc.net/problem/13422)
* 첫번째 집과 마지막 집이 이웃한 형태 다루기
* 슬라이딩 윈도우 문제인데 오랜만에 만나서 아이디어를 떠올리지 못함
* 코너 케이스: 집 개수가 n이고 한 번에 훔쳐야하는 개수인 m이 n과 같을 때.
* 이 때는 딱 1번만 확인하고 0 또는 1을 출력하면 됨.


## 04월 15일 - dfs & bfs

1. 메모리 효율적으로 사용하기

visited 배열 따로 만들지 않아도 될까?

2. dfs, return 값 활용하기

전역에 변수를 선언하고 활용하는 방법도 있지만
```c++
int sum;
void findGroup(int x, int y) {
    sum++;
    map[x][y] = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || n <= nx || n <= ny || !map[nx][ny]) {
            continue; // 방문 불가능 or 이미 방문 -> 건너뛰기
        }
        findGroup(nx, ny);
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                sum = 0;
                findGroup(i, j);
                ans.push_back(sum);
            }
        }
    }
}
```

함수의 리턴값으로 연결된 노드의 개수를 반환받도록 구현할 수 있다. 
```c++
int findGroup(int x, int y, int sum) { // x,y 방문했을 때 누적 sum개 방문했음.
    map[x][y] = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || n <= nx || n <= ny || !map[nx][ny]) {
            continue; // 방문 불가능 or 이미 방문 -> 건너뛰기
        }
        // 다음 노드 방문 가능. 방문 로직
        sum = findGroup(nx, ny, sum + 1);
    }
    return sum;
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                ans.push_back(findGroup(i, j, 1));
            }
        }
    }
}
```

3. visited 배열을 만들어두고 잘 안사용하더라

그래서 한 번씩 디버깅해봐... 한 흐름에 작성할 수 있도록 상기!

4. vector도 선언만 해두고 꼭 메모리 할당을 안해서 seg fault 내더라

에러 났을 때 벡터 메모리 할당 부분 의심해보기

## 05월 03일 - 최단 경로

BFS는 가중치가 1인 그래프의 최단 경로를 구하는 것과 같다.

가중치가 다양하다면 최단 경로 알고리즘을 활용해야 한다.

- Single-Source Problem (SSP): 하나의 시작점에 대한 모든 정점까지의 최단 경로
- Single-Destination: 모든 정점으로부터 하나의 도착점까지의 최단 경로. SSP를 뒤집어서 구현
- Single-Pair: 특정 정점 2개 사이의 최단 경로. SSP의 sub-problem
- All-Pairs (ASP): 가능한 모든 정점 2개의 조합에 대한 최단 경로

SSP: 다익스트라, 벨만-포드
ASP: 플로이드-워셜

### 1. 다익스트라 Dijkstra 

정점 기준 탐색

시작 정점으로부터 가장 가까운 정점부터 탐색하는 그디리적 접근

(cf. 시작점으로부터의 거리가 아니라 간선 자체의 가중치만 고려하는 것은 Prim 알고리즘)

O(VlogV + ElogV)

priority queue를 활용해 갱신된 dist가 우선순위에 따라 배치될 때 (logn), 가장 작은 값을 찾아 삭제할 때 (logn)

다익스트라는 음의 사이클을 잡아낼 수 없음

의사코드
```c++
모든 정점까지의 거리를 담은 dist 배열을 INF로 초기화
시작 정점까지의 거리를 0으로 초기화

while (갱신할 정점이 있을 때까지) {
    int v = 탐색하지 않은 정점 중 시작점에서 가장 가까운 정점
    for (v와 연결된 모든 정점에 대해) {
        int u = v와 연결된 정점
        if (dist[v] + weight[v][u] < dist[u]) {
            dist[u] = dist[v] + weight[v][u]
        }
    }
}
```

코드
```c++
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v + 1, INF); //각 정점까지의 최단 경로 저장
    //현재 탐색하는 중간 정점까지의 최단 경로
    priority_queue<ci, vector<ci>, greater<>> pq; //first: 시작점으로부터의 거리, second: 정점

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) { //이미 더 작은 값으로 기록된 정점
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            //시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) { //최단 경로 값이 갱신된다면
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}
```

### 2. 플로이드 워셜

정점 기준 탐색

가능한 모든 정점 2개의 조합에 대한 최단 경로를 구하는 ASP 알고리즘

두 정점 사이의 최단 경로에 포함될 수 있는 모든 정점의 경우를 고려하는 dp 접근

O(V^3)

중간 정점을 지나는 모든 경로에 대한 값을 계산한다.

```c++
// 1. 자기 자신과의 거리는 0으로 초기화

// 2. 플로이드워셜
void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) { //중간 정점
        for (int i = 1; i <= n; i++) { //출발 정점
            for (int j = 1; j <= n; j++) { //도착 정점
                //중간에 k를 거쳐서 i에서 j로 갈 때의 비용
                int cost = graph[i][k] + graph[k][j];
                //더 짧은 경로 선택
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}
```

### 3. 벨만-포드 bellmanFord

하나의 시작점에서 모든 정점까지의 최단 경로를 구하는 SSP 알고리즘

가중치가 음수일 때 다익스트라 대신 사용

모든 정점을 V-1번 갱신한 뒤 한 번 더 갱신을 시도하는 브루트포스적 접근

O(VE)

간선 기준 탐색

- 그래프 정보를 저장할 때 인접 행렬이나 인저 리스트가 아닌 주어진 간선 정보만 저장하면 됨. 
- 사이클이 없다면 특정 간선은 최대 V-1번만 사용됨.
- 음의 사이클을 잡아낼 수 있음.
- 모든 간선을 활용해 갱신한 후 

아이디어: 정점이 V개일 때 2개의 정점 사이 경로에는 최대 V-1개의 간선이 있을 수 있음.
그 이상의 간선을 사용하면 **사이클 형성**됨.
= 최단 경로를 이루는 간선이 V개 이상인 정점 A, B가 있다. = **V번 이상 갱신되는 간선이 있다.**

의사 코드
```c++
for (V-1회 루프) { // (V-1) * E
    for (모든 간선에 대해)
        간선을 사용하여 최단 경로 갱신
}
for (모든 간선에 대해) { // E
    if (간선을 사용하여 최단 경로가 갱신됨)
        음의 사이클 존재!
}
```

코드
```c++
vector<ll> bellmanFord(int start, int n, int m, vector<tp> &edges) {
    //최솟값 갱신하는 과정에서 언더플로우 일어날 수 있음
    //500 * 6000 * (-10000) = -3e10 => int 범위 넘어감!
    vector<ll> dist(n + 1, INF);

    //시작 정점 초기화
    dist[start] = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true; // 더 이상 반복문을 실행할 필요가 없는지 확인 (갱신 확인)
        for (int j = 0; j < m; j++) {
            // s->d인 간선의 가중치가 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) { // 아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue;
            }
            ll next_weight = dist[s] + w;
            if (next_weight < dist[d]) {
                dist[d] = next_weight;
                flag = false;
                if (i == n) { // n번째 갱신이었다면 -> 음의 사이클
                    return {-1};
                }
            }
        }
        if (flag) { //더 이상 갱신되지 않았다면 더 탐색할 필요 없음
            break;
        }
    }
    return dist;
}
```

튜플 사용 방법
```c++
#include <tuple>
typedef tuple<int, int, int> tp;
vector<tp> edges(m); // 간선 정보
edges[0] = {a, b, c};
int a = get<0>(edges[0]);
int b = get<1>(edges[0]);
int c = get<2>(edges[0]);  
```

팁
코딩테스트는 시간이 부족하므로 int 최댓값을
const int INF = 2e9로 두자.

## 05월 17일 - 트리

1. 트리는 간선의 수가 정점의 개수 - 1개이고 
2. **특정한 두 정점 사이의 경로의 수는 단 1가지이다.**
3. 또한 간선이 단방향이고 
4. 사이클이 존재하면 안된다. 
5. 계층 관계가 존재한다.


트리의 종류: 크게 이진트리와 일반 트리로 나뉜다.

트리 구현: 

- 실시간으로 트리를 만들 땐, **구조체 + 포인터 조합** 으로 구현하고, 5639번처럼(링크첨부) 
- 이미 트리의 관계가 정의되어 있다면 **맵**으로 구현한다.
 
트리임이 확실히 가정된다면

-> 간선이 단방향이고, 사이클은 없다는 트리의 특성이 가정된 것이다.

평소 graph를 구현하기 위해 벡터로 인접리스트를 구현하는 대신에 **map**을 사용하여 구현할 수 있다. 

O((ceil) log(V+1)) <= 이진 트리의 시간 복잡도 <= O(V)

이진 트리 순회

- 레벨 순회 (BFS 활용)
- 전위 순회 (V L R)
- 중위 순회 (L V R)
- 후위 순회 (L R V)

트리 연산

기본적으로 그래프의 한 종류라서, DFS, BFS 탐색이 가능하다.
- 트리의 정점 수 구하기
- 리프 노드의 수 구하기
- 트리의 높이 구하기

트리 문제 유형

- 사이클 판단 (자료구조는 인접 리스트로 구현해야함) 4803번처럼(링크첨부) 

## 05월 24일 - 유니온 파인드

## 번외 주제 - 비트마스킹

```c++
run |= (1 << idx); // 원소 추가
if (run & (1 << i)) // 원소의 존재여부 확인
run &= ~(1 << i); // 원소 삭제
```

## ✨문자열 오답노트

for loop 돌릴 때 벡터나 문자열의 size 값을 활용하는데, 이때 unsigned int 대신 size_t를 활용하면 된다.

int t{}: 중괄호를 사용하는 유니폼 초기화(uniform initialization). 중괄호 안에 값이 없을 땐 기본 초기화, 0으로 초기화한다.

알파벳은 26개

괄호 변환 [#](https://school.programmers.co.kr/learn/courses/30/lessons/60058)
* 풀이 시간 50분 이내
* 틑린 이유: "나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다." 에서 뒤집는 거에만 집중해서 냅다 reverse 해버렸음.
* 문법 정리
  * reverse는 algorithm 헤더에 있고 reverse(str.begin(), str.end()); // 원본 변화!!!
  * string u = str.substr(1, u.size() - 2); // 시작, 길이. 원본 변화 X, 리턴됨.  
  * str.append(tmp); // str에 이어붙여짐.

팰린드롬 만들기 [#](https://www.acmicpc.net/problem/1213)
* 틀린 이유: 홀수 개인 문자의 개수가 1을 초과할 때 시작 부분에 홀수 개인 문자를 추가해야한다.
* 문법 정리
  * character를 string에 추가하는 방법: str.append(1, ch); // str에 추가됨.
  * character를 string으로 변환하는 방법: string(1, ch); // 반환값 이용.
  * character의 아스키코드값을 string으로 변환하는 방법: to_string(ch); // 반환값 이용.

키로거 [#]()

- string str2 = str1.insert(2, "CD"); // 2번 index에 문자열 삽입

JAVA vs C++ [#](https://www.acmicpc.net/problem/3613)
- 문자열 다룰 때 엣지 케이스 (첫, 끝 경계 부분) 잘 보기
- isupper(ch), islower(ch) -> true/false로 리턴
- toupper(ch), tolower(ch) -> 대문자로, 소문자로 변환해 리턴해줌.
  - 'A'-'a' 값을 더하거나 빼서 구현할 수도 있음.

## ✨구현 오답노트

창용이의 시계 [#](https://www.acmicpc.net/problem/12840)
- underflow 처리할 때 0보다 작을 때 1번만 더하는 것이 아니라 양수가 될 때까지 여러 번 더해주어야 함.

숫자 야구 [#](https://www.acmicpc.net/problem/2503)
* 처음 제출 (32분)까지 시간이 걸린 이유: for loop i, j 실수!!!
* 틀린 이유: 문제에서 빠뜨린 조건. 세 자리 수는 1~9, 서로 다른 수
* 서로 다른 수인 세자리 문자열 구하는데 시간 오래 걸림 
  * 순열, 조합 등 어느 문제인지 파악하고 stl을 활용해 구현하는 방법 익히기

등수 구하기 [#](https://www.acmicpc.net/problem/1205)
 
* 문제 설명: 위에서 몇번째?, 동일 점수, 가장 작은(좋은) 등수
* (예전에 처음 풀 때 못 풀어냈다가 다시 꺼내서 풀어봤음.)
* 틀린 이유: 코너 케이스는 처음부터 완벽히 처리했는데, 핵심 로직을 잘못 이해했음
  * "같은 점수가 있을 때는 그러한 점수의 등수 중에 가장 작은 등수가 된다." 이 조건에만 정신 팔려서
  * 같은 점수 이후에는 랭크를 다시 랭킹 리스트에서 몇 번째인지로 따져야하는데 여러 같은 점수들을 1개로 묶어버렸었음.

컨베이어 벨트 위의 로봇 [#](https://www.acmicpc.net/problem/20055)
* 코테에서 낼만한 좋은 문제.
* 회전 아이디어는 투 포인터를 두어 잘 구현했음, deque로도 풀 수 있으므로 확인해보자.
* 틀린 부분 1. 0과 n-1이 연결되는 자료 구조를 다루는 것이 핵심임.
  * end에서 start로 차례로 순회해야하는데
  * end = 2, start = 5 이런 경우에만 집중해서 항상 end += SIZE을 했음.
  * start = 0, end = 5일 땐 end 값이 배로 커져서 로직을 더 여러번 수행함.
  * -> 결과값만 찍어서 확인했는데 너무 보기 어려웠음.
  * 디버깅할 때 로직이 분명한 부분은 제외하고 세부적으로 for loop의 idx 값을 확인해보자

* 틀린 부분 2. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
  * 이 조건 문장에서 이동하려는 칸에 로봇이 없어야 한다는 조건을 빼먹었었다.
  * 금방 찾기는 했지만 한 번에 작성할 수 있도록 문제를 답지처럼 계속 읽자!

행운의 바퀴 [#](https://www.acmicpc.net/problem/2840)
* 풀이시간: 26분
* 틀린 이유: 바퀴에 같은 글자는 두 번 이상 등장하지 않는다.
* 방문 확인하는 로직 추가하여 AC 받음.

⚾ [#](https://www.acmicpc.net/problem/17281)
* 다시 구현해볼 문제.
* 주어진 숫자가 굉장히 작을 땐 가장 먼저 브루트 포스를 의심해보자.

뱀 [#](https://www.acmicpc.net/problem/3190)

* 아디이어: 덱을 활용하여 쉽게 뱀의 위치 정보를 갱신할 수 있음.
* 그래프 문제에서 범위 초과 판단할 때 주의깊게 작성하기!
* if (x < 0 || y < 0 || n <= x || n <= y) continue;

테트로미노 [#](https://www.acmicpc.net/problem/14500)
* 걸린 시간: 1시간
* 개선 사항
  1. visited 배열 없애기
  
  ```c++
  int save = p[nr][nc];
  p[nr][nc] = 0; // 방문함.
  backtracking(d + 1, nr, nc, ans + save);
  p[nr][nc] = save;
  ```
  
  2. 아이디어
     * 보라색 블럭을 모든 케이스를 나누어 러프하게 구현함. backtracking 함수 안에서 처리할 수 있었음.
     * 3개의 블럭이 결정된 이후에, 가운데에서 탐색해 구현할 수 있음.
  3. 가지치기
     - 나머지의 모든 값이 MAX여도 ans가 더 클 때는 더 이상 탐색할 이유가 없음.

나무 재테크 [#](https://www.acmicpc.net/problem/16235)

* 걸린 시간: 2시간
- **현재 계산한 값이 현재 값에 영향을 주면 안됨.** 
  - 봄에 나이가 증가하면서 죽은 나무가 양분이 되는 여름 연산을 연달아 하기 쉬움. 하지만 죽은 나무를 따로 저장해둔 뒤 봄이 끝나면 여름 작업이 시작되어야 함.
- 1씩 증가하거나 삭제되고 나서 1이 삽입되는 특별한 상황.
  - deque을 사용하여 앞뒤 삽입 삭제가 자유롭게,
  - 정렬을 매번하지 않도록 구현 가능. 
    - 원소 개수만큼 도는데 앞에서 빼고(삭제) 필요하면 수정해 뒤로 넣기(증가)
    - 삽입될 수 있는 가장 작은 값인 1은 push_front()를 활용해서 넣어주면 됨.


+) 디버깅이 어려운 상황에서 문법 한 줄 한 줄에 대한 완벽한 이해가 없으면 막막하고 두려워짐.

- deque은 sort 가능
- vector erase, 3차원 vector 초기화 방법