#pragma once
#include "Util.h"
// JZ42 连续子数组的最大和
class JZ42Solution
{
public:
    //输入：[1,-2,3,10,-4,7,2,-5]
    //子数组[3,10,-4,7,2]可以求得最大和为18
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int now = 0;             //表示当前累加和，要是<0 前面都可以不需要了
        int max_value = INT_MIN; //用来保存最大值
        for (int i = 0; i < array.size(); i++)
        { // now<0,则舍去前面的
            if (now < 0)
                now = array[i];
            else
            {
                now += array[i]; //比0大则直接加上去
            }
            max_value = max(now, max_value); //更新最大值
        }
        return max_value;
    }
    //动态规划 dp[n]为以第n个数为结尾，得到的子数组的和的最大值
    int FindGreatestSumOfSubArray2(vector<int> array)
    {
        int size = array.size();
        // dp[i] 第i个数时最大合
        vector<int> dp;
        dp.push_back(array[0]);
        int max_value = dp[0];
        for (int i = 1; i < size; i++)
        {
            dp.push_back(max(array[i], dp[i - 1] + array[i]));
            max_value = max(max_value, dp[i]);
        }
        return max_value;
    }
};
// JZ85 连续子数组的最大和(二)
class JZ85Solution
{
public:
    //输入：[1,-2,3,10,-4,7,2,-5]子数组[3,10,-4,7,2]可以求得最大和为18
    //输入：[1,-2,3,10,-4,7,2,-1,1,-5] 子数组[3,10,-4,7,2,-1,1] 返回长度较长的子数组
    vector<int> FindGreatestSumOfSubArray(vector<int> &array)
    {
        vector<int> res;
        int c_max = array[0];  //当前轮
        int maxsum = array[0]; //历史和最大值
        int left = 0, right = 0;
        int resl = 0, resr = 0;
        for (int i = 1; i < array.size(); i++)
        {
            right++;
            if (c_max + array[i] < array[i])
            {
                left = right;
                c_max = array[i];
            }
            else
            {
                c_max = c_max + array[i];
            }
            // c_max当前轮循环最后一个数结尾子数组的和的最大值
            if (c_max > maxsum || c_max == maxsum && (right - left + 1) > (resr - resl + 1))
            {
                maxsum = c_max;
                resl = left;
                resr = right;
            }
        }
        for (int i = resl; i <= resr; i++)
        {
            res.push_back(array[i]);
        }
        return res;
    }
};
// JZ69 跳台阶
class JZ69Solution
{
public:
    //数据范围:40 1≤n≤40
    int jumpFloor(int number)
    {
        int dp[41];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        int k = 2;
        while (k <= number)
        {
            dp[k] = dp[k - 1] + dp[k - 2];
            k++;
        }
        return dp[number];
    }
};
// JZ10 斐波那契数列
class JZ10Solution
{
public:
    // fib(1)=1,fib(2)=1,fib(3)=fib(3-1)+fib(3-2)=2
    int Fibonacci(int n)
    {
        if (n <= 2)
            return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
    int Fibonacci2(int n)
    {
        int dp[41];
        dp[0] = dp[1] = dp[2] = 1;
        int k = 3;
        while (k <= n)
        {
            dp[k] = dp[k - 1] + dp[k - 2];
            k++;
        }
        return dp[n];
    }
};
// JZ19 正则表达式匹配
class JZ19Solution
{
public:
    //会超时
    bool match(const string &str, const string &pattern)
    {
        if (str.empty() && pattern.empty())
            return true;
        if (!str.empty() && pattern.empty())
            return false;
        if (pattern[1] == '*')
        {
            if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty()))
            {
                //进入下一状态 "" "a" *只用来匹配一次
                bool ok1 = match(str.substr(1), pattern.substr(2));
                //留在当前状态 "" *继续匹配
                bool ok2 = match(str.substr(1), pattern);
                //忽略一个'*'
                bool ok3 = match(str, pattern.substr(2));
                return ok1 || ok2 || ok3;
            }
            else
            {
                //忽略一个'*'
                return match(str, pattern.substr(2));
            }
        }
        //正常进入下一个阶段
        if (str[0] == pattern[0] || (pattern[0] == '.' && !str.empty()))
            return match(str.substr(1), pattern.substr(1));

