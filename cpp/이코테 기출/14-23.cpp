// 코드 구현법 (문법) 외워야함. 잘 나오는 템플릿
#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int kor;
    int eng;
    int m;
    Student(string name, int kor, int eng, int m) {
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->m = m;
    }
    /*
    [ 정렬 기준 ]
    1) 두 번째 원소를 기준으로 내림차순 정렬
    2) 두 번째 원소가 같은 경우, 세 번째 원소를 기준으로 오름차순 정렬
    3) 세 번째 원소가 같은 경우, 네 번째 원소를 기준으로 내림차순 정렬
    4) 네 번째 원소가 같은 경우, 첫 번째 원소를 기준으로 오름차순 정렬
    */
    bool operator <(const Student &other) const {
        if (this->kor == other.kor && this->eng == other.eng && this->m == other.m) {
            return this->name < other.name;
        }
        if (this->kor == other.kor && this->eng == other.eng) {
            return this->m > other.m;
        }
        if (this->kor == other.kor) {
            return this->eng < other.eng;
        }
        return this->kor > other.kor;
    }
};

int n;
vector<Student> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor;
        int eng;
        int m;
        cin >> name >> kor >> eng >> m;
        v.push_back(Student(name, kor, eng, m));
    }

    sort(v.begin(), v.end());

    // 정렬된 학생 정보에서 이름만 출력
    for (int i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
}