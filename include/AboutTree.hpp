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
                q.push(tmp->left);
                q.push(tmp->right);
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

//JZ54 二叉搜索树的第k个节点
class JZ54Solution {
public:
    stack<int> q;
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if(!proot || k<=0)
            return -1;
        KthNode(proot->left,k);
        if(q.size()<k)
            q.push(proot->val);
        //这里不加也行，但是没必要
        if(q.size()<k)
            KthNode(proot->right,k);
        if(q.size() == k)
        {
            return q.top();
        }else{
            return -1;
        }
    }
};
//JZ7 重建二叉树
class JZ7Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() ==0)
            return nullptr;
        TreeNode *treeNode = new TreeNode(pre[0]);
        //从中序中找到根节点，前序遍历第一个为根结点
        int mid = distance(begin(vin),find(vin.begin(),vin.end(),pre[0]));
        vector<int> left_pre(pre.begin()+1,pre.begin()+mid+1);
        vector<int> right_pre(pre.begin()+mid+1,pre.end());
        vector<int> left_vin(vin.begin(),vin.begin()+mid);
        vector<int> right_vin(vin.begin()+mid+1,vin.end());
         
        treeNode->left = reConstructBinaryTree(left_pre, left_vin);
         
        treeNode->right = reConstructBinaryTree(right_pre, right_vin);
        return treeNode;
    }
};