// 모음사전

#include <string>
#include <vector>

using namespace std;

bool visited[6] = {false, };
string fullLetters = "AEIOU";
int answer = 0;
int count = 0;

// 기존의 백트래킹과는 다르게 이 문제는 count가 백트래킹 시에도
// 계속 증가되어야 하므로 count를 함수의 매개변수가 아닌
// 전역변수로 선언하여 계속 증가시켜줘야 한다.
// 또한 이렇게 되면 함수의 종료 조건에서 5라는 수를 count를 통해 확인할 수 없으므로
// 현재 단어의 길이를 통해 확인해야 한다.
void dfs(string target, string curWord) {
    if (curWord == target) {
        answer = count;
        return;
    }

    if (curWord.length() >= 5) return;

    for (int i = 0; i < fullLetters.size(); i++) {
        count++;
        dfs(target, curWord + fullLetters[i]);
    }
}

int solution(string word) {
    
    dfs(word, "");

    return answer;
}