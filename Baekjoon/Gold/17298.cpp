#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // 입력
    int n;
    cin >> n;

    stack<int> s;
    vector<int> nums(n);
    vector<int> result(n);

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        while(!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        result[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
}