#include <string>
#include <vector>

using namespace std;


void dfs(int index, int sum, int target, int* answer, vector<int>* numbers) {
    if (index == ((*numbers).size() - 1)) {
        if (sum == target) {
            (*answer)++;
            return;
        }
        return;
    }

    dfs(index + 1, sum - (*numbers)[index + 1], target, answer, numbers);
    dfs(index + 1, sum + (*numbers)[index + 1], target, answer, numbers);
}

int solution(vector<int> numbers, int target) {

    int answer = 0;

    dfs(-1, 0, target, &answer, &numbers);
    return answer;
}