#include <iostream>

using namespace std;

// 돌을 이동할 수 있는지 확인하는 함수
bool canMove(string king_pos, string rock_pos) {
    return king_pos != rock_pos;
}

// 체스판을 벗어나지 않는지 확인하는 함수
bool checkAvail(string pos) {
    if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8') {
        return true;
    }

    return false;
}

// 킹과 돌을 이동시키는 함수
void move(pair<string, string>& pos, int direction) {
    // 0 1 2 3 4 5 6 7 순서대로 R L B T RT LT RB LB -> 인덱스에 맞게 이동 배열 선언
    int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};

    // 킹과 돌의 위치 임시로 저장할 변수
    string king_pos = pos.first;
    string rock_pos = pos.second;

    // 킹을 방향에 맞게 움직임
    king_pos[0] += dx[direction];
    king_pos[1] += dy[direction];

    // 킹의 위치가 체스판을 벗어나는 경우 해당 스텝 스킵
    if (checkAvail(king_pos)) {
        return;
    }

    // 킹의 위치와 돌의 위치가 같으면 돌도 같은 방향으로 이동
    if (king_pos == rock_pos) {
        rock_pos[0] += dx[direction];
        rock_pos[1] += dy[direction];

        // 돌의 위치가 체스판을 벗어나지 않는지 확인
        if (checkAvail(rock_pos)) {
            return;
        }
    }

    // 모든 조건을 만족하면 이동
    pos.first = king_pos;
    pos.second = rock_pos;
}

int main() {
    // 입력
    pair<string, string> pos;
    int n;
    cin >> pos.first >> pos.second >> n;

    string cmd;

    while (n--) {
        cin >> cmd;
        int direction = -1;

        // 주어진 명령어에 따라 이동 방향 결정
        if (cmd == "R") {
            direction = 0;
        } else if (cmd == "L") {
            direction = 1;
        } else if (cmd == "B") {
            direction = 2;
        } else if (cmd == "T") {
            direction = 3;
        } else if (cmd == "RT") {
            direction = 4;
        } else if (cmd == "LT") {
            direction = 5;
        } else if (cmd == "RB") {
            direction = 6;
        } else if (cmd == "LB") {
            direction = 7;
        }

        if (direction != -1 && canMove(pos.first, pos.second)) {
            move(pos, direction);
        }
    }

    // 출력
    cout << pos.first << "\n" << pos.second << "\n";
}