#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// DFS
class Solution
{
private:
    vector<vector<bool>> visited;
    int count;

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        if ((x < 0) || (x >= grid[0].size()) || (y < 0) || (y >= grid.size()) || visited[y][x] || (grid[y][x] == '0'))
        {
            return;
        }

        visited[y][x] = true;

        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        count = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && (grid[i][j] == '1'))
                {
                    ++count;         // 遇到没访问过的陆地
                    dfs(grid, j, i); // 将与其链接的陆地都标记上true
                }
            }
        }

        return count;
    }
};
