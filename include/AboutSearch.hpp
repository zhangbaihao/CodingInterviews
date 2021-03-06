#pragma once
#include "Util.h"
// JZ53 数字在升序数组中出现的次数
class JZ53Solution
{
public:
    //[1,2,3,3,3,3,4,5],3 返回值 4
    int GetNumberOfK1(vector<int> data, int k)
    {
        int count = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] == k)
            {
                count++;
            }
            if (count == 0 && data[i] > k)
                return 0;
        }
        return count;
    }
    //二分查找
    int GetNumberOfK2(vector<int> nums, int target)
    {
        int lbound = 0, rbound = 0;
        //下界第一个等于target数
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        lbound = l;
        // 寻找上界 即第一个比target大的数
        l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        rbound = l;
        return rbound - lbound;
    }
};

// JZ4 二维数组中的查找
class JZ4Solution
{
public:
    bool Find1(int target, vector<vector<int>> array)
    {
        for (auto i : array) // c++11语法
        {
            for (auto j : i)
            {
                if (j == target)
                    return true; //找到目标值
            }
        }
        return false; //未找到
    }
    bool BinarySearch(int target, vector<int> array)
    {
        int l = 0, r = array.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (array[mid] == target)
            {
                return true;
            }
            else if (array[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
    bool Find2(int target, vector<vector<int>> array)
    {
        for (auto i : array)
        {
            if (BinarySearch(target, i))
            {
                return true;
            }
        }
        return false;
    }
    bool Find3(int target, vector<vector<int>> array)
    {
        int rows = array.size();
        int k = 0;
        for (int i = rows - 1; i >= 0; i--)
        {
            int cols = array[i].size();
            if (cols == 0)
                return false;
            if (array[i][0] > target)
            {
                continue;
            }
            for (int j = k; j < cols; j++)
            {
                if (array[i][j] == target)
                    return true;
                else if (array[i][j] > target)
                {
                    k = j - 1;
                    break;
                }
            }
        }
        return false;
    }
};
// JZ11 旋转数组的最小数字
class JZ11Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int l = 0;
        int r = rotateArray.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            //原本有序 旋转后说明最小值一定在右边
            if (rotateArray[mid] > rotateArray[r])
            {
                l = mid + 1;
            } //重复的值
            else if (rotateArray[mid] == rotateArray[r])
            {
                r = r - 1;
            }
            else
            {
                r = mid;
            }
        }
        return rotateArray[l];
    }
};
// JZ38 字符串的排列
class JZ38Solution
{
public:
    set<string> str1;
    void recursion(std::string str,int length,int n){
        if(n == length)
            str1.insert(str);
        //第n个与之后的第i字母进行交换，其中i=0 则为本身不变 如Permutation("ABC",3,1) = ABC + A(BC)交换
        for(int i=0;i+n<length;i++){
            char temp = str[n+i];
            str[n+i] = str[n];
            str[n] = temp;
            recursion(str,length,n+1);
        }
    }
    vector<string> Permutation(string str)
    {
        vector<string> res;
        if(str.length() > 0)
            recursion(str,str.length(),0);
        for(auto a = str1.begin();a != str1.end();a++){
            res.push_back(*a);
        }
        return res;
    }
};

// JZ44 数字序列中某一位的数字
class JZ44Solution
{
public:
    /*
    1-9       9个*1
    10-99     90个*2
    100-999   900个*3
    1000-9999 9000个*4
    */
    int findNthDigit(int n)
    {
        if (n == 0)
            return 0;
        long long start = 1; //起始数
        long long digit = 1; //记录位数
        long long count = 9; //记录区间个数，比如9 90 900
        while(n > count){
            n -= count;
            start *= 10;
            digit++;//1-9 ~ 1位  10-99 2位
            count = 9 *start * digit;//1位数 9 -2位数 90 - 3位数 900
        }
        //从start开始第在哪个数 如100开始 + 270 则370 
        long long number = start + (n-1) / digit;
        //从这个number第几位 temp 范围应该是1~digit
        int temp = 1 + (n-1) % digit;
        for(int i = digit;i > temp; i--){
            //每次去掉最后一位 
            number /= 10;
        }
        //number最后一位数字
        return number % 10;
    }
};
