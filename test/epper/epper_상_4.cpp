#include <deque>
#include <iostream>
#include <string>
using namespace std;

//id톱니 dir방향으로 움직이기
void move_wheel(deque<char>* wheel, int id, int dir) {  
    if (dir == -1) { //반시계방향
        wheel[id].push_back(wheel[id][0]);
        wheel[id].pop_front();
    } else {  //시계방향
        wheel[id].push_front(wheel[id][7]);
        wheel[id].pop_back();
    }
}

	/*
		 0
	  7     1
	6	      2
	  5     3
		 4
	*/
// 9시 방향은 2, 3시 방향은 6
//톱니 전체 움직이기
void play(deque<char>* wheel, int num, int dir) {
    
	char pre_pole = wheel[num][6];  //움직이기 전의 극
    int tmp_dir = dir;
    for (int i = num - 1; i >= 0; i--) {  //움직일 톱니의 왼쪽 톱니들 움직이기
        if (wheel[i][2] == pre_pole) break;  //극이 같으면 패스
		tmp_dir *= (-1);
        pre_pole = wheel[i][6];              //움직이기 전의 극 저장
        move_wheel(wheel, i, tmp_dir);              //톱니 움직이기
    }
    
	pre_pole = wheel[num][2];
    tmp_dir = dir;
    for (int i = num + 1; i < 4; i++) {  //움직일 톱니의 오른쪽 톱니 들 움직이기
        if (wheel[i][6] == pre_pole) break;  //극이 같으면 패스
		tmp_dir *= (-1);
        pre_pole = wheel[i][2];
        move_wheel(wheel, i, tmp_dir);
    }
    
	move_wheel(wheel, num, dir);  //해당 톱니 움직이기
}

int solution(deque<char>* wheel, int k, int[][] spin) {
    for (int i = 0; i < k; i++) {
        int num = spin[i][0];
        int dir = spin[i][1];
        play(wheel, num - 1, dir);  // 톱니바퀴 번호는 1~4, 인덱스는 0~3
    }

	//점수계산
    int total = 0;
	int plus = 1;  
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0] == '1') total += plus;
        plus *= 2;
    }
    return total;
}

int main() {
    deque<char> wheel[4];  // 톱니바퀴 [번호][방향]
    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            wheel[i].push_back(str[j]);
        }
    }
    int k;  // 회전 횟수
    cin >> k;
    int** spin = new int*[k];  // 회전정보[번호][방향]
    for (int i = 0; i < k; i++) {
		spin[i] = new int[2];
        int num, dir;
        cin >> num >> dir;
        spin[i][0] = num;
        spin[i][1] = dir;
    }
    cout << solution(wheel, k, spin) << "\n";
    return 0;
}