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

// JZ54 二叉搜索树的第k个节点
class JZ54Solution
{
public:
    stack<int> q;
    int KthNode(TreeNode *proot, int k)
    {
        // write code here
        if (!proot || k <= 0)
            return -1;
        KthNode(proot->left, k);
        if (q.size() < k)
            q.push(proot->val);
        //这里不加也行，但是没必要
        if (q.size() < k)
            KthNode(proot->right, k);
        if (q.size() == k)
        {
            return q.top();
        }
        else
        {
            return -1;
        }
    }
};
// JZ7 重建二叉树
class JZ7Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0 || vin.size() == 0)
            return nullptr;
        TreeNode *treeNode = new TreeNode(pre[0]);
        //从中序中找到根节点，前序遍历第一个为根结点
        int mid = distance(begin(vin), find(vin.begin(), vin.end(), pre[0]));
        vector<int> left_pre(pre.begin() + 1, pre.begin() + mid + 1);
        vector<int> right_pre(pre.begin() + mid + 1, pre.end());
        vector<int> left_vin(vin.begin(), vin.begin() + mid);
        vector<int> right_vin(vin.begin() + mid + 1, vin.end());

        treeNode->left = reConstructBinaryTree(left_pre, left_vin);

        treeNode->right = reConstructBinaryTree(right_pre, right_vin);
        return treeNode;
    }
};

// JZ27 二叉树的镜像
class JZ27Solution
{
public:
    TreeNode *Mirror(TreeNode *pRoot)
    {
        // write code here
        if (!pRoot)
            return pRoot;
        TreeNode *temp = pRoot->left;
        pRoot->left = Mirror(pRoot->right);
        pRoot->right = Mirror(temp);
        return pRoot;
    }
};

// JZ32 从上往下打印二叉树
class JZ32Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (!front)
                continue;
            res.push_back(front->val);
            q.push(front->left);
            q.push(front->right);
        }
        return res;
    }
};

// JZ33 二叉搜索树的后序遍历序列
class JZ33Solution
{
public:
    //输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
    //如果是则返回 true ,否则返回 false 。假设输入的数组的任意两个数字都互不相同
    // sequence[end] 后续遍历根节点是最后一个结点
    bool Verify(vector<int> sequence, int start, int end)
    {
        if (start >= end)
            return true;
        int k = start;
        //找到第一个比根节点大的结点 从此节点到根节点皆为右子树
        while (k < end && sequence[k] < sequence[end])
        {
            k++;
        }
        for (int i = k; i < end; i++)
        {
            if (sequence[i] < sequence[end])
                return false;
        }
        return Verify(sequence, start, k - 1) && Verify(sequence, k, end - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
            return false;
        if (sequence.size() == 1)
            return true;
        return Verify(sequence, 0, sequence.size() - 1);
    }
};
// JZ82 二叉树中和为某一值的路径(一)
class JZ82Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        // write code here
        if (!root)
            return false;
        sum -= root->val;
        if (!root->left && !root->right && sum == 0)
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
// JZ34 二叉树中和为某一值的路径(二)
class JZ34Solution
{
public:
    vector<vector<int>> res;
    void FindOnePath(vector<int> temp, TreeNode *root, int expectNumber)
    {
        if (!root)
            return;
        temp.push_back(root->val);
        //这里需要到叶子结点
        if (!root->left && !root->right && expectNumber == root->val)
            res.push_back(temp);
        else
        {
            FindOnePath(temp, root->left, expectNumber - root->val);
            FindOnePath(temp, root->right, expectNumber - root->val);
        }
        temp.pop_back();
    }
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<int> temp;
        FindOnePath(temp, root, expectNumber);
        return res;
    }
};

// JZ36 二叉搜索树与双向链表
class JZ36Solution
{
public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
            return nullptr;
        stack<TreeNode *> st;
        TreeNode *head = nullptr;
        TreeNode *pre = nullptr;
        while (!st.empty() || pRootOfTree)
        {
            //优先访问左子树，其他先存栈
            while (pRootOfTree && pRootOfTree->left)
            {
                st.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            //当前结点左子树 自己 右子树均访问结束，往上走
            if (!pRootOfTree && !st.empty())
            {
                pRootOfTree = st.top();
                st.pop();
            }
            //第一次出栈pre还未赋值
            if (!pre)
            {
                head = pRootOfTree;
            }
            else
            {
                //调整当前结点与上结点的left和right指针关系
                pre->right = pRootOfTree;
                pRootOfTree->left = pre;
            }
            pre = pRootOfTree;
            //访问默认的下个结点
            pRootOfTree = pRootOfTree->right;
        }
        return head;
    }
};
// JZ79 判断是不是平衡二叉树
class JZ79Solution
{
public:
    map<TreeNode *, int> hs;
    int getDeepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        int l = getDeepth(pRoot->left);
        int r = getDeepth(pRoot->right);
        hs[pRoot] = (max(l, r) + 1);
        return hs[pRoot];
    }
    bool isBalanced(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        return abs(hs[pRoot->left] - hs[pRoot->right]) <= 1 && isBalanced(pRoot->left) && isBalanced(pRoot->right);
    }
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        getDeepth(pRoot);
        return isBalanced(pRoot);
    }
};
// JZ8 二叉树的下一个结点
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //指向父结点的next指针
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class JZ8Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
            return pNode;
        //如果有右子树则，下一个结点一点在右子树上的左下角
        if (pNode->right)
        {
            pNode = pNode->right;
            while (pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }
        //没有右子树的情况下，如果有父节点
        while (pNode->next)
        {
            TreeLinkNode *root = pNode->next;
            //判断一下当前结点是不是父结点的左子树，是下一个就是父节点
            if (root->left == pNode)
            {
                return root;
            }
            else
            {
                //右子树，则往上移动
                pNode = pNode->next;
            }
        }
        return nullptr;
    }
};
// JZ28 对称的二叉树
class JZ28Solution
{
public:
    bool isSame(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        return root1->val == root2->val && isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
    }
    bool isSymmetrical(TreeNode *pRoot)
    {
        return isSame(pRoot, pRoot);
    }
};
// JZ78 把二叉树打印成多行
class JZ78Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (!pRoot)
            return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (!t)
                    continue;
                q.push(t->left);
                q.push(t->right);
                temp.push_back(t->val);
            }
            if (!temp.empty())
                res.push_back(temp);
        }
        return res;
    }
};
//JZ37 序列化二叉树
class Solution {
public:

    char* Serialize(TreeNode *root) {    
        
    }
    //{1,2,3,#,#,6,7} 转成二叉树
    TreeNode* Deserialize(char *str) {
    
    }
};
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    string SerializeCore(TreeNode* root){
        if(root == nullptr){
            return "#!";
        }
        string str;
        str = to_string(root->val) + "!";
        str += SerializeCore(root->left);
        str += SerializeCore(root->right);
        return str;
    }
    char* Serialize(TreeNode* root) {
        string str = SerializeCore(root);
        char *res = new char[str.size()];
        for(int i = 0; i<str.size(); i++){
            res[i] = str[i];
        }
        return res;
    }
    //反序列化字符串 重建二叉树
    TreeNode* DeserializeCore(char* &str){
        if(*str == '#'){
            str++;
            return nullptr;
        }
        
        int num = 0;
        while(*str != '!'){
            num = num*10 + *str - '0';
            str++; 
        }
        TreeNode *node = new TreeNode(num);
        node->left = DeserializeCore(++str);
        node->right = DeserializeCore(++str);
        return node;
    }
    TreeNode* Deserialize(char* str) {
        return DeserializeCore(str);
    }
};