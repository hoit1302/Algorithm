#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
 * 접근: 구현 문제
 * 풀이 시간: 1시간
 * 40분 정도 삽질을 하다가 코드를 싹 지우고 종이에 로직을 적어본 뒤 구현하니 통과됨.
 * 아쉬운 점: 대소 비교를 활용하지 않고 풀었음, order로 for loop를 돌리면 더 쉽게 풀림.
 */

int solution(vector<int> order) {
    size_t n = order.size();
    stack<int> st;
    int or_p = 0, b_p = 1; // b_p: 영재에게 전달되는 상자

    // 주어 3개: 영재, 서브, 트럭
    // 행동 2가지: 서브에 넣기, 트럭에 넣기
    while (true) {
        // 종료 조건: 영재 끝까지 탐색했고, stack이 비었거나 top과 다를 때
        if (b_p == n + 1 && (st.empty() || st.top() != order[or_p])) {
            break;
        }

        if (b_p == order[or_p]) { // 영재와 트럭이 같아 영재가 트럭에 넣기
            b_p++;
            or_p++;
            continue;
        }
        // 영재와 트럭이 다름
        if (st.empty() || st.top() != order[or_p]) {
            st.push(b_p++);
            continue;
        }
        // 서브와 트럭이 같아 서브에서 트럭에 넣기
        st.pop();
        or_p++;
    }
    return or_p;
}
