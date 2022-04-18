#pragma once
#include "Util.h"
//JZ42 连续子数组的最大和
class JZ42Solution {
public:
    //输入：[1,-2,3,10,-4,7,2,-5]
    //子数组[3,10,-4,7,2]可以求得最大和为18   
  int FindGreatestSumOfSubArray(vector<int> array)
  {
      int now = 0;
      int ans = INT_MIN;
      for (int i = 0; i < array.size(); i++)
      {
          if (now < 0)//now<0,则舍去前面的
              now = array[i];
          else
          {
              now += array[i];//比0大则直接加上去
          }
          ans = max(now, ans);//更新ans
      }
      return ans;
  }
  //动态规划 dp[n]为以第n个数为结尾，得到的子数组的和的最大值
  int FindGreatestSumOfSubArray2(vector<int> array) {
      int n=array.size();
      vector<int> dp;
      dp.push_back(array[0]);
      // 初始化
      int ans=dp[0];
      for(int i=1;i<n;i++){
          // 根据状态转移公式进行状态转移  
          dp.push_back(max(array[i],dp[i-1]+array[i]));
          // 维护最终的答案
          ans=max(ans,dp[i]);
      }
      return ans;
  }
};
//JZ85 连续子数组的最大和(二)
class JZ85Solution {
public:
    //输入：[1,-2,3,10,-4,7,2,-5]子数组[3,10,-4,7,2]可以求得最大和为18
    //输入：[1,-2,3,10,-4,7,2,-1,1,-5] 子数组[3,10,-4,7,2,-1,1] 返回长度较长的子数组
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> res;
        int x = array[0];//以上一轮循环最后一个数结尾子数组的和的最大值
        int y = 0;//当前轮循环最后一个数结尾子数组的和的最大值
        int maxsum = x;//历史子数组的和最大值
        int left = 0, right = 0; //滑动区间
        int resl = 0, resr = 0; //记录最长的区间
        for(int i = 1; i < array.size(); i++){
            right++;
            y = max(x + array[i], array[i]); //状态转移：连续子数组和最大值
            if(x + array[i] < array[i]) //区间新起点，前面全部丢弃
                left = right;
            if(y > maxsum || y == maxsum && (right - left + 1) > (resr - resl + 1)){ //更新最大值
                maxsum = y;
                resl = left;
                resr = right;
            }
            x = y; //更新x的状态
        }
        for(int i = resl; i <= resr; i++) //取数组
            res.push_back(array[i]);
        return res;
    }
};
