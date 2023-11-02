#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> nums;
    
    int n = number.size();
    
    for (int i = 0; i < n; i++) {
        // 만약 스택에 저장한 수가 집어놓고자 하는 수보다 작은 경우
        // 해당 값을 제외 (k 감소)
        while (!nums.empty() && nums.top() < number[i] && k > 0) {
            nums.pop();
            k--;
        }
        nums.push(number[i]);
    }
    
    // 남은 숫자 중에서 k개 제거 (스택의 크기가 n-k가 됨)
    while (k > 0) {
        nums.pop();
        k--;
    }
    
    // 스택에 남은 숫자를 결과 문자열에 추가
    while (!nums.empty()) {
        answer = nums.top() + answer;
        nums.pop();
    }
    
    return answer;
}
