class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res(grid);
        for (int i = 0; i < grid.size(); ++i) {
          for (int j = 0; j < grid[i].size(); ++j) {
            int next_y = (j + k) % grid[i].size();
            int next_x = (i + ((j + k) / grid[i].size())) % grid.size();
            res[next_x][next_y] = grid[i][j];
          }
        }
        return res;
    }
};
