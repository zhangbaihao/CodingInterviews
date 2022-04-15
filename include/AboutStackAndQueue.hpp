#pragma once
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
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
    {
        vector<int> maxValue;
        int max = 0;
        int i = 0;
        queue<int> q;
        for (int k = 0; k < size; k++)
        {
            if (nums[k] > max)
                max = nums[k];
            q.push(nums[k]);
        }
        maxValue.push_back(max);
        i += size;
        while (i < nums.size())
        {
            int front = q.front();
            q.pop();
            q.push(nums[i]);
            if (nums[i] > max)
            {
                max = nums[i];
            }
            else
            {
                if (front == max)
                {
                    max = q.front();
                    for (int k = 0; k < size; k++)
                    {
                        if (nums[i-k] > max)
                            max = nums[i-k];
                    }
                }
                
            }
            i++;
            maxValue.push_back(max);
        }
        return maxValue;
    }   
};