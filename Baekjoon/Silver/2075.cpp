#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n, ele;
    cin >> n;

    // 표의 숫자를 저장할 우선순위 큐 선언 -> top에 최솟값이 오도록 비교연산자에 greater 사용
    priority_queue<int, vector<int>, greater<int> > q;

    // 표 입력 -> 그냥 전체를 우선순위 큐에 한번에 입력 받으면 메모리 초과 발생
    // 입력받은 숫자를 우선순위 큐에 삽입하되 크기가 n이 되도록 유지
    for (int i = 0; i < n * n; i++) {
        cin >> ele;
        q.push(ele);

        if(q.size() > n) {
            q.pop();
        }
    }
    
    // 출력
    cout << q.top();
}