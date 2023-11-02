#include <iostream>

using namespace std;

// 유클리드 호제법
int getGcd(int a, int b) {
    // b == 0이 되는 순간 a가 최대공약수가 됨
    while(b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // 입력
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    // 분수 덧셈 계산
    int num1, num2;
    num1 = a1 * b2 + a2 * b1;
    num2 = a2 * b2;

    // 기약분수 연산
    int gcd = 1;
    gcd = getGcd(num1, num2);

    cout << num1 / gcd << " " << num2 / gcd;
}
