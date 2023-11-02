#include <iostream>
#include <vector>

using namespace std;

const int ALPHA = 26;

// 주어진 문자열의 알파벳 카운트 배열을 반환하는 함수
vector<int> getCharCnt(string s) {
    vector<int> charArr(ALPHA, 0);

    for (int i = 0; i < s.size(); i++) {
        charArr[s[i] - 'A']++;
    }
    
    return charArr;
}

// 비슷한 단어인지 확인하는 함수
bool similarWord(string s1, string s2) {
    vector<int> arr1, arr2;
    int diffCnt = 0;

    // 각 문자열 별로 알파벳 카운트 계산
    arr1 = getCharCnt(s1);
    arr2 = getCharCnt(s2);
    
    for (int i = 0; i < ALPHA; i++) {
        // 알파벳 갯수의 차이 만큼 diffCnt 증가시켜 줌
        diffCnt += abs(arr1[i] - arr2[i]);
    }

    // diffCnt가 1인 경우는 한 문자를 더하거나 빼주면 비슷한 단어가
    // diffCnt가 2인 경우는 하나의 문자를 다른 문자로 바꿔주면 비슷한 단어가 됨

    int n1 = s1.size();
    int n2 = s2.size();
    
    // 다른 문자로 바꿔주는 경우 (diffCnt == 2)
    if(diffCnt == 2) {
        // s1과 s2의 사이즈가 같은지 확인
        return n1 == n2;
    }

    // 같은 구성을 갖는 단어(diffCnt == 0)거나
    // 한 문자를 더하거나 빼주는 경우 (diffCnt == 1)
    return diffCnt == 1 || diffCnt == 0;
}

int main() {
    // 입력
    int n, cnt = 0;
    cin >> n;

    string origin_s, comp_s;

    // 첫 번째 단어 입력
    cin >> origin_s;
    n--;

    while(n--) {
        // 비교할 단어 입력
        cin >> comp_s;

        // 비슷한 단어인지 연산
        if(similarWord(origin_s, comp_s)) {
            cnt++;
        }
    }

    // 출력
    cout << cnt << "\n";
}