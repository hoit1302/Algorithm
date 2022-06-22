#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int node[2];
    int dist;
    Node(int a, int b, int dist) {
        this->node[0] = a;
        this->node[1] = b;
        this->dist = dist;
    }
    bool operator <(Node &node) {
        return this->dist < node.dist;
    }
};
int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
bool findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}

vector<Node> v;
int parent[1004];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Node(a, b, c));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!findParent(parent, v[i].node[0], v[i].node[1])) {
            sum += v[i].dist;
            unionParent(parent, v[i].node[0], v[i].node[1]);
        }
    }
    cout << sum << "\n";
    return 0;
}
