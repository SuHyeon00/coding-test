#include <iostream>
#include <stack>

using namespace std;

// 연산자 우선순위 결정 함수
int checkPriority(char c) {
    if(c == '(') {
        return 0;
    }
    if(c == '+' || c == '-') {
        return 1;
    }
    
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    // 입력
    string infix;
    cin >> infix;

    stack<char> operators;
    int priority;

    for (int i = 0; i < infix.length(); i++) {
        // 알파벳일 경우 그대로 출력
        if(infix[i] >= 'A' && infix[i] <= 'Z') {
            cout << infix[i];
        } else if(infix[i] == '(') {
            operators.push(infix[i]); // 여는 괄호 저장
        } else if(infix[i] == ')') { // 닫는 괄호일 경우 여는 괄호 만나기 전까지 출력
            while (!operators.empty() && operators.top() != '(') {
                cout << operators.top();
                operators.pop();
            }
            operators.pop(); // 여는 괄호 제거
        } else { // 연산자( + - * / '(' )일 경우 우선순위 체크
            priority = checkPriority(infix[i]);
            while (!operators.empty() && checkPriority(operators.top()) >= priority) {
                cout << operators.top();
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }

    // 스택에 남아있는 연산자들 출력
    while(!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }
}