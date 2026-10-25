class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<vector<int>> q;
        int ans = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (grid[x][y] == 0 && visited[x][y] == false) {
                    bool corner = false;
                    q.push({x,y});
                    while(!q.empty()) {
                        vector<int> curr = q.front();
                        if (curr[0] == 0 || curr[0] == N-1 || curr[1] == 0 || curr[1] == M-1) corner = true;
                        q.pop();
                        visited[curr[0]][curr[1]] = true;
                        if (curr[0] - 1 >= 0 && grid[curr[0]-1][curr[1]] == 0 && visited[curr[0]-1][curr[1]] == false) 
                            q.push({curr[0]-1, curr[1]});
                        if (curr[0] + 1 <  N && grid[curr[0]+1][curr[1]] == 0 && visited[curr[0]+1][curr[1]] == false) 
                            q.push({curr[0]+1, curr[1]});
                        if (curr[1] - 1 >= 0 && grid[curr[0]][curr[1]-1] == 0 && visited[curr[0]][curr[1]-1] == false) 
                            q.push({curr[0], curr[1]-1});
                        if (curr[1] + 1 <  M && grid[curr[0]][curr[1]+1] == 0 && visited[curr[0]][curr[1]+1] == false) 
                            q.push({curr[0], curr[1]+1});
                    }
                    if (!corner) ans++;
                }
            }
            
        }
        return ans;
    }
};
