#include <string> // not use
#include <vector>
#include <algorithm> // to use max_element()
#include <iostream>

using namespace std;


bool isPossible(long long timeLimit, int n, vector<int>& times) {
    long long total = 0;

    vector<int>::iterator it;
    for (it = times.begin(); it < times.end(); ++it) {
        total += timeLimit / *it;
    }

    // if you don't want use iterator
    // for (int t : times) {
    //     total += timeLimit / t;
    // }
    // use like this

    if (total < n) {
        return false;
    }
    else return true;
}


long long solution(int n, vector<int> times) {

    long long answer = 0;
    long long leftValue = 1;
    long long rightValue;
    long long minTime = 0;

    vector<int>::iterator maxTimeIterator = max_element(times.begin(), times.end());
    if (maxTimeIterator != times.end()) {
        // If you don't declare maxTime as long long,
        // maxTime * n will be computed as int * int,
        // which may overflow before being assigned to rightValue.
        long long maxTime = *maxTimeIterator;
        rightValue = maxTime * n;
    }
    else {
        cout << "times vector is empty\n";
        return -1;
    }

    while (true) {
        if (leftValue > rightValue) break;

        long long mid = (leftValue + rightValue) / 2;
        if (isPossible(mid, n, times)) {
            minTime = mid;
            rightValue = mid - 1;
        }
        else {
            leftValue = mid + 1;
        }
    }

    answer = minTime;
    return answer;
}


// For test

// int main() {

//     long long answer = solution(1000000000, {1, 2, 3});
//     cout << answer << endl;

//     return 0;
// }