#include <iostream>
#include <string>

using namespace std;

int bruteforce (int cnt) {
    int num = 665; // 체크한 마지막 종말의 수 저장
    while(cnt) {
        // 종말의 수를 하나씩 증가시켜 봄 (마지막으로 체크한 종말의 수보다 하나 큰 값부터 조사)
        for (int i = num + 1; i > 0; i++) {
            string s = to_string(i);
            if(s.find("666") != string::npos) { // 666이 포함된 경우 종말의 수 업데이트 후 카운트 줄임
                num = i;
                break;
            }
        }
        cnt--;
    }

    return num;
}

int main() {
    // 입력
    int n;
    cin >> n;

    // 연산 & 출력
    cout << bruteforce(n);
}