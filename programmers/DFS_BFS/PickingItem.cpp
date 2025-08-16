#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int arr[101][101] = {0,};
int visited[101][101] = {0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct location{
    int x;
    int y;
    int distance;
};


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    for (int i = 0; i < rectangle.size(); i++) {

        // 사각형 좌표 및 캐릭터 좌표, 아이템 좌표 전부 2배로 만들어야 함
        // 그래야 붙어있지 않지만 거리가 1인 경로를 탐색하지 않음
        for (int j = 0; j < rectangle[i].size(); j++) {
            rectangle[i][j] = rectangle[i][j] * 2;
        }

        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                arr[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < rectangle.size(); i++) {

        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = (y1 + 1); y < y2; y++) {
            for (int x = (x1 + 1); x < x2; x++) {
                arr[y][x] = 0;
            }
        }
    }

    queue<location> q;
    q.push({characterX * 2, characterY * 2, 0});
    visited[characterX * 2][characterY * 2] = 1;

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int curDist = q.front().distance;

        if ((curX == itemX * 2) && (curY == itemY * 2)) {
            answer = curDist / 2;
            break;
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int mx = curX + dx[i];
            int my = curY + dy[i];

            if ((mx >= 1) && (mx <= 100) && (my >= 1) && (my <= 100)) {
                if ((arr[my][mx] == 1) && (!visited[mx][my])){
                    visited[mx][my] = 1;
                    q.push({mx, my, (curDist + 1)});
                }
            }
        }
    }
    
    return answer;
}
