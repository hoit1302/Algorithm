#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int a, b;

    while (t--) {
        cin >> a >> b;
        vector<int> arr;
        int first = a % 10;

        arr.push_back(first);
        int bef = first;
        while (first != (bef * first) % 10) {
            bef = (bef * first) % 10;
            arr.push_back(bef);
        }
        int ans = arr[(b - 1) % arr.size()];
        cout << (ans ? ans : 10)  << '\n';
    }
}