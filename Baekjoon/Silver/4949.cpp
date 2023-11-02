#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkPair(stack<char> &s, string input) {
    bool flag = true;

    for (int i = 0; i < input.length(); i++) {
        // 문장 종료 조건을 만났을 경우 반복문 벗어난 후 결과 출력
        if(input[i] == '.') {
            break;
        }
            
        // 괄호의 쌍이 맞는지 체크
        if(input[i] == '(' || input[i] == '[') {    // 여는 괄호일 경우 스택에 추가하기
            s.push(input[i]);
        } else if(input[i] == ')') {                // 닫는 괄호의 경우 스택의 top과 비교
            if(!s.empty() && s.top() == '(') {      // 스택이 비어있지 않으며 짝이 맞는 경우 제거
                s.pop();
            } else {                                // 짝이 맞지 않는 경우 즉시 반복문 벗어남
                flag = false;
                break;
            }
        } else if(input[i] == ']') {                // 소괄호와 동일
            if(!s.empty() && s.top() == '[') {
                s.pop();
            } else {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

int main() {

    string input;

    // 입력이 있는 동안 반복
    while (getline(cin, input)) {
        
        stack<char> s; // 괄호 저장할 스택 선언
        bool flag = true;

        // 입력 종료 조건
        if(input == ".") {
            break;
        }
        
        flag = checkPair(s, input);
        
        if(flag && s.empty()) {    // 스택이 비어있으며 종료조건을 만난 후 반복문 벗어난 경우
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}