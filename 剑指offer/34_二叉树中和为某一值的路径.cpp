#include <iostream>
#include <vector>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if(root == nullptr)
        {
            return res;
        }
        vector<int> curPath;
        int curNumber = 0;
        FindPathCore(root, expectNumber, curNumber, curPath, res);
        return res;
    }
    void FindPathCore(TreeNode* root, int expectNumber, int curNumber, vector<int>& curPath, vector<vector<int>>& res)
    {
        curNumber += root->val;
        curPath.push_back(root->val);
        bool isLeaf = (root->left == nullptr && root->right == nullptr);
        //当前结点是叶节点，并且满足要求
        if(curNumber == expectNumber && isLeaf)
        {
            if(res.size() <= 0)
            {
                res.push_back(curPath);
            }
            else 
            {
                vector<vector<int>>::iterator it = res.begin();
                while(it != res.end())
                {
                    if(curPath.size() >= it->size())
                    {
                        it = res.insert(it, curPath);
                        break;
                    }
                    it++;
                }
                if(it == res.end())
                {
                    res.insert(it, curPath);
                }
            }
        }
        if(root->left != nullptr)
        {
            FindPathCore(root->left, expectNumber, curNumber, curPath, res);
        }
        if(root->right != nullptr)
        {
            FindPathCore(root->right, expectNumber, curNumber, curPath, res);
        }
        curNumber -= root->val;
        curPath.pop_back();
    }
};