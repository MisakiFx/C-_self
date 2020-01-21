#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        std::vector<int> res;
        if(root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            res.push_back(node->val);
            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        return res;
    }
};