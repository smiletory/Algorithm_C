#include <string>
#include <vector>
#include <cmath>
// #include <iostream>

using namespace std;

vector<int> result;
bool visited[9] = {false, };


bool isPrime(int num) {
    if ((num == 2) || (num == 3)) return true;

    int sqrtNum = static_cast<int>(sqrt(num));

    for (int i = 2; i <= sqrtNum; i++) {
        if ((num % i) == 0) return false;
    }

    return true;
}


bool isOnly(int num) {
    for (int i = 0; i < result.size(); i++) {
        if (num == result[i]) return false;
    }

    return true;
}


void bt(string numbers, int limit, int count, string curNum) {
    if (count == limit) {

        // 앞자리가 0이거나 값이 1이면 정답에서 제외
        if ((curNum[0] == '0') || (curNum == "1")){
            return;
        }

        // int형 변환
        int num = stoi(curNum);

        // 소수이면서 정답 배열에 없는 수이면 정답 배열에 추가
        if (isPrime(num) && isOnly(num)) {
            result.push_back(num);
            // cout << "num :" << num << endl;
        }
        return;
    }

    for (int i = 0 ; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            bt(numbers, limit, (count + 1), (curNum + numbers[i]));
            visited[i] = false;
        }
    }
}


int solution(string numbers) {
    int answer = 0;

    // 1자리부터 n자리까지 백트래킹 진행
    for (int i = 1; i <= numbers.size(); i++) {
        bt(numbers, i, 0, "");
    }

    answer = result.size();
    
    return answer;
}
