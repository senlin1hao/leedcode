#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//哈希法+vector+排序
class Solution
{
private:
    //注意这里需要static
    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        return (p1.second > p2.second);
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> numsMap;
        for (int i : nums)
        {
            ++numsMap[i];
        }

        vector<pair<int, int>> v(numsMap.begin(), numsMap.end());
        sort(v.begin(), v.end(), compare);

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(v[i].first);
        }
        
        return result;
    }
};