#include <iostream>
#include <vector>

using namespace std;

// 블루레이의 크기가 target일 때 나오는 블루레이의 갯수
int cntBlueRay(int target, vector<int> &videos) {
    int cnt = 0;
    int total_len = 0;

    for(int video : videos) {
        total_len += video;

        // 현재까지 저장한 동영상의 길이가 target보다 작거나 같으면
        if(total_len <= target) {
            // 같은 블루레이에 동영상 더 넣을 수 있음
            continue;
        } else {
            // 새 블루레이에 저장해야 함
            cnt++;
            total_len = video;
        }
    }

    return cnt;
}

int binarySearch(int left, int right, int target, vector<int> &videos) {
    while(left <= right) {
        // 블루레이의 크기를 최대 최소의 절반으로 설정
        int mid = (left + right) / 2;
        // 해당 크기로 강의 나눴을 때 나오는 블루레이 갯수 연산
        int blueray = cntBlueRay(mid, videos);

        // 목표치보다 더 많이 나온 경우 크기를 늘려야 함
        if(blueray >= target) {
            left = mid + 1;
        } else { // 목표치보다 작게 나온 경우 크기 줄여야 함
            right = mid - 1;
        }
    }

    return left;
}

// 동영상 길이의 최댓값 구하기
int findMax(vector<int> &videos) {
    int max = 0;

    for(int video : videos) {
        if(max < video) {
            max = video;
        }
    }

    return max;
}

// 동영상 길이의 합 구하기
int sumVideos(vector<int> &videos) {
    int sum = 0;

    for(int video : videos) {
        sum += video;
    }

    return sum;
}

int main() {
    // 입력
    int lecture, blueray;
    cin >> lecture >> blueray;

    vector<int> videos(lecture, 0);
    for (int i = 0; i < lecture; i++) {
        cin >> videos[i];
    }

    // 연산
    // 최소 블루레이의 크기 : 가장 긴 강의
    int left = findMax(videos);
    // 최대 블루레이의 크기 : 모든 강의 길이의 합
    int right = sumVideos(videos);

    cout << binarySearch(left, right, blueray, videos);
}