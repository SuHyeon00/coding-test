#include <iostream>
#include <map>

using namespace std;

int main() {
    // 입력
    int t, n;
    cin >> t;

    // 의상의 종류 별 갯수를 저장할 맵 선언
    map<string, int> clothes;
    string item;
    string category;

    // 테스트 케이스 만큼 반복문 돌림
    while(t--) {
        cin >> n;

        // 옷장과 결과 가짓수 초기화
        clothes.clear();
        int result = 1;

        for (int j = 0; j < n; j++) {
            cin >> item >> category;

            // 해당하는 카테고리의 item 수 증가시키기
            clothes[category]++;
        }

        // 맵을 돌면서 각 카테고리 별 아이템 수 탐색
        // 각 카테고리 별 1가지 아이템을 선택하거나 선택하지 않는 경우가 있으므로
        // value + 1의 값들을 모두 곱한 후
        // 아무것도 선택하지 않은 경우인 1을 빼준다
        for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
            result *= iter->second + 1;
        }

        cout << result - 1 << '\n';   
    }
}