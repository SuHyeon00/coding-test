#include <iostream>

using namespace std;

// 체중 변화 계산 함수
int calWeightChange(int i, int b, int a) {
    // 체중 += 일일 에너지 섭취량 - (일일 기초 대사량 + 일일 활동 대사량)
    return i - (b + a);
}

int main() {
    int w_0, i_0, t, a_0 = 0; // 다이어트 전 체중, 에너지 섭취량, 역치, 활동 대사량
    int d, i, a; // 다이어트 기간, 에너지 섭취량, 활동 대사량

    // 입력
    cin >> w_0 >> i_0 >> t;
    cin >> d >> i >> a;

    int w_bo = w_0; // 기초 대사량 고려한 체중 변화
    int w_bx = w_0; // 기초 대사량 고려하지 않은 체중 변화

    int b = i_0; // 기초 대사량

    // 기초 대사량 변화 고려하지 않았을 때
    for (int j = d; j >= 0; j--) {
        // 다이어트 기간이 끝난 경우 결과 출력
        if(j == 0) {
            cout << w_bx << ' ' << i_0 << '\n';
            break;
        }

        // 체중 변화 계산
        w_bx += calWeightChange(i, b, a);

        // 체중이 0 이하가 된 경우 다이어트 중단
        if(w_bx <= 0) {
            cout << "Danger Diet" << '\n';
            break;
        }
    }

    // 기초 대사량 변화 고려
    int weight_change = 0;

    for (int j = d; j >= 0; j--) {
        // 다이어트 기간이 끝난 경우 결과 출력
        if(j == 0) {
            cout << w_bo << ' ' << b << ' ';

            // 다이어트 전으로 돌아갈 경우
            if(i_0 - b > 0) {
                cout << "YOYO";
            } else {
                cout << "NO";
            }
            break;
        }

        // 체중 변화 계산 (i - (b + a))
        weight_change = calWeightChange(i, b, a);
        w_bo += weight_change;

        // 기초대사량 변화 역치 초과하는 경우
        if(abs(weight_change) > t) {
            // 기초 대사량 변화 계산
            b += (weight_change % 2 == 0) ? // 음수 나눗셈 계산을 위해 삼항 연산자 사용
                weight_change / 2 : // 나누어 떨어질 경우
                weight_change / 2 - 1; // 나누어 떨어지지 않을 경우
        }

        // 다이어트 기간 도중 체중이 0 이하거나 기초대사량이 0 이하인 경우 중단
        if(w_bo <= 0 || b <= 0) {
            cout << "Danger Diet" << '\n';
            break;
        }
    }
}