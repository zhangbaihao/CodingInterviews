#include "Util.h"
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
// JZ55 二叉树的深度
class JZ55Solution
{
public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        int lval = TreeDepth(pRoot->left);
        int rval = TreeDepth(pRoot->right);
        return max(lval, rval) + 1;
    }
};
// JZ77 按之字形顺序打印二叉树
class JZ77Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (!pRoot)
            return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        int level = 0;
        while (!q.empty())
        {
            vector<int> arr;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (!tmp)
                    continue;
                q.push(pRoot->left);
                q.push(pRoot->right);
                if (level % 2 == 0)
                {
                    arr.push_back(tmp->val);
                }
                else
                {
                    arr.insert(arr.begin(), tmp->val);
                }
            }
            level++;
            if (!arr.empty())
                res.push_back(arr);
        }
        return res;
    }
};