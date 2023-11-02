#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumDigit(string a) {
    int a_sum = 0; // 문자열 a의 자리수 합

    for (int i = 0; i < a.length(); i++) {
        // 자리수가 숫자인 경우 합하기
        if(isdigit(a[i])) {
            a_sum += a[i] - '0';
        }
    }

    return a_sum;
}

bool cmp(string a, string b) {
    // 1번 조건 길이가 짧은 것이 앞으로
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    // 2번 조건 자리수 합이 작은 것이 앞으로
    int a_sum, b_sum;
    
    // 각각 a와 b의 자리수 합
    a_sum = sumDigit(a);
    b_sum = sumDigit(b);

    // 합이 작은 것이 앞으로
    if(a_sum != b_sum) {
        return a_sum < b_sum;
    }

    // 1, 2번 조건으로 비교가 안 된 경우 오름차순 정렬 (3번 조건)
    return a < b;
}

int main() {
    // 입력
    int n; // 기타의 개수
    cin >> n;
    vector<string> arr(n); // 시리얼 번호 저장 변수
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 정렬 함수 호출
    sort(arr.begin(), arr.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}