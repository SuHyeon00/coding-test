#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 에라토스테네스의 체
void isPrime(int n, vector<bool> &is_prime) {
    // 0과 1은 소수가 아님
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(n); i++) {
        if(is_prime[i]) { //i가 소수인 경우
            for (int j = i * i; j <= n; j += i) {
                // i의 배수들은 소수가 아님
                is_prime[j] = false;
            } 
        }
    }
}

int checkResult(int n, vector<bool> &is_prime) {
    
    // n에서 해당 소수를 뺀 값이 또 소수일 경우 a와 b 값 업데이트
    for (int i = 2; i <= n / 2; i++) {
        if(is_prime[i] && is_prime[n - i]) { // i가 소수인 경우 b의 후보가 됨
            return i;
        }
    }
    return -1;
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1000000;

    //에라토스테네스의 체
    vector<bool> is_prime(n + 1, true);
    isPrime(n, is_prime);

    while(1) {
        cin >> n;
        int result = 0; // 찾았는지 안 찾았는지 체크

        if(n == 0) {
            break;
        }

        // 가설 검증
        result = checkResult(n, is_prime);


        if(result != -1) {
            cout << n << " = " << result << " + " << n - result << "\n";
        } else {
            cout << "Goldbach's conjecture is wrong.";
        }
    }
}