class Solution {
public:
    int m, n;
    vector<vector<vector<char>>> dp;
    vector<vector<char>> graph;

    bool dfs(int x, int y, int cnt) {
        if (dp[x][y][cnt] != '?') {
            return dp[x][y][cnt] == 'S';
        }

        // Destination: current cell has not been processed yet.
        if (x == m - 1 && y == n - 1) {
            bool valid = graph[x][y] == ')' && cnt == 1;
            dp[x][y][cnt] = valid ? 'S' : 'N';
            return valid;
        }

        if (graph[x][y] == '(') {
            if (x + 1 < m && dfs(x + 1, y, cnt + 1)) {
                dp[x][y][cnt] = 'S';
                return true;
            }

            if (y + 1 < n && dfs(x, y + 1, cnt + 1)) {
                dp[x][y][cnt] = 'S';
                return true;
            }
        } else {
            if (cnt == 0) {
                dp[x][y][cnt] = 'N';
                return false;
            }

            if (x + 1 < m && dfs(x + 1, y, cnt - 1)) {
                dp[x][y][cnt] = 'S';
                return true;
            }

            if (y + 1 < n && dfs(x, y + 1, cnt - 1)) {
                dp[x][y][cnt] = 'S';
                return true;
            }
        }

        dp[x][y][cnt] = 'N';
        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] != '(')
            return false;

        graph = grid;

        dp = vector<vector<vector<char>>>(m, vector<vector<char>>(n, vector<char>(m * n, '?')));

        return dfs(0, 0, 0);
    }
};
