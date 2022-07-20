#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 20;
vector<int> v(SIZE + 1);

void printVector() {
    for (int i = 0; i < 20; i++)
        cout << v[i] << ' ';
    cout << '\n';
}
int main() {
    for (int i = 0; i < SIZE; i++)
        v[i] = i + 1;

    int s, e;
    while (cin >> s >> e) {
        reverse(v.begin() + s - 1, v.begin() + e);
    }

    printVector();
    return 0;
}
