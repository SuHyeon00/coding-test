#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> bfs(vector<int>& ground, int b) {
    int min_time = INT_MAX;
    int goal_h = 0;

    // 최종 땅의 높이가 될 수 있는 범위는 맵의 키 값의 최대 최솟값이 됨
    for (int h = ground[0]; h <= ground[ground.size() - 1]; h++) {
        int time = 0; // 현재 높이에서 필요한 시간
        int blocks = b; // 인벤토리의 블록 수

        for (int i = 0; i < ground.size(); i++) {
            int diff = ground[i] - h;

            // 현재 땅의 높이가 목표 높이보다 높은 경우
            if (diff > 0) {
                // 블록을 깎아서 인벤토리에 넣어야 함 (2초)
                time += 2 * diff;
                blocks += diff;
            } else { // 현재 땅의 높이가 목표 높이보다 작은 경우 (1초)
                time -= diff; // diff가 음수이기 때문에 부호 반대로
                blocks += diff;
            }
        }

        // 최종 시간을 구했을 때 인벤토리가 음수가 아니면서 전에 구한 시간보다 작은 경우
        // 해당 정보로 업데이트
        if(blocks >= 0 && time <= min_time) {
            min_time = time;
            goal_h = h;
        }
        
    }

    return make_pair(min_time, goal_h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int n, m, b, height;
    cin >> n >> m >> b;

    // 땅의 높이를 저장할 벡터 선언
    vector<int> ground(n * m);

    for (int i = 0; i < n * m; i++) {
        cin >> ground[i];
    }

    sort(ground.begin(), ground.end()); // 땅의 높이 정렬

    pair<int, int> pp = bfs(ground, b);
    cout << pp.first << " " << pp.second;
}