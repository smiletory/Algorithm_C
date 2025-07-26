#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int student1[5] = {1, 2, 3, 4, 5};
int student2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};


vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int result1 = 0, result2 = 0, result3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        int student1Index = i % 5;
        int student2Index = i % 8;
        int student3Index = i % 10;

        if (answers[i] == student1[student1Index]) result1++;
        if (answers[i] == student2[student2Index]) result2++;
        if (answers[i] == student3[student3Index]) result3++;
    }

    int maxResult = max({result1, result2, result3});

    if (maxResult == result1) answer.push_back(1);
    if (maxResult == result2) answer.push_back(2);
    if (maxResult == result3) answer.push_back(3);
    
    return answer;
}