#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 서류 순위와 면접 순위를 쌍으로 저장할 pair<int, int> 를 p라는 이름으로 정의
typedef pair<int, int> p;

int maxEmploy(vector<p> score) {
    // 서류 심사(first) 1위는 자동 합격
    int result = 1, highest_score = score[0].second;

    for (int i = 1; i < score.size(); i++) {
        // 이전 참가자의 순위보다 현재 순위가 더 높을 (숫자로는 낮을) 경우 합격자 추가
        if(highest_score > score[i].second) {
            highest_score = score[i].second; // 면접 순위 갱신
            result++;
        }
    }

    return result;
}

int main() {

    // 입력
    int t, n, result;
    cin >> t;

    // 테스트 케이스 갯수만큼 결과 계산
    while (t--) {
        cin >> n;

        // 면접자들의 순위를 저장할 벡터 정의
        vector<p> score(n, p(0, 0)); // n개의 데이터를 (0,0)으로 초기화

        for (int i = 0; i < n; i++) {
            cin >> score[i].first >> score[i].second; // 입력값 벡터에 저장
        }

        // 서류 심사(first) 순서대로 정렬 -> 면접 순위만 비교하면 됨
        sort(score.begin(), score.end());

        // 맵을 탐색하며 면접 순위 비교
        result = maxEmploy(score);

        cout << result << '\n';
    } 
}