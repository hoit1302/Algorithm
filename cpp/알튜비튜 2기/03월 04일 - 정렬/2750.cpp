#include <iostream>
#include <vector>

using namespace std;

// 버블 소트 구현해보기, 향상된 버블 소트 구현해보기

vector<int> arr;

void bubbleSort(int n);

void bubbleSortAdv(int n);

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //연산
//    bubbleSort(n);
    bubbleSortAdv(n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}

void bubbleSortAdv(int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swap_flag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swap_flag = true;
            }
        }
        if (!swap_flag)
            return;
    }
}

void bubbleSort(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
