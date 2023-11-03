#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;

    // (인물, 그리움 점수) 맵 생성
    for(int i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i];
    }


    for(auto people : photo) {
        int score = 0;
        for(auto person : people) {
            // 그리움 목록에 있는 경우
            if(m.find(person) != m.end()) {
                score += m[person];
            }
        }
        answer.push_back(score);
    }
    return answer;
}