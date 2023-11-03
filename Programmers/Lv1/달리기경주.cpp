#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> rankings;
    int rank = 0;
    string prev = "";

    // players를 등수 맵으로 저장하기 => 호출한 플레이어의 등수 바로 찾기 위함
    for(int i = 0; i < players.size(); i++) {
        rankings[players[i]] = i;
    }

    // 호출한 선수 등수 업데이트
    for(string call : callings) {
        rank = rankings[call];

        // 앞 선수와 현재 선수 등수 바꾸기
        prev = players[rank - 1];
        players[rank - 1] = players[rank];
        players[rank] = prev;

        // 랭킹 맵 업데이트
        rankings[call] = rank - 1;
        rankings[prev] = rank;
    }

    return players;
}