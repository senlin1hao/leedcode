#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// BFS
class Solution
{
private:
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    queue<pair<int, int>> que;
    int count;

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        visited[y][x] = true;
        que.push({x, y});

        while (!que.empty())
        {
            pair<int, int> point = que.front();
            que.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextX = point.first + direction[i][0];
                int nextY = point.second + direction[i][1];

                if ((nextX < 0) || (nextX >= grid[0].size()) || (nextY < 0) || (nextY >= grid.size()))
                {
                    continue;
                }

                if (!visited[nextY][nextX] && grid[nextY][nextX] == '1')
                {
                    que.push({nextX, nextY});
                    visited[nextY][nextX] = true;
                }
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        count = 0;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && (grid[i][j] == '1'))
                {
                    ++count;
                    bfs(grid, j, i);
                }
            }
        }

        return count;
    }
};
