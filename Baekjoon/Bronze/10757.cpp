#include <iostream>
#include <stack>

using namespace std;

int main() {

    // 입력된 문자 하나를 스택에 저장한 후
    // 뒷자리 (FILO 구조 이용 -> 스택)부터 합하며 계산
    stack<int> a, b;
    string a_string, b_string;

    stack<int> result; // 결과 저장해 둘 큐 선언 (FILO: 뒷자리 수부터 계산)
    int carry = 0;

    cin >> a_string >> b_string;

    // 입력값 스택에 저장
    for (int i = 0; i < a_string.length(); i++) {
        a.push(a_string[i] - '0');
    }
    for (int i = 0; i < b_string.length(); i++) {
        b.push(b_string[i] - '0');
    }

    // 연산
    while (!a.empty() || !b.empty()) {
        // 둘 중 한 스택이 비어있는 경우 비어있지 않은 스택의 값을 그대로 저장
        if(a.empty()) {
            if(b.top() + carry > 9) {
                result.push((b.top() + carry) % 10);
                carry = 1;
            } else {
                result.push(b.top() + carry);
                carry = 0;
            }
            b.pop();
            continue;
        } else if(b.empty()) {
            if(a.top() + carry > 9) {
                result.push((a.top() + carry) % 10);
                carry = 1;
            } else {
                result.push(a.top() + carry);
                carry = 0;
            }
            a.pop();
            continue;
        }

        // 두 스택 모두 값이 있는 경우 연산
        // 두 숫자의 합이 10 이상이면 올림 값이 있으므로 carry 업데이트
        result.push((a.top() + b.top() + carry) % 10);
        carry = (a.top() + b.top() + carry) / 10;

        a.pop(); b.pop();
    }

    // 만약 올림 수가 남아있을 경우 추가
    if(carry) {
        result.push(carry);
    }

    // 출력
    while(!result.empty()) {
        cout << result.top();
        result.pop();
    }
}