// https://leetcode.com/problems/island-perimeter/
class Solution {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int check[101][101];
    queue<pair<int, int> > q;
    int n,m,cnt=0;
public:
    void islandSearch(vector<vector<int>>& grid) {
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;
            //sea check
            int land = 0;
            for(int j = 0; j < 4; j++) {
                int xx = x + dx[j];
                int yy = y + dy[j];
                if(xx >= n || yy >= m || xx < 0 || yy < 0) continue;
                if(grid[xx][yy] == 1) {
                    land++;
                }
            }
            cnt += (4-land);
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;
                if(grid[nx][ny] == 0 || check[nx][ny]) continue;
                check[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        if(n==1) {
            if(grid[0].size()==1) {
                return 4;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                m = grid[i].size();
                if(check[i][j] == 0 && grid[i][j] == 1) {
                    check[i][j] = 1;
                    q.push({i,j});
                    islandSearch(grid);
                }                
            }
        }
        return cnt;
    }
};