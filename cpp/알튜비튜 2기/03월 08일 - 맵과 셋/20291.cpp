#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    string str;
    map<string, int> map;
    cin >> n;
    while (n--) {
        cin >> str;
        // . 뒤의 부분 문자열 추출
        string ext = str.substr(str.find('.') + 1);
        map[ext]++;
    }
    for (auto & iter : map) {
        cout << iter.first << ' ' << iter.second << '\n';
    }
    return 0;
}