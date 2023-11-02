#include <iostream>
#include <queue>

using namespace std;

void Josephus(queue<int> &q, int k) {
    // k의 간격이 되기 전까지 사람을 큐에서 제거하고
    // k의 간격이 된 순간 해당 사람을 출력하며 제거
    int ele; // 임시 저장 변수
    int cnt = 0;
    while (q.size() != 1) {
        cnt++;
        if(cnt % k == 0) { // 간격이 맞을 경우 출력
            cout << q.front() << ", ";
            q.pop();
        } else { // 간격이 맞지 않을 경우 제거 후 가장 뒤에 추가
            ele = q.front();
            q.pop();
            q.push(ele);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    // 입력
    int n, k;
    cin >> n >> k;

    queue<int> q;

    // 사람 수 만큼 큐에 번호 추가
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    // k의 간격이 되기 전까지 사람을 큐에서 제거하고
    // k의 간격이 된 순간 해당 사람을 출력하며 제거
    cout << '<';
    Josephus(q, k);

    // 마지막 원소 출력 형태 맞추기
    cout << q.front() << '>';
}