#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;
    vector<ll> velocity(n);

    int v;
    for (int i = 0; i < n; i++) {
        cin >> velocity[i];
    }

    // 뒤에서부터 속도를 비교 
    ll speed = velocity[--n];

    while(n--) {
        // 앞의 속도가 더 큰 경우 해당 속도를 speed로 업데이트
        if(velocity[n] >= speed) {
            speed = velocity[n];
        } else if(speed % velocity[n] != 0) { // 앞의 속도가 더 작으면서 이미 speed가 앞의 속도의 양의 배수라면 스킵
            // speed가 앞의 속도의 양의 배수가 아닌 경우 양의 배수가 되도록 업데이트 필요
            // 이때 양의 배수는 현재 speed를 초과해야(몫이 0이 아님) 하므로 작은 속도의 몫 + 1이 됨
            speed = (speed / velocity[n] + 1) * velocity[n];
        }
    }

    cout << speed;
    
}