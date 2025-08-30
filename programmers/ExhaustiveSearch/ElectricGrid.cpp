// 전력망을 둘로 나누기

#include <string>
#include <vector>
#include <algorithm> // fill 함수 사용
#include <limits>

using namespace std;

bool visited[101] = {false, };


void dfs(int startNode, int endNode, int& count, vector<vector<int>>& wires) {
    for (int i = 0; i < wires.size(); i++) {
        if (!visited[i]) {
            // 다음 탐색 노드가 현재 탐색 노드의 경로상 숫자를 하나라도 가지고 있으면
            // 서로 연결된 것으로 볼 수 있음
            if ((startNode == wires[i][0]) || (startNode == wires[i][1]) ||
                (endNode == wires[i][0]) || (endNode == wires[i][1])) {
                    
                visited[i] = true;
                count++;

                dfs(wires[i][0], wires[i][1], count, wires);
            }
        }
    }
}


int solution(int n, vector<vector<int>> wires) {
    int answer = numeric_limits<int>::max();
    int countFirst = 0;
    int countSecond = 0;

    // 전체 노드 개수가 2개일 경우 경로 하나를 제거하면 방문할 경로가 없음
    // 또한 최솟값은 무조건 0이므로 answer = 0
    if (n == 2) {
        answer = 0;
        return answer;
    }

    // 경로 하나씩 제외해보면서 차이값 최소 구하기
    for (int i = 0; i < wires.size(); i++) {
        // 방문 처리하여 경로 제거
        visited[i] = true;

        if (i == (wires.size() - 1)) {
            dfs(wires[i - 1][0], wires[i -1][1], countFirst, wires);
        }
        else {
            dfs(wires[i + 1][0], wires[i + 1][1], countFirst, wires);
        }

        // 간선의 개수에다가 +1 해주면 노드의 개수
        countFirst++;

        // 전체 노드의 개수 - countFirst 노드 개수
        countSecond = (wires.size() + 1) - countFirst;


        int sub = countFirst - countSecond;
        if (sub < 0) sub = -sub;

        answer = min(answer, sub);

        // 다시 초기화
        countFirst = 0;
        countSecond = 0;
        fill(visited, visited + wires.size(), false);
    }

    return answer;
}
