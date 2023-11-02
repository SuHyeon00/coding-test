#include <iostream>
#include <vector>

using namespace std;

const int ALPHA = 26;

string greedy(string s) {
    string ans_f = "", ans_b = ""; // 팰린드롬을 이룰 앞 문자열과 뒷 문자열
    vector<int> charArr(ALPHA, 0); // 알파벳 빈도수 체크를 위한 배열

    // 문자열 s가 갖고 있는 알파벳 수 업데이트
    for (char c : s) {
        charArr[c - 'A']++;
    }
    
    // 문자열의 크기가 홀수인 경우 중앙 문자를 찾아야 함
    string middle_s = "";
    for (int i = 0; i < ALPHA; i++) {
        // 알파벳 갯수가 홀수이면서 중앙 문자가 없는 경우 해당 알파벳으로 업데이트
        if(charArr[i] % 2 == 1 && middle_s == "") {
            middle_s = i + 'A';
            charArr[i]--; // 중앙 문자로 사용함
        } else if(charArr[i] % 2 == 1) { // 중앙 문자를 업데이트 한 후에 또 홀수개인 알파벳이 있는 경우
            // 팰린드롬 성립 불가
            return "I'm Sorry Hansoo";
        }
    }

    // 앞 뒤로 문자 추가
    for (int i = 0; i < ALPHA; i++) {
        // 알파벳 순으로 확인하며 해당 알파벳의 갯수가 남아있는 경우
        if(charArr[i] > 0) {
            // 갯수를 절반 나누어서 앞 뒤로 붙여줌
            string chars(charArr[i] / 2, i + 'A');
            ans_f = ans_f + chars;
            ans_b = chars + ans_b;
        }
    }
    

    return ans_f + middle_s + ans_b;

}

int main() {
    // 입력
    string s;
    cin >> s;

    // 연산 & 출력
    cout << greedy(s);
}