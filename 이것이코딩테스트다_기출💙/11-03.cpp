#include <iostream>
#include <string>

using namespace std;

// 문자열 뒤집기
// 1100111 -> 1
// cur=1일 때(idx=1) 걸림, nxt = 0 시작점...(idx=2~, j=4)
// 101010101010 -> 6
// 구현은 그냥 순차적으로 접근해서 다르면 바꿔주면 됨!
// 근데 되게 복잡하게 구현함 ㅎㅎㅎ휴ㅠㅠㅠ
int main() {
//    freopen("../input.txt", "r", stdin);
    string str;
    cin >> str;
    int res = 0;
    for (int i = 0; i < str.length() - 1;) {
        char cur = str[i], nxt = str[i + 1];
        if (cur == nxt) {
            i++;
            continue;
        }

        res++;

        int j;
        for (j = i + 1; j < str.length(); j++) {
            if (nxt != str[j])
                break;
        }
        // i가 i+1이랑 다르고 i+1부터 j-1까지 (j 미포함) 같음.
        for (int k = i + 1; k < j; k++) {
            str[k] = cur;
        }
        i = j;
    }
    cout << res << "\n";
    return 0;
}