#include <iostream>
#include <vector>

using namespace std;

const int OP_NUMS = 4;
const int MAX_N = 11;

// 연산 결과의 범위 -10억 ~ 10억
int max_num = -1e9, min_num = 1e9, N;
int symbols[OP_NUMS];
int sequence[MAX_N];

void backtracking(int cnt, int result) {
    // 기저 조건 -> 연산 N-1번 다 돌았을 경우
    if(cnt == N - 1) {
        max_num = max(max_num, result);
        min_num = min(min_num, result);
    }

    for (int i = 0; i < OP_NUMS; i++) {
        // 연산자가 남아있는 경우
        if(symbols[i] > 0) {
            // 연산자 사용
            symbols[i]--;
            cnt++;

            // 각 연산자 별로 연산 수행
            if(i == 0) {
                backtracking(cnt, result + sequence[cnt]);
            } else if(i == 1) {
                backtracking(cnt, result - sequence[cnt]);
            } else if(i == 2) {
                backtracking(cnt, result * sequence[cnt]);
            } else {
                backtracking(cnt, result / sequence[cnt]);
            }

            // 사용한 연산자 회수
            symbols[i]++;
            cnt--;
        }
    }
}

int main() {
    // 입력
    cin >> N;
    
    // 숫자 입력
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    // 기호 입력
    for (int i = 0; i < OP_NUMS; i++) {
        cin >> symbols[i];
    }

    // 연산
    backtracking(0, sequence[0]);

    // 출력
    cout << max_num << '\n' << min_num;
    
}