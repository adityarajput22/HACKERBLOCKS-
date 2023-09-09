#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, int n) {
    if (!is_valid(x, y, n) || visited[x][y] || matrix[x][y] == 0) {
        return 0;
    }
    
    visited[x][y] = true;
    int count = 1;
    
    // Define all possible neighbors' coordinates
    vector<pair<int, int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    for (const auto& neighbor : neighbors) {
        int new_x = x + neighbor.first;
        int new_y = y + neighbor.second;
        count += dfs(matrix, visited, new_x, new_y, n);
    }
    
    return count;
}

int find_connected_sets(vector<vector<int>>& matrix, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int connected_sets = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                connected_sets++;
                dfs(matrix, visited, i, j, n);
            }
        }
    }
    
    return connected_sets;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        
        vector<vector<int>> matrix(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }
        
        int connected_sets = find_connected_sets(matrix, N);
        cout << connected_sets << endl;
    }
    
    return 0;
}