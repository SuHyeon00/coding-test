#include <iostream>

using namespace std;

const int ALL = (1 << 20) - 1;

int setOper(string cmd, int x, int &S) {
    if (cmd == "add") {
        S |= 1<<x; // 합칩합 ( "|" 연산)
        return 2;
    }

    if (cmd == "remove") {
        S &= ~(1<<x); // 차집합 ( & ~ 연산)
        return 2;
    }

    if (cmd == "check") {
        // & 연산을 했을 때 x가 S에 존재했다면 1 & 1 --> 1이고
        // 존재하지 않았다면 1 & 0 --> 0이므로
        // 존재하지 않을 경우에는 연산 결과 0(false)이
        // 존재할 경우에는 연산 결과 1<<x(true)가 됨
        return (S & (1<<x)) ? 1 : 0;
    }

    // S에 x가 있는 경우 제거
    if (cmd == "toggle") {
        S ^= 1<<x; // xor 연산으로 있는 경우에는 제거 없는 경우에는 추가
        return 2;
    }
    
    if (cmd == "all") {
        S = ALL; //1 ~ 20번째 비트 1로 체크
        return 2;
    }

    if (cmd == "empty") {
        S = 0; // 초기화
        return 2;
    } 
    
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 입력
    int m, x, S = 0; // 집합 S를 비트마스크 0으로 초기화
    cin >> m;

    string cmd;

    // 연산
    while(m--) {
        cin >> cmd;
        // all or empty의 경우 x input이 없음 
        if(cmd != "all" && cmd != "empty") {
            cin >> x;
            x--;  // 문제에서 주어지는 숫자는 1부터 20까지지만, 배열 인덱스는 0부터 시작하므로 1을 뺌
        }
        int oper = setOper(cmd, x, S);

        // check 명령어 이외의 경우 연산 계속 진행
        if(oper == 2) {
            continue;
        }

        // 출력
        cout << oper << "\n";
    }
}