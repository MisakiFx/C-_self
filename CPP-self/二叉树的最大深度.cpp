struct TreeNode
{
    int _val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val) : _val(val), right(nullptr), left(nullptr) {}
};
class Solution {
    //递归的方法
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        //计算左子树高度
        int left = maxDepth(root->left);
        //计算右子树高度
        int right = maxDepth(root->right);
        //返回左右子树高度较大值 + 1
        return left > right ? left + 1 : right + 1;
    }
};