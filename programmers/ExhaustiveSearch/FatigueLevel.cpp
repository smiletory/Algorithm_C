#include <string>
#include <vector>

using namespace std;

bool visited[9] = {false, };

void bt(int k, vector<vector<int>>& dungeons, int count, int limit, 
    int result, int& maxOutput) {

    // 모든 던전을 다 돌았을 때
    if (count == limit) {
        maxOutput = max(maxOutput, result);

        return;
    }

    for (int i = 0; i < dungeons.size(); i++) {
        // 방문하지 않은 던전이고, 현재 피로도가 최소 피로도 이상이여야 탐험 진행
        if ((!visited[i]) && (k >= dungeons[i][0])){
            visited[i] = true;
            result++;

            bt((k - dungeons[i][1]), dungeons, (count + 1), limit, result, maxOutput);
            visited[i] = false;
            result--;
        }
    }

    maxOutput = max(maxOutput, result);
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    bt(k, dungeons, 0, dungeons.size(), 0, answer);

    return answer;
}
