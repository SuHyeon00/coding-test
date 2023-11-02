#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, vector<int> adj[], vector<bool> visited) {
    // 현재 인덱스 해킹 표시
    visited[start] = true;
    int cnt = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // 현재 컴퓨터가 해킹할 수 있는 다음 컴퓨터를 조회하여
        // 해킹하지 않은 컴퓨터일 경우 해킹 표시를 한 후
        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    int n, m;
    cin >> n >> m;

    // 각 인덱스의 해당하는 컴퓨터가 해킹할 수 있는 컴퓨터 번호를 저장할 인접리스트 생성
    vector<int> adj[n+1];
    vector<bool> visited(n+1, false);

    while(m--) {
        int a, b;
        cin >> a >> b;
        // a가 b를 신뢰하므로 b는 a를 해킹할 수 있음
        adj[b].push_back(a);
    }

    vector<int> result;
    int maxCnt = 0;

    // 1 ~ n번까지 조회하며 해킹할 수 있는 모든 컴퓨터 갯수 카운팅
    for (int i = 1; i <= n; i++) {
        int cnt = bfs(i, adj, visited);
        // 만약 최댓값이 바뀌는 경우 result 리셋 후 다시 저장
        if (cnt > maxCnt) {
            maxCnt = cnt;
            result.clear();
            result.push_back(i);
        } else if (cnt == maxCnt) {
            result.push_back(i);
        }
    }

    for (int i : result) {
        cout << i << " ";
    }
}