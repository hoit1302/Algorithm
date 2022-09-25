#include <vector>
using namespace std;

int arr[1001][2]; // 2번째 0: 2^n으로 정해진 배열 크기, 원소 수

vector<int> two;
int findArraySize(int n) {
    for (int i = 0; i < two.size(); i++) {
        if (n <= two[i]) {
            return two[i];
        }
    }
}

int solution(vector<vector<int>> queries) {
    for (int i = 1; i < 2e9; i *= 2) {
        two.push_back(i);
    }
    int ans = 0;
    for (auto query: queries) {
        int arr_n = query[0];
        // 1. 배열이 생성되지 않았을 때, 복사 X, 원소만 추가됨.
        if (arr[arr_n][0] == 0) {
            arr[arr_n][0] = findArraySize(query[1]);
            arr[arr_n][1] = query[1];
            continue;
        }
        // 2. 배열이 이미 생성되어 있고 원소를 추가했을 때
        // 2-1.  배열 크기 이하일 때 복사 X
        if (arr[arr_n][1] + query[1] <= arr[arr_n][0]) {
            arr[arr_n][1] += query[1];
            continue;
        }
        // 2-2. 배열 크기 초과일 때 복사 후 배열 크기 증가시켜 원소 추가
        ans += arr[arr_n][1];
        arr[arr_n][1] += query[1];
        arr[arr_n][0] = findArraySize(arr[arr_n][1]);
    }
    return ans;
}
