#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, rm, p;
    cin >> n;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        cin >> parent[i];
    cin >> rm;
    // 특정 노드를 지운 트리 만들기
    parent[rm] = -2;
    for (int i = 0; i < n; i++) {
        // 부모 노드(-1)나 지울 노드(-2)까지 거슬러 올라감.
        p = parent[i];
        while (0 <= p) {
            p = parent[p];
        }
        if (p == -2) { // 지울 노드면 부모 노드를 -2로 바꾸어 연결 끊기
            parent[i] = -2;
        }
    }
    // 리프노드를 찾을 수 있도록 자식 정보를 저장함.
    // 만약 2개의 노드 정보를 가지고 있다면 1개의 정보만 저장됨. (있/없 정보 저장)
    vector<bool> child(n, 0);
    for (int i = 0; i < n; i++) {
        if (parent[i] < 0)
            continue;
        child[parent[i]] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        // 자신이 지울 노드가 아니고 리프 노드이면 개수 + 1
        if (parent[i] != -2 && child[i]) {
            res++;
        }
    }
    cout << res;
}
