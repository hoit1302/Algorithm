#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int v[200000];
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }
    sort(v, v + N); // -> array
//    sort(v.begin(), v.end()); -> vector
//    sort(v, v+N, cmp); 이렇게 해서 cmp 함수 구현 가능
    cout << v[(N - 1) / 2] << "\n";
    return 0;
}