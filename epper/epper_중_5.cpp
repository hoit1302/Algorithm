// epper 중 5
#include <string>
#include <vector>
using namespace std;

long long solution(int n, vector<int> times) {
    long long low, high, mid, sum, answer;
    high = 1e18;  // 이 문제 조건에서 정답으로 낼 수 있는 최댓값
    // 최대 1e9 심사대에서, 각 심사대마다 최대 1e9 시간이 걸릴 수 있으므로
    low = 1;
    answer = high;

    while (high >= low) {
        mid = (high + low) / 2;
        sum = 0;
        for (int i = 0; i < times.size(); i++) {
            sum += mid / times[i];  // mid 값의 시간이 걸린다고 했을 때 심사받을 수 있는 사람 수를 sum에 저장
            if (sum >= n) break;
        }
        if (sum >= n) {                      // 심사받기 원하는 사람수와 같거나 많으면
            if (mid < answer) answer = mid;  // answer에는 최소값을 담아야하므로 최솟값으로 갱신
            high = mid - 1;                  // down
        } else {                             // 심사받기 원하는 사람수보다 적으면
            low = mid + 1;                   // up
        }
    }
    return answer;
}
