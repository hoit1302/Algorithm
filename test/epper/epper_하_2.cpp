// epper 하 2
#include <string>
using namespace std;
int solution(string str) {
    int score = 0, totalScore = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'O') score += 1;
        else score = 0;
        totalScore += score;
    }
    return totalScore;
}
