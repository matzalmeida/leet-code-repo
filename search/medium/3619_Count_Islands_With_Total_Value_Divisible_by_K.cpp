class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int ans = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (grid[x][y] > 0 && !visited[x][y]) {
                    queue<vector<int>> q;
                    q.push({x,y});
                    long sum = 0;
                    while(!q.empty()) {
                        int _x = q.front()[0], _y = q.front()[1];
                        q.pop();
                        if (!visited[_x][_y] && grid[_x][_y] > 0) {
                            sum += grid[_x][_y];
                            visited[_x][_y] = true;
                            if (_x - 1 >= 0) q.push({_x-1,_y});
                            if (_x + 1 <  N) q.push({_x+1,_y});
                            if (_y - 1 >= 0) q.push({_x,_y-1});
                            if (_y + 1 <  M) q.push({_x,_y+1});
                        }
                    }
                    if (sum % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};