        return false;
    }
    // dp[i][j]表示str的前i个字符与pattern的前j个字符是否匹配 当前的表示为j-1
    //""和 “a*c*"匹配过程"
    // j=1 pattern[1-1] == 'a' dp[0][1] = 0
    // j=2 pattern[2-1] == '*' dp[0][2] = dp[0][0] == 1
    // j=3 pattern[3-1] == 'c' dp[0][3] = 0
    // j=4 pattern[4-1] == 'c' dp[0][4] = dp[0][2] == 1
    // "a"  "a*"
    //第j个字符是'*' 在str下标0开始默认需要-1
    // dp[i][j] 表示前面i个字符和pattern前面j个字符匹配
    int dp[35][35] = {0};
    bool match2(string str, string pattern)
    {
        int len1 = str.length();
        int len2 = pattern.length();
        dp[0][0] = 1;
        for (int i = 0; i <= len1; i++) // i==0是处理空str串,非空pattern串的情况
        {
            for (int j = 1; j <= len2; j++)
            {
                //这里题目好像保证了输入*一定不会出现在pattern第1个字符但还是j>=2 好一些
                if (j >= 2 && pattern[j - 1] == '*')
                {
                    if (i > 0 && pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1])
                    {
                        dp[i][j] = dp[i - 1][j]; //*用了至少1次 则应该跟少一个字符dp相等
                    }
                    dp[i][j] |= dp[i][j - 2]; //字符 *号 使用0次
                }
                else if (pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1])
                { //如果模式串字符与str字符匹配,和如果模式串字符为.,则dp[i][j]=dp[i-1][j-1]
                    if (i > 0)
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[len1][len2] == 1;
    }
};

// JZ71 跳台阶扩展问题
/*描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。
数据范围：1≤n≤20
进阶：空间复杂度 O(1)O(1) ， 时间复杂度 O(1)O(1)
输入：3返回值：4
输入：1
返回值：1
*/
class JZ71Solution
{
public:
    int jumpFloorII(int number)
    {
        int dp[21] = {0};
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            int sum = 0;
            for (int j = i; j > 1; j--)
            {
                sum += dp[j - 1];
            }
            dp[i] = sum + 1; //直接跳上来
        }
        return dp[number];
    }
};

// JZ70 矩形覆盖
/*
我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，从同一个方向看总共有多少种不同的方法？
进阶：0≤n≤38 空间复杂度 O(1)\O(1)  ，时间复杂度 O(n)\O(n)
注意：约定 n == 0 时，输出 0
比如n=3时，2*3的矩形块有3种不同的覆盖方法(从同一个方向看)：
*/
class JZ70Solution
{
public:
    int rectCover(int number)
    {
        int a[39] = {0};
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[number];
    }
};
// JZ63 买卖股票的最好时机(一)
class JZ63Solution
{
public:
    //输入：[8,9,2,5,4,7,1] 返回值：5  第三天2块钱买入 第6天7块卖出
    int maxProfit(vector<int> &prices)
    {
        int profits = 0;
        int days = prices.size();
        int buyingPrice = prices[0];
        for (int i = 1; i < days; ++i)
        {
            profits = max(profits, prices[i] - buyingPrice);
            buyingPrice = min(prices[i], buyingPrice);
        }
        return profits;
    }
};

// JZ47 礼物的最大价值
class JZ47Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        // dp[x][y] 代表第x行 y列时礼物的最大值
        int dp[201][201];
        dp[1][1] = grid[0][0];
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = i + 1, y = j + 1;
                dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]) + grid[i][j];
            }
        }
        return dp[n][m];
    }
    int maxValue(vector<vector<int>> &grid)
    {
        // dp[x][y] 代表第x行 y列时礼物的最大值
        int dp[201][201] = {0};
        dp[1][1] = grid[0][0];
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[rows][cols];
    }
};
// JZ48 最长不含重复字符的子字符串
class JZ48Solution
{
public:
    //"abcabcbb" 3
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        int maxValue = 1, cur = 0, begin = 0;

        for (int i = 1; i < s.size(); i++)
        {
            for (int j = begin; j < i; j++)
            {
                if (s[j] == s[i])
                {
                    begin = j + 1;
                }
            }
            if (i - begin + 1 > maxValue)
            {
                maxValue += 1;
            }
        }
        return maxValue;
    }
    int lengthOfLongestSubstring2(string s)
    {
        unordered_map<char, int> m;
        int start = 0;
        int maxValue = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //查找
            if (m.find(s[i]) != m.end())
            {
                //起始位置更新为之前该字符位置的后一个位置
                start = max(start, m[s[i]] + 1);
            }
            maxValue = max(maxValue, i - start + 1);
            //存储字符的位置
            m[s[i]] = i;
        }
        return maxValue;
    }
};
// JZ46 把数字翻译成字符串
class JZ46Solution
{
public:
    //有一种将字母编码成数字的方式：'a'->1, 'b->2', ... , 'z->26'
    //输入："12" 返回值：2   2种可能的译码结果（”ab” 或”l”）
    //数据范围：字符串长度满足 0<n≤90
    //"31717126241541717"
    int solve(string nums)
    {
        // dp[i] 代表第i个数字的solve最大数量
        int dp[91] = {0};
        dp[0] = 1;
        int length = nums.length();
        for (int i = 1; i <= length; i++)
        {
            if (nums[i-1] != '0')
            {
                dp[i] += dp[i-1];
            }
            //i-1代表nums当前字符,下标i-2上一个数字，考虑是否能和当前数字结合<=26(z)
            if (i >= 2 && nums[i - 2] != '0' && (nums[i - 2] - '0') * 10 + (nums[i-1] - '0') <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[length];
    }
};