#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

bool cmpAdv(const student &a, const student &b) {
    if (a.kor != b.kor)
        return a.kor > b.kor;
    if (a.eng != b.eng)
        return a.eng < b.eng;
    if (a.math != b.math)
        return a.math > b.math;
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;
    vector<student> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
    }
    sort(arr.begin(), arr.end(), cmpAdv);
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << '\n';
    }
    return 0;
}