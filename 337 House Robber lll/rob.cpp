#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<int> robTree(TreeNode *parent)
    {
        if (parent == nullptr)
        {
            return {0, 0};
        }

        vector<int> left = robTree(parent->left);
        vector<int> right = robTree(parent->right);

        //抢劫parent节点
        int result1 = parent->val + left[1] + right[1];

        //不抢劫parent节点
        int result2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {result1, result2};
    }

public:
    int rob(TreeNode *root)
    {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
};