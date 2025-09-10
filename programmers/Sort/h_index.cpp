// H-Index

#include <string>
#include <vector>
#include <algorithm>
// #include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    for (int h = 1; h <= citations.size(); h++) {
        int left = 0, right = citations.size() - 1;
        // 인용된 횟수가 h번 이상인 논문 중 가장 적게 인용된 논문의 위치
        int fewest_position;
        int count = 0;
    
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (citations[mid] < h) {
                left = mid + 1;
            } 
            else if (citations[mid] >= h) {
                right = mid - 1;
                fewest_position = mid;
            }
        }
        
        // h번 이상 인용된 논문 개수 구하기
        count = citations.size() - fewest_position;
        // cout << "count: " << count << "\n";
        // cout << "h: " << h << "\n";

        // 만약 h번 이상 인용된 논문 개수가 h개 이상이면 조건을 만족하므로 최댓값 비교
        if (count >= h) answer = max(answer, h);
    }

    return answer;
}

// int main() {
//     vector<int> citations;
//     int n;

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int value;
//         cin >> value;
//         citations.push_back(value);
//     }

//     int answer = solution(citations);
//     cout << answer << "\n";

//     return 0;
// }