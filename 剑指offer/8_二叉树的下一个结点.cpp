#include <iostream>
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};
class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == nullptr)
        {
            return nullptr;
        }
        //当前节点右子树不为空找右子树的最左节点
        if (pNode->right != nullptr)
        {
            pNode = pNode->right;
            while (pNode->left)
            {
                pNode = pNode->left;
            }
        }
        else
        {
            TreeLinkNode *parent = pNode->next;
            while (parent != nullptr && pNode == parent->right)
            {
                pNode = parent;
                parent = parent->next;
            }
            pNode = parent;
        }
        return pNode;
    }
};