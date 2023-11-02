#include <iostream>
#include <vector>

using namespace std;

bool checkAvail(int pos, vector<bool> &robots, vector<int> &durability) {
    // 로봇이 없으면서 내구도가 1 이상이어야 이동 가능
    return !robots[pos] && durability[pos] >= 1;
}

int conveyor(vector<int> &durability, int k) {
    int step = 0, cnt = 0, n = durability.size() / 2;
    vector<bool> robots(n, false);

    while(true) {
        step++;
        // 1. 벨트 한 칸 회전
        // 마지막 컨베이어벨트 칸이 앞으로 와야하므로 잠시 저장
        int last_d = durability[2 * n - 1];
        for (int i = 2 * n - 1; i > 0; i--) {
            // 인덱스 한 칸 뒤로 내구도 옮기기
            durability[i] = durability[i - 1];
        }
        // 올리는 칸 내구도 업데이트
        durability[0] = last_d;

        // 벨트 회전에 따른 로봇 이동
        for (int i = n - 1; i > 0; i--) {
            robots[i] = robots[i - 1];
        }
        robots[0] = false;

        // 로봇이 내려가는 위치에 도달하면 즉시 내리기
        robots[n - 1] = false;

        // 2. 로봇 이동 -> 가장 먼저 벨트에 올라간 로봇 (뒤에서부터 조회)
        for (int i = n - 2; i > 0; i--) {
            // 현재 칸에 이동시킬 로봇이 없는 경우 스킵
            if(!robots[i]) {
                continue;
            }
            
            // 다음 칸으로 이동시킬 수 있는지 확인
            if(checkAvail(i + 1, robots, durability)) {
                // 로봇 이동 (이동 즉시 내구도 감소)
                robots[i] = false;
                robots[i + 1] = true;
                durability[i + 1]--;

                // 내구도가 0이 되었다면 카운트값 증가
                if(durability[i + 1] == 0) {
                    cnt++;
                }
            }
        }

        // 3. 로봇 올리기 (올리는 위치 0)
        if(checkAvail(0, robots, durability)) {
            robots[0] = true;
            durability[0]--;

            // 내구도가 0이 되었다면 카운트값 증가
            if(durability[0] == 0) {
                cnt++;
            }
        }

        // 4. 내구도 검사
        if(cnt >= k) {
            return step;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n, k;
    cin >> n >> k;

    // 내구도 입력
    n *= 2;
    vector<int> duraility(n);
    for (int i = 0; i < n; i++) {
        cin >> duraility[i];
    }

    // 연산
    int step = conveyor(duraility, k);

    // 출력
    cout << step;
}