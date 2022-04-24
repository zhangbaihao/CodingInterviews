#include "Util.h"
// JZ12 矩阵中的路径
class JZ12Solution
{
public:
    bool dfs(vector<vector<char>> matrix, int i, int row, int col, string str)
    {
        //先找到入口
        if (matrix[row][col] != str[i])
            return false;       //没找到入口，返回
        matrix[row][col] = '*'; //把每次成功找到的走过的路径上的字符设置为*；防止str中存在重复的元素
        i++;                    //每一次找到了之后，i=i+1

        //找到对应的值之后，找出口
        if (i == str.size())
            return true; //当找到的路径数目等于字符长度，那么说明路径已经找到了

        //设置偏移量，要么向上要么向下要么向左要么向右
        int dx[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //分别是向左 向右 向上 向下
        for (int j = 0; j < 4; j++)                        //每次可以有四个方向进行移动
        {
            row = row + dx[j][0];
            col = col + dx[j][1];
            if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size())
            {
                if (dfs(matrix, i, row, col, str))
                { //找到了
                    return true;
                }
            }
            row = row - dx[j][0]; //当超出边界，返回现场；当移动之后没找到，返回现场
            col = col - dx[j][1];
        }
        //如果没找到
        return false;
    }
    bool hasPath(vector<vector<char>> &matrix, string word)
    {
        // write code here
        int rowLen = matrix.size();    //行数
        int colLen = matrix[0].size(); //列数
        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < colLen; j++)
            {
                if (dfs(matrix, 0, i, j, word))
                    return true;
            }
        }
        return false;
    }
};
