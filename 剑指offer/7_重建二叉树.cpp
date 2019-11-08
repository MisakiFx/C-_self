#include <iostream>
#include <vector>
using namespace std;
//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0 || vin.size() == 0)
        {
            return nullptr;
        }
        return reConstructBinaryTreeCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    //左闭又闭区间
    TreeNode *reConstructBinaryTreeCore(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd)
    {
        int rootValue = pre[preStart];
        TreeNode *root = new TreeNode(rootValue);
        //说明此时前序遍历序列中只有一个元素
        if (preStart == preEnd)
        {
            //说明此时中序遍历序列中也只有一个元素
            if (vinStart == vinEnd && pre[preStart] == vin[vinStart])
            {
                return root;
            }
        }
        int pos = vinStart;
        while (vin[pos] != rootValue && pos <= vinEnd)
        {
            pos++;
        }
        int leftLength = pos - vinStart;
        int leftPreEnd = preStart + leftLength;
        //构建左子树
        if (leftLength > 0)
        {
            root->left = reConstructBinaryTreeCore(pre, preStart + 1, leftPreEnd, vin, vinStart, pos - 1);
        }
        if (leftLength < (preEnd - preStart))
        {
            root->right = reConstructBinaryTreeCore(pre, leftPreEnd + 1, preEnd, vin, pos + 1, vinEnd);
        }
        return root;
    }
};