#pragma once
#include"Util.h"
// JZ31 栈的压入、弹出序列

//[1,2,3,4,5],[4,5,3,2,1] true
//[1,2,3,4,5],[4,3,5,1,2] false
class JZ31Solution
{
public:
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
    {    vector<int> ret;
        if (nums.size() == 0 || size < 1 || nums.size() < size) 
            return ret;
        int n = nums.size();
           deque<int> dq;
           for (int i = 0; i < n; ++i) {
               /*
               如果arr[i+1] 已经大于了 arr[i], 那么还要arr[i]有什么用.
               如果arr[i+1] < arr[i],显然arr[i]还是需要保留的。因为又可以arr[i] 对于下一个arr[i+1]所在的窗口来说，arr[i]已经失效了
               */
               while (!dq.empty() && nums[dq.back()] < nums[i]) {
                   dq.pop_back();
               }
               dq.push_back(i);
               // 判断队列的头部的下标是否过期
               if (dq.front() + size <= i) {
                   dq.pop_front();
            }
            // 判断是否形成了窗口
               if (i + 1 >= size) {
                   ret.push_back(nums[dq.front()]);
               }
           }
           return ret; 
    }
};