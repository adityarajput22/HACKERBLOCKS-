// test 2 is corrrect only
#include <iostream>
#include <vector>

using namespace std;

int knight_min_unreachable_cells(vector<vector<int>>& chessboard, int n) {
    // Initialize reachability matrix
    vector<vector<bool>> reach(n, vector<bool>(n, false));
    
    // Set initial reachable positions
    reach[0][0] = true;
    
    // Possible moves of a knight
    vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    
    // Calculate reachability using Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (const auto& move : moves) {
                    int new_x = i + move.first;
                    int new_y = j + move.second;
                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                        reach[i][j] = reach[i][j] || (reach[new_x][new_y] && chessboard[i][j] == 1);
                    }
                }
            }
        }
    }
    
    // Count unreachable cells
    int unreachable_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!reach[i][j] && chessboard[i][j] == 1) {
                unreachable_count++;
            }
        }
    }
    
    return unreachable_count;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> chessboard(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> chessboard[i][j];
        }
    }
    
    int result = knight_min_unreachable_cells(chessboard, n);
    cout << result << endl;
    
    return 0;
}