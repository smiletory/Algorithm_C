#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int widthMax = 0;
    int heightMax = 0;

    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            if (sizes[i][0] > widthMax) widthMax = sizes[i][0];
            if (sizes[i][1] > heightMax) heightMax = sizes[i][1];
        }
        else {
            if (sizes[i][1] > widthMax) widthMax = sizes[i][1];
            if (sizes[i][0] > heightMax) heightMax = sizes[i][0];
        }
    }

    answer = widthMax * heightMax;
    
    return answer;
}