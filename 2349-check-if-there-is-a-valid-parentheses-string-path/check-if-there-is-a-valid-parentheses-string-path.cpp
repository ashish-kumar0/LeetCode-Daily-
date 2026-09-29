#include <vector>

using namespace std;

class Solution {
    int memo[101][101][105];

    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid, int m, int n) {
        bal += (grid[r][c] == '(' ? 1 : -1);

        // Balance cannot drop below zero
        if (bal < 0) return false;

        // Balance cannot exceed remaining possible closing brackets
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (bal > remaining_steps) return false;

        // Reached destination
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }

        bool canReach = false;
        // Move down
        if (r + 1 < m) {
            canReach = canReach || dfs(r + 1, c, bal, grid, m, n);
        }
        // Move right
        if (!canReach && c + 1 < n) {
            canReach = canReach || dfs(r, c + 1, bal, grid, m, n);
        }

        return memo[r][c][bal] = canReach;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Parity check: length of path must be even
        if ((m + n - 1) % 2 != 0) return false;
        // Start must be '(' and end must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid, m, n);
    }
};