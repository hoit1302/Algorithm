// epper 하 1
#include <string>
#include <vector>
using namespace std;
vector<string> solution(int r, int c, int zr, int zc, vector<string> words) {
    vector<string> answer;
    string temp;
    for (int i = 0; i < r; i++) { // 각 줄마다 zr, zc 처리
        temp = "";
        for (int j = 0; j < c; j++)
            for (int k = 0; k < zc; k++)
                temp += words[i][j]; // 가로로 늘리고
        for (int m = 0; m < zr; m++)
            answer.push_back(temp); // 세로로 늘리고
    }
    return answer;
}
