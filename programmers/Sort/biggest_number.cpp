// 가장 큰수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 두 수를 문자열 형태로 합쳐보고 크기 비교
bool compare(string a, string b) {
    return ((a + b) > (b + a));
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numbers_string;

    // 1. numbers 배열 요소를 전부 string으로 변환 후 정렬을 수행하는 것
    // 2. int형 배열 요소를 그대로 사용하여 compare() 호출 시 string으로 변환하는 것
    // 둘 중 첫번째가 더 효율적 -> 두번째 요소는 비교할 때마다 매번 to_string() 함수가
    // 호출되어서 상대적으로 비효율적
    for (int i = 0; i < numbers.size(); i++) {
        numbers_string.push_back(to_string(numbers[i]));
    }

    sort(numbers_string.begin(), numbers_string.end(), compare);

    for (int i = 0; i < numbers_string.size(); i++) {
        answer += numbers_string[i];
    }

    // 입력값이 전부 0인 경우 결과가 "000" 과 같이 나옴
    // 이때는 그냥 "0"으로 간주할 것
    if (answer[0] == '0') {
        answer = "0";
    }

    return answer;
}
