#include <string>
#include <vector>

using namespace std;

/*
 * 접근: 각 수의 개수를 저장하고 최소 개수를 구한 뒤 정답 리턴
 * 풀이 시간: 15분 ~ 20분
 */
string solution(string x, string y) {
    // 1. 정수 개수 저장
    vector<int> x_c(10, 0), y_c(10, 0);
    for (size_t i = 0; i < x.size(); i++) {
        x_c[x[i] - '0']++;
    }
    for (size_t i = 0; i < y.size(); i++) {
        y_c[y[i] - '0']++;
    }

    // 2. 같은 최소 개수 저장
    bool is_exist = false, is_na_exist = false;
    for (int i = 0; i <= 9; i++) {
        x_c[i] = min(x_c[i], y_c[i]);
        if (x_c[i] != 0) {
            is_exist = true;
        }
        if (i != 0 && x_c[i] != 0) {
            is_na_exist = true;
        }
    }
    if (!is_exist)
        return "-1";
    if (!is_na_exist)
        return "0";

    // 3. 정답 문자열 생성
    string ans = "";

    for (int i = 9; i >= 0; i--) {
        if (x_c[i] == 0) {
            continue;
        }
        // 정수 i가 1개 이상 존재함.
        for (int j = 0; j < x_c[i]; j++) {
            ans.append(to_string(i));
        }
    }
    return ans;
}
