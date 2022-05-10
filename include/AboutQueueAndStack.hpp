#pragma once
#include "Util.h"
// JZ9 用两个栈实现队列
class JZ9Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int value = 0;
        if (!stack2.empty())
        {
            value = stack2.top();
            stack2.pop();
        }
        else
        {
            while (!stack1.empty())
            {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            value = stack2.top();
            stack2.pop();
        }
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
// JZ30 包含min函数的栈
class JZ30Solution
{
public:
    stack<int> stack1;
    multiset<int> number;
    void push(int value)
    {
        stack1.push(value);
        number.insert(value);
    }
    void pop()
    {
        int value = stack1.top();
        number.erase(number.find(value));
        stack1.pop();
    }
    int top()
    {
        return stack1.top();
    }
    int min()
    {
        return *number.begin();
    }
};
// JZ31 栈的压入、弹出序列
class JZ31Solution
{
public:
    //[1,2,3,4,5],[4,5,3,2,1] true
    //[1,2,3,4,5],[4,3,5,1,2] false
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> temp;
        int size = pushV.size();
        int i = 0, j = 0;
        while (j < size)
        {
            if (pushV[i] != popV[j])
            {
                if (!temp.empty())
                {
                    if (temp.top() == popV[j])
                    {
                        temp.pop();
                        j++;
                        continue;
                    }
                    else
                    {
                        if (i >= size)
                            return false;
                    }
                }
                temp.push(pushV[i]);
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return true;
    }
};

//输入:"nowcoder. a am I"
//返回值:"I am a nowcoder."
class JZ73Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.empty())
            return str;

        int i = 0;
        int size = str.size();
        while (i < size && str[i] == ' ')
            ++i;
        if (i == size)
            return str;
        istringstream ss(str);
        vector<string> ret;
        string s;
        // 拆分单词
        while (ss >> s)
            ret.push_back(s);
        reverse(ret.begin(), ret.end());
        ostringstream oss;
        // 合并成字符串
        for (int i = 0; i < ret.size() - 1; ++i)
            oss << ret[i] << ' ';
        //返回当前vector容器中末尾元素的引用。
        oss << ret.back();
        return oss.str();
    }
};
/*
他们的最大值分别为{4,4,6,6,6,5};
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1},
{2,[3,4,2],6,2,5,1},
{2,3,[4,2,6],2,5,1},
{2,3,4,[2,6,2],5,1},
{2,3,4,2,[6,2,5],1},
{2,3,4,2,6,[2,5,1]}。
*/
class JZ59Solution
{
public:
    vector<int> maxInWindows(const vector<int> &nums, int size)
    {
        vector<int> ret;
        if (nums.size() == 0 || size < 1 || nums.size() < size)
            return ret;
        int n = nums.size();
        //用来存储vector中的下标，其中front代表滑动窗口最大值，
        deque<int> dq;
        for (int i = 0; i < n; ++i)
        {
            /*
            如果arr[i+1] > arr[i], 那么还要arr[i]有什么用.
            如果arr[i+1] < arr[i],显然arr[i]还是需要保留的。
            */
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            // 判断队列的头部的下标是否过期
            if (dq.front() + size <= i)
            {
                dq.pop_front();
            }
            // 判断是否形成了窗口
            if (i + 1 >= size)
            {
                ret.push_back(nums[dq.front()]);
            }
        }
        return ret;
    }
};