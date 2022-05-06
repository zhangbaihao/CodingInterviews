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

//JZ27 二叉树的镜像
class JZ27Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if(!pRoot)
            return pRoot;
        TreeNode* temp = pRoot->left;
        pRoot->left = Mirror(pRoot->right);
        pRoot->right = Mirror(temp);
        return pRoot;
    }
};

//JZ32 从上往下打印二叉树
class JZ32Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(!front)
                continue;
            res.push_back(front->val);
            q.push(front->left);
            q.push(front->right);
        }
        return res;
    }
};

//JZ33 二叉搜索树的后序遍历序列
class JZ33Solution {
public:
    //输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
    //如果是则返回 true ,否则返回 false 。假设输入的数组的任意两个数字都互不相同
    //sequence[end] 后续遍历根节点是最后一个结点
    bool Verify(vector<int> sequence,int start,int end){
        if(start>=end)
            return true;
        int k = start;
        //找到第一个比根节点大的结点 从此节点到根节点皆为右子树
        while(k<end && sequence[k]<sequence[end]){
            k++;
        }
        for(int i=k;i<end;i++){
            if(sequence[i]<sequence[end])
                return false;
        }
        return Verify(sequence,start,k-1) && Verify(sequence,k,end-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        if(sequence.size() == 1)
            return true;
        return Verify(sequence,0,sequence.size()-1);
    }
};
//JZ82 二叉树中和为某一值的路径(一)
class JZ82Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(!root)
            return false;
        sum -= root->val;
        if(!root->left && !root->right && sum == 0)
            return true;
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
    }
};
//JZ34 二叉树中和为某一值的路径(二)
class JZ34Solution {
public:
    vector<vector<int>> res;
    void FindOnePath(vector<int> temp,TreeNode* root,int expectNumber){
        if(!root)
            return ;
        temp.push_back(root->val);
        //这里需要到叶子结点
        if(!root->left && !root->right && expectNumber == root->val)
            res.push_back(temp);
        else{
            FindOnePath(temp,root->left,expectNumber-root->val);
            FindOnePath(temp,root->right,expectNumber-root->val);
        }
        temp.pop_back();
    }
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<int> temp;
        FindOnePath(temp,root,expectNumber);
        return res;
    }
};

//JZ36 二叉搜索树与双向链表
class JZ36Solution {
public:
 TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        stack<TreeNode*> st;
        vector<TreeNode*> result;
        TreeNode* head = nullptr,*pre = nullptr;
        while( !st.empty() || pRootOfTree != nullptr){
            while(pRootOfTree != nullptr){
                st.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            if( !st.empty()){
                pRootOfTree = st.top();
                st.pop();
              if(pre == nullptr){//表示第一次出栈，为最左值，记录下最小的元素
                  head = pRootOfTree;
              }
              else{
                  pre->right = pRootOfTree;
                  pRootOfTree->left = pre;
               }

                pre = pRootOfTree;
                pRootOfTree = pRootOfTree->right;
            }
        }
        return head;
    }
};