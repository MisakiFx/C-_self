#include <iostream>
#include <cmath>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
class Solution
{
public:
    bool Equal(double num1, double num2)
    {
        if (abs(num1 - num2) < 0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool DoesHasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == nullptr)
        {
            return true;
        }
        if (pRoot1 == nullptr)
        {
            return false;
        }
        if (!Equal(pRoot1->val, pRoot2->val))
        {
            return false;
        }
        return DoesHasSubtree(pRoot1->left, pRoot2->left) && DoesHasSubtree(pRoot1->right, pRoot2->right);
    }
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
        {
            return false;
        }
        bool result = false;
        if (Equal(pRoot1->val, pRoot2->val))
        {
            result = DoesHasSubtree(pRoot1, pRoot2);
        }
        if (!result)
        {
            result = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!result)
        {
            result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
};