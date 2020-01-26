#include <iostream>
using namespace std;

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
        {
            return nullptr;
        }
        TreeNode* lastNode = nullptr;
        ConvertCore(pRootOfTree, &lastNode);
        TreeNode* head = lastNode;
        while(head != nullptr && head->left != nullptr)
        {
            head = head->left; 
        }
        return head;
    }
    void ConvertCore(TreeNode* pRootOfTree, TreeNode** lastNode)
    {
        if(pRootOfTree == nullptr)
        {
            return;
        }
        if(pRootOfTree->left != nullptr)
        {
            ConvertCore(pRootOfTree->left, lastNode);
        }
        pRootOfTree->left = *lastNode;
        if(*lastNode != nullptr)
        {
            (*lastNode)->right = pRootOfTree;
        }
        *lastNode = pRootOfTree;
        if(pRootOfTree->right != nullptr)
        {
            ConvertCore(pRootOfTree->right, lastNode);
        }
    }
};