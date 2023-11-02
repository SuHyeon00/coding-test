#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 소수인지 판별
bool isPrime(int n) {
    // 0과 1은 소수가 아님
    if(n == 0 || n == 1) {
        return false;
    }
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    
    // 입력값 정렬
    sort(nums.begin(), nums.end());
    
    // 연산 - 조합 이용
    vector<int> ind{ 1, 1, 1 };
    for(int i = 0; i < nums.size() - 3; i++) {
        ind.push_back(0);
    }
    
    sort(ind.begin(), ind.end());
    
    do{
        sum = 0;
        // 1의 갯수만큼 nums에서 뽑음 (3개의 숫자 합 구하기)
        for(int i = 0; i < ind.size(); i++) {
            if(ind[i] == 1) {
                sum += nums[i];
            }
        }
        
        if(isPrime(sum)) {
            answer++;
        }
    } while(next_permutation(ind.begin(), ind.end()));
    

    return answer;
}