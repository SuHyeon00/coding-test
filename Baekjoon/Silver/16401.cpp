#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과자의 길이가 len일 때 나눠줄 수 있는 조카의 수
int cntNephew(int len, vector<int> &snacks) {
    int cnt = 0;

    // 각 과자의 길이를 len으로 나눈 몫 만큼 나눠주기 가능
    for(int snack : snacks) {
        cnt += snack / len;
    }

    return cnt;
}

// 나눠줄 수 있는 과자의 길이 중 최댓값 구하기
int binarySearch(int left, int right, int target, vector<int> &snacks) {
    while(left <= right) {
        // 과자의 길이가 mid일 때, 나눠줄 수 있는 조카의 수
        int mid = (left + right) / 2;
        int nephew = cntNephew(mid, snacks);
        // mid의 길이로 target 개수 이상의 조카에게 나눠주기 가능
        // 과자의 길이 늘려보기
        if(nephew >= target) {
            left = mid + 1;
        } else { // mid의 길이로는 모든 조카에게 나눠주기 불가 -> 길이 줄여보기
            right = mid - 1;
        }
    }

    return left - 1;
}

int main() {
    // 입력
    int nephew, snack;
    cin >> nephew >> snack;

    vector<int> snacks(snack, 0);
    for(int i = 0; i < snack; i++) {
        cin >> snacks[i];
    }

    // 연산
    sort(snacks.begin(), snacks.end());

    // 연산 & 출력
    // 최소 과자 길이 : 1
    // 최대 과자 길이 : 가장 큰 과자의 길이
    cout << binarySearch(1, snacks[snack - 1], nephew, snacks);
}