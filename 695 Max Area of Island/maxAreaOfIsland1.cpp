#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// DFS
class Solution
{
private:
    int tempArea;
    int maxArea;
    vector<vector<bool>> visited;
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if ((x < 0) || (x >= grid[0].size()) || (y < 0) || (y >= grid.size()) || visited[y][x] || (grid[y][x] == 0))
        {
            return;
        }

        visited[y][x] = true;
        ++tempArea;

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];

            dfs(grid, nextX, nextY);
        }

        return;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        tempArea = 0;
        maxArea = 0;
        visited = vector(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && (grid[i][j] == 1))
                {
                    tempArea = 0;
                    dfs(grid, j, i);
                    maxArea = max(maxArea, tempArea);
                }
            }
        }

        return maxArea;
    }
};
