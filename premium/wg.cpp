#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = row + dirs[i][0];
                int y = col + dirs[i][1];

                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != INT_MAX) {
                    continue;
                }

                rooms[x][y] = rooms[row][col] + 1;
                q.push({x, y});
            }
        }
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main() {
    Solution a;
    int b = std::numeric_limits<int>::max();
    vector<vector<int>> rooms = {{b, -1, 0, b}, {b, b, b, -1},{b, -1, b, -1}, {0, -1, b, b}};
    a.wallsAndGates(rooms);

    for (auto row : rooms) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
