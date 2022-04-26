#include "Util.h"
// JZ3 数组中重复的数字
class JZ3Solution
{
public:
    //[2,3,1,0,2,5,3] 2或者3
    int duplicate(vector<int> &numbers)
    {
        // write code here
        if (numbers.empty())
            return -1;
        int num = -1;
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        for (int i = 0; i < size - 1; i++)
        {
            if (numbers[i] == numbers[i + 1])
            {
                num = numbers[i];
                return num;
            }
        }
        return num;
    }
    int duplicate2(vector<int> &numbers)
    {
        if (numbers.empty())
            return -1;
        map<int, int> m;
        int size = numbers.size();
        int k1 = size - 1 / 2;
        int k2 = size - 1 / 2 + 1;
        for (int i = 0, j = size - 1; i < size && i < j; i++, j--)
        {
            m[numbers[i]]++;
            m[numbers[j]]++;
            if (m[numbers[i]] > 1)
                return numbers[i];
            if (m[numbers[j]] > 1)
                return numbers[j];
            if (k1 > i && k2 < j)
            {
                m[numbers[k1]]++;
                m[numbers[k2]]++;
                if (m[numbers[k1]] > 1)
                    return numbers[k1];
                if (m[numbers[k2]] > 1)
                    return numbers[k2];
                k1--;
                k2++;
            }
        }
        return -1;
    }
};
//JZ51 数组中的逆序对
/*
描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P mod 1000000007
数组中所有数字的值满足 val≤1000000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(nlogn)O(nlogn)
输入描述：题目保证输入的数组中没有的相同的数字
*/
class JZ51sSolution {
public:
    //[1,2,3,4,5,6,7,0]
    //7
    int InversePairs(vector<int> data) {
        int size = data.size();
        int count = 0;
        for(int i=0;i<size;i++){
            for(int j=size-1;j>i;j--){
                if(data[i]>data[j]){
                    count++;
                }
            }
        }
        count = count % 1000000007;
        return count;
    }
};
//JZ40 最小的K个数
/*描述
给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。
例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
数据范围：0≤k,n≤10000，数组中每个数的大小 0≤val≤1000
要求：空间复杂度 O(n) ，时间复杂度 O(nlogn)*/
class JZ40Solution {
public:
    //[4,5,1,6,2,7,3,8],4 
    //1 2 3 4 返回最小的4个数即可，返回[1,3,2,4]也可以  
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
    }
};