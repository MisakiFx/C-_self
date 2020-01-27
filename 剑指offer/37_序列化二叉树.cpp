#include <iostream>
#include <sstream>
#include <string>
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
    char* Serialize(TreeNode *root) 
    {   
        stringstream res;
        SerializeCore(root, res);
        string resString = res.str();
        char* resChar = new char[resString.size() + 1];
        for(int i = 0; i < resString.size(); i++)
        {
            resChar[i] = resString[i];
        }
        resChar[resString.size()] = '\0';
        return resChar;
    }
    void SerializeCore(TreeNode *root, stringstream& res)
    {
        if(root == nullptr)
        {
            res << "#!";
            return;
        }
        res << root->val << "!";
        SerializeCore(root->left, res);
        SerializeCore(root->right, res);
    }
    TreeNode* Deserialize(char *str) 
    {
        return DeserializeCore(&str);
    }
    TreeNode* DeserializeCore(char** str)
    {
        int num;
        if(ReadStr(str, num) == false)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(num);
        root->left = DeserializeCore(str);
        root->right = DeserializeCore(str);
        return root;
    }
    //每次从流中读取一个结点的值
    //当其为数字则返回真，否则返回假
    bool ReadStr(char** str, int& num)
    {
        string stringStr = (*str);
        int pos = stringStr.find('!');
        if(pos == string::npos)
        {
            num = 0;
            return false;
        }
        string value = stringStr.substr(0, pos);
        (*str) += pos + 1;
        if(value == "#")
        {
            num = 0;
            return false;
        }
        stringstream valueStream;
        valueStream << value.c_str();
        valueStream >> num;
        return true;
    }
};