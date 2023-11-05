#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, maxSum = 0; // 종이 사이즈 & 최대합 저장 변수
// 상, 하, 좌, 우 순서
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 이동한 위치가 범위 내에 있는지 확인
bool checkAvail(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

// depth가 4가 되면 최댓값 업데이트
void dfs(int r, int c, int depth, int sum,
vector<vector<int>> &paper, vector<vector<bool>> &visited) {
    sum += paper[r][c]; // 종이에 쓰여있는 숫자 더하기
    visited[r][c] = true; // 방문 처리
    
    if(depth == 4) {
        maxSum = max(sum, maxSum);
        visited[r][c] = false;
        return;
    }

    // 상, 하, 좌, 우 탐색
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(checkAvail(nr, nc) && !visited[nr][nc]) {
            dfs(nr, nc, depth + 1, sum, paper, visited);
        }
    }
    visited[r][c] = false; // 방문 처리 초기화
}

/**
 * ㅜ 모양 넣었을 때 합 구하기
 * 기준점을 튀어나온 부분으로 설정
 * 
 * ㅜ 모양 : (0, 0), (-1, -1), (-1, 0), (-1, 1) 이동
 * ㅏ 모양 : (0, 0), (-1, -1), (0, -1), (1, -1) 이동
 * ㅗ 모양 : (0, 0), (1, -1), (1, 0), (1, 1) 이동
 * ㅓ 모양 : (0, 0), (-1, 1), (0, 1), (1, 1) 이동
 * 
 * 해당 칸의 숫자 합하기
*/
void checkPink(int r, int c, vector<vector<int>> &paper,
vector<vector<bool>> &visited) {
    int sum = 0, nr, nc;
    
    // 이동 방향
    int dr[4][3] = {{-1, -1, -1}, {-1, 0, 1}, {1, 1, 1}, {-1, 0, 1}};
    int dc[4][3] = {{-1, 0, 1}, {-1, -1, -1}, {-1, 0, 1}, {1, 1, 1}};
    
    for(int i = 0 ; i < 4; i++) {
        // 현재 칸 숫자로 초기화
        sum = paper[r][c];
        for(int j = 0; j < 3; j++) {
            nr = r + dr[i][j];
            nc = c + dc[i][j];

            if(checkAvail(nr, nc)) {
                sum += paper[nr][nc];
            }
        }

        // 최댓값 업데이트
        maxSum = max(sum, maxSum);
    }
}

/**
 * [테트로미노가 놓인 칸에 쓰여 있는 수들의 최댓값]
 * ㅜ 모양을 제외하고는 dfs로 가능 (depth 4) : 상하좌우 이동해보며 확인 가능
*/
int main() {
    // 입력
    cin >> N >> M;
    int input;

    vector<vector<int>> paper;
    vector<vector<bool>> visited;
    for(int i = 0; i < N; i++) {
        paper.push_back({});
        visited.push_back({});
        for (int j = 0; j < M; j++) {
            cin >> input;
            paper[i].push_back(input);
            visited[i].push_back(false);
        }   
    }

    // 연산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // ㅜ 모양 제외하고 dfs 돌리기
            dfs(i, j, 1, 0, paper, visited);
            // ㅜ 모양 확인
            checkPink(i, j, paper, visited);
        }
    }
    
    // 출력
    cout << maxSum;
}