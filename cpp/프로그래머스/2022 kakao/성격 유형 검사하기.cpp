#include <string>
#include <vector>
#include <iostream>
using namespace std;

int score[4][2] = {0, };
char type[4][2] = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
int getTypeNum(string str) {
    char s = str[0];
    if (s == 'R' || s == 'T') return 0;
    if (s == 'C' || s == 'F') return 1;
    if (s == 'J' || s == 'M') return 2;
    return 3;
}
int getPos(char c) {
    if (c == 'R' || c == 'C' || c == 'J' || c == 'A') return 0;
    return 1;
}

/*
 * https://school.programmers.co.kr/learn/challenges?partIds=31236
 * Lv. 1
 * 풀이 시간: 35분... 배울 점은 정신 차리고 풀기
 */
string solution(vector<string> survey, vector<int> choices) {
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] < 4) {
            score[getTypeNum(survey[i])][getPos(survey[i][0])] += abs(choices[i] - 4);
        } else {
            score[getTypeNum(survey[i])][getPos(survey[i][1])] += abs(choices[i] - 4);
        }
    }
    string ans;
    for (int i = 0; i < 4; i++) {
        if (score[i][0] < score[i][1]) {
            ans.append(1, type[i][1]);
        } else {
            ans.append(1, type[i][0]);
        }
    }
    return ans;
}