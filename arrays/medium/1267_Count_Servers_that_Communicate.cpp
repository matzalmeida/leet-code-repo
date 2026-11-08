class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<bool>> counted(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int ant = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    if (ant != -1) {
                        if (!counted[i][j]) {
                            counted[i][j] = true;
                            ans++;
                        }
                        if (!counted[i][ant]) {
                            counted[i][ant] = true;
                            ans++;
                        }
                    }
                    ant = j;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int ant = -1;
            for (int j = 0; j < m; j++) {
                if (grid[j][i]) {
                    if (ant != -1) {
                        if (!counted[j][i]) {
                            counted[j][i] = true;
                            ans++;
                        }
                        if (!counted[ant][i]) {
                            counted[ant][i] = true;
                            ans++;
                        }
                    }
                    ant = j;
                }
            }
        }
        return ans;
    }
};
