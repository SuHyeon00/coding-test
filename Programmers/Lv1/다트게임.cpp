#include <string>
#include <stack>
#include <cmath>

using namespace std;

void star(stack<int>& scores) {
    int num1, num2;
    
    // 현재 점수 2배
    num1 = scores.top();
    num1 *= 2;
    scores.pop();
    
    // 이전 점수 2배
    if(!scores.empty()) {
        num2 = scores.top();
        num2 *= 2;
        scores.pop();
        scores.push(num2);
    }
    
    scores.push(num1);
}

void dartGame(stack<int>& scores, char c) {
    // *상
    if(c == '*') {
        star(scores);
        return;
    }
    
    int cal_num = 0;
    // S, D, T
    if(c == 'S') {
        cal_num = pow(scores.top(), 1);
    } else if(c == 'D') {
        cal_num = pow(scores.top(), 2);
    } else if(c == 'T') {
        cal_num = pow(scores.top(), 3);
    } else if(c == '#') {
        cal_num = scores.top() * (-1);
    }
    
    // 계산 값 업데이트
    scores.pop();
    scores.push(cal_num);
}

int solution(string dartResult) {
    int answer = 0;
    stack<int> scores;
    string score = "";
    bool flag = false;
    
    for(auto c : dartResult) {
        // 숫자일 경우 숫자 추가
        if(c - '0' >= 0 && c - '0' < 10) {
            score += c;
            flag = true;
        } else { // 숫자가 아닐 경우 연산 수행
            if(flag) {
                scores.push(stoi(score));
                flag = false;
            }
            dartGame(scores, c);
            score = "";
        }    
    }
    
    // 연산
    while(!scores.empty()) {
        answer += scores.top();
        scores.pop();
    }
    
    return answer;
}