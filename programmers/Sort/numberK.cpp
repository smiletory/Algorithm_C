// k번째 수

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> tempArr;
        int start = commands[i][0] - 1;
        int end = commands[i][1] - 1;
        int IndexK = commands[i][2] - 1;

        for (int j = start; j <= end; j++) {
            tempArr.push_back(array[j]);
        }

        sort(tempArr.begin(), tempArr.end());

        int numberK = tempArr[IndexK];
        answer.push_back(numberK);
    }

    return answer;
}
