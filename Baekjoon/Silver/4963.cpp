#include <iostream>

using namespace std;

const int MAX = 50;

int w, h;
int map[MAX][MAX];
bool visited[MAX][MAX];

// 이동 방향 (반시계 방향 순)
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};


// 지도를 벗어나는 범위인지 아닌지 체크하는 함수
bool checkAvail(int x, int y) {
    if(x >= 0 && x < h && y >= 0 && y < w) {
        return true;
    }

    return false;
}


void dfs(int x, int y) {
    // 현재 땅 방문 표시
    visited[x][y] = true;

    // 8가지 방향으로 이동해보며 땅인지 바다인지 확인
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(checkAvail(nx, ny) && !visited[nx][ny] && map[nx][ny] == 1) {
            // 해당 위치에 대해 dfs 다시 수행
            dfs(nx, ny);
        }
    }
}

int main() {
    while (true){
        // 입력
        cin >> w >> h;

        // 0 0이 들어오면 종료
        if(w == 0 && h == 0) {
            break;
        }

        // 지도 & 방문 여부 입력
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++){
                cin >> map[i][j];
                visited[i][j] = false; // 방문 여부 초기화 시키기

            }
        }

        // 섬 개수 세기
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // 해당 지형이 땅이면서 아직 방문하지 않은 땅인 경우 카운트 증가
                if(map[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
        
    }
}