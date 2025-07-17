#include <vector>
#include <queue>
using namespace std;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int visited[101][101] = {0,};


void bfs(vector<vector<int>>& maps, int& answer, queue<pair<pair<int, int>, int>>& q) {

    while (!q.empty()) {
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int dist = q.front().second;

        if ((nx == (maps[0].size() - 1)) && (ny == (maps.size() - 1))) {
            answer = dist;
            return;
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int mx = nx + dx[i];
            int my = ny + dy[i];

            if ((mx >= 0) && (mx < maps[0].size()) && (my >= 0) && (my < maps.size())) {
                if ((maps[my][mx] == 1) && (visited[my][mx] == 0)) {
                    q.push({{mx, my}, (dist + 1)});
                    visited[my][mx] = 1;
                }
            }
        }
    }

    answer = -1;
    return;
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0,0}, 1});
    visited[0][0] = 1;

    bfs(maps, answer, q);

    return answer;
}

// Insted of queue pair, you can use structure for queue