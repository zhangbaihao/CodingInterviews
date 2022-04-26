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
// JZ51 数组中的逆序对
/*
描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P mod 1000000007
数组中所有数字的值满足 val≤1000000
要求：空间复杂度 O(n)，时间复杂度 O(nlogn)
输入描述：题目保证输入的数组中没有的相同的数字
*/
class JZ51sSolution
{
public:
    //[1,2,3,4,5,6,7,0]
    // 7
    int InversePairs(vector<int> data)
    {
        int size = data.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (data[i] > data[j])
                {
                    count++;
                }
            }
        }
        count = count % 1000000007;
        return count;
    }
    int mod = 1000000007;
        int mergeSort(int left, int right, vector<int> &data, vector<int> &temp)
        {
            //停止划分
            if (left >= right)
                return 0;
            //取中间
            int mid = (left + right) / 2;
            //左右划分合并
            int res = mergeSort(left, mid, data, temp) + mergeSort(mid + 1, right, data, temp);
            //防止溢出
            res %= mod;
            int i = left, j = mid + 1;
            for (int k = left; k <= right; k++)
                temp[k] = data[k];
            for (int k = left; k <= right; k++)
            {
                // mid左边已经全部排进data，只剩下右边，且不会再出现逆序对
                if (i == mid + 1)
                    data[k] = temp[j++];
                else if (j == right + 1 || temp[i] <= temp[j])
                    data[k] = temp[i++];
                //左边temp[i]>temp[j]则区间[i]-[mid]都比右边[j]大,，答案增加
                else
                {
                    data[k] = temp[j++];
                    //统计逆序对
                    res += mid - i + 1;
                }
            }
            return res % mod;
        }
        int InversePairs(vector<int> data)
        {
            int n = data.size();
            vector<int> res(n);
            return mergeSort(0, n - 1, data, res);
        }
};
// JZ40 最小的K个数
/*描述
给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。
例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
数据范围：0≤k,n≤10000，数组中每个数的大小 0≤val≤1000
要求：空间复杂度 O(n) ，时间复杂度 O(nlogn)*/
class JZ40Solution
{
public:
    //[4,5,1,6,2,7,3,8],4
    // 1 2 3 4 返回最小的4个数即可，返回[1,3,2,4]也可以
    //[1] 0 返回[]即可
    //暴力解法排序后 for前面k个数
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        if (k == 0)
            return result;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++)
        {
            result.push_back(input[i]);
        }
        return result;
    }
    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k)
    {
        vector<int> res;
        //排除特殊情况
        if (k == 0 || input.size() == 0)
            return res;
        //优先队列（大根堆），只要限制堆的大小为k，那么堆顶就是k个数字的中最大值，
        //如果需要替换，将这个最大值拿出，加入新的元素就好了。
        priority_queue<int> q;
        //构建一个k个大小的堆
        for (int i = 0; i < k; i++)
            q.push(input[i]);
        for (int i = k; i < input.size(); i++)
        {
            //较小元素入堆
            if (q.top() > input[i])
            {
                q.pop();
                q.push(input[i]);
            }
        }
        //堆中元素取出入vector
        for (int i = 0; i < k; i++)
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
// JZ41 数据流中的中位数
/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
数据范围：数据流中数个数满足 1≤n≤1000  ，大小满足1≤val≤1000
进阶： 空间复杂度 O(n)， 时间复杂度 O(nlogn) */
//[5,2,3,4,1,6,7,0,8]
//返回值："5.00 3.50 3.00 3.50 3.00 3.50 4.00 3.50 4.00 "
//说明：数据流里面不断吐出的是5,2,3...,则得到的平均数分别为5,(5+2)/2,3...
class JZ41Solution
{
public:
    //[5,2,3,4,1,6,7,0,8]
    vector<int> datas;
    void Insert(int num)
    {
        int size = datas.size();
        if (size > 0 && num >= datas[size - 1])
        {
            datas.push_back(num);
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (datas[i] > num)
            {
                datas.insert(datas.begin() + i, num);
                return;
            }
        }
        datas.insert(datas.begin() + size, num);
    }

    double GetMedian()
    {
        int size = datas.size();
        int index = size / 2;
        if (size % 2 == 0)
        {
            return (datas[index] + datas[index - 1]) / 2.0;
        }
        else
        {
            return datas[index];
        }
    }
};
//堆排序
class HeapSortSolution
{
    //对有一定顺序的堆，当前第i个结点取根左右的最大值（这个操作称heapfiy）
    void heapify(vector<int> &nums, int n, int i)
    {
        int l = i * 2 + 1, r = i * 2 + 2;
        int max = i;
        if (l < n && nums[l] > nums[max])
            max = l;
        if (r < n && nums[r] > nums[max])
            max = r;
        if (max != i)
        {
            swap(nums[max], nums[i]);
            //因为交换了，还需要向下调整
            heapify(nums, n, max);
        }
    }
    //建立大根堆
    void heapify_build(vector<int> &nums, int n)
    {
        //由最后一个结点下标是n-1，parent = (i-1)/2
        //从树的倒数第二层第一个结点开始，对每个结点进行heapify操作，然后向上走
        int temp = (n - 2) / 2;
        for (int i = temp; i >= 0; i--)
            heapify(nums, n, i);
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;
    }
    //数组 总共有n个结点
    void heapify_sort(vector<int> &nums, int n)
    {
        //建立大根堆
        heapify_build(nums, n);
        //每次交换最后一个结点和根节点（最大值），
        //对交换后的根节点继续进行heapify（此时堆的最后一位是最大值，因此不用管他，n变为n-1）
        for (int i = 0; i < n; i++)
        {
            swap(nums.front(), nums[n - i - 1]);
            heapify(nums, n - i - 1, 0);
        }
    }
};
