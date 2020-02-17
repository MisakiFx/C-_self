#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)
        {
            return nullptr;
        }
        return KthNodeCore(pRoot, k);
    }
    TreeNode* KthNodeCore(TreeNode* pRoot, int& k)
    {
        if(pRoot == nullptr || k <= 0)
        {
            return nullptr;
        }
        TreeNode* res = KthNodeCore(pRoot->left, k);
        if(res == nullptr && k == 1)
        {
            res = pRoot;
        }
        k--;
        if(res == nullptr)
        {
            res = KthNodeCore(pRoot->right, k);
        }
        return res;
    }
};