#include <iostream>
#include <deque>

using namespace std;

struct conveyor {
    int durability; // 내구도
    bool robot; // 로봇 존재 여부
};

// 1. 벨트 한 칸 회전
void rotateBelt(deque<conveyor> &belt, int n) {
    // 가장 마지막 칸 벨트가 첫번째 벨트로 이동
    belt.push_front(belt.back());
    belt.pop_back();

    // 로봇이 내려가는 위치에 도달하면 즉시 내리기
    belt[n - 1].robot = false;
}

// 2. 로봇 이동 -> 가장 먼저 벨트에 올라간 로봇 (뒤에서부터 조회)
void moveRobot(deque<conveyor> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) {
        // 현재 칸에 이동시킬 로봇이 없는 경우 스킵
        if(!belt[i].robot) {
            continue;
        }
        
        // 다음 칸으로 이동시킬 수 있는지 확인
        if(!belt[i + 1].robot && belt[i + 1].durability >= 1) {
            // 로봇 이동 (이동 즉시 내구도 감소)
            belt[i].robot = false;
            belt[i + 1].robot = true;
            belt[i + 1].durability--;
        }

        // 로봇 내리는 위치에서 내리기
        belt[n - 1].robot = false;
    }
}

// 3. 로봇 올리기 (올리는 위치 0)
void pubRobot(deque<conveyor> &belt) {
    if(!belt[0].robot && belt[0].durability >= 1) {
        belt[0].durability--;
        belt[0].robot = true;
    }
}

// 벨트 내구도 체크
bool checkFinish(deque<conveyor> &belt, int n, int k) {
    int count = 0;

    for(int i = 0; i < 2 * n; i++) {
        if(belt[i].durability == 0) {
            count++;
        }
    }

    return count >= k;
}

int solution(deque<conveyor> &belt, int n, int k) {
    int step = 1;

    while(true) {
        // 1. 벨트 한 칸 회전
        rotateBelt(belt, n);

        // 2. 로봇 이동 -> 가장 먼저 벨트에 올라간 로봇 (뒤에서부터 조회)
        moveRobot(belt, n);

        // 3. 로봇 올리기 (올리는 위치 0)
        pubRobot(belt);

        // 4. 내구도 검사
        if(checkFinish(belt, n, k)) {
            return step;
        }

        step++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n, k;
    cin >> n >> k;

    // 컨베이어 벨트의 내구도 및 로봇 존재 여부 저장
    deque<conveyor> belt(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].durability;
        belt[i].robot = false;
    }

    // 연산
    int step = solution(belt, n, k);

    // 출력
    cout << step;
}