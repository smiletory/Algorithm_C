#include <iostream>
#include <vector>
using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++) {
        
    }
}

int main() {
    
    return 0;
}