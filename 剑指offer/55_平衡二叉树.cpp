#include <iostream>
#include <cmath>
#include <algorithm>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int height = 0;
        return IsBalance(pRoot, height);
    }
    bool IsBalance(TreeNode* pRoot, int& height)
    {
        if(pRoot == nullptr)
        {
            height = 0;
            return true;
        }
        int left = 0, right = 0;
        bool isBalance = IsBalance(pRoot->left, left) && IsBalance(pRoot->right, right);
        int dec = abs(left - right);
        if(isBalance == false || dec > 1) 
        {
            return false;
        }
        else 
        {
            height = max(left, right) + 1;
            return true;
        }
    }
};