#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 입력
    int n; // 아이들과 거점지를 방문한 횟수
    cin >> n;

    priority_queue<int> presents;
    int a, num;

    while(n--) {
        cin >> a;

        // a가 0인 경우 아이들에게 준 선물의 가치 출력
        if(a == 0) {
            // 아이들에게 줄 선물이 없는 경우
            if(presents.empty()) {
                cout << "-1\n";
            } else {
                // 줄 선물이 있는 경우 가장 가치가 큰 선물 전달
                cout << presents.top() << "\n";
                presents.pop();
            }
        } else { // a가 0이 아닌 경우엔 충전할 선물의 갯수
            while(a--) {
                cin >> num;

                presents.push(num); // 선물 충전
            }
        }
    }
}