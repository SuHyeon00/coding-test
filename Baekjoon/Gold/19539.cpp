#include <iostream>

using namespace std;

int main() {
    // 입력
    int n, h, total_h = 0, two_cnt = 0;
    cin >> n;

    while(n--) {
        cin >> h;
        total_h += h;
        // 사과나무의 높이를 2만큼 조절할 수 있는 횟수 카운팅
        two_cnt += h / 2;
    }
    
    /*
     총 물 뿌리는 횟수 == total_h / 3

    */

    // 연산 & 출력
    // 한 단계마다 총 나무 높이는 3씩 증가하기 때문에 최종 합이 3의배수가 되어야 하며
    // 2만큼 높이를 조절하는 횟수가 전체 나무 높이의 합 / 3보다 크거나 같아야 함
    if(total_h % 3 != 0 || two_cnt < total_h / 3) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}