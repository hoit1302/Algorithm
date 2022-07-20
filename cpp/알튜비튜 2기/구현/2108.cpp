#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // floor, round

using namespace std;

const int SIZE = 4000;

int calMode(vector<int> fre) {
    int max = *max_element(fre.begin(), fre.end());
//    cout << max << "임\n";
    vector<int> as;
    for (int i = 0; i <= SIZE * 2; i++) {
        if (max == fre[i]) {
            as.push_back(i);
        }
    }
    if (as.size() == 1) {
        return as[0] - SIZE;
    } else {
        sort(as.begin(), as.end());
        return as[1] - SIZE;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, total = 0, mean, median, mode, range;
    cin >> n;
    vector<int> v(n);
    vector<int> fre(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i]; // float total = accumulate(arr.begin(), arr.end(), 0); 이렇게도 구할 수 있음..!
        fre[v[i] + SIZE] += 1;
    }

    sort(v.begin(), v.end());
    mean = floor(total / (float) n + 0.5);
    median = v[n / 2];
    mode = calMode(fre);
    range = v[n - 1] - v[0]; // rbegin() -> 마지막 원소

    cout << mean << '\n' << median << '\n' << mode << '\n' << range << '\n';
    return 0;
}