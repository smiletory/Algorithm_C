// 징검다리

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0, right = distance;
    sort(rocks.begin(), rocks.end());

    while (left <= right) {
        // 바위 간 거리 최솟값을 mid로 설정
        int mid = (left + right) / 2;
        // count는 제거한 바위의 개수
        int prev = 0, count = 0;

        for (int i = 0; i < rocks.size(); i++) {
            // 바위 간의 거리가 설정한 mid(최솟값)보다 작으면 해당 바위 제거
            if ((rocks[i] - prev) < mid) {
                count++;
            }
            // 크면 해당 바위는 mid(최솟값) 기준을 만족하므로 해당 바위 기준으로 다음 바위 탐색
            else {
                prev = rocks[i];
            }
        }

        // 마지막 바위와 도착점까지의 거리는 위의 for문 범위로 검증이 안되므로 밑에 추가
        if ((distance - prev) < mid) {
            count++;
        }

        // 만약 제거한 바위의 개수가 문제 조건 안에 들어오면 바위를 더 제거해서 mid(최솟값)을 올릴수도 있으므로 
        // left 증가시켜서 mid 값 증가시키기
        // 최대 mid(최소값)는 무조건 count == n일 때 나옴. -> mid(최솟값) 기준을 올릴수록 더 많은 바위가 제거되기 때문
        if (count <= n) {
            answer = max(answer, mid);
            left = mid + 1;
        }
        // 제거한 바위 개수가 문제 조건보다 많으면 mid(최솟값) 기준을 낮춰서 제거할 바위 개수 낮추기
        else {
            right = mid - 1;
        }
    }

    return answer;
}