#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// DFS
class Solution
{
private:
    vector<vector<int>> paths;
    vector<int> currentPath;

    void dfs(vector<vector<int>>& graph, int point)
    {
        if (point == graph.size() - 1)
        {
            paths.emplace_back(currentPath);
            return;
        }

        for (int i = 0; i < graph[point].size(); i++)
        {
            currentPath.emplace_back(graph[point][i]);
            dfs(graph, graph[point][i]);
            currentPath.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        currentPath.emplace_back(0);
        dfs(graph, 0);

        return paths;
    }
};
