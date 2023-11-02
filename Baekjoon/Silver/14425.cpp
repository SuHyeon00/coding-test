#include <iostream>
#include <set>

using namespace std;

int main() {

    int result = 0;

    // 입력
    int n, m;
    cin >> n;   cin >> m;

    // set을 이용해 집합에 포함되어 있는 문자열을 key값으로 하고
    // 비교해야 하는 문자열을 조회해 set에 있는 경우
    // result를 1 증가시킨다

    string set_input = "";
    string find = "";

    set<string> set;
    for (int i = 0; i < n; i++) {
       cin >> set_input;
       set.insert(set_input); // 입력 문자열 저장
    }

    for (int i = 0; i < m; i++) {
        // 검색할 문자열 입력 받기
        cin >> find;

        // set에 찾고자 하는 문자열이 있는 경우 +1
        if(set.find(find) != set.end()) {
            result++;
        }
    }

    // 최종 결과 출력
    cout << result;
}