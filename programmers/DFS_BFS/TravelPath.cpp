#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[10001] = {0,};

bool dfs(string start, vector<vector<string>>& tickets, vector<string>& answer, int count) {

    answer.push_back(start);

    if (count == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i] == 1) continue;

        string departure = tickets[i][0];
        string destination = tickets[i][1];

        if (start == departure) {
            visited[i] = 1;
            if (dfs(destination, tickets, answer, count + 1)) {
                return true;
            }
            visited[i] = 0;
        }
    }

    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, 0);

    return answer;
}