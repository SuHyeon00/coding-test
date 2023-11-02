#include <iostream>
#include <set>

using namespace std;

const int MAX = 7;

int n, m;
int sequence[MAX];
set<int> nums[MAX]; // 입력 숫자의 중복 제거를 위해 셋으로 입력값 받음

void printSequence() {
    for(int num: sequence) {
        if(num != 0) {
            cout << num << " ";
        }
    }
    cout << '\n';
}

void backtracking(int cnt) {
    // 기저 조건
    if(cnt == m) {
        printSequence();
        return;
    }

    for(auto iter = nums->begin(); iter != nums->end(); iter++) {
        sequence[cnt] = *iter;

        // 다음 숫자 진행
        backtracking(cnt + 1);
    }
}

int main() {
    // 입력
    cin >> n >> m;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums->insert(x);
    }

    // 연산 & 출력
    backtracking(0);
}