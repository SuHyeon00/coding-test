#include <iostream>
#include <vector>

using namespace std;

int findChar(vector<char> &wheel, vector<bool> &used, int indent, int idx, char c) {
    int n = wheel.size();

    // 입력받은 간격 만큼 배열을 조회
    // 화살표는 반시계로 돌기 때문에 음수의 나머지로 계산
    idx = (idx + indent) % n;

    // 접근한 적 있는 인덱스의 문자가 입력받은 문자와 다를 경우
    if(wheel[idx] != '?' && wheel[idx] != c) {
        return -1; //해당하는 행운의 바퀴 없음
    }

    // 처음 접근하는 인덱스의 경우
    if(wheel[idx] == '?') {
        // 해당 문자가 이미 다른 인덱스에 있는 경우 (중복 문자 X)
        if(used[c - 'A']) {
            return -1;
        }

        // 문자 업데이트
        wheel[idx] = c;
        used[c - 'A'] = true;
    }

    return idx;
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    const int ALPHA = 26;

    // 바퀴 배열 생성
    vector<char> wheel(n, '?');
    // 해당 문자가 바퀴에 이미 들어간 문자인지 확인하기 위한 배열
    vector<bool> used(ALPHA, false);
    int indent, idx = 0;
    char c;

    while (k--) {
        // 연산
        cin >> indent >> c;
        idx = findChar(wheel, used, indent, idx, c);

        // 해당하는 바퀴가 없는 경우 프로그램 종료
        if(idx == -1) {
            break;
        }
    }

    // 결과 출력
    if(idx == -1) {
        cout << "!";
    } else {
        for (int i = idx + n; i > idx; i--) {
            cout << wheel[i % n];
        }
    }
}