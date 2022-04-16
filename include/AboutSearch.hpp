#pragma once
#include"Util.h"
//JZ53 数字在升序数组中出现的次数
class JZ53Solution {
public:
    //[1,2,3,3,3,3,4,5],3 返回值 4
    int GetNumberOfK1(vector<int> data ,int k) {
        int count = 0;
        for(int i=0;i<data.size();++i){
            if(data[i] == k){
                count++;
            }
            if(count==0 && data[i]>k)
                return 0;
        }
        return count;
    }
    //二分查找
    int GetNumberOfK2(vector<int> nums ,int target) {
        int lbound = 0, rbound = 0;
        //下界第一个等于target数
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        lbound = l;
        // 寻找上界 即第一个比target大的数
        l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        rbound = l;
        return rbound - lbound;
    }
};

//JZ4 二维数组中的查找
class JZ4Solution {
public:
    bool Find1(int target, vector<vector<int> > array) {
       for(auto i : array)//c++11语法
        {
            for(auto j : i)
            {
                if(j == target) 
                    return true;//找到目标值
            }
        }
        return false;//未找到
    }
    bool BinarySearch(int target,vector<int> array){
        int l = 0,r = array.size()-1;
        while(l<=r){
            int mid = (l+r) / 2;
            if(array[mid] == target){
                return true;
            }else if(array[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
    bool Find(int target, vector<vector<int> > array) {
        for(auto i : array){
            if(BinarySearch(target,i)){
                return true;
            }
        }
        return false;
    }
};
//JZ44 数字序列中某一位的数字
class Solution {
public:
    /*
    1-9       9个*1
    10-99     90个*2
    100-999   900个*3
    1000-9999 9000个*4
    */
    int findNthDigit(int n) {
        // write code here
        if(n==0)
            return 0;
        long long start=1;//起始数
        long long digit=1;//记录位数
        long long count=9;//记录区间个数，比如9 90 900
        while(n>count){//先减去前面有规律的数
            digit++;
            n-=count;
            start*=10;
            count=digit*9*start;//-9 -90 - 900依次
        }
        //以下就是n剩余的数
        //这里我们先判断剩余的n是在哪个数
        long long number=start+(n-1)/digit;//start就是开始的第一个数字，所以后面要n-1
        //判断好是在哪个数字后，下面对数字分解
        long long temp=(n-1)%digit+1;//这个数的第几位
        for(int i=digit;i>temp;i--){//把这个数后面多余的尾巴去掉
            number/=10;
            cout<<number<<" ";
        }
        return number%10;
    }
};
