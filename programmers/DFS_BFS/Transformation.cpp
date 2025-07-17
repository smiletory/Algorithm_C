#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[51] = {0,};

void bfs(string begin, string target, vector<string>& words, 
        queue<pair<string, int>>& q, int& answer) {
    while (!q.empty()) {
        string cur = q.front().first;
        int dist = q.front().second;

        if (cur.compare(target) == 0) {
            answer = dist;
            return;
        }

        q.pop();

        for (int i = 0; i < words.size(); i++) {
            if (visited[i] == 0) {
                int count = 0;

                for (int j = 0; j < words[i].length(); j++) {
                    if (count >= 2) {
                        count = -1;
                        break;
                    }

                    if (cur[j] != words[i][j]) {
                        count++;
                    }
                }

                if ((count == 0) || (count == 1)) {
                    q.push({words[i], (dist + 1)});
                    visited[i] = 1;
                }
            }
        }
    }

    answer = 0;
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;

    q.push({begin, 0});
    bfs(begin, target, words, q, answer);

    return answer;
}