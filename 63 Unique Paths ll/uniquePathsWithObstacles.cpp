#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int dp[100];
        int t = 1;
        for (int i = 0; i < obstacleGrid[0].size(); i++)
        {
            if (obstacleGrid[0][i] == 1)
            {
                t = 0;
            }
            dp[i] = t;
        }

        if (obstacleGrid.size() == 1)
        {
            return dp[obstacleGrid[0].size() - 1];
        }

        t = (dp[0] == 1);
        
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                t = 0;
            }
            dp[0] = t;

            for (int j = 1; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                }
                else
                {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        return dp[obstacleGrid[0].size() - 1];
    }
};