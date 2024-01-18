#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// BFS
class Solution
{
private:
    int tempArea;
    int maxArea;
    const int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> que;
    vector<vector<bool>> visited;

    void bfs(vector<vector<int>>& grid, int x, int y)
    {
        que.push({x, y});
        visited[y][x] = true;
        ++tempArea;

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

                if (!visited[nextY][nextX] && (grid[nextY][nextX] == 1))
                {
                    visited[nextY][nextX] = true;
                    ++tempArea;
                    que.push({nextX, nextY});
                }
            }
        }

        return;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        maxArea = 0;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        que = queue<pair<int, int>>();

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && (grid[i][j] == 1))
                {
                    tempArea = 0;
                    bfs(grid, j, i);
                    maxArea = max(maxArea, tempArea);
                }
            }
        }

        return maxArea;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    Solution solution;

    int maxArea = solution.maxAreaOfIsland(grid);
    cout << maxArea << endl;

    return 0;
}
