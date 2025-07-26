#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= int(sqrt(yellow)); i++) {
        int remains = yellow % i;

        if (remains == 0) {
            int yellowWidth = yellow / i;
            int yellowLength = i;

            int brownSum = (yellowWidth * 2) + (yellowLength * 2) + 4;

            if (brownSum == brown) {
                int totalWidth = yellowWidth + 2;
                int totalLength = yellowLength + 2;

                answer.push_back(totalWidth);
                answer.push_back(totalLength);
            }
        }
    }

    return answer;
}