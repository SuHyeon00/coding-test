#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    // 입력
    int n, m, input;
    cin >> n;
    vector<int> arr(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 이분탐색을 위한 정렬
    sort(arr.begin(), arr.end());

    cin >> m;
    while(m--) {
        cin >> input;
        // 연산 & 출력
        cout << binary_search(arr.begin(), arr.end(), input) << " ";
    }
}